#include "header.h"

void moveAndClearLine(int i, int j, hd44780 &lcd){
	lcd.move(i,j);
	lcd.write("                    ");
	lcd.move(i,j);
}
char getch(){
        struct termios old_tio, new_tio;
        char buf = 0;
        
        tcgetattr(STDIN_FILENO,&old_tio);
        new_tio=old_tio;
        new_tio.c_lflag &= ~(ICANON|ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

        if (read(0, &buf, 1) < 0)
                perror ("read()");

        tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
        return (buf);     
	
}
void getLine(char buf[], hd44780 &lcd){
	char c;
	int i = 0;
	lcd.setCursor(hd44780::CURSOR_BLINKING);
	uint8_t startx = lcd.getXpos();
	uint8_t starty = lcd.getYpos();	
	uint8_t xpos;
	do{
		xpos = lcd.getXpos();
		c = getch();
		if ((int)c == 127){
			if (i > 0){
				write(1, "\b \b", 3);
				i--;
			}
			xpos = (xpos <= startx)?(startx):(xpos-1);
			lcd.move(xpos,starty);
			lcd.write(' ');
			lcd.move(xpos,starty);
			
		}else{
			buf[(i++)%128] = c;
			lcd.write(c);
			write(1, &c, 1);
		}
	}while (c != '\n');
	buf[i%128] = '\0';
	lcd.setCursor(hd44780::NO_CURSOR);
}
void printfl(string str, hd44780 &lcd){
	printf("%s\n", str.c_str());
	lcd.write(str);
}

char* str2char(string s){

	char *c=new char[s.size()+1];
	c[s.size()]=0;
	memcpy(c,s.c_str(),s.size());

	return c;
}
std::string exec( const std::string &cmd ) {

	// Open the process for reading
	FILE *pfile = popen( cmd.c_str(), "r" );

	if ( !pfile ) return "<failed>";

	// Output of the process and buffer
	std::string output;
	char buffer[128];

	// Copy the output of the process
	while ( !feof( pfile ) ) {

		if ( fgets( buffer, 128, pfile ) != NULL )
			output.append( buffer );
	}

	// Close the process
	pclose( pfile );

	return output;
}

void scanCard(map<const int, Entry> &entries, int &card, hd44780 &lcd){
	string input;
	char buf[128];

	do{
		moveAndClearLine(0,0,lcd);
		printfl("Scan:", lcd);
		getLine(buf, lcd);
		input = buf;
		stringstream checkIfNumber(input);
		if (checkIfNumber >> card){
			if (card == -1){return;}		
			if (entries.find(card) == entries.end()){
				moveAndClearLine(0,3,lcd);
				moveAndClearLine(0,2,lcd);
				moveAndClearLine(0,1,lcd);
				printfl("Card ID not found!",lcd);
			}else{
				return;
			}
		}
		else{
			moveAndClearLine(0,3,lcd);
			moveAndClearLine(0,2,lcd);
			moveAndClearLine(0,1,lcd);
			printfl("Invalid input!",lcd);
		}
	}while (true);
	return;
}
void printInfo(map<const int, Entry> &entries, int &card, hd44780 &lcd){
	char buf[128];
	lcd.clear(); lcd.move(0, 0);
	sprintf(buf, "%s", entries.find(card)->second.getFirstName().c_str());
	printfl(buf, lcd);
	lcd.move(0,1);
	sprintf(buf, "Balance: %ikr", entries.find(card)->second.getCash());
	printfl(buf, lcd);
}
void transaction(map<const int, Entry> &entries, int &card, hd44780 &lcd){
	char buf[128];
	string input;
	int *amount = new int(-1);
	moveAndClearLine(0,2,lcd);
	printfl("Amount:", lcd);
	moveAndClearLine(0,3,lcd);
	printfl("Prefix + to deposit.", lcd);
	lcd.move(8,2);
	getLine(buf, lcd);
	input = buf;

	if (input.substr(0,1) == "+"){
		input.erase(0,1);
		if ((*amount = atoi(input.c_str())) && (*amount <= maxAmount)){
			entries.find(card)->second.depositCash(*amount);
			moveAndClearLine(0,1,lcd);
			moveAndClearLine(0,2,lcd);
			sprintf(buf, "%ikr deposited.", *amount);
			printfl(buf, lcd);
			moveAndClearLine(0,3,lcd);
			sprintf(buf, "New balance: %ikr", entries.find(card)->second.getCash());
			printfl(buf, lcd);
			printf("\n");
		}else if(buf[1] == '0'){
			moveAndClearLine(0,1,lcd);
			printfl("You used 0.", lcd);
			moveAndClearLine(0,2,lcd);
			printfl("It's not very ", lcd);
			moveAndClearLine(0,3,lcd);
			printfl("effective...", lcd);
		}else{
			moveAndClearLine(0,2,lcd);
			printfl("Invalid input!", lcd);
			moveAndClearLine(0,3,lcd);
			sprintf(buf, "Input int <= %i", maxAmount);
			printfl(buf, lcd);
		}
	}else{
		if ((*amount = abs(atoi(input.c_str()))) && (*amount <= maxAmount)){
			if ((entries.find(card)->second.getCash() - *amount) >= -((entries.find(card)->second.getTab()*maxCredit))){
				entries.find(card)->second.withdrawCash(*amount);
				entries.find(card)->second.increaseSpent(*amount);
				moveAndClearLine(0,1,lcd);
				moveAndClearLine(0,2,lcd);
				sprintf(buf, "%i kr withdrawn.", *amount);
				printfl(buf, lcd);
				moveAndClearLine(0,3,lcd);
				sprintf(buf, "New balance: %i kr", entries.find(card)->second.getCash());
				printfl(buf, lcd);
			}else{
				moveAndClearLine(0,3,lcd);
				moveAndClearLine(0,2,lcd);
				printfl("Not enough money!",lcd);
			}
		}else if (buf[0] == '0'){
			moveAndClearLine(0,1,lcd);
			printfl("You used 0.", lcd);
			moveAndClearLine(0,2,lcd);
			printfl("It's not very ", lcd);
			moveAndClearLine(0,3,lcd);
			printfl("effective...", lcd);	
		}else{
			moveAndClearLine(0,2,lcd);
			printfl("Invalid input!", lcd);
			moveAndClearLine(0,3,lcd);
			sprintf(buf, "Input int <= %i", maxAmount);
			printfl(buf, lcd);
		}
	}
	updateSQL(card, "cash", entries.find(card)->second.getCash(), lcd);
	updateSQL(card, "spent", entries.find(card)->second.getSpent(), lcd);
}
	CInternetSession session(_T("sessionID"));
	CStdioFile* pFile = NULL;
	CHAR szBuff[1024];
	string html;
	string text;
	int start = 0;
	int end = 0;
	int counter = 0;
	//use a URL and print a Web page to the console
	try{
		pFile = session.OpenURL(pszURL);
		while (pFile->Read(szBuff, 1024) > 0)
		{
			//printf_s("%1023s", szBuff);
			html.append(szBuff);
		}
		DeleteUrlCacheEntry(pszURL);
		session.Close();
		delete pFile;

		html.erase(0,html.find("<body>")+830);
		html.erase(remove(html.begin(),html.end(),'\t'),html.end());
		html.erase(remove(html.begin(),html.end(),'\n'),html.end());

		do{
			if (html.find("<br />")!=string::npos){
				html.erase(html.find("<br />"),6);	
			}

		} while (html.find("<br />")!=string::npos);
		//cout << html;
		do{
			html.erase(end,1);
			html.erase(start,1);
			start = html.find(">");
			end = html.find("<");
			if ((end-start) > 1 && html.substr(start+1) != " "){
				if (counter++ >= 10){break;}
				text.append(html.substr(start+1,end-start-1));
				text.append("\n");
			}
		} while (html.find("<")!=string::npos);
		cout << text;
	}catch (CInternetException* pEx){
			//catch errors from WinInet
			TCHAR pszError[64];
			pEx->GetErrorMessage(pszError, 64);
			_tprintf_s(_T("%63s"), pszError);
		}
}*/

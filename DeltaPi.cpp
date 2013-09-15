#include "header.h"

map<const int, Entry> entries;


int main(int argc, char* argv[]){

	hd44780 lcd(14, 15, 24, 25, 8, 7);
   	lcd.init(20, 4);
   	lcd.clear();
	lcd.setAutoscroll(hd44780::HSCROLL_LINE | hd44780::VSCROLL);

	uint8_t blank[8]		= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	lcd.defChar(hd44780::CCHAR2, blank);

	retrieveSQL(entries, lcd);
	entries.erase(0);
	
	int card = 0;
	
	do{
		retrieveSQL(entries, lcd);
		scanCard(entries, card, lcd);
		if (card > 10){
			printInfo(entries, card, lcd);
			transaction(entries, card, lcd);
		} else if (card == 5){
			printTime(lcd);
		} else if (card == 1){
			
		}
	}while (card != -1);
	lcd.clear();
	printfl("  Closing DeltaPi.\n\n      Goodbye!", lcd);
	
	return 0;
}

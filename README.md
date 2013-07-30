DeltaPiBeer
===========

#Dependencies
Rpi-hw 0.4.1<br>
https://github.com/Wicker25/Rpi-hw

Boost 1.49.0<br> 
sudo apt-get install libboost-all-dev

MySQL connector<br>
C++ 1.1.3

#Root access to shared libraries (for MySQL connector)
sudo bash -c "echo /usr/local/lib/ > /etc/ld.so.conf.d/local.conf"<br>
sudo /sbin/ldconfig

#Give file root access without running sudo
sudo chown root ./DeltaPi <br>
sudo chmod 4755 ./DeltaPi

#Startup on boot
$ nano ~/startup.sh

 #!/bin/bash<br>
sleep 5
/etc/local/DeltaPi
sleep 2
shutdown -h now

$ chmod ugo+x startup.sh<br>
$ sudo chown root:your_user_name /sbin/shutdown && sudo chmod 4770 /sbin/shutdown

$ nano ~/.bashrc

 # Run the startup bash script:<br>
echo starting DeltaPi<br>
bash startup.sh

#Autologin

sudo nano /etc/inittab

comment out a line:<br>
"1:2345:respawn:/sbin/ getty 115200 tty1"  => "#1:2345:respawn:/sbin/ getty 115200 tty1"

add:<br>
1:2345:respawn:/bin/login -f pi tty1</dev/tty1>/dev/tty1 2>&1

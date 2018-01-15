# Ethereum price ticker display for Freetronics arduino DMD display
Hardware required for this project:
  1x Arduino Uno (https://store.arduino.cc/usa/arduino-uno-rev3)
  1x Freetronics DMD for Arduino (https://www.freetronics.com.au/products/dot-matrix-display-32x16-red#.Wlr9hiOPBFx)
  
 ## Software required:
  Ruby
  
  Arduino IDE
  
  net/http (Included with Ruby installation)
  
  json (Included with Ruby installation)
  
  serialport gem
  
  cryptocompare gem
  
  Terminal or your choice
  
  
 ## Installation instructions
  Install Arduino IDE if you do not already have it installed: https://www.arduino.cc/en/Main/Software
  
  Install Ruby: https://www.ruby-lang.org/en/documentation/installation/
  
  Install serialport: ```sudo gem install serialport```
  
  Install cryptocompare: ```sudo gem install cryptocompare```
  
  Clone this Repo, and cd into it: ```git clone https://github.com/20jjanssen/Arduino-Dmd-Ethereum-Price.git & cd Arduino-Dmd-Ethereum-Price```
  
  Open up your Arduino IDE and plug in your Arduino uno to a spare USB port on your computer
  
  Upload the DMD.ino file to your Arduino
  
  Open up your favorite text editing program, and change the serial port in the DMD.rb file to whatever port your arduino is on
  
  Run the DMD.rb: ```ruby DMD.rb```
  
  

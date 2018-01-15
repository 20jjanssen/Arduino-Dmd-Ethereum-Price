// dmd-rss.ino
 
#include "SPI.h"      
#include "DMD.h" 
#include "TimerOne.h"
#include "Arial_black_16.h"<arial_black_16.h> 
// you can remove the fonts if unused
#include "SystemFont5x7.h"
 
#define DISPLAYS_ACROSS 1   
#define DISPLAYS_DOWN 1       
/* change these values if you have more than one DMD connected */
DMD dmd(DISPLAYS_ACROSS,DISPLAYS_DOWN);
 
void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}
 
void drawText(String dispString, int scrollspeed) 
{
  dmd.clearScreen( true );
  dmd.selectFont( SystemFont5x7 );
  char newString[256];
  int sLength = dispString.length();
  dispString.toCharArray( newString, sLength+1 );
  dmd.drawMarquee(newString,sLength,( 32*DISPLAYS_ACROSS )-1 , 0 );
  long start=millis();
  long timer=start;
  long timer2=start;
  boolean ret=false;
  while(!ret){
    if ( ( timer+1050-scrollspeed ) < millis() ) {
      ret=dmd.stepMarquee( -1 , 0 );
      timer=millis();
    }
  }
}
 
void setup()
{
    Serial.begin(9600);
   Timer1.initialize( 5000 );           
/*period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.*/
 
   Timer1.attachInterrupt( ScanDMD );  
/*attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()*/
 
   dmd.clearScreen( true );            
/* true is normal (all pixels off), false is negative (all pixels on) */
}
 
void loop() {
   
  String content = "";
  char character;
 
  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
      Serial.println(content);
  }
 
  if (content != "") {
    drawText(content,980);
    delay(1000);
    dmd.clearScreen( true);
    delay(500);
  }
  else {
    delay(500);
    }
     
}

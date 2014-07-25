/*
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Time.h> 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonPin = 10;
int on = 1;
unsigned long time = 0;
unsigned long reset = 0;
  
void setup() {
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 4);
  
}

void printTime() {
  unsigned long diff = time - reset;
  
  unsigned long seconds = diff / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  unsigned long days = hours / 24;
  
  lcd.setCursor(0,0);
  if(hours > 23) {
    lcd.print("Feed Me!      ");
  } else {
    lcd.print("Don't Feed Me!");
  }
  lcd.setCursor(0,2);
  lcd.print("I was fed");
  lcd.setCursor(0,3);
  
  if(days > 0) {
    lcd.print(days);
    lcd.print(" days");
  } else if(hours > 0) {
    lcd.print(hours);
    lcd.print(" hours");
  } else if(minutes > 0) {
    lcd.print(minutes);
    lcd.print(" minutes");
  } else if(seconds > 0) {
    lcd.print(seconds);
    lcd.print(" seconds");
  }
  lcd.print(" ago      ");
  
}

void loop() {
  
  if(on) {
    lcd.display();
  } else {
    lcd.noDisplay();  
  }
  time = millis();
  
  printTime();
  
  if(!digitalRead(buttonPin)) {
    reset = time;
  }
}

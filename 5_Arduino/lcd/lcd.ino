#include <Wire.h>                              // To communicate with I2C.
#include <LiquidCrystal_I2C.h>                 // To control I2C(LCD) displays with functions.

LiquidCrystal_I2C lcd(0x27, 16, 2);            // Set the LCD address to 0x27 for a 16 chars and 2 line display.


void setup()                               // Run the code at the begining of the program for one iteration.
{

  lcd.init();                              // Initialize the LCD.
  lcd.backlight();                         // For the backlight of the LCD.

  lcd.setCursor(0, 0);                                // To print to the LCD.  setCursor(column,row).
  lcd.print("Welcome ");
  lcd.setCursor(7, 1);                                // To print to the LCD.  setCursor(column,row).
  lcd.print("User!");
  delay(90000);                                        // Delay the program by 9 seconds. i.e. Welcome is displayed for 9 seconds.
  //lcd.clear();                                        // To clear the LCD.



}



void loop()                                     // The code is excuted continuosly.
{


}

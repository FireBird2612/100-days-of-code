#include <Arduino.h>
#include <LiquidCrystal_I2C.h>          //library for using 16x2 display

LiquidCrystal_I2C lcd(0x27, 16, 2);     //address, rows, columns

void setup() {
  lcd.init();                           //initialise the I2C_16x2 Display
  lcd.backlight();                      //turn the backlight
  Serial.begin(115200);                   //baudrate for the serial communication
  lcd.setCursor(0, 0);                  //set the cursor to whereever you want to print the characters
  lcd.print("#100DaysOfCode");          //prints the characters to lcd
  Serial.print("\n#100DaysOfCode");       //prints the characters to the serial monitor
}

void loop(){

}
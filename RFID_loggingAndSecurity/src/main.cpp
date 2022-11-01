#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);                //addr, row, columns  

MFRC522 mfrc522(D8, D3);                          // D8=CS, D3=RST on ESP8266

String newCard = "";

void setup() {

  Serial.begin(9600);
  SPI.begin();
  Wire.begin();
  lcd.init();
  mfrc522.PCD_Init();

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("The display is");
  lcd.setCursor(0, 1);
  lcd.print("working!");
}

void loop() {

  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Scan your");
    lcd.setCursor(6, 1);
    lcd.print("ID");
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }

  for (byte i = 0; i < mfrc522.uid.size; i++){
    newCard += mfrc522.uid.uidByte[i];
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(newCard);
  delay(5000);
}
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

constexpr uint8_t pushButton = D0;                  //pushButton pin no.

LiquidCrystal_I2C lcd(0x27, 16, 2);                //addr, row, columns  

MFRC522 mfrc522(D8, D3);                          // D8=CS, D3=RST on ESP8266

MFRC522::MIFARE_Key key;

int blockNum = 1;                                 //refere to datasheet for PICC.
byte blockdata[16] = "Sanket_Gunjal";             //16 bytes since a has 16bytes that could be written to it

byte uidstorage[5][10];
byte counter;

void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  for (byte i = 0; i < 6; i++){
      key.keyByte[i] = 0xFF;
  }

  Serial.print("Oky this is done!");
}


void loop(){

  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }

  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  Serial.print("Success");

  for (counter = 0; counter < 5; counter++)
  {
    Serial.print("Card UID:");

    for (byte j = 0; j < 10; j++){
    uidstorage[counter][j] = mfrc522.uid.uidByte[counter];
    Serial.print("uidstorage[counter][j]");
    delay(100);
    }

    Serial.print("\n");
  }


}

/*
String newCard = "";

int convert = 0;

byte cardstorage[50];
int counter = 0;

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



  if ( ! mfrc522.PICC_IsNewCardPresent())                                         //will check if any tag is presesnt on PCD.
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Scan your");
    lcd.setCursor(6, 1);
    lcd.print("ID");
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()){                                          //this is return true if PICC is readable
    return;
  }

  for (byte i = 0; i < mfrc522.uid.size; i++){
    cardstorage[i] = mfrc522.uid.uidByte[i];
    Serial.print(cardstorage[i]);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  delay(5000);
}
*/
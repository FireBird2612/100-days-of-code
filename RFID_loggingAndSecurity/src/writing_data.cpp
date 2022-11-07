#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define RST_PIN D3
#define SS_PIN D8

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte bufferUIDStore[5];
byte mastercard[5];
char uidStoreRoom[50][5]={ {135, 196, 119, 122, 132},

};
int idNumber = 1;

//variables weed to read the data on PICC
byte block, length;
byte inputSerialBuffer[20];
MFRC522:: StatusCode status;

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	SPI.begin();
	mfrc522.PCD_Init();		// Init MFRC522
}

void loop(){

	MFRC522::MIFARE_Key key;
	for (byte i = 0; i < 6; i++){
		key.keyByte[i] = 0xFF;
	}


	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}
	
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

    Serial.print("Reading ID!\n");
    delay(500);
    Serial.print("ID: ");

    for (int i = 0; i < mfrc522.uid.size; i++){
		bufferUIDStore[i] = mfrc522.uid.uidByte[i];
		Serial.print(bufferUIDStore[i]);
		Serial.print(" ");
	}

	Serial.print("\n");

	Serial.print("Enter your Name!\n");
	Serial.setTimeout(20000);			//User will have 20 seconds for typing their name
	length = Serial.readBytesUntil('#', (char *) inputSerialBuffer, 30);

	for(byte i = length; i < 30; i++){
		inputSerialBuffer[i] = ' ';
		Serial.print(inputSerialBuffer[i]);
	}
}

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "masterUID.h"

#define RST_PIN D3
#define SS_PIN D8
#define pushButton D4

LiquidCrystal_I2C ocd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

MFRC522 _mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

// key to access blocks of sectors
MFRC522::MIFARE_Key _key;

// Function prototype for READING DATA FROM PICC
void readFromBlock1(int Block, byte dataFromBlock[]);
void readFromBlock2(int Block, byte dataFromBlock2[]);
// Function prototype for WRITING DATA TO PICC
void writeDataPICCFN(int block, byte writeBuffer[]);
void writeDataPICCMN(int block, byte writeBuffer[]);

// UID storage variables
byte bufferUIDStore[4];					   // stores the incoming UID
byte mastercard[4] = {135, 196, 119, 122}; // Hardcoded UID of PICC by which one can write data to the new PICC

char uidStoreRoom[50][4]; // Stores all the UIDs read

int idNumber = 1;

// variables needed to read the data on PICC
byte blockNo = 1, length = 18;
byte dataFromBlock1[18];
byte dataFromBlock2[18];

// variable for switch
int swStatus;

MFRC522::StatusCode status;

void setup()
{
	lcd.init(); // lcd initialization
	lcd.backlight();
	lcd.setCursor(1, 0);
	lcd.print("Tinkerers' Lab");
	lcd.setCursor(2, 1);
	lcd.print("ATLS System");
	Serial.print("Tinkerers' Lab ATLS System");
	delay(2000);
	Serial.begin(112500); // Initialize serial communications with the PC
	SPI.begin();
	mfrc522.PCD_Init(); // Init MFRC522

	// the defualt key is fffffffff. you can find this in the datasheet
	for (byte i = 0; i < 6; i++) // key used to accessed every sectors of the PICC
	{
		key.keyByte[i] = 0xFF;
	}
}

void loop()
{
	lcd.clear();
	lcd.setCursor(1, 0);
	lcd.print("Scan your tag");

	// checks for new PICC
	if (!mfrc522.PICC_IsNewCardPresent())
	{
		return;
	}

	// reads the PICC if new card is found.
	if (!mfrc522.PICC_ReadCardSerial())
	{
		return;
	}

	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Reading ID!");
	lcd.setCursor(0, 1);
	lcd.print("ID: ");
	Serial.print("Reading ID!\n");
	Serial.print("ID: ");

	// prints the UID of PICC
	for (int i = 0; i < mfrc522.uid.size; i++)
	{
		bufferUIDStore[i] = mfrc522.uid.uidByte[i];
		lcd.display();
		lcd.print(" ");
		Serial.print(bufferUIDStore[i]);
		Serial.print(" ");
	}

	Serial.print("\n");

	readFromBlock1(blockNo, dataFromBlock1);
	//  print data to the serial monitor
	lcd.clear();
	lcd.setCursor(0, 0);
	Serial.print("Name: ");
	for (int i = 0; i < 16; i++)
	{
		Serial.write(dataFromBlock1[i]);
	}
	Serial.print(" \n");

	// readFromBlock2(blockNo, dataFromBlock2);
	//  print data to the serial monitor
	/*
	for (int i = 0; i < 16; i++)
	{
		Serial.write(dataFromBlock2[i]);
	}
	*/

	delay(1000);
	mfrc522.PICC_HaltA();
	mfrc522.PCD_StopCrypto1();

	swStatus = digitalRead(pushButton);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(">");
	delay(1000);
	Serial.printf("check switch: %d\n", swStatus);

	// checks for master access
	if (swStatus == 0)
	{
		masterUIDAccess(mastercard, swStatus);
		return;
	}
}

// Function that reads data from the block!
void readFromBlock1(int Block, byte dataFromBlock1[])
{
	// autenticate with keyA before proceding with reading data
	status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
	// check status
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print("Authentication Failed!");
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		Serial.println("Authentication Successful!");
	}

	// read data from the block 1
	status = mfrc522.MIFARE_Read(Block, dataFromBlock1, &length);
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print("Read Failed!");
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		Serial.print("Read Success!\n");
	}
}

void readFromBlock2(int Block, byte dataFromBlock2[])
{
	Block = 2;
	// autenticate with keyA before proceding with reading data
	status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
	// check status
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print("Authentication Failed!");
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		Serial.println("Authentication Successful!");
	}

	// read data from the block 2
	status = mfrc522.MIFARE_Read(Block, dataFromBlock2, &length);
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print("Read Failed!");
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		Serial.print("Read Success!");
	}
}

// Write data to the PICC
void writeDataPICCFN(int block, byte writeBuffer[])
{
	int Block = 1;
	// Ask data from serial port
	Serial.setTimeout(20000);
	Serial.println("Enter your first name, ending with #");
	// read bytes until # character
	Serial.readBytesUntil('#', (char *)writeBuffer, 18);
	/*
	Serial.printf("%c", writeBuffer[0]);
	Serial.printf("%c", writeBuffer[1]);
	Serial.printf("%c", writeBuffer[2]);
	Serial.printf("%c", writeBuffer[3]);
	Serial.printf("%c", writeBuffer[4]);
	Serial.printf("%c\n", writeBuffer[5]);
	*/

	// authenticate with KeyA before proceeding to write the data
	status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
	// check status
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print("Authentication Failed!");
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		Serial.print("Authentication Successful!");
	}

	Serial.print("\n");

	// write data to block 1
	status = mfrc522.MIFARE_Write(block, writeBuffer, 16);
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print(F("MIFARE_Write() failed: "));
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
		Serial.println(F("MIFARE_Write() success: "));
}

void writeDataPICCMN(int block, byte writeBuffer[])
{
	int Block = 2;
	// Ask data from serial port
	Serial.setTimeout(20000);
	Serial.println("Enter your Middle name, ending with #");
	// read bytes until # character
	Serial.readBytesUntil('#', (char *)writeBuffer, 18);
	/*
	Serial.printf("%c", writeBuffer[0]);
	Serial.printf("%c", writeBuffer[1]);
	Serial.printf("%c", writeBuffer[2]);
	Serial.printf("%c", writeBuffer[3]);
	Serial.printf("%c", writeBuffer[4]);
	Serial.printf("%c\n", writeBuffer[5]);
	*/

	// authenticate with KeyA before proceeding to write the data
	status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
	// check status
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print("Authentication Failed!");
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		Serial.print("Authentication Successful!");
	}

	Serial.print("\n");

	// write data to block 1
	status = mfrc522.MIFARE_Write(block, writeBuffer, 16);
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print(F("MIFARE_Write() failed: "));
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
		Serial.println(F("MIFARE_Write() success: "));
}
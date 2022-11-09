
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define RST_PIN D3
#define SS_PIN D8

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

MFRC522::MIFARE_Key key;

void readFromBlock1(int Block, byte dataFromBlock[]);
void readFromBlock2(byte dataFromBlock2[]);
void writeDataPICC(int block, byte writeBuffer[]);

byte bufferUIDStore[4];
byte mastercard[4];
char uidStoreRoom[50][4] = {
	{135, 196, 119, 122},
};
int idNumber = 1;

// variables weed to read the data on PICC
byte blockNo = 1, length = 18;
byte dataFromBlock1[18];
byte dataFromBlock2[18];

// variable to write data to PICC
byte datatoblock1[18];
byte datatoblock2[18];

MFRC522::StatusCode status;

void setup()
{
	Serial.begin(112500); // Initialize serial communications with the PC
	SPI.begin();
	mfrc522.PCD_Init(); // Init MFRC522

	for (byte i = 0; i < 6; i++)
	{
		key.keyByte[i] = 0xFF;
	}
}

void loop()
{

	if (!mfrc522.PICC_IsNewCardPresent())
	{
		return;
	}

	if (!mfrc522.PICC_ReadCardSerial())
	{
		return;
	}

	Serial.print("Reading ID!\n");
	delay(500);
	Serial.print("ID: ");

	for (int i = 0; i < mfrc522.uid.size; i++)
	{
		bufferUIDStore[i] = mfrc522.uid.uidByte[i];
		Serial.print(bufferUIDStore[i]);
		Serial.print(" ");
	}

	Serial.print("\n");

	writeDataPICC(blockNo, dataFromBlock1);

	readFromBlock1(blockNo, dataFromBlock1);
	// print data to the serial monitor
	Serial.print("Name: ");
	for (int i = 0; i < 16; i++)
	{
		Serial.write(dataFromBlock1[i]);
	}
	Serial.print(" ");

	readFromBlock2(dataFromBlock2);
	// print data to the serial monitor
	for (int i = 0; i < 16; i++)
	{
		Serial.write(dataFromBlock2[i]);
	}
	Serial.print("");
	mfrc522.PICC_HaltA();
	mfrc522.PCD_StopCrypto1();
}

// Function that reads data from the block!
void readFromBlock1(int Block, byte dataFromBlock1[])
{
	// autenticate with keyA before proceding with reading data
	status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
	// check status
	if (status != MFRC522::STATUS_OK)
	{
		// Serial.print("Authentication Failed!");
		// Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		// Serial.println("Authentication Successful!");
	}

	// read data from the block 1
	status = mfrc522.MIFARE_Read(Block, dataFromBlock1, &length);
	if (status != MFRC522::STATUS_OK)
	{
		// Serial.print("Read Failed!");
		// Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		// Serial.print("Read Success!");
	}
}

void readFromBlock2(byte dataFromBlock2[])
{
	int Block = 4;
	// autenticate with keyA before proceding with reading data
	status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
	// check status
	if (status != MFRC522::STATUS_OK)
	{
		// Serial.print("Authentication Failed!");
		// Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		// Serial.println("Authentication Successful!");
	}

	// read data from the block 2
	status = mfrc522.MIFARE_Read(Block, dataFromBlock2, &length);
	if (status != MFRC522::STATUS_OK)
	{
		// Serial.print("Read Failed!");
		// Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
	{
		// Serial.print("Read Success!");
	}
}

// Write data to the PICC
void writeDataPICC(int block, byte writeBuffer[])
{
	int Block = 1;
	// Ask data from serial port
	Serial.setTimeout(20000);
	Serial.println("Enter your first name, ending with #");
	// read bytes until # character
	length = Serial.readBytesUntil('#', (char *)writeBuffer, 30);

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

	// write data to block 1
	status = mfrc522.MIFARE_Write(block, writeBuffer, length);
	if (status != MFRC522::STATUS_OK)
	{
		Serial.print(F("MIFARE_Write() failed: "));
		Serial.println(mfrc522.GetStatusCodeName(status));
		return;
	}
	else
		Serial.println(F("MIFARE_Write() success: "));
}
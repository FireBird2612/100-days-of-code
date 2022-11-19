#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

//variables for LED and reedSwitch
#define reedSwitch D2

//boolean variable to detect the state of the door
bool doorChangeStatus = false;

//variables for holing the reedSwitch state
bool state;
String doorState;

//a delay time of 1500ms from the door change state to get back again into the reading state
unsigned long previousMillis = 0;
const long interval = 1500;

//variables to store the credentials of the newtwork
const char *ssid = "Sanket";
const char *password = "Gunjal@8378";

//initialize Telegram Bot
#define BOTtoken "5927307714:AAHkhn3-qBdTkKbO0l7ojIPcJsXtjxXzI9M"

//The chatID of the bot
#define chatID "5183041842"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

unsigned long currentMillis;

//runs whenever the reedswitch changes state
ICACHE_RAM_ATTR void changeDoorStatus(){
  Serial.println("State changed\n");
  doorChangeStatus = true;
}


void setup(){
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org");       //get UTC time via NTP
  client.setTrustAnchors(&cert);          //add root certificate for api.telgram.org

  //Read the cuuurent door state
  pinMode(reedSwitch, INPUT_PULLUP);
  state = digitalRead(reedSwitch);

  // set LED state to match door sate
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, state);

  // Set the reedswitch pin as interrupt, assign interrupt function and set CHANGE mode
  attachInterrupt(digitalPinToInterrupt(reedSwitch), changeDoorStatus, CHANGE);

  //connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
    Serial.print("");
    Serial.print("WiFi Connected!");

    bot.sendMessage(chatID, "Bot started up", "");
}

void loop(){
  if (doorChangeStatus){
    currentMillis = millis();
    if(currentMillis - previousMillis >= interval){
      previousMillis = currentMillis;
      //If a state has occured, invert the current door stae
      state = !state;
      if (state){
        doorState = "closed";
      }
      else{
        doorState = "Open";
      }
      digitalWrite(LED_BUILTIN, state);
      doorChangeStatus = false;
      Serial.println(state);
      Serial.println(doorState);

      //send notification
      bot.sendMessage(chatID, "The door is " + doorState, "");
    }
  }
}
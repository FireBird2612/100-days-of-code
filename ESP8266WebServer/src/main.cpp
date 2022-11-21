#include <Arduino.h>
#include <ESP8266WiFi.h>

//WiFi Credentials
#define SSID "Sanket"
#define PASS "Gunjal@8378"

//WebServer Port Number
WiFiServer server(80);

//variable that will store http request
String header;

//output variables to GPIO pins
String rgbPinState = "off";

// RGB LED connection to ESP8266 on pin number 4
const int rgbPin = 4;

void setup() {
  pinMode(rgbPin, OUTPUT);
  digitalWrite(rgbPin, LOW);
  Serial.begin(112500);

  // Lets connect to the WiFi Network
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("WiFi Connection Established!\n");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();           // keep listening for the incoming clients

  if (client){                                      // If a new client is connected
    Serial.print("New Client!");
    String currentline = "";                        // The string will hold the incoming data from the client

    while (client.connected()){                      // loop while the client is connected
      if (client.available()){
        char c = client.read();
        Serial.write(c);
        header += c;

        if ( c == '\n'){                            // If the byte is a newline character
          if(currentline.length() == 0){
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: Close");
            client.println();

            //turn the LED on and off
            if (header.indexOf("GET /5/on") >= 0){
              Serial.println("The RGB LED is ON");
              rgbPinState = "on";
              digitalWrite(rgbPin, HIGH);
            }
            else if (header.indexOf("GET /5/off") >= 0){
              Serial.println("The RGB LED is OFF");
              rgbPinState = "off";
              digitalWrite(rgbPin, LOW);
            }

            //Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Merriweather; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #0083EB; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #EB0201;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>LED CONTROL</h1>");
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>GPIO 5 - State " + rgbPinState + "</p>");
            // If the output5State is off, it displays the ON button       
            if (rgbPinState == "off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } 
            else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            //break out of while loop
            break;
          }
          else {                                                                    // If you got a newline, then clear cuttentLine
            currentline = "";
          }
        }
        else if (c != '\r') {                                                       // If you got anything else but a carriage
          currentline += c;                                                         // Add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    //close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println();
  }
}
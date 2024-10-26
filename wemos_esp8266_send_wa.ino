#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "base64.h"

// Setup WiFi network
const char* ssid = "Pppp";
const char* password = "Akustress";

// read sensor
const int sensorPin = A0;
int speakerPin = D5;
int state = 0;

// Twilio Parameter
String account_sid = "ACc35db4046a778ed970310973db39b9cf";
String auth_token = "33c34b99d078a8548f1a0174db8f4603";
String from = "+14155238886";
String to = "+6285851118001";
String body = "Ada sesuatu didekat jendela rumah mu!";

void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  
  pinMode(sensorPin,INPUT);
  pinMode(speakerPin, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to WiFi");
 
}
 
void loop() {

  state = analogRead(sensorPin);
//  Serial.println(state);
  if(state < 500) {
      
      if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
     
        HTTPClient http;
     
        int nilai = random(29,37);
        String data = (String) nilai;
//        String link = "https://github.com/Nikee892/esp-whatsapp-pythonanywhere" + state;
        String link = "http://Nikee892.pythonanywhere.com/kirimwa?account_sid=" + ACc35db4046a778ed970310973db39b9cf + "&33c34b99d078a8548f1a0174db8f4603="+ 33c34b99d078a8548f1a0174db8f4603 +"&+6285851118001=" + to + "&+14155238886="+ from +"&Ada sesuatu didekat jendela rumah mu!=" + body;
        
        http.begin(link);
        int httpCode = http.GET();
        Serial.println(httpCode);
        
        if (httpCode > 0) { //Check for the returning code
            
            String payload = http.getString();
            Serial.println(link);
            Serial.println(httpCode);
            Serial.println(payload);
        }
        else {
            Serial.println("Error on HTTP request");
        }
        http.end();
      }
      digitalWrite(speakerPin, HIGH);
      delay(3000);
      digitalWrite(speakerPin, LOW);
      delay(1000);
  }
  delay(200);
 
}

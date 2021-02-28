#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "";
const char* password = "";
int ifLaunch=0 ;

 
void setup () {

  
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  pinMode(4, INPUT_PULLUP);

 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
    
 
  }

}
 
void loop() {
    if(Serial.available()>0){
     ifLaunch=Serial.read();
    }
   int pinVal=digitalRead(4);
   delay(10);
   
   
   if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
    if (pinVal==LOW)/*(ifLaunch=='3')*/{
   http.begin("https://url","fingerprint"); 
   
    int httpCode = http.GET(); //Send the request
    auto httpCode2 = http.POST("output");
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   
      Serial.println(payload);             
    }
 
    http.end();   //Close connection
    ifLaunch=0;
 
  }
   }
 
}

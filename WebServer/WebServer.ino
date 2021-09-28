

#include <EEPROM.h>
#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const char *ssid = "Nathivo's House";
const char *password = "baileys123";
String btnLiga = "Ligar";
String btnDesliga = "Desligado";
String status_input1;
String status_input2;
ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600); 
  delay(10);
  SPIFFS.begin();
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);
  delay(500); 
  Serial.print("Conectando.");
  while(WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado no ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(16, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  server.on("/",pgIndex);
  server.on("/style.css",style_css);
  server.on("/status",statuis);
  server.on("/liga_desliga",liga_desliga);
  server.begin();
}

void loop() {
  server.handleClient();
}

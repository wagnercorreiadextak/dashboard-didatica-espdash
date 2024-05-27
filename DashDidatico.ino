/*
  -----------------------
  ESPDASH - Basic Example
  -----------------------

  Skill Level: Intermediate

  In this example we will be creating a basic dashboard which consists 
  of some cards and then update them in realtime ( at 3s interval ).

  Github: https://github.com/ayushsharma82/ESP-DASH
  WiKi: https://ayushsharma82.github.io/ESP-DASH/

  Works with both ESP8266 & ESP32
*/

#include <Arduino.h>
#if defined(ESP8266)
  /* ESP8266 Dependencies */
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
  #include <ESPAsyncWebServer.h>
#elif defined(ESP32)
  /* ESP32 Dependencies */
  #include <WiFi.h>
  #include <AsyncTCP.h>
  #include <ESPAsyncWebServer.h>
#endif
#include <ESPDash.h>

/* Inclusões próprias */
#include "Configuracao.h"
#include "Rele.h"
#include "Mqtt.h"
#include "SensorTemperatura.h"
#include "StatusSensores.h"
#include "DisplayOled.h"
#include "Tarefas.h"

void iniciarWifi() {
  /* Connect WiFi */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  } else {
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    enderecoIp = WiFi.localIP();
  }

}

void webServerTask() {
  /* Start AsyncWebServer */
  server.begin();
}

void setup() {

  Serial.begin(115200);
  configurarPortas();

  //Mostra no monitor em qual core o setup() foi chamado
  Serial.println(xPortGetCoreID());

  iniciarWifi();
  webServerTask();
  iniciarMqtt();
  
  callBackBotoesRele();

  iniciarDisplay();

  agendarTarefas();

  delay(100);
  
}

void loop() {
  
}
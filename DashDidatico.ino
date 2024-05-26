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

void callBackBotoes() {
  /* Button card callback */
  cardRele1.attachCallback([&](int value){
    Serial.println("Button Callback Triggered: "+String((value == 1)?"true":"false"));
    /* Button card updater - you need to update the button with latest value upon firing of callback */
    cardRele1.update(value);
    /* Send update to dashboard */
    dashboard.sendUpdates();
  });
}

void setup() {
  Serial.begin(115200);

  /* Connect WiFi */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.printf("WiFi Failed!\n");
      return;
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  /* Start AsyncWebServer */
  server.begin();

  callBackBotoes();
}

void loop() {
  /* Update Card Values */
  card1Mqtt.update("Publicando", "s");
  cardTemperatura.update((int)random(0, 50));
  cardIntensidadeLuz.update((int)random(0, 100));

  /* Send Updates to our Dashboard (realtime) */
  dashboard.sendUpdates();

  /* 
    Delay is just for demonstration purposes in this example,
    Replace this code with 'millis interval' in your final project.
  */
  delay(3000);
}
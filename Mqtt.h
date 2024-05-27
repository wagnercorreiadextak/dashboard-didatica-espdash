#include <PubSubClient.h>
#include "ArduinoJson.h"

const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClientWi;
PubSubClient clientMqtt(espClientWi);

const char* idMqtt = "espdash-automacao-000001";

const char* topicoRele = "espdash/automacao/rele";
const char* topicoSensor = "espdash/automacao/sensor";

void ouvirMqtt(char* topic, byte* message, unsigned int length) {

  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  JsonDocument parsed;
  deserializeJson(parsed, messageTemp);

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message

  if (true) { //Check for errors in parsing

    if (String(topic) == topicoRele) {

      int rele = parsed["rele"];
      int status = parsed["status"];

      alternarRele(rele, status);
    }

  } else {
    Serial.println("Falha ao ler mensagem MQTT");
  }
}

void reconnectMqtt() {
  // Loop until we're reconnected
  if (!clientMqtt.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (clientMqtt.connect("idMqtt")) {
      Serial.println("connected");
      // Subscribe
      clientMqtt.subscribe(topicoRele);
    } else {
      Serial.print("failed, rc=");
      Serial.print(clientMqtt.state());
      Serial.println(" try again in 5 seconds");
    }
  } else {
    digitalWrite(portaLedVemelho, LOW);
  }
}

void iniciarMqtt() {
  clientMqtt.setServer(mqtt_server, 1883);
  clientMqtt.setCallback(ouvirMqtt);
}
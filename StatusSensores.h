int vlrLuz = 0;

void publicarTeperatura() {
  cardTemperatura.update(vlrTemperatura);
  dashboard.sendUpdates();
  
  JsonDocument doc;
  doc["sensor"] = "temperatura";
  doc["valor"] = vlrTemperatura;

  char json[300];
  serializeJson(doc, json);
  
  clientMqtt.publish(topicoSensor, json);
}

void publicarLuz() {
  vlrLuz = random(0, 100);

  cardIntensidadeLuz.update(vlrLuz);
  dashboard.sendUpdates();

  JsonDocument doc;
  doc["sensor"] = "luz";
  doc["valor"] = vlrLuz;

  char json[300];
  serializeJson(doc, json);

  clientMqtt.publish(topicoSensor, json);
}
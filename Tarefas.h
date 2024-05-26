void monitorarWifi(void * parameter) {
  for(;;) {
      
      if(WiFi.status() != WL_CONNECTED) {
        digitalWrite(portaLedAzul, LOW);
      } else {
        digitalWrite(portaLedAzul, HIGH);
      }
      
      vTaskDelay(3000);
  }
}

void teste(void * parameter) {
  Serial.println("Hoy");
  vTaskDelete(NULL);
}

void reconnectMqttTask(void * parameter) {
  for(;;) {
    if(WiFi.status() == WL_CONNECTED) {
      reconnectMqtt();
      clientMqtt.loop();
    }

    vTaskDelay(500);
  }
}

void agendarTarefas() {

  xTaskCreate(
    teste,    // Função a ser chamada
    "callBackBotoes",   // Nome da tarefa
    1000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    1,               // Prioridade da Tarefa
    NULL             // Task handle
  );

  xTaskCreate(
    monitorarWifi,    // Função a ser chamada
    "monitorarWifi",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    1,               // Prioridade da Tarefa
    NULL             // Task handle
  );

  xTaskCreate(
    reconnectMqttTask,    // Função a ser chamada
    "reconnectMqttTask",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    1,               // Prioridade da Tarefa
    NULL             // Task handle
  );

}
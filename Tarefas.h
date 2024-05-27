void monitorarWifi(void * parameter) {
  for(;;) {
      
      if(WiFi.status() != WL_CONNECTED) {
        digitalWrite(portaLedAzul, LOW);
        digitalWrite(portaLedVemelho, LOW);
      } else {
        digitalWrite(portaLedAzul, HIGH);
        digitalWrite(portaLedVemelho, HIGH);
      }
      
      vTaskDelay(3000);
  }
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

void publicarStatusSensores(void * parameter) {
  for(;;) {
    if (clientMqtt.connected()) {
      digitalWrite(portaLedAmarelo, HIGH);

      publicarTeperatura();

      vTaskDelay(1000);
      digitalWrite(portaLedAmarelo, LOW);
      digitalWrite(portaLedVerde, HIGH);

      publicarLuz();

      vTaskDelay(1000);
      digitalWrite(portaLedVerde, LOW);
    }
    vTaskDelay(4000);
  }
}

void coletarDadosTask(void * parameter) {
  for(;;) {
    coletarTemperatura();
    vTaskDelay(500);
  }
}

void atualizarDisplay(void * parameter) {
  for(;;) {
    setInformacoesDisplay();
    vTaskDelay(1000);
  }
}

void agendarTarefas() {

  xTaskCreate(
    monitorarWifi,    // Função a ser chamada
    "monitorarWifi",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    10,               // Prioridade da Tarefa
    NULL             // Task handle
  );

  xTaskCreate(
    reconnectMqttTask,    // Função a ser chamada
    "reconnectMqttTask",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    9,               // Prioridade da Tarefa
    NULL             // Task handle
  );

  xTaskCreate(
    publicarStatusSensores,    // Função a ser chamada
    "publicarStatusSensores",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    8,               // Prioridade da Tarefa
    NULL             // Task handle
  );

  xTaskCreate(
    coletarDadosTask,    // Função a ser chamada
    "coletarDadosTask",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    8,               // Prioridade da Tarefa
    NULL             // Task handle
  );

  xTaskCreate(
    atualizarDisplay,    // Função a ser chamada
    "atualizarDisplay",   // Nome da tarefa
    3000,            // Tamanho (bytes)
    NULL,            // Parametro a ser passado
    8,               // Prioridade da Tarefa
    NULL             // Task handle
  );

}
/* Wifi */
const char* ssid = "wagner_rede";
const char* password = "73ax9192";

/* WebServer */
AsyncWebServer server(80);
ESPDash dashboard(&server); 

/*Cards*/
Card card1Mqtt(&dashboard, STATUS_CARD, "Publicação MQTT", "i");
Card cardTemperatura(&dashboard, TEMPERATURE_CARD, "Temperatura", "°C");
Card cardIntensidadeLuz(&dashboard, GENERIC_CARD, "Intensidade de luz");

Card cardRele1(&dashboard, BUTTON_CARD, "Rele 1");
Card cardRele2(&dashboard, BUTTON_CARD, "Rele 2");
Card cardRele3(&dashboard, BUTTON_CARD, "Rele 3");
Card cardRele4(&dashboard, BUTTON_CARD, "Rele 4");
Card cardRele5(&dashboard, BUTTON_CARD, "Rele 5");
Card cardRele6(&dashboard, BUTTON_CARD, "Rele 6");
Card cardRele7(&dashboard, BUTTON_CARD, "Rele 7");
Card cardRele8(&dashboard, BUTTON_CARD, "Rele 8");

/* Configuração de portas */
int portasRele[8] = {12, 13, 14, 15, 16, 17, 18, 19};
int portaSensorTemperatura = 26;
int portaSensorLuz = 25;
int portaBuzzer = 27;

void configurarPortas() {

  //Configura as portas de rele
  for(int i = 0 ; i < 8; i++) {
    pinMode(portasRele[i], OUTPUT);
  }

  //Configura a porta do sensor de luz
  pinMode(portaSensorLuz, INPUT);

  //Porta buzzer
  pinMode(portaBuzzer, OUTPUT);

}
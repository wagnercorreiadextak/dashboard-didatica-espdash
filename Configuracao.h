/* Wifi */
const char* ssid = "wagner-nokia";
const char* password = "13041968";

/* WebServer */
AsyncWebServer server(80);
ESPDash dashboard(&server); 

/*Cards*/
Card card1Mqtt(&dashboard, STATUS_CARD, "Publicação MQTT", "i");
Card cardTemperatura(&dashboard, TEMPERATURE_CARD, "Temperatura", "°C");
Card cardIntensidadeLuz(&dashboard, GENERIC_CARD, "Intensidade de luz");

Card cardRele0(&dashboard, BUTTON_CARD, "Rele 1");
Card cardRele1(&dashboard, BUTTON_CARD, "Rele 2");
Card cardRele2(&dashboard, BUTTON_CARD, "Rele 3");
Card cardRele3(&dashboard, BUTTON_CARD, "Rele 4");
Card cardRele4(&dashboard, BUTTON_CARD, "Rele 5");
Card cardRele5(&dashboard, BUTTON_CARD, "Rele 6");
Card cardRele6(&dashboard, BUTTON_CARD, "Rele 7");
Card cardRele7(&dashboard, BUTTON_CARD, "Rele 8");

/* Configuração de portas */
int portasRele[8] = {12, 13, 14, 15, 16, 17, 18, 19};

int portaSensorLuz = 27;
int portaSensorTemperatura = 26;
int portaBuzzer = 25;

int portaBtnVemelho = 39;
int portaLedVemelho = 23;

int portaBtnAmarelo = 36;
int portaLedAmarelo = 5;

int portaBtnVerde = 35;
int portaLedVerde = 4;

int portaBtnAzul = 34;
int portaLedAzul = 2;

IPAddress enderecoIp;

void configurarPortas() {

  //Configura as portas de rele
  for(int i = 0 ; i < 8; i++) {
    pinMode(portasRele[i], OUTPUT);
  }

  //Configura a porta do sensor de luz
  pinMode(portaSensorLuz, INPUT);

  //Porta buzzer
  pinMode(portaBuzzer, OUTPUT);

  //Botão vermelho
  pinMode(portaBtnVemelho, INPUT_PULLUP);
  pinMode(portaLedVemelho, OUTPUT);

  //Botão amarelo
  pinMode(portaBtnAmarelo, INPUT_PULLUP);
  pinMode(portaLedAmarelo, OUTPUT);

  //Botão verde
  pinMode(portaBtnVerde, INPUT_PULLUP);
  pinMode(portaLedVerde, OUTPUT);

  //Botão azul
  pinMode(portaBtnAzul, INPUT_PULLUP);
  pinMode(portaLedAzul, OUTPUT);

}
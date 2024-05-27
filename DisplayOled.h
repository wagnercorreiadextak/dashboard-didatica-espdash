#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setInformacoesDisplay() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1, 10);

  // Display static text
  display.print("IP: ");
  display.println(enderecoIp);

  display.setCursor(1, 33);
  display.print("Temperatura: ");
  display.println(vlrTemperatura);

  display.setCursor(1, 54);
  display.print("Luminosidade: ");
  display.println(vlrLuz);

  display.display(); 
}

void iniciarDisplay() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("DISPLAY SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, WHITE);

  display.display();
}
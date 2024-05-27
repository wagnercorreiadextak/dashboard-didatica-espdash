#include <OneWire.h>
#include <DallasTemperature.h>

float vlrTemperatura = 0;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(portaSensorTemperatura);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void coletarTemperatura() {
  sensors.requestTemperatures(); 
  vlrTemperatura = sensors.getTempCByIndex(0);
}
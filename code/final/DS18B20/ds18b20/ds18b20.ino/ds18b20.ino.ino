#include <OneWire.h>
#include <DallasTemperature.h>

// Broche de données de la sonde DS18B20
const int oneWireBus = 2;  // Définir la broche où la sonde est connectée

// Initialise l'objet OneWire et DallasTemperature
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  // Démarre la communication série
  Serial.begin(9600);
  
  // Initialise le capteur DS18B20
  sensors.begin();
}

void loop() {
  // Appelle la fonction pour lire la température
  float temperature = getTemperature();
  
  // Affiche la température sur le moniteur série
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  // Attends 1 seconde avant la prochaine lecture
  delay(1000);
}

float getTemperature() {
  // Appelle la méthode requestTemperatures() pour obtenir la température
  sensors.requestTemperatures();
  
  // Lit la température en degrés Celsius
  float tempC = sensors.getTempCByIndex(0);
  
  // Retourne la température en degrés Celsius
  return tempC;
}


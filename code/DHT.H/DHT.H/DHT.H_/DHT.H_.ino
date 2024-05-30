#include <DHT.h>
#include <Wire.h>

#define DHTPIN 2       // Connectez le capteur DHT à la broche D2 du Grove Mega Shield
#define DHTTYPE DHT22  // Type de capteur DHT (DHT11 ou DHT22, selon le capteur utilisé)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Capteur DHT test !");
  dht.begin();
}

void loop() {
  // Attendre quelques secondes entre chaque lecture
  delay(2000);

  // Lecture de l'humidité relative
  float h = dht.readHumidity();
  // Lecture de la température en degrés Celsius
  float t = dht.readTemperature();

  // Vérifier si la lecture a échoué
  if (isnan(h) || isnan(t)) {
    Serial.println("Echec de la lecture du capteur DHT !");
    return;
  }

  // Affichage des valeurs lues sur le moniteur série
  Serial.print("Humidité : ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Température : ");
  Serial.print(t);
  Serial.println(" °C");
}


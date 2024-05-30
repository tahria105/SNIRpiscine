‌#include <DHT.h>

#define DHTPIN 2     // Broche de données du capteur DHT22
#define DHTTYPE DHT22   // Type de capteur DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Capteur DHT22 test!");

  dht.begin();
}

void loop() {
  delay(2000);  // Attendre 2 secondes entre chaque lecture

  float temp = dht.readTemperature(); // Lecture de la température en degrés Celsius
  float hum = dht.readHumidity();     // Lecture de l'humidité relative

  // Vérification si la lecture est réussie
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Échec de lecture du capteur DHT22!");
    return;
  }

  // Affichage des valeurs de température et d'humidité
  Serial.print("Température: ");
  Serial.print(temp);
  Serial.print(" °C\t");
  Serial.print("Humidité: ");
  Serial.print(hum);
  Serial.println(" %");
}

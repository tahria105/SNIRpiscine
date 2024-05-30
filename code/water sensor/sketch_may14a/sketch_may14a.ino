#include <Wire.h> // Bibliothèque pour la communication I2C

#define WATER_SENSOR_ADDR 0x0 // Adresse du capteur d'eau (peut varier selon le modèle)

void setup() {
  Serial.begin(9600); // Initialisation de la communication série
  Wire.begin();        // Initialisation de la communication I2C
}

void loop() {
  int waterLevel = readWaterLevel(); // Lecture du niveau d'eau

  Serial.print("Niveau d'eau (en cm) : ");
  Serial.println(waterLevel);

  delay(1000); // Attendre 1 seconde entre chaque lecture
}

int readWaterLevel() {
  Wire.beginTransmission(WATER_SENSOR_ADDR); // Début de la transmission vers le capteur
  Wire.requestFrom(WATER_SENSOR_ADDR, 2);    // Demande de lecture de 2 octets depuis le capteur

  int waterLevel = 0;
  if (Wire.available() >= 2) {
    byte highByte = Wire.read();   // Lecture du byte de poids fort
    byte lowByte = Wire.read();    // Lecture du byte de poids faible
    waterLevel = highByte << 8 | lowByte; // Concaténation des deux bytes pour obtenir la valeur complète
  }

  Wire.endTransmission(); // Fin de la transmission

  return waterLevel;
}


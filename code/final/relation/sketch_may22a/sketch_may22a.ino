#include <Wire.h>

void setup() {
  Wire.begin(); // Initialise en tant que maître
  Serial.begin(9600); // Initialise la communication série pour le débogage
}

void loop() {
  Wire.beginTransmission(8); // Commence la transmission à l'adresse 8 (celle du Raspberry Pi)
  Wire.write("Hello from Arduino"); // Envoie des données
  Wire.endTransmission(); // Termine la transmission
  delay(1000); // Attente d'une seconde
}

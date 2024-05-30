#include <Arduino.h>

#define RELAY_PIN_1 1
#define RELAY_PIN_2 2
#define RELAY_PIN_3 3
#define RELAY_PIN_4 4
#define RELAY_PIN_5 5
#define RELAY_PIN_6 6
#define RELAY_PIN_7 7
#define RELAY_PIN_8 8

void setup() {
  Serial.begin(9600); // Démarre la communication série à 9600 bauds
  Serial.println("Initialisation...");

  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(RELAY_PIN_4, OUTPUT);
  pinMode(RELAY_PIN_5, OUTPUT);
  pinMode(RELAY_PIN_6, OUTPUT);
  pinMode(RELAY_PIN_7, OUTPUT);
  pinMode(RELAY_PIN_8, OUTPUT);
  
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);
  digitalWrite(RELAY_PIN_4, HIGH);
  digitalWrite(RELAY_PIN_5, HIGH);
  digitalWrite(RELAY_PIN_6, HIGH);
  digitalWrite(RELAY_PIN_7, HIGH);
  digitalWrite(RELAY_PIN_8, HIGH);

  Serial.println("Initialisation terminée.");
}

void loop() {
  Serial.println("Activation des relais...");

  digitalWrite(RELAY_PIN_1, LOW);
  Serial.println("Relais 1 activé");
  delay(150);
  digitalWrite(RELAY_PIN_1, HIGH);
  Serial.println("Relais 1 désactivé");

  digitalWrite(RELAY_PIN_2, LOW);
  Serial.println("Relais 2 activé");
  delay(150);
  digitalWrite(RELAY_PIN_2, HIGH);
  Serial.println("Relais 2 désactivé");

  digitalWrite(RELAY_PIN_3, LOW);
  Serial.println("Relais 3 activé");
  delay(150);
  digitalWrite(RELAY_PIN_3, HIGH);
  Serial.println("Relais 3 désactivé");

  digitalWrite(RELAY_PIN_4, LOW);
  Serial.println("Relais 4 activé");
  delay(150);
  digitalWrite(RELAY_PIN_4, HIGH);
  Serial.println("Relais 4 désactivé");

  digitalWrite(RELAY_PIN_5, LOW);
  Serial.println("Relais 5 activé");
  delay(150);
  digitalWrite(RELAY_PIN_5, HIGH);
  Serial.println("Relais 5 désactivé");

  digitalWrite(RELAY_PIN_6, LOW);
  Serial.println("Relais 6 activé");
  delay(150);
  digitalWrite(RELAY_PIN_6, HIGH);
  Serial.println("Relais 6 désactivé");

  digitalWrite(RELAY_PIN_7, LOW);
  Serial.println("Relais 7 activé");
  delay(150);
  digitalWrite(RELAY_PIN_7, HIGH);
  Serial.println("Relais 7 désactivé");

  digitalWrite(RELAY_PIN_8, LOW);
  Serial.println("Relais 8 activé");
  delay(150);
  digitalWrite(RELAY_PIN_8, HIGH);
  Serial.println("Relais 8 désactivé");

  delay(1000); // Délai supplémentaire entre les cycles de la boucle
}


#include <CapacitiveSensor.h>

#define NUM_SENSORS 12 // Nombre de capteurs capacitifs
#define THRESHOLD 50   // Seuil de détection, à ajuster selon votre configuration

// Broches des capteurs capacitifs
const int sensorPins[NUM_SENSORS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// Correspondance entre les touches et les index des capteurs
const char keys[NUM_SENSORS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#'};

// Utilisation de la broche RX0 (pin 0) pour la réception des données série
#define RX_PIN 0

// Déclaration des capteurs capacitifs avec les broches correspondantes
CapacitiveSensor sensors[NUM_SENSORS] = {
  CapacitiveSensor(RX_PIN, RX_PIN), // Configuration arbitraire pour RX et TX, car nous n'utilisons pas la transmission série
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN),
  CapacitiveSensor(RX_PIN, RX_PIN)
};

void setup() {
  Serial.begin(9600);
  // Initialisation des capteurs capacitifs
  for (int i = 0; i < NUM_SENSORS; i++) {
    sensors[i].set_CS_AutocaL_Millis(0xFFFFFFFF); // Désactivation de l'autocalibration
    sensors[i].set_CS_Timeout_Millis(100);       // Temps d'attente avant de considérer un toucher
    sensors[i].capacitiveSensorRaw(30);          // Niveau de sensibilité
  }
}

void loop() {
  // Lecture de l'état des capteurs capacitifs
  for (int i = 0; i < NUM_SENSORS; i++) {
    long sensorValue = sensors[i].capacitiveSensor(30);
    if (sensorValue > THRESHOLD) {
      Serial.println(keys[i]); // Affichage de la touche détectée
    }
  }
  delay(100); // Délai pour éviter une boucle trop rapide
}




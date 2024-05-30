#include <Arduino.h>

void setup() {
  Serial.begin(9600); // Initialiser la communication série pour le moniteur série
  Serial1.begin(9600); // Initialiser la communication série sur Serial1 (RX1 et TX1) à 9600 bauds
  Serial.println("Version:v1.0");
}

void loop() {
  printData();
}

void printData() {
  while(Serial1.available()) {
    uint8_t data = Serial1.read();
    switch(data) {
      case 0xE1 :
        Serial.println("1");
        break;
      case 0xE2 :
        Serial.println("2");
        break;
      case 0xE3 :
        Serial.println("3");
        break;
      case 0xE4 :
        Serial.println("4");
        break;
      case 0xE5 :
        Serial.println("5");
        break;
      case 0xE6 :
        Serial.println("6");
        break;
      case 0xE7 :
        Serial.println("7");
        break;
      case 0xE8 :
        Serial.println("8");
        break;
      case 0xE9 :
        Serial.println("9");
        break;
      case 0xEA :
        Serial.println("*");
        break;
      case 0xEB :
        Serial.println("0");
        break;
      case 0xEC :
        Serial.println("#");
        break;
      default:
        break;
    }
  }
}


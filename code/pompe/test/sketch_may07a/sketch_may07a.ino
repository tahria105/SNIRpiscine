// Définition des broches pour contrôler le L298N
const int enablePin1 = 9; // Broche Enable du moteur 1
const int in1Pin = 8;     // Broche IN1 du moteur 1
const int in2Pin = 7;     // Broche IN2 du moteur 1

void setup() {
  // Déclaration des broches comme des sorties
  pinMode(enablePin1, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  // Faire tourner le moteur 1 dans un sens à pleine vitesse pendant 5 secondes
  digitalWrite(in1Pin, HIGH);      // Sens de rotation
  digitalWrite(in2Pin, LOW);       // Sens de rotation inverse
  analogWrite(enablePin1, 255);    // Activer le moteur 1 à pleine vitesse
  
  delay(5000); // Attendre pendant 5 secondes
  
  // Arrêter le moteur 1
  digitalWrite(in1Pin, LOW); // Désactiver le moteur 1
  digitalWrite(in2Pin, LOW);
  analogWrite(enablePin1, 0);
  
  delay(5000); // Attendre pendant 5 secondes avant de recommencer
}


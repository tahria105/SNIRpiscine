// Définir les broches des relais
const int relayPins[8] = {22, 23, 24, 25, 26, 27, 28, 29};

// Définir les broches du L298N
const int motor1Pin1 = 30;  // IN1 sur le L298N
const int motor1Pin2 = 31;  // IN2 sur le L298N
const int motor2Pin1 = 32;  // IN3 sur le L298N
const int motor2Pin2 = 33;  // IN4 sur le L298N
const int enableA = 2;      // ENA sur le L298N (PWM)
const int enableB = 3;      // ENB sur le L298N (PWM)

void setup() {
  // Initialiser les broches des relais comme sorties
  for (int i = 0; i < 8; i++) {
    pinMode(relayPins[i], OUTPUT);
  }

  // Initialiser les broches du L298N comme sorties
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);

  // Éteindre tous les relais au début
  for (int i = 0; i < 8; i++) {
    digitalWrite(relayPins[i], LOW);
  }

  // Éteindre les moteurs au début
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
}

void loop() {
  // Exemple de séquence pour allumer les relais et faire tourner les moteurs
  
  // Activer le premier relais
  digitalWrite(relayPins[0], HIGH);
  delay(2000); // Attendre 1 seconde
  digitalWrite(relayPins[0], LOW);
  
  // Faire tourner le moteur 1 dans un sens
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(enableA, 255); // Vitesse maximale
  delay(2000); // Faire tourner le moteur pendant 2 secondes
  analogWrite(enableA, 0); // Arrêter le moteur
  digitalWrite(motor1Pin1, LOW);

  // Faire tourner le moteur 2 dans le sens inverse
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enableB, 255); // Vitesse maximale
  delay(2000); // Faire tourner le moteur pendant 2 secondes
  analogWrite(enableB, 0); // Arrêter le moteur
  digitalWrite(motor2Pin2, LOW);
  
  // Activer le deuxième relais
  digitalWrite(relayPins[1], HIGH);
  delay(2000); // Attendre 1 seconde
  digitalWrite(relayPins[1], LOW);

  delay(5000); // Attendre 5 secondes avant de répéter la séquence
}


#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2       // Connectez le capteur DHT à la broche D2 du Grove Mega Shield
#define DHTTYPE DHT22  // Type de capteur DHT (DHT11 ou DHT22, selon le capteur utilisé)

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adresse I2C de l'afficheur LCD et dimensions (16 colonnes, 2 lignes)

void setup() {
  Serial.begin(9600);
  Serial.println("Capteur DHT test !");
  dht.begin();
  lcd.init();                      // Initialisation de l'afficheur LCD
  lcd.backlight();                 // Activation du rétroéclairage
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

  // Affichage des valeurs sur l'afficheur LCD
  lcd.clear();                   // Effacer l'afficheur LCD
  lcd.setCursor(0, 0);          // Positionner le curseur en haut à gauche
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0, 1);          // Positionner le curseur en bas à gauche
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print(" %");
}


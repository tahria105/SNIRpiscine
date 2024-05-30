#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#define DHTPIN 2       // Connectez le capteur DHT à la broche D2 du Grove Mega Shield
#define DHTTYPE DHT22  // Type de capteur DHT (DHT11 ou DHT22, selon le capteur utilisé)
#define I2C_ADDR 0x27  // Adresse I2C de l'afficheur LCD
#define LCD_COLS 16    // Nombre de colonnes de l'afficheur LCD
#define LCD_ROWS 2     // Nombre de lignes de l'afficheur LCD
#define pHSense A0     // Broche du capteur de pH
#define samples 10     // Nombre d'échantillons pour la moyenne
#define adc_resolution 1023.0 // Résolution de l'ADC

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS); 

void setup() {
  Serial.begin(9600);
  Serial.println("Capteur DHT & pH test !");
  dht.begin();
  lcd.init();
  lcd.backlight();
}

float ph(float voltage) {
  return ((2.5 - voltage) / 0.18);
}

void loop() {
  // Attendre quelques secondes entre chaque lecture
  delay(200);

  // Lecture de l'humidité relative
  float h = dht.readHumidity();
  // Lecture de la température en degrés Celsius
  float t = dht.readTemperature();

  // Vérifier si la lecture a échoué
  if (isnan(h) || isnan(t)) {
    Serial.println("Echec de la lecture du capteur DHT !");
    return;
  }

  int measurings = 0;

  for (int i = 0; i < samples; i++) {
    measurings += analogRead(pHSense);
    delay(10);
  }

  float voltage = 5 / adc_resolution * measurings / samples;
  float pH_value = ph(voltage);

  // Affichage des valeurs sur le moniteur série
  Serial.print("Humidité : ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Température : ");
  Serial.print(t);
  Serial.println(" °C");
  Serial.print("pH : ");
  Serial.println(pH_value);

  // Affichage des valeurs sur l'afficheur LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(0, 2);
  lcd.print("pH:");
  if (pH_value < 7) {
    lcd.print("Acide ");
  } else {
    lcd.print("Basique ");
  }
  lcd.print(pH_value);

  delay(20);
}


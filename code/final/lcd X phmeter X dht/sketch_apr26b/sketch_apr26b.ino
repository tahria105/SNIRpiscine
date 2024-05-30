#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2       // Connectez le capteur DHT à la broche D2 du Grove Mega Shield
#define DHTTYPE DHT22  // Type de capteur DHT (DHT11 ou DHT22, selon le capteur utilisé)
#define I2C_ADDR 0x27  // Adresse I2C de l'afficheur LCD
#define I2C_ADDR2 0x28 // Adresse I2C du deuxième afficheur LCD
#define LCD_COLS 16    // Nombre de colonnes de l'afficheur LCD
#define LCD_ROWS 4     // Nombre de lignes de l'afficheur LCD
#define pHSense A0     // Broche du capteur de pH
#define samples 10     // Nombre d'échantillons pour la moyenne
#define adc_resolution 1023.0 // Résolution de l'ADC

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS); 
LiquidCrystal_I2C lcd2(I2C_ADDR2, LCD_COLS, LCD_ROWS); 

String keypadValue = ""; // Variable pour stocker la valeur du clavier
bool addAcid = false;    // Indique si l'utilisateur veut ajouter de l'acide
bool addBase = false;    // Indique si l'utilisateur veut ajouter de la base
float pH_value = 7.0;    // Initialisation du pH à 7.0

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); // Initialiser la communication série sur Serial1 (RX1 et TX1) à 9600 bauds
  Serial.println("Capteur DHT & pH test !");
  Serial.println("Version:v1.0");
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd2.init();
  lcd2.backlight();
}

float ph(float voltage) {
  return ((2.5 - voltage) / 0.18);
}

void loop() {
  printData();

  // Attendre quelques secondes entre chaque lecture
  delay(200);

  // Lecture de l'humidité relative et de la température
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Vérifier si la lecture a échoué
  if (isnan(h) || isnan(t)) {
    Serial.println("Echec de la lecture du capteur DHT !");
    return;
  }

  // Lecture du pH
  pH_value = measurePH();

  // Modifier le pH en conséquence de l'ajout d'acide ou de base
  if (addAcid && pH_value > 0) {
    // Diminuer le pH
    pH_value -= 0.1;
    addAcid = false; // Réinitialiser après ajustement
  } else if (addBase && pH_value < 14) {
    // Augmenter le pH
    pH_value += 0.1;
    addBase = false; // Réinitialiser après ajustement
  }

  // Déterminer le statut acide/basique/neutre
  int pH_status = determinePHStatus(pH_value);

  // Affichage des valeurs sur le premier écran LCD
  displayOnLCD1(t, h, pH_value, pH_status);

  // Affichage du statut d'ajout d'acide ou de base sur le deuxième écran LCD
  displayOnLCD2();
  
  delay(700);
}

void displayOnLCD1(float t, float h, float pH_value, int pH_status) {
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
  lcd.print(pH_value);
  lcd.print(" (");
  lcd.print(pH_status);
  lcd.print(")");
  lcd.setCursor(0, 3);
  lcd.print("Clavier: ");
  lcd.print(keypadValue);
}

void displayOnLCD2() {
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("Ajouter de l'acide");
  lcd2.setCursor(0, 1);
  lcd2.print("ou de la base:");
  lcd2.setCursor(0, 2);
  lcd2.print("A: Acide  B: Base");
}

void printData() {
  while(Serial1.available()) {
    uint8_t data = Serial1.read();
    keypadValue = ""; // Réinitialiser la valeur du clavier
    switch(data) {
      case 0xE1 :
        keypadValue += "1";
        break;
      case 0xE2 :
        keypadValue += "2";
        break;
      case 0xE3 :
        keypadValue += "3";
        break;
      case 0xE4 :
        keypadValue += "4";
        break;
      case 0xE5 :
        keypadValue += "5";
        break;
      case 0xE6 :
        keypadValue += "6";
        break;
      case 0xE7 :
        keypadValue += "7";
        break;
      case 0xE8 :
        keypadValue += "8";
        break;
      case 0xE9 :
        keypadValue += "9";
        break;
      case 0xEA :
        keypadValue += "*";
        break;
      case 0xEB :
        keypadValue += "0";
        break;
      case 0xEC :
        keypadValue += "#";
        break;
      case 'A': // Si l'utilisateur appuie sur 'A', ajouter de l'acide
        addAcid = true;
        addBase = false;
        break;
      case 'B': // Si l'utilisateur appuie sur 'B', ajouter de la base
        addBase = true;
        addAcid = false;
        break;
      default:
        break;
    }
  }
}

float measurePH() {
  int measurings = 0;

  for (int i = 0; i < samples; i++) {
    measurings += analogRead(pHSense);
    delay(10);
  }

  float voltage = 5.0 / adc_resolution * measurings / samples;
  return ph(voltage);
}

int determinePHStatus(float pH_value) {
  if (pH_value < 7.0) {
    return 1; // Acide
  } else if (pH_value > 7.0) {
    return 3; // Basique
  } else {
    return 2; // Neutre
  }
}

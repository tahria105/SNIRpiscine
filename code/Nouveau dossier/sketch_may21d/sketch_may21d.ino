#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adresses I2C des écrans LCD
#define LCD1_ADDR 0x27
#define LCD2_ADDR 0x3F

// Configuration des écrans LCD
LiquidCrystal_I2C lcd1(LCD1_ADDR, 20, 4); // 20 colonnes, 4 lignes
LiquidCrystal_I2C lcd2(LCD2_ADDR, 16, 2); // 16 colonnes, 2 lignes

void setup() {
  // Initialisation des écrans LCD
  lcd1.begin(20, 4); // 20 colonnes, 4 lignes
  lcd2.begin(16, 2); // 16 colonnes, 2 lignes

  // Allumer le rétroéclairage (si nécessaire)
  lcd1.backlight();
  lcd2.backlight();

  // Effacer les écrans LCD
  lcd1.clear();
  lcd2.clear();

  // Afficher du texte sur chaque écran
  lcd1.setCursor(0, 0);
  lcd1.print("Hello LCD 1!");

  lcd2.setCursor(0, 0);
  lcd2.print("Hello LCD 2!");
}

void loop() {
  // Votre code ici
}

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String uid = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  lcd.begin();   // SENİN KÜTÜPHANE
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Sistem Hazir");
  delay(1500);
  lcd.clear();
}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("Kart Bekleniyor");

  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  uid = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) uid += " ";
  }

  uid.toUpperCase();

  Serial.println(uid);

  lcd.clear();

  // 🔵 MAVİ KART
  if (uid == "93 9C 2E 16") {

    lcd.setCursor(0,0);
    lcd.print("MAVI KART");

  }

  // ⚪ BEYAZ KART
  else if (uid == "8D 40 F6 04") {

    lcd.setCursor(0,0);
    lcd.print("BEYAZ KART");
  }

  // ❌ BİLİNMEYEN
  else {

    lcd.setCursor(0,0);
    lcd.print("ERISIM RED");

    lcd.setCursor(0,1);
    lcd.print("BILINMEYEN KART");
  }

  delay(2000);

  lcd.clear();
  rfid.PICC_HaltA();
}

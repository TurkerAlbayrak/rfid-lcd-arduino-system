# rfid-lcd-arduino-system
RFID-based access control system using Arduino UNO, MFRC522 module and I2C LCD display. Supports multiple card authentication and real-time UID display.

# 🔐 RFID Access Control System (Arduino UNO + LCD)

Bu proje, **Arduino UNO**, **MFRC522 RFID modülü** ve **I2C 16x2 LCD ekran** kullanarak kart bazlı bir erişim kontrol sistemi oluşturur.

Kart UID’lerine göre farklı mesajlar gösterir ve kullanıcıyı tanımlar.

---

## 🚀 Özellikler

- RFID kart okuma (MFRC522)
- LCD ekranda gerçek zamanlı UID gösterimi
- Kart bazlı yetkilendirme sistemi
- 2 farklı kart desteği (mavi & beyaz kart)
- Bilinmeyen kartlara erişim reddi mesajı

---

## 🧠 Sistem Mantığı

| Kart UID | Aksiyon |
|----------|--------|
| 93 9C 2E 16 |
| 8D 40 F6 04 |
| Diğer | ERİŞİM RED |

---

## 🔌 Bağlantı Şeması

(Resim Temsilidir.)
<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/e2731c5d-0b71-4a3a-a30e-0211866b97ef" />


### 📡 MFRC522 RFID Bağlantıları

| RC522 Pin | Arduino UNO |
|-----------|-------------|
| SDA (SS)  | D10 |
| SCK       | D13 |
| MOSI      | D11 |
| MISO      | D12 |
| RST       | D9 |
| 3.3V      | 3.3V ⚠️ |
| GND       | GND |

---

### 📺 I2C LCD Bağlantıları

| LCD Pin | Arduino UNO |
|---------|-------------|
| VCC     | 5V |
| GND     | GND |
| SDA     | A4 |
| SCL     | A5 |

---

## 🧩 Basit Bağlantı Diyagramı

    +----------------------+
    |   Arduino UNO R3     |
    +----------------------+
     | D10 → RC522 SDA
     | D11 → RC522 MOSI
     | D12 → RC522 MISO
     | D13 → RC522 SCK
     | D9  → RC522 RST
     | 3.3V→ RC522 VCC
     | GND → RC522 GND
     
     | A4  → LCD SDA
     | A5  → LCD SCL
     | 5V  → LCD VCC
     | GND → LCD GND

---

## 💻 Gereksinimler

Arduino IDE kütüphaneleri:

- MFRC522
- LiquidCrystal_I2C
- SPI
- Wire

---

## ⚙️ Kurulum

1. Arduino IDE'yi aç
2. Kütüphaneleri yükle:
   - MFRC522
   - LiquidCrystal_I2C
3. Kodları yükle
4. Bağlantıları yap
5. Kartı okut

---

## ▶️ Kullanım

1. Sistemi aç
2. LCD "Kart Bekleniyor" yazar
3. RFID kartı yaklaştır
4. Sistem UID'yi tanır ve LCD'de gösterir

---

## 📌 Notlar

- RC522 sadece **13.56 MHz MIFARE kartları** destekler
- 3.3V kullanmak zorunludur (5V zarar verebilir)
- LCD adresi genelde `0x27` dir

---

## 🔥 Geliştirme Fikirleri

- Servo motor ile kapı kilidi
- EEPROM kart kayıt sistemi
- Admin kart sistemi
- Buzzer + LED uyarı sistemi
- WiFi bildirim (ESP8266)

---

## 🧑‍💻 Geliştirici

Türker Albayrak

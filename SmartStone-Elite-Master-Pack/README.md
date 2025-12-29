# SmartStone V3 Elite - Teknik Dökümantasyon ve Kurulum Kılavuzu 💎

Bu döküman, 350x350mm çalışma alanına sahip, çift kafalı ve 8 renk kapasiteli otomatik taş dizim makinesinin kurulum ve işletme detaylarını içerir.

## 1. Donanım Mimarisi ve Pin Konfigürasyonu (RAMPS 1.6)
Makine üzerinde 5 adet Nema 17 motor ve 2 adet solenoid/tetikleyici bulunur.

| Komponent       | RAMPS Portu | Sürücü  | Görev |
| :---            | :---        | :---    | :--- |
| **Vakum Kafası**| X-Axis      | TMC2209 | X ekseninde taşı alıp koordinata götürür. |
| **Ultra Kafası**| Y-Axis      | TMC2209 | Bağımsız X ekseninde yapıştırma yapar. |
| **Taşıyıcı Tabla**| E0-Axis     | TMC2209 | Y ekseni (ileri-geri) hareketini sağlar. |
| **Z-Kaldıraç** | Z-Axis      | TMC2209 | Ultrasonik kafayı kumaşa bastırır. |
| **Revolver** | E1-Axis     | TMC2209 | 8 hazneli döner tepsiyi kontrol eder. |
| **Vakum Valfi** | D9 (PWM)    | MOSFET  | Negatif basıncı anlık kesip taşı bırakır. |
| **Ultrasonik** | D8 (PWM)    | MOSFET  | Jeneratör devresini tetikler. |

## 2. Hassas Kalibrasyon ve Offset Değerleri
IDEX sistemlerde iki kafa arasındaki mesafe kritiktir:
- **X-Offset:** Vakum iğnesi ile Ultrasonik uç arasındaki mesafe (Varsayılan: 85.00mm).
- **Z-Baskı:** Ultrasonik uç kumaşa değdiğinde yaylı mekanizma 2mm esnemelidir.
- **Revolver:** Her renk değişimi için motor 400 step (1.8 derece motorlarda) dönmelidir.

## 3. Yazılım Haberleşme Protokolü (G-Code)
Makine, standart seri port üzerinden 115200 baud hızında komut kabul eder:
- `M106 P1`: Vakumu Aç / `M107 P1`: Vakumu Kapat
- `T0`: Vakum Kafasını Seç / `T1`: Ultrasonik Kafayı Seç
- `G1 X100 Y150`: Hedef koordinata git.

## 4. Periyodik Bakım
- **Raylar:** MGN12H raylar her 100 çalışma saatinde bir lityum gres ile yağlanmalıdır.
- **Nozül:** 20G iğne ucu tıkanmalara karşı haftalık alkol ile temizlenmelidir.
- **Vakum:** Pompa filtresi her ay kontrol edilmelidir.

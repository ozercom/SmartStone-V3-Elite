/* * SmartStone V3 Elite - Final Firmware v1.1
 * Optimized for TMC2209, IDEX Dual-Head & 8-Slot Revolver
 */
#include <AccelStepper.h>

// Motor Pinleri (RAMPS 1.6)
AccelStepper vacX(1, 3, 2);      // X Portu: Vakum Kafası
AccelStepper ultraX(1, 15, 14);  // Y Portu: Ultrasonik Kafa
AccelStepper tableY(1, 5, 4);    // E0 Portu: Tabla (Y Ekseni)
AccelStepper axisZ(1, 11, 10);   // Z Portu: Dikey Hareket
AccelStepper revolver(1, 1, 0);  // E1 Portu: 8 Renk Haznesi

// Yardımcı Pinler
#define VAC_VALVE 9
#define ULTRA_TRIGGER 8
#define REVOLVER_STEPS_PER_COLOR 200 // 360/8 dereceye denk gelen adım

void setup() {
  Serial.begin(115200);
  pinMode(VAC_VALVE, OUTPUT);
  pinMode(ULTRA_TRIGGER, OUTPUT);

  // Hız ve İvme Ayarları (350mm Frame)
  vacX.setMaxSpeed(5000); vacX.setAcceleration(3000);
  ultraX.setMaxSpeed(5000); ultraX.setAcceleration(3000);
  tableY.setMaxSpeed(3500); tableY.setAcceleration(2500);
  revolver.setMaxSpeed(1000); 
}

// 8 Renk Seçici Fonksiyon
void selectColor(int colorIndex) {
  if(colorIndex >= 0 && colorIndex < 8) {
    revolver.runToNewPosition(colorIndex * REVOLVER_STEPS_PER_COLOR);
  }
}

// Ana Yapıştırma Döngüsü (Hız Odaklı)
void executeCycle(float x, float y, int color) {
  selectColor(color); // Renk Değişimi
  
  tableY.moveTo(y);
  vacX.moveTo(x);
  while(vacX.distanceToGo() != 0 || tableY.distanceToGo() != 0) {
    vacX.run(); tableY.run();
  }

  digitalWrite(VAC_VALVE, HIGH); // Taş Bırak
  vacX.moveTo(-50); // Vakum kaçar
  ultraX.moveTo(x); // Ultra gelir
  
  while(ultraX.distanceToGo() != 0) {
    vacX.run(); ultraX.run();
  }
  
  digitalWrite(ULTRA_TRIGGER, HIGH); // Yapıştır
  delay(300);
  digitalWrite(ULTRA_TRIGGER, LOW);
  digitalWrite(VAC_VALVE, LOW);
}

void loop() {
  // G-Code Parse Mantığı buraya eklenecek
}

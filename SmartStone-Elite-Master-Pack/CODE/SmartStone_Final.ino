#include <AccelStepper.h>

// Motor ve Pin Tanimlamalari
AccelStepper vacX(1, 3, 2);
AccelStepper ultraX(1, 15, 14);
AccelStepper tableY(1, 5, 4);
AccelStepper axisZ(1, 11, 10);
AccelStepper revolver(1, 1, 0);

#define VAC_PIN 9
#define ULTRA_PIN 8

void setup() {
  Serial.begin(115200);
  pinMode(VAC_PIN, OUTPUT);
  pinMode(ULTRA_PIN, OUTPUT);

  // Hiz Ayarlari
  vacX.setMaxSpeed(5000); vacX.setAcceleration(3000);
  ultraX.setMaxSpeed(5000); ultraX.setAcceleration(3000);
  tableY.setMaxSpeed(3500); tableY.setAcceleration(2500);
  axisZ.setMaxSpeed(2000);
  revolver.setMaxSpeed(1000);
}

void loop() {
  if (Serial.available()) {
    // Burada gelen komutlar islenecek
  }
}

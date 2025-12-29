/* SmartStone V3 Elite - Firmware v1.0 */
#include <AccelStepper.h>

// RAMPS 1.6 Pins
AccelStepper vacX(1, 3, 2);    // Vacuum Head
AccelStepper ultraX(1, 15, 14);  // Ultrasonic Head
AccelStepper tableY(1, 5, 4);   // Table Movement
AccelStepper axisZ(1, 11, 10);  // Vertical Axis

#define VAC_VALVE 9
#define ULTRA_TRIGGER 8

void setup() {
  Serial.begin(115200);
  pinMode(VAC_VALVE, OUTPUT);
  pinMode(ULTRA_TRIGGER, OUTPUT);

  // High Speed Optimization for 350mm Frame
  vacX.setMaxSpeed(5000); vacX.setAcceleration(4000);
  ultraX.setMaxSpeed(5000); ultraX.setAcceleration(4000);
  tableY.setMaxSpeed(3500); tableY.setAcceleration(2500);
  axisZ.setMaxSpeed(2000);
}

void loop() {
  // Command Listener
}

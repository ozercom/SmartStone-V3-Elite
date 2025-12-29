# SmartStone V3 Elite - Professional Rhinestone Setting CNC 💎

This repository contains the full open-source documentation for the **SmartStone V3 Elite**, a high-speed, dual-head (IDEX) CNC machine designed for precision rhinestone setting on garments.

## 🚀 Performance Specifications
- **Work Area:** 350mm x 350mm (Optimized for 30x30cm designs)
- **Speed:** 30-45 stones per minute (Ultrasonic fixing included)
- **Accuracy:** ±0.05mm positioning, 0.1mm minimum stone spacing.
- **Heads:** Independent Dual-X (IDEX) - Vacuum Pickup + Ultrasonic Fixer.
- **Drive System:** TMC2209 Silent Steppers (UART Configured).

## 🛠 Hardware Architecture
- **Controller:** Arduino Mega 2560 + RAMPS 1.6
- **Motion:** MGN12H Linear Rails on all axes.
- **Fixing:** 28kHz/35kHz Ultrasonic Generator.
- **Pickup:** 12V High-Pressure Vacuum Pump with Solenoid Instant Release.

## 📂 Project Structure
- **/CODE:** Arduino source for RAMPS 1.6.
- **/ELECTRONICS:** Wiring diagrams, BOM (Bill of Materials).
- **/MECHANICAL:** 3D assembly guides and 2D DXF files.
- **/DOCS:** Operational manuals and calibration guides.

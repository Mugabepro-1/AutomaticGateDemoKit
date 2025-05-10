# Automatic Gate Demo Kit (Arduino Project)

This project is an embedded systems simulation of an automatic gate that detects nearby objects and responds accordingly using an Arduino microcontroller. It demonstrates real-world automation concepts like proximity sensing, timed actuation, and state indication.

## Features
- Automatic gate opens when an object is detected within 15 cm.
- Buzzer beeps twice per second for 5 seconds while the gate is open.
- LEDs indicate gate state (red for closed, blue for open).
- Servo motor controls the physical movement of the gate.

## Components Used
- Arduino Uno or Nano
- Ultrasonic Sensor (HC-SR04)
- SG90 Servo Motor
- Red LED (Gate Closed Indicator)
- Blue LED (Gate Open Indicator)
- Piezo Buzzer
- Breadboard and jumper wires
- 150-ohm resistors for LEDs
- 5V USB power supply
- Optional: Toy car for simulation

## Arduino Pin Configuration

| Arduino Pin | Component               |
|-------------|--------------------------|
| D2          | Ultrasonic Trigger       |
| D3          | Ultrasonic Echo          |
| D4          | Red LED (Gate Closed)    |
| D5          | Blue LED (Gate Open)     |
| D6          | Servo Motor (PWM)        |
| D7, D8      | Hardwired LOW (GND)      |
| D12         | Piezo Buzzer             |
| GND         | Common Ground            |
| 5V          | Power Supply             |

## How It Works

1. The system keeps the gate closed (servo at 1°) by default, with the red LED ON.
2. The ultrasonic sensor measures distance continuously.
3. If an object is detected within 15 cm:
   - The servo rotates to 90° to open the gate.
   - Blue LED turns ON, red LED turns OFF.
   - Buzzer beeps 2 times per second for 5 seconds (10 total beeps).
4. After 5 seconds:
   - The servo returns to 0° to close the gate.
   - Blue LED turns OFF, red LED turns ON.
   - Buzzer stops.

## Getting Started

1. Build the circuit on a breadboard using the pin configuration above.
2. Upload the Arduino sketch (`.ino` file) using the Arduino IDE.
3. Open the Serial Monitor to observe distance readings (optional).
4. Place an object in front of the ultrasonic sensor to trigger the gate.

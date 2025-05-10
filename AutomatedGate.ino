#include <Servo.h>

// Pin definitions
const int TRIG_PIN = 2;    // Ultrasonic Trigger
const int ECHO_PIN = 3;    // Ultrasonic Echo
const int RED_LED = 4;     // Red LED (Gate Closed)
const int BLUE_LED = 5;    // Blue LED (Gate Open)
const int SERVO_PIN = 6;   // Servo Motor
const int GND_PIN1 = 7;    // Hardwired GND (LOW)
const int GND_PIN2 = 8;    // Hardwired GND (LOW)
const int BUZZER_PIN = 12; // Buzzer

// Variables
Servo gateServo;
const float GATE_CLOSED_ANGLE = 1;   // Gate closed position
const int GATE_OPEN_ANGLE = 95;      // Gate open position
const int DISTANCE_THRESHOLD = 15;   // Distance in cm to trigger gate
bool isGateOpen = false;             // Track gate state

void setup() {
  // Initialize pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GND_PIN1, OUTPUT);
  pinMode(GND_PIN2, OUTPUT);

  // Set D7 and D8 as hardwired LOW
  digitalWrite(GND_PIN1, LOW);
  digitalWrite(GND_PIN2, LOW);

  // Attach the servo
  gateServo.attach(SERVO_PIN);

  // Initial state: gate closed, red LED on
  gateServo.write(GATE_CLOSED_ANGLE);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  // Measure distance
  long duration;
  float distance;

  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo and convert to distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;

  // If car is close and gate is closed
  if (distance < DISTANCE_THRESHOLD && !isGateOpen) {
    // Open the gate
    gateServo.write(GATE_OPEN_ANGLE);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    isGateOpen = true;

    // Beep the buzzer 2 times per second for 5 seconds
    for (int i = 0; i < 10; i++) { // 10 beeps = 5 seconds
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100); // ON for 100ms
      digitalWrite(BUZZER_PIN, LOW);
      delay(400); // OFF for 400ms
    }

    // Close the gate
    gateServo.write(GATE_CLOSED_ANGLE);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    isGateOpen = false;
  }

  delay(100); // Sensor cooldown
}

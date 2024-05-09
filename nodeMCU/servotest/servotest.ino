#include <ESP32Servo.h>

#define SERVO_PIN 33
#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180

Servo servo;

void setup() {
  Serial.begin(115200);
  servo.setPeriodHertz(50); // Set the PWM frequency to 50Hz (standard for most servos)
  servo.attach(SERVO_PIN);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the input until newline character
    int angle = input.toInt(); // Convert the input to an integer angle value
    angle = constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE); // Constrain the angle to valid range
    servo.write(angle); // Move the servo to the specified angle
  }
}

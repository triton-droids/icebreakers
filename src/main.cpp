/*
 * ESP32 4-Servo Continuous Loop Controller
 * 
 * This program controls 4 microservos connected to an ESP32,
 * moving them continuously in a loop pattern.
 * 
 * Connections:
 * - Servo 1: GPIO 18
 * - Servo 2: GPIO 19
 * - Servo 3: GPIO 21
 * - Servo 4: GPIO 22
 * 
 * The servos will sweep back and forth continuously.
 */

#include <Arduino.h>
#include <ESP32Servo.h>

// Define servo pins
const int SERVO_PIN_1 = 18;
const int SERVO_PIN_2 = 19;
const int SERVO_PIN_3 = 21;
const int SERVO_PIN_4 = 22;

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Servo parameters
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;
const int STEP_DELAY = 15;  // Delay in ms between steps
const int ANGLE_STEP = 1;   // Degrees to move per step

// Current positions
int pos1 = MIN_ANGLE;
int pos2 = MIN_ANGLE;
int pos3 = MIN_ANGLE;
int pos4 = MIN_ANGLE;

// Direction flags (1 = increasing, -1 = decreasing)
int dir1 = 1;
int dir2 = 1;
int dir3 = 1;
int dir4 = 1;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("ESP32 4-Servo Controller Starting...");
  
  // Attach servos to pins
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  servo3.attach(SERVO_PIN_3);
  servo4.attach(SERVO_PIN_4);
  
  // Initialize servos to start position
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  
  Serial.println("Servos initialized. Starting continuous loop...");
  
  delay(1000);  // Wait 1 second before starting
}

/**
 * Update a single servo's position in the continuous loop
 * @param servo Reference to the Servo object to update
 * @param pos Reference to current position (modified by this function)
 * @param dir Reference to current direction (modified by this function)
 */
void updateServo(Servo &servo, int &pos, int &dir) {
  pos += dir * ANGLE_STEP;
  if (pos >= MAX_ANGLE) {
    pos = MAX_ANGLE;
    dir = -1;
  } else if (pos <= MIN_ANGLE) {
    pos = MIN_ANGLE;
    dir = 1;
  }
  servo.write(pos);
}

void loop() {
  // Update all servos
  updateServo(servo1, pos1, dir1);
  updateServo(servo2, pos2, dir2);
  updateServo(servo3, pos3, dir3);
  updateServo(servo4, pos4, dir4);
  
  // Small delay between updates
  delay(STEP_DELAY);
  
  // Optional: Print positions every 100 iterations for debugging
  static int counter = 0;
  counter++;
  if (counter >= 100) {
    Serial.printf("Positions - S1:%d S2:%d S3:%d S4:%d\n", pos1, pos2, pos3, pos4);
    counter = 0;
  }
}

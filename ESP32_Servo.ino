#include <ESP32Servo.h>

Servo s;

const int SERVO_PIN = 18;

// pulse limits
const int MIN_US = 700;
const int MAX_US = 2300;
const int MID_US = 1500;

// motion shape
const int PERIOD_MS = 800;     // full cycle duration
const int AMP_US    = 450;     // swing around MID; keep MID±AMP within [MIN,MAX]

void setup() {
  s.attach(SERVO_PIN, MIN_US, MAX_US);
  s.writeMicroseconds(MID_US);
  delay(300);
}

void loop() {
  // Continuous sine: MID + AMP * sin(2π * t / T)
  unsigned long t = millis();
  float phase = (t % PERIOD_MS) / float(PERIOD_MS);    // 0..1
  float theta = sinf(2.0f * 3.1415926f * phase);       // -1..1
  int us = MID_US + int(AMP_US * theta);

  // Clamp to safe range
  if (us < MIN_US) us = MIN_US;
  if (us > MAX_US) us = MAX_US;

  s.writeMicroseconds(us);
  delay(5);   // small pacing; lower = smoother motion, slightly more CPU
}

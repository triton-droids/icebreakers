# Icebreakers

This project involves controlling microservos with ESP32, Arduino Nano, and Arduino Uno R3 microcontrollers using Arduino IDE.

## Setup Instructions

### 1. Install Arduino IDE

Download and install the latest version of Arduino IDE from the [official website](https://www.arduino.cc/en/software).

### 2. Configure Board Support

#### For ESP32:
1. Open Arduino IDE
2. Go to **File > Preferences** (or **Arduino IDE > Preferences** on macOS)
3. In the "Additional Boards Manager URLs" field, add:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
4. Click **OK**
5. Go to **Tools > Board > Boards Manager**
6. Search for "ESP32"
7. Install **"ESP32 by Espressif Systems"**

#### For Arduino Nano and Uno R3:
These boards are supported by default in Arduino IDE - no additional board packages needed.

### 3. Select Your Board

Choose the appropriate board for your project:

**For ESP32:**
- Go to **Tools > Board > ESP32 Arduino**
- Select your ESP32 board (e.g., "ESP32 Dev Module")

**For Arduino Nano:**
- Go to **Tools > Board > Arduino AVR Boards**
- Select "Arduino Nano"
- Set **Tools > Processor** to "ATmega328P (Old Bootloader)" if using older Nano clones

**For Arduino Uno R3:**
- Go to **Tools > Board > Arduino AVR Boards**
- Select "Arduino Uno"

Then select the appropriate **Port** under **Tools > Port**

### 4. Required Libraries for Servo Control

#### For ESP32:
Install the **ESP32Servo Library** (Recommended):
- Go to **Sketch > Include Library > Manage Libraries**
- Search for "ESP32Servo"
- Install **"ESP32Servo by Kevin Harrington"**

#### For Arduino Nano and Uno R3:
Use the built-in **Servo Library** (already included with Arduino IDE):
- No additional installation required
- Include with `#include <Servo.h>`

### 5. Basic Servo Connections

#### ESP32:
- **Servo Signal Wire**: Connect to any GPIO pin (e.g., GPIO 18)
- **Servo Power (Red)**: Connect to 5V or 3.3V depending on your servo
- **Servo Ground (Brown/Black)**: Connect to GND

#### Arduino Nano:
- **Servo Signal Wire**: Connect to any digital pin (e.g., pin 9)
- **Servo Power (Red)**: Connect to 5V
- **Servo Ground (Brown/Black)**: Connect to GND

#### Arduino Uno R3:
- **Servo Signal Wire**: Connect to any digital pin (e.g., pin 9)
- **Servo Power (Red)**: Connect to 5V
- **Servo Ground (Brown/Black)**: Connect to GND

### 6. Test Your Setup

#### For ESP32:
```cpp
#include <ESP32Servo.h>

Servo myServo;
int servoPin = 18;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);
}
```

#### For Arduino Nano and Uno R3:
```cpp
#include <Servo.h>

Servo myServo;
int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);
}
```

## Troubleshooting

### ESP32:
- **Upload Issues**: Press and hold the BOOT button on ESP32 while uploading
- **Port Not Found**: Make sure ESP32 drivers are installed and the board is connected

### Arduino Nano:
- **Upload Issues**: Try selecting "ATmega328P (Old Bootloader)" in Tools > Processor
- **Port Issues**: Install CH340 or FTDI drivers if using clone boards

### Arduino Uno R3:
- **Upload Issues**: Check that the correct board and port are selected
- **Port Issues**: Ensure USB cable supports data transfer (not just power)

### General:
- **Servo Not Moving**: Check power supply and wiring connections
- **Erratic Servo Movement**: Ensure adequate power supply for your servo's current requirements
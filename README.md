# ESP32 4-Servo Controller

This repository contains code for programming an ESP32 microcontroller to control 4 microservos continuously in a loop pattern.

## Overview

The program makes 4 servos sweep back and forth continuously between 0° and 180°, creating a smooth looping motion. Each servo operates independently and can be customized.

## Hardware Requirements

- ESP32 development board (ESP32-DevKitC or compatible)
- 4x Microservos (SG90 or similar)
- Power supply for servos (5V, adequate current for 4 servos - typically 2A+)
- Jumper wires
- Breadboard (optional)

## Wiring Connections

Connect the servos to the following GPIO pins on the ESP32:

| Servo | GPIO Pin |
|-------|----------|
| Servo 1 | GPIO 18 |
| Servo 2 | GPIO 19 |
| Servo 3 | GPIO 21 |
| Servo 4 | GPIO 22 |

**Important:** 
- Connect all servo signal wires to the respective GPIO pins
- Connect all servo ground (brown/black) wires to ESP32 GND
- Connect all servo power (red) wires to external 5V power supply
- Connect ESP32 GND to power supply GND (common ground)

## Software Requirements

### Install PlatformIO

This project uses PlatformIO for dependency management and building. You can use PlatformIO with:

#### Option 1: PlatformIO IDE (VS Code Extension)
1. Install [Visual Studio Code](https://code.visualstudio.com/)
2. Install the PlatformIO IDE extension from VS Code marketplace
3. Open this project folder in VS Code

#### Option 2: PlatformIO CLI
```bash
# Install PlatformIO CLI
pip install platformio

# Navigate to project directory
cd icebreakers
```

## Dependencies

The project automatically installs the following dependencies (configured in `platformio.ini`):
- **ESP32Servo** - Servo control library optimized for ESP32

These will be automatically downloaded when you first build the project.

## Building and Uploading

### Using PlatformIO IDE (VS Code)
1. Open the project folder in VS Code
2. Click the checkmark icon (✓) in the bottom toolbar to build
3. Click the arrow icon (→) in the bottom toolbar to upload to ESP32

### Using PlatformIO CLI
```bash
# Build the project
pio run

# Upload to ESP32 (make sure ESP32 is connected via USB)
pio run --target upload

# Monitor serial output (optional)
pio device monitor
```

## Customization

You can modify the following parameters in `src/main.cpp`:

- **Servo pins**: Change `SERVO_PIN_1` through `SERVO_PIN_4` constants
- **Angle range**: Modify `MIN_ANGLE` and `MAX_ANGLE` (default: 0-180°)
- **Speed**: Adjust `STEP_DELAY` (milliseconds between steps)
- **Smoothness**: Change `ANGLE_STEP` (degrees per step)

## Serial Monitor

The program outputs servo positions to the serial monitor at 115200 baud. You can view this for debugging:

```bash
pio device monitor --baud 115200
```

## Troubleshooting

- **Servos jittering**: Ensure adequate power supply for all servos
- **Servos not moving**: Check wiring connections and GPIO pin assignments
- **Upload fails**: Make sure ESP32 is properly connected and correct COM port is selected
- **Build errors**: Run `pio lib install` to ensure all dependencies are installed

## Project Structure

```
icebreakers/
├── src/
│   └── main.cpp          # Main Arduino sketch
├── platformio.ini        # PlatformIO configuration & dependencies
├── .gitignore           # Git ignore file
└── README.md            # This file
```

## License

This project is open source and available for educational and personal use.
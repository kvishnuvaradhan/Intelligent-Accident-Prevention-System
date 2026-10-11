# Intelligent Accident Prevention System

## Overview
This starter Arduino prototype measures distance with an HC-SR04 ultrasonic sensor and activates a buzzer and LED when an obstacle is within a configurable warning distance.

## Assumed components
- Arduino Uno
- HC-SR04 ultrasonic sensor
- Buzzer compatible with the output (use a driver if required)
- Built-in LED on pin 13

## Pin mapping
| Component | Arduino pin |
|---|---|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Buzzer signal | D6 |
| Built-in LED | D13 |
| Sensor VCC | 5V, if module is 5V-compatible |
| Sensor GND | GND |

## Run
1. Open `accident_prevention.ino` in Arduino IDE.
2. Confirm wiring matches your hardware and module specifications.
3. Select the correct board and port.
4. Upload the sketch.
5. Open Serial Monitor at 9600 baud.
6. Move an object in front of the sensor and observe the distance and warning.

Change `WARNING_DISTANCE_CM` to adjust the warning threshold.

## Scope and safety
This is a generated educational starter implementation based on the project topic, not the original source code. It only provides an obstacle warning; it does not control brakes or guarantee accident prevention. Do not connect it to a real vehicle's braking or steering system.

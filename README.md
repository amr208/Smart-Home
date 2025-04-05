# Smart Home Automation System

## Description
This project implements a smart home automation system using an ATmega32 microcontroller. The system monitors environmental conditions including temperature and light intensity, and automatically controls lighting, ventilation, and fire alarms based on sensor inputs.

## Features
- **Automatic Lighting Control**: Adjusts LED lighting based on ambient light levels
- **Temperature-Controlled Fan**: Varies fan speed according to room temperature
- **Fire Detection**: Flame sensor triggers audible alarm
- **Real-time Monitoring**: LCD displays current temperature, light levels, and system status
- **Multiple Safety Systems**: Integrated flame detection with buzzer alarm

## Hardware Components
- **Microcontroller**: ATmega32
- **Sensors**:
  - LM35 Temperature Sensor
  - LDR (Light Dependent Resistor)
  - Flame Sensor
- **Actuators**:
  - DC Motor (Fan)
  - RGB LED
  - Buzzer
- **Display**: 16x2 LCD
- **Other**: PWM controller for fan speed

## Software Architecture
### Main Components
1. **Sensor Modules**:
   - `LDR.c/h`: Light intensity measurement
   - `LM35.c/h`: Temperature measurement
   - `flame.c/h`: Fire detection

2. **Actuator Modules**:
   - `LED.c/h`: Lighting control
   - `motor.c/h`: Fan control
   - `buzzer.c/h`: Alarm system

3. **Interface Modules**:
   - `LCD.c/h`: System status display
   - `PWM.c/h`: Fan speed control

### Key Functions
- `Lighting_System()`: Controls LEDs based on ambient light
- `Fan_Speed_Interfacing()`: Adjusts fan speed according to temperature
- `Flame_Alert()`: Handles fire detection and alarm
- `Display_*()`: Various LCD display functions

## System Behavior
### Lighting Control
- **Very Low Light (≤15)**: All LEDs (Red, Green, Blue) ON
- **Low Light (16-50)**: Red and Green LEDs ON
- **Moderate Light (51-70)**: Red LED ON
- **Bright Light (>70)**: All LEDs OFF

### Fan Control
| Temperature Range | Fan Speed | PWM Duty Cycle |
|-------------------|-----------|----------------|
| ≤25°C            | OFF       | 0%             |
| 26-30°C          | Low       | 25%            |
| 31-35°C          | Medium    | 50%            |
| 36-40°C          | High      | 75%            |
| >40°C            | Maximum   | 100%           |

### Fire Detection
- Immediately triggers buzzer alarm
- Displays "Critical alert!" on LCD

## Display Information
- **First Line**: 
  - Fan status ("Fan is ON/OFF")
  - Flame alert (when triggered)
- **Second Line**:
  - Current temperature ("Temp=XX")
  - Light intensity ("LDR=XX%")

## Technical Specifications
- **ADC**: 10-bit resolution for sensor readings
- **PWM**: Timer0 in Fast PWM mode (1024 prescaler)
- **LCD Interface**: 4-bit mode
- **Sensor Sampling**: Continuous in main loop

## Setup Instructions
1. Connect all sensors and actuators as per schematic
2. Configure microcontroller fuses for 16MHz operation
3. Flash compiled hex file to ATmega32
4. Power on the system

## Usage
The system operates automatically:
1. Lights adjust based on ambient light
2. Fan speed varies with temperature
3. Flame detection triggers immediate alarm
4. All status information displays on LCD

## Safety Features
- Visual and audible fire alarm
- Automatic temperature regulation
- Clear status indicators

## Limitations
- No remote monitoring/control
- Basic threshold-based control (no PID)
- No data logging capability

## Expansion Possibilities
- Add IoT connectivity for remote monitoring
- Implement PID control for smoother transitions
- Add additional sensors (humidity, air quality)
- Incorporate manual override controls

## Dependencies
- AVR Libc
- Standard C libraries
- Custom driver libraries for peripherals

## Files
- `Main_Application.c`: Main system logic
- Peripheral drivers:
  - ADC, PWM, LCD, GPIO
- Sensor/actuator modules:
  - LDR, LM35, Flame, LED, Motor, Buzzer

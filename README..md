# ESP32-Based Industrial Motor Condition Monitoring System

## Overview

This project demonstrates an embedded motor condition monitoring system using C++ and the ESP32 development platform.

The application monitors simulated motor sensor readings — temperature, vibration, and current — and determines the motor's operating condition using configurable warning and fault thresholds.

The project focuses on embedded software development, modular C++ design, state-machine-based logic, and hardware-independent unit testing.

## Key Features

- Modular C++ implementation using separate header and source files.
- Motor operating state management using an enumeration-based state machine.
- Threshold-based warning and fault detection.
- Monitoring of temperature, vibration, and current parameters.
- Simulated sensor readings for hardware-independent development.
- Native unit testing using PlatformIO and Unity.
- Separate ESP32 firmware and native testing environments.

## System Architecture

The application consists of three main components:

1. **Sensor Data:** Stores temperature, vibration, and current readings.
2. **Motor Monitor:** Evaluates sensor readings against configured thresholds.
3. **Application:** Simulates sensor inputs and periodically displays motor status through the serial interface.

## Motor Operating States

| State | Description |
|---|---|
| STOPPED | Motor is not running. |
| RUNNING | Motor is running under normal operating conditions. |
| WARNING | One or more sensor readings have reached warning thresholds. |
| FAULT | One or more sensor readings have reached fault thresholds. |

## Configured Thresholds

| Parameter | Warning Threshold | Fault Threshold |
|---|---:|---:|
| Temperature | 70 °C | 85 °C |
| Vibration | 4.5 | 7.0 |
| Current | 8 A | 10 A |

*Note: These are illustrative software thresholds for this prototype, not validated industrial motor protection limits.*

## Technologies Used

- **Programming Language:** C++
- **Development Platform:** ESP32
- **Framework:** Arduino
- **Build System:** PlatformIO
- **Unit Testing:** Unity
- **Native Compiler:** GCC (MSYS2 UCRT64)
- **Version Control:** Git and GitHub

## Project Structure

```text
esp32_motor_monitor/
├── include/
│   └── motor_monitor.h
├── src/
│   ├── main.cpp
│   └── motor_monitor.cpp
├── test/
│   └── test_motor_monitor/
│       └── test_main.cpp
├── platformio.ini
├── wokwi.toml
├── .gitignore
└── README.md
```

## Building the Firmware

Install [PlatformIO](https://platformio.org/) and open the project.

Build the ESP32 firmware:

```bash
pio run -e esp32dev
```

Upload to an ESP32 board when available:

```bash
pio run -e esp32dev -t upload
```

## Running Unit Tests

The motor monitoring logic can be tested on a native platform without requiring physical ESP32 hardware.

Run:

```bash
pio test -e native
```

### Current Test Coverage

The following test cases have been implemented and successfully executed:

- Verify initial motor state is STOPPED.
- Verify normal sensor readings return RUNNING.
- Verify high temperature returns WARNING.
- Verify critical temperature returns FAULT.
- Verify a stopped motor returns STOPPED.

## Current Limitations

- Sensor readings are simulated; no physical sensors are connected.
- No actual motor control or protection hardware is implemented.
- Threshold values are illustrative and require application-specific validation.
- Hardware-in-the-loop testing has not yet been performed.

## Future Enhancements

- Integrate physical temperature, vibration, and current sensors.
- Add additional unit tests for vibration and current warning/fault conditions.
- Implement sensor data filtering and validation.
- Add structured serial telemetry.
- Integrate automated testing with GitHub Actions.
- Explore MQTT-based remote condition monitoring.

## Author

Developed as an embedded C++ portfolio project to demonstrate firmware development, state-machine design, and software testing practices.
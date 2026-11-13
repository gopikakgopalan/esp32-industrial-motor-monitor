#include <Arduino.h>
#include "motor_monitor.h"

MotorMonitor motor_monitor;

void setup() {
  Serial.begin(115200);
  Serial.println("Setup in progress");
}

void loop() {
  SensorData motor_data ={45.0f, 2.5f, 5.0f};

  bool motor_running = true;

  MotorState state = motor_monitor.update(motor_data, motor_running);

  Serial.print("Temperature: ");
    Serial.print(motor_data.temperature);
    Serial.println(" C");

    Serial.print("Vibration: ");
    Serial.print(motor_data.vibration);
    Serial.println(" mm/s");

    Serial.print("Current: ");
    Serial.print(motor_data.current);
    Serial.println(" A");

    Serial.print("Motor State: ");

    switch (state) {
        case MotorState::STOPPED:
            Serial.println("STOPPED");
            break;

        case MotorState::RUNNING:
            Serial.println("RUNNING");
            break;

        case MotorState::WARNING:
            Serial.println("WARNING");
            break;

        case MotorState::FAULT:
            Serial.println("FAULT");
            break;
    }

    Serial.println("---------------------------");

    delay(2000);

}

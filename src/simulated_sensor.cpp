#include "simulated_sensor.h"

SimulatedSensor::SimulatedSensor(SimulationScenario scenario): current_scenario(scenario){}

SensorData SimulatedSensor::read(){

    switch (current_scenario){
        case SimulationScenario::NORMAL:
            return {45.0f, 2.5f, 5.0f};

        case SimulationScenario::OVERHEATING:
            return {90.0f, 2.5f, 5.0f};

        case SimulationScenario::HIGH_VIBRATION:
            return {45.0f, 8.0f, 5.0f};

        case SimulationScenario::OVERLOAD:
            return {45.0f, 2.5f, 11.0f};

        default:
            return {0.0f, 0.0f, 0.0f};
    }

}
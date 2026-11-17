#pragma once

#include "sensor_source.h"


enum class SimulationScenario{
    NORMAL,
    OVERHEATING,
    HIGH_VIBRATION,
    OVERLOAD
};

class SimulatedSensor : public ISensorSource{

public:
    explicit SimulatedSensor(SimulationScenario scenario);

    SensorData read()override;

private:
    SimulationScenario current_scenario;

};
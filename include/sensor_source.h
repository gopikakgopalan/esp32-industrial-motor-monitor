#pragma once

#include "motor_monitor.h"

// Abstract interface for all sensor sources
class ISensorSource{
public:

    virtual ~ISensorSource() = default;

    virtual SensorData read() = 0;
};
#pragma once

#include "motor_monitor.h"
#include "sensor_source.h"


class MotorMonitorService{
public:

    MotorMonitorService(ISensorSource& sensor_source, MotorMonitor& motor_monitor);

    MotorState update(bool motor_running);


private:
    ISensorSource& sensor_source;
    MotorMonitor& motor_monitor;
};
#include "motor_monitor_service.h"


MotorMonitorService::MotorMonitorService(ISensorSource& sensor_source, MotorMonitor& motor_monitor):
                    sensor_source(sensor_source), motor_monitor(motor_monitor){}


MotorState MotorMonitorService::update(bool motor_running){

    SensorData sensor_data = sensor_source.read();

    return motor_monitor.update(sensor_data, motor_running);

}
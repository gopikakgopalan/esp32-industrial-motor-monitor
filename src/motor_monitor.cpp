#include "motor_monitor.h"


MotorMonitor::MotorMonitor(): current_state(MotorState::STOPPED){}

MotorState MotorMonitor::update(const SensorData& sensor_data, bool motor_running){
    if(! motor_running){
        current_state = MotorState::STOPPED;
    }
    else if(sensor_data.temperature >= thresholds.temperature_fault || 
            sensor_data.vibration>= thresholds.vibration_fault ||
            sensor_data.current >= thresholds.current_fault){
        current_state = MotorState::FAULT;
    }
    else if(sensor_data.temperature >= thresholds.temperature_warning || 
            sensor_data.vibration>= thresholds.vibration_warning ||
            sensor_data.current >= thresholds.current_warning){
        current_state = MotorState::WARNING;
    }
    else{
        current_state = MotorState::RUNNING;
    }

    return current_state;
}


MotorState MotorMonitor::get_state()const{
    return current_state;
}

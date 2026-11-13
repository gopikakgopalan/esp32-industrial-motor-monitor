#pragma once


    //Motor operating states
    enum class MotorState{
        STOPPED,
        RUNNING,
        WARNING,
        FAULT
    };

    // Motor sensor readings
    struct SensorData{
        float temperature;
        float vibration;
        float current;
    };

    //Motor Threshold Values
    struct MotorThreshold{
        float temperature_warning = 70.0f;
        float temperature_fault = 85.0f;
        float vibration_warning = 4.5f;
        float vibration_fault = 7.0f;
        float current_warning = 8.0f;
        float current_fault = 10.0f;

    };

    class MotorMonitor{

    public:
        MotorMonitor();

        MotorState update(const SensorData& sensor_data, bool motor_running);

        MotorState get_state()const;


    private:

        MotorState current_state;
        MotorThreshold thresholds;


    };

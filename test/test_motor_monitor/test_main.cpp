#include "unity.h"
#include "motor_monitor.h"
#include "simulated_sensor.h"
#include "motor_monitor_service.h"


void test_initial_state_is_stopped(){
    MotorMonitor motor_monitr;
    TEST_ASSERT_EQUAL(MotorState::STOPPED, motor_monitr.get_state());
}

void test_normal_readings_return_running(){
    MotorMonitor motor_monitr;

    SensorData motor_data ={45.0f, 2.5f, 5.0f};

    MotorState motor_state =  motor_monitr.update(motor_data, true);

    TEST_ASSERT_EQUAL( MotorState::RUNNING, motor_state);

}

void test_high_temperature_returns_warning(){
    MotorMonitor motor_monitr;

    SensorData motor_data ={75.0f, 2.5f, 5.0f};

    MotorState motor_state =  motor_monitr.update(motor_data, true);

    TEST_ASSERT_EQUAL( MotorState::WARNING, motor_state);
}

void test_high_temperature_returns_fault(){
    MotorMonitor motor_monitr;

    SensorData motor_data ={90.0f, 2.5f, 5.0f};

    MotorState motor_state =  motor_monitr.update(motor_data, true);

    TEST_ASSERT_EQUAL(MotorState::FAULT, motor_state );
}

void test_stopped_motor_returns_stopped(){
    MotorMonitor motor_monitr;

    SensorData motor_data ={90.0f, 2.5f, 5.0f};

    MotorState motor_state =  motor_monitr.update(motor_data, false);

    TEST_ASSERT_EQUAL(MotorState::STOPPED, motor_state );
}


void test_service_returns_running_for_normal_sensor(){
    SimulatedSensor sensor(SimulationScenario::NORMAL);
    MotorMonitor monitor;
    MotorMonitorService service(sensor, monitor);

    MotorState state = service.update(true);

    TEST_ASSERT_EQUAL(static_cast<int>(MotorState::RUNNING), static_cast<int>(state));

}


void test_service_returns_fault_for_overheating_sensor(){
    SimulatedSensor sensor(SimulationScenario::OVERHEATING);
    MotorMonitor monitor;
    MotorMonitorService service(sensor, monitor);

    MotorState state = service.update(true);

    TEST_ASSERT_EQUAL(static_cast<int>(MotorState::FAULT), static_cast<int>(state));
}

void test_service_returns_fault_for_high_vibration(){
    SimulatedSensor sensor(SimulationScenario::HIGH_VIBRATION);
    MotorMonitor monitor;
    MotorMonitorService service(sensor, monitor);

    MotorState state = service.update(true);

    TEST_ASSERT_EQUAL(static_cast<int>(MotorState::FAULT), static_cast<int>(state));
}

void test_service_returns_fault_for_overload(){
    SimulatedSensor sensor(SimulationScenario::OVERLOAD);
    MotorMonitor monitor;
    MotorMonitorService service(sensor, monitor);

    MotorState state = service.update(true);

    TEST_ASSERT_EQUAL(static_cast<int>(MotorState::FAULT), static_cast<int>(state));
}

void setUp(void)
{
}

void tearDown(void)
{
}

int main(int argc, char ** argv){
    UNITY_BEGIN();

    RUN_TEST(test_initial_state_is_stopped);
    RUN_TEST(test_normal_readings_return_running);
    RUN_TEST(test_high_temperature_returns_warning);
    RUN_TEST(test_high_temperature_returns_fault);
    RUN_TEST(test_stopped_motor_returns_stopped);
    RUN_TEST(test_service_returns_running_for_normal_sensor);
    RUN_TEST(test_service_returns_fault_for_overheating_sensor);
    RUN_TEST(test_service_returns_fault_for_high_vibration);
    RUN_TEST(test_service_returns_fault_for_overload);

    return UNITY_END();
}



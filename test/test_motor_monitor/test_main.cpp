#include <unity.h>
#include <motor_monitor.h>


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

    return UNITY_END();
}
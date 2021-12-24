
#ifndef DC_MOTOR_WIRING_PI_HPP_
#define DC_MOTOR_WIRING_PI_HPP_

#include <ros/ros.h>
#include <wiringPi.h>

#define RPI_MAX_PWM_VALUE 1023

class DCMotorWiringPi {
public:
    DCMotorWiringPi(int8_t a_channel_pin, int8_t b_channel_pin, int8_t enable_pin);
    void cw(uint16_t val);
    void ccw(uint16_t val);
    void stop();
private:
    int8_t _a_channel_pin;
    int8_t _b_channel_pin;
    int8_t _enable_pin;
    uint16_t protectOutput(uint16_t val);
};

DCMotorWiringPi::DCMotorWiringPi(int8_t a_channel_pin, int8_t b_channel_pin, int8_t enable_pin) {
    _a_channel_pin = a_channel_pin;
    _b_channel_pin = b_channel_pin;
    _enable_pin = enable_pin;
    if (wiringPiSetupGpio() < 0) {
        ROS_ERROR("DCMotor wiringPi error: GPIO setup error");
        throw std::runtime_error("");
    }
    ROS_INFO("DCMotor wiringPi: GPIO setup");
    pinMode(_a_channel_pin, OUTPUT);
    pinMode(_b_channel_pin, OUTPUT);
    pinMode(_enable_pin, PWM_OUTPUT);
    stop();
    ROS_INFO("DCMotor wiringPi: Motor setup");
}

void DCMotorWiringPi::stop() {
	pwmWrite(_enable_pin, 0);
	digitalWrite(_a_channel_pin, 0);
	digitalWrite(_b_channel_pin, 0);
}

void DCMotorWiringPi::cw(uint16_t val) {
	pwmWrite(_enable_pin, protectOutput(val));
	digitalWrite(_a_channel_pin, 1);
	digitalWrite(_b_channel_pin, 0);
}

void DCMotorWiringPi::ccw(uint16_t val) {
	pwmWrite(_enable_pin, protectOutput(val));
	digitalWrite(_a_channel_pin, 0);
	digitalWrite(_b_channel_pin, 1);;
}

uint16_t DCMotorWiringPi::protectOutput(uint16_t val) {
    return val > RPI_MAX_PWM_VALUE ? RPI_MAX_PWM_VALUE : val;
}

#endif // DC_MOTOR_WIRING_PI_HPP_

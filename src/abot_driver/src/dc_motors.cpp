
#include "dc_motor_wiring_pi.hpp"
#include <std_msgs/Float64.h>

#define MOTOR_1_PIN_A 4 // Wiring pi 7 = BCM 4
#define MOTOR_1_PIN_B 5 // Wiring pi 7 = BCM 4
#define MOTOR_1_PIN_E 18 // Wiring pi 1 = BCM 18
#define MOTOR_2_PIN_A 12 // Wiring pi 26 = BCM 12
#define MOTOR_2_PIN_B 6 // Wiring pi 26 = BCM 12
#define MOTOR_2_PIN_E 13 // Wiring pi 23 = BCM 13

DCMotorWiringPi left_dc_motor(MOTOR_1_PIN_A, MOTOR_1_PIN_B, MOTOR_1_PIN_E);
DCMotorWiringPi right_dc_motor(MOTOR_2_PIN_A, MOTOR_2_PIN_B, MOTOR_2_PIN_E);

void leftMotorCallback(const std_msgs::Float64& msg) {
	int16_t pwm = msg.data * 100;
	if (pwm > 0) {
		left_dc_motor.ccw(abs(pwm));
	} else if (pwm < 0) {
		left_dc_motor.cw(abs(pwm));
	} else if (pwm == 0) {
		left_dc_motor.stop();
	}
}

void rightMotorCallback(const std_msgs::Float64& msg) {
	int16_t pwm = msg.data * 100;
	if (pwm > 0) {
		right_dc_motor.ccw(abs(pwm));
	} else if (pwm < 0) {
		right_dc_motor.cw(abs(pwm));
	} else if (pwm == 0) {
		right_dc_motor.stop();
	}
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "dc_motors");
	ros::NodeHandle node;
	ros::Subscriber left_motor_target_vel_sub = node.subscribe("/abot/left_wheel/pwm", 1, &leftMotorCallback);
	ros::Subscriber right_motor_target_vel_sub = node.subscribe("/abot/right_wheel/pwm", 1, &rightMotorCallback);
	ros::spin();
	return 0;
}

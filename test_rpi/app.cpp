
#include <iostream>
#include <wiringPi.h>
#include <chrono>
#include <thread>

using namespace std;

int main(){
	constexpr uint8_t STEP_PIN = 20;  // Wiring pi 0 = BCM 17
	constexpr uint8_t DIR_PIN = 21;  // Wiring pi 2 = BCM 27

	wiringPiSetupGpio();	
	
	pinMode(STEP_PIN, OUTPUT);
	pinMode(DIR_PIN, OUTPUT);
	digitalWrite(STEP_PIN, 0);
	digitalWrite(DIR_PIN, 0);

	constexpr int STEP_COUNT = 2000;
	constexpr int PULSE_DURATION_US = 500;

	for (int i = 0; i < STEP_COUNT ; i++ ){
		digitalWrite(STEP_PIN, 1);
		std::this_thread::sleep_for(std::chrono::microseconds(PULSE_DURATION_US));
		digitalWrite(STEP_PIN, 0);
		std::this_thread::sleep_for(std::chrono::microseconds(PULSE_DURATION_US));
		//cout << "step: " << i << endl;
	}

	return 0;
}

//other commands

	//wiringPiSetupSys(); - for interrupts

//	wiringPiSetupGpio();	
//	pullUpDnControl(ENCODER_1_PIN_B, PUD_UP);
//	constexpr uint8_t ENCODER_1_PIN_B = 27;  // Wiring pi 2 = BCM 27
//		int val_A = digitalRead(ENCODER_1_PIN_B);		



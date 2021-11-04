
#include <iostream>
#include <wiringPi.h>

extern "C"{
	int read(){
		return digitalRead(17);
	}
}

int main(){
	constexpr uint8_t ENCODER_1_PIN_A = 17;  // Wiring pi 0 = BCM 17
	constexpr uint8_t ENCODER_1_PIN_B = 27;  // Wiring pi 2 = BCM 27
	constexpr uint8_t ENCODER_2_PIN_A = 24;  // Wiring pi 5 = BCM 24
	constexpr uint8_t ENCODER_2_PIN_B = 25;  // Wiring pi 6 = BCM 25
	
	//wiringPiSetupSys();
	wiringPiSetupGpio();	
	
	int prev = 0;
	while (true){
		int val_A = digitalRead(ENCODER_1_PIN_A);		
if (val_A != prev)		
std::cout << "val A " << val_A << "test"  << std::endl;
		prev = val_A;
	}	
	return 0;
}


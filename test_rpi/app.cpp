
#include <iostream>
#include <wiringPi.h>

int main(){
	constexpr uint8_t ENCODER_1_PIN_A = 17;  // Wiring pi 0 = BCM 17
	constexpr uint8_t ENCODER_1_PIN_B = 27;  // Wiring pi 2 = BCM 27
	constexpr uint8_t ENCODER_2_PIN_A = 24;  // Wiring pi 5 = BCM 24
	constexpr uint8_t ENCODER_2_PIN_B = 25;  // Wiring pi 6 = BCM 25

	while (true){
		uint8_t val_A = digitalRead(17);		
		std::cout << "val A " << val_A  << std::endl;
		
	}	
	return 0;
}

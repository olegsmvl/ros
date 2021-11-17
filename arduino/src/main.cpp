#include <Arduino.h>
#include <Servo.h>

Servo servo_yaw; 
Servo servo_pitch; 

void setup(){
    pinMode(13, OUTPUT);
    servo_yaw.attach(9); //привязываем привод к порту 10
    servo_pitch.attach(10); //привязываем привод к порту 10
}

void loop()
{
    while (true)
    {
        servo_yaw.write(60); //ставим вал под 0

        delay(2000); //ждем 2 секунды

        servo_yaw.write(120); //ставим вал под 180

        delay(2000); //ждем 2 секунды

        servo_pitch.write(60); //ставим вал под 0

        delay(2000); //ждем 2 секунды

        servo_pitch.write(120); //ставим вал под 180

        delay(2000); //ждем 2 секунды


        digitalWrite(13, LOW);
        delay(200);
        digitalWrite(13, HIGH);
        delay(200);
    }
}

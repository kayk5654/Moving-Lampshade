
#include <Servo.h>

Servo myservo;

// pins for dimming LEDs
int pwm1 = 2; //digitalWrite
int pwm2 = 4; //digitalWrite
int pwm3 = 5; //digitalWrite
int pwm4 = 6; //pwm
int pwm5 = 7; //pwm
int pwm6 = 12; //digitalWrite

//pins to control servo
int servoPin = 9;

void setup() {
  // initialize pins to control LEDs
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(pwm5, OUTPUT);
  pinMode(pwm6, OUTPUT);

  myservo.attach(servoPin);

  Serial.begin(115200);
}

void loop() {
  // control LEDs
  dimmingDigital(pwm1, 5000, 6000, 5000, 2000, millis());
  dimmingDigital(pwm2, 3000, 3000, 3000, 3000, millis());
  dimmingDigital(pwm3, 2000, 1000, 2000, 3000, millis());
  //analogWrite(pwm4, dimming(4000, 4000, 6000, 4000, millis()));
  dimmingDigital(pwm4, 4000, 4000, 6000, 4000, millis());
  //analogWrite(pwm5, dimming(3000, 3000, 4000, 5000, millis()));
  dimmingDigital(pwm5, 3000, 3000, 4000, 5000, millis());
  dimmingDigital(pwm6, 2000, 1000, 2000, 4000, millis());

  myservo.write(servoControl(4000, 3000, 4000, 2000, millis()));
  //myservo.write(servoControl(1000, 1000, 1000, 1000, millis()));

}

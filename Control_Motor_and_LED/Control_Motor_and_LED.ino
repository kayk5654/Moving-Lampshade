// print destination and currentplace. then draw a graph.
//and maybe print phase as well?

#include "faderControlClass.h"
#include "faderChoreography.h"

// pins for dimming LEDs
int pwm1 = 12; //digitalWrite
int pwm2 = 2; //digitalWrite
int pwm3 = 4; //digitalWrite
int pwm4 = 5; //pwm
int pwm5 = 6; //pwm
int pwm6 = 7; //digitalWrite

// pins to control motors
int motorPin1_1 = 9;
int motorPin1_2 = 10; 
int motorPin1_3 = A0;

int motorPin2_1 = 3;
int motorPin2_2 = 11;
int motorPin2_3 = A1;

// instances
faderChoreography faderControl1; //for inside

faderChoreography faderControl2; //for outside

void setup() {
  // initialize pins to control LEDs
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(pwm5, OUTPUT);
  pinMode(pwm6, OUTPUT);
  
  // initialize pins to control motor faders
  faderControl1.setup(motorPin1_1, motorPin1_2, motorPin1_3);
  faderControl2.setup(motorPin2_1, motorPin2_2, motorPin2_3);

  Serial.begin(115200);
}

void loop() {
  // control LEDs
  dimmingDigital(pwm1, 5000, 6000, 5000, 2000, millis());
  dimmingDigital(pwm2, 3000, 3000, 3000, 3000, millis());
  dimmingDigital(pwm3, 2000, 1000, 2000, 3000, millis());
  analogWrite(pwm4, dimming(4000, 4000, 6000, 4000, millis()));
  analogWrite(pwm5, dimming(3000, 3000, 4000, 5000, millis()));
  dimmingDigital(pwm6, 2000, 1000, 2000, 4000, millis());

  // control motors
  faderControl1.faderCycle(4000, 400, 3000, 4000, 0, 500, millis());
  faderControl2.faderCycle(3500, 900, 5000, 4000, 600, 2000, millis());

  //for test
  //faderControl1.faderCycle(2000, 800, 1000, 2000, 100, 1000, millis());
  //faderControl2.faderCycle(2000, 900, 1000, 2000, 400, 1000, millis());
  
}

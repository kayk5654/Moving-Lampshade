//dimming function

void dimmingDigital(int pin, float turnOn, float keepOn, float turnOff, float keepOff, unsigned long dimTime) {
  int val = dimming(turnOn, keepOn, turnOff, keepOff, dimTime);

  //output
  int i = map(val, 0, 255, 0, 1000);

  digitalWrite(pin, HIGH);
  delayMicroseconds(i);
  digitalWrite(pin, LOW);
  delayMicroseconds(1000 - i);

}

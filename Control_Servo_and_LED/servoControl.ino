

int servoControl(float turnOn, float keepOn, float turnOff, float keepOff, unsigned long dimTime){
  float cyclePeriod = turnOn + keepOn + turnOff + keepOff;
  float phase = float(dimTime % long(cyclePeriod));

  float turnOnEnd = turnOn;
  float keepOnEnd = turnOnEnd + keepOn;
  float turnOffEnd = keepOnEnd + turnOff;
  int val;

  if (phase < turnOnEnd) {
    val = (long(phase) % long(turnOn)) * 120 / turnOn;
  } else if (phase >= turnOnEnd && phase < keepOnEnd) {
    val = 120;
  } else if (phase >= keepOnEnd && phase < turnOffEnd) {
    val = (long(phase) % long(turnOffEnd) - keepOnEnd) * -120 / turnOff + 120;
  } else if (phase >= turnOffEnd) {
    val = 0;
  }

  return val;
}

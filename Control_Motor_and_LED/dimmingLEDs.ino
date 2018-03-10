//dimming function

int dimming(float turnOn, float keepOn, float turnOff, float keepOff, unsigned long dimTime){
  float cyclePeriod = turnOn + keepOn + turnOff + keepOff;
  float phase = float(dimTime % long(cyclePeriod));

  float turnOnEnd = turnOn;
  float keepOnEnd = turnOnEnd + keepOn;
  float turnOffEnd = keepOnEnd + turnOff;
  int val;

  if (phase < turnOnEnd) {
    val = (long(phase) % long(turnOn)) * 255 / turnOn;
  } else if (phase >= turnOnEnd && phase < keepOnEnd) {
    val = 255;
  } else if (phase >= keepOnEnd && phase < turnOffEnd) {
    val = (long(phase) % long(turnOffEnd) - keepOnEnd) * -255 / turnOff + 255;
  } else if (phase >= turnOffEnd) {
    val = 0;
  }

  return val;
}

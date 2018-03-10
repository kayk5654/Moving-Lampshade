//
//  faderChoreography.cpp
//  
//
//  this knows choreography, but doesn't know pins.
//  it includes faderControlClass and give destination and time
//  search with "reference to an object c++"

#include "faderChoreography.h"
#include "Arduino.h"


faderChoreography::faderChoreography() {

}

void faderChoreography::setup(int _controlPin1, int _controlPin2, int _positionDetectPin) {
    
    faderControl.setup(_controlPin1, _controlPin2, _positionDetectPin);

}

//sets the cycle of movement
void faderChoreography::faderCycle(float moveForward, int position1, float interval1, float moveBackward, int position2, float interval2, unsigned long faderTime) {
    
    // define period of cycle
    float cyclePeriod = moveForward + interval1 + moveBackward + interval2;
    float phase = float(faderTime % long(cyclePeriod));
    
    float moveForwardEnd = moveForward;
    float interval1End = moveForwardEnd + interval1;
    float moveBackwardEnd = interval1End + moveBackward;

    int Destination;
    int initialPosition = analogRead(faderControl.positionDetectPin);
    
    // define movement
    
    if (phase < moveForwardEnd) {
        Destination = (long(phase) % long(moveForward)) * (position1 - initialPosition) / moveForward + initialPosition;
        faderControl.moveFader(Destination);
    } else if (phase >= moveForwardEnd && phase < interval1End) {
        Destination = position1;
        faderControl.moveFader(Destination);
    } else if (phase >= interval1End && phase < moveBackwardEnd) {
        Destination = (long(phase) % long(moveBackwardEnd) - interval1End) * (position2 - position1) / moveBackward + position1;
        faderControl.moveFader(Destination);
    } else if (phase >= moveBackwardEnd) {
        Destination = position2;
        faderControl.moveFader(Destination);
    }
}

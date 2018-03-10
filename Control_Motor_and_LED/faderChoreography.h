//
//  faderChoreography.h
//  
//
// 
//
//

#ifndef ____faderChoreography__
#define ____faderChoreography__

#include <stdio.h>
#include "Arduino.h"
#include "faderControlClass.h"

class faderChoreography {
    public:
        faderControlClass faderControl;
        faderChoreography();
        void setup(int _controlPin1, int _controlPin2, int _positionDetectPin);
        void faderCycle(float moveForward, int position1, float interval1, float moveBackword, int position2, float interval2, unsigned long faderTime);
};

#endif /* defined(____faderChoreography__) */

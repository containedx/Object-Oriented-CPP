//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_ACCELERATION_H
#define INC_06_OBSERVER_PATTERN_ACCELERATION_H

#include "Observer.h"

class Acceleration: public Observer {

private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;

public:
    float get()
    {
        float x = thirdValue - secondValue;
        x -= (secondValue - firstValue);

        return x;
    }

    void notify(float value) override
    {
        if(!hasFirstValue) //pierwsze wywolanie
        {
            firstValue = value;
            hasFirstValue = true;
        }
        else if(!hasSecondValue)
        {
            secondValue = value;
            hasSecondValue = true;
        }
        else if(!hasThirdValue)
        {
            thirdValue = value;
            hasThirdValue = true;
        }
        else
        {
            firstValue = secondValue;
            secondValue = thirdValue;
            thirdValue = value;
        }
    }

};


#endif //INC_06_OBSERVER_PATTERN_ACCELERATION_H

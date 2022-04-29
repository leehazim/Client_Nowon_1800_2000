#pragma once
#include "Human.h"
class WHuman :
    public Human {
public:
    void GoToTravle();
    // 
    void Grow();
    void Breath();
    virtual void Dothing();
    virtual void Print();
};


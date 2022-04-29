#pragma once
#include "Human.h"
class BHuman :
    public Human {
public:
    void GotoGym();
    void Breath();
    void Grow();
    virtual void Dothing();
    virtual void Print();
};


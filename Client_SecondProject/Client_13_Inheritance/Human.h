#pragma once
#include "Creature.h"
#include "TDArray.h"
#include "ITwoLeggedWalker.h"
#include <string>
class Human :
    public Creature, public ITwoLeggedWalker {
public:
    TDArray<std::string> clothes;

public:
    void WearCloth(std::string cloth);
    void PrintAllClothes();
    virtual void Dothing();
    virtual void Print();
    virtual void Grow();
    virtual void Walk();
};
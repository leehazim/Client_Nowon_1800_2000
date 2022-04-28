#pragma once
#include "Creature.h"
#include "TDArray.h"
#include <string>
class Human :
    public Creature {
public:
    TDArray<std::string> clothes;

public:
    void WearCloth(std::string cloth);
    void PrintAllClothes();
};
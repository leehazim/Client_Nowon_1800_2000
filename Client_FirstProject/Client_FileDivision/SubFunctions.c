#include"SubFunctions.h"
extern opCount;

int subInt(int a, int b) { opCount++; return a - b; }
double subDouble(double a, double b) { opCount++; return a - b; }
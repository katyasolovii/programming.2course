// ration.h - Header for Rational type
#ifndef RATION_H
#define RATION_H
#include <stdbool.h>

typedef struct Ration {
    int num;
    unsigned dem;
} Ration;

Ration Ration_add(Ration x, Ration y); 
Ration Ration_mult(Ration x, Ration y);
bool bool_greater(Ration x, Ration y);
void reduce(Ration* x);
void output(Ration x);
int input(Ration* x);
#endif

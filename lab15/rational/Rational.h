#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

class Rational{
private: 
    int nom;
    unsigned denom;
    void reduce();
    static unsigned gcd(unsigned x, unsigned y);

public: 
    Rational();
    Rational(int x, unsigned y);
    void show();
    int input();
    int setNom(int x){
        nom = x;
        return 0;
    }
    int setDenom(unsigned y){
        if (y != 0){
            denom = y;
            return 0;
        }
        return -1;
    }
    Rational add(const Rational &x);
    Rational mult(const Rational &y);
    bool less(const Rational &x){
        return (nom * x.denom < denom * x.nom);
    }
    double compare(double z){
        return fabs(z - (nom + 0.)/ denom);
    }
};

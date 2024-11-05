#include "Rational.h"
#include <iostream>

Rational minRational(Rational *arr, int n){
    Rational minRat;
    minRat = arr[0];
    for (int i=1; i < n; i++){
        if (arr[i].less(minRat)){
            minRat = arr[i];
        }
    }
    return minRat;
}

Rational Grehory(double eps){
    Rational s;
    int sign = -1;
    for (int i=2; eps * i * i < 1; i++){
        Rational tmp;
        tmp.setNom(sign);
        sign = -sign;
        tmp.setDenom(i * i);
        s = s.add(tmp);
    }
    return s;
}

int main() {
    Rational r1(3, 4);
    Rational r2(5, 6);
    
    r1.show();
    r2.show();

    Rational r3 = r1.add(r2);; 
    r3.show();

    Rational r4 = r1.mult(r2);
    r4.show();

    return 0;
}
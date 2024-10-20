// Ration_test.c
#include <stdio.h>
#include "ration.h"


int main(){
    Ration a, b, c, m, r;
    input(&a);
    input(&b);
    c = Ration_add(a, b);
    m = Ration_mult(a, b);
    reduce(&c);
    printf("The sum: ");
    output(c);
    printf("The product: ");
    output(m);
    if (bool_greater(a, b)) {
        printf("Fraction a is greater than fraction b. \n");
    } else {
        printf("Fraction a is not greater than fraction b. \n");
    }    
    printf("Irreducible form of the rational number: ");
    reduce(&c);
    output(c);
}

#include <stdbool.h>
#include <stdio.h>
#include "ration.h"

void output(Ration x){
    printf("%d / %u \n", x.num , x.dem);
}

int input(Ration *x){
    printf("x/y = ");
    scanf("%d", &x->num);
    scanf("%u", &x->dem);
    return x->num != 0;
}

Ration Ration_add(Ration x, Ration y){
    Ration z;
    z.num = (int)(x.num * y.dem + y.num * x.dem);
    z.dem = x.dem * y.dem;
    return z;
}

Ration Ration_mult(Ration x, Ration y){
    Ration z;
    z.num = (int)(x.num * y.num);
    z.dem = x.dem * y.dem;
    return z;
}

unsigned gcd(unsigned n, unsigned m){
    while (m != 0) {
        unsigned temp = m;
        m = n % m;
        n = temp;
    }
    return n;
}

bool bool_greater(Ration x, Ration y) {
    return (x.num * y.dem > y.num * x.dem);
}

void reduce(Ration *x) {
    unsigned g = gcd(x->num, x->dem); 
    x->num /= g;
    x->dem /= g;
    if (x->dem < 0) {
        x->num = -x->num;
        x->dem = -x->dem;
    }
}

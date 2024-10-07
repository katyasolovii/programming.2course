#include <stdio.h>
#include <math.h>


void task16m(){

    double eps;
    double s_k, x, a_k;

    printf("x = ");
    scanf("%lf", &x);
    
    if (fabs(x) >= 1) {
        printf("x must be less than 1. \n");
        return;
    }

    do {
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    a_k = x;
    s_k = a_k;
    for (int i=2; fabs(a_k) >= eps; i++){
        a_k *= ((2.0 * i - 1) * x * x) / (2.0 * i * (2.0 * i + 1));
        s_k += a_k;
    }
    printf("y = %.10lf , math arcsin(%lf) = %.10lf\n", s_k, x, asin(x));

}

int main(){

    task16m();

}
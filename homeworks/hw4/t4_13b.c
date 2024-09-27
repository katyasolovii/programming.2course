#include <stdio.h>
#include <math.h>

void task13b(){

    unsigned int n;
    double res=1, x;

    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);

    for (int i=1; i <= n; i++){
        res += pow(sin(x), i);
    }
    printf("Result: %lf \n", res);

}

int main(){

    task13b();

}
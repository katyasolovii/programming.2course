#include <stdio.h>
#include <math.h>


int main() {

    double x;
    printf("Enter x:");
    scanf("%lf", &x);

    double cos_x = cos(x);
    printf("cos(x) = %.3lf \n", cos_x);

}
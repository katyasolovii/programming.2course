#include <stdio.h>
#include <math.h>

int main() {

    double x; 
    double y;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);

    double diff = x - y;
    double pr = x * y;

    printf("Різниця: %.2lf \n", diff);
    printf("Добуток: %.2lf \n", pr);
}
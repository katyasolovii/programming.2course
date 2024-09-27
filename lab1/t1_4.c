#include <stdio.h>
#include <math.h>

int main() {

    double m1; // %lf
    double m2;
    double r1;
    const double g = 6.673E-11;
    // const double g = 6.673 * pow(10, -11);

    printf("Enter m1: ");
    scanf("%lf", &m1);
    printf("Enter m2: ");
    scanf("%lf", &m2);
    printf("Enter r1: ");
    scanf("%lf", &r1);

    double f = g * ((m1 * m2) / pow(r1, 2));
    printf("Result: %le \n", f); // %le - експоненціальна форма запису

}
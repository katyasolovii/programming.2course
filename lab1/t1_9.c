#include <stdio.h>

int main() {

    double x, y, arith, harm;

    printf("Enter x and y: ");
    scanf("%lf %lf", &x, &y);

    arith = (x + y) / 2;

    if (x != 0 && y != 0) {
        harm = 2 / ((1 / x) + (1 / y));
        printf("Harmonic mean: %.3lf \n", harm);
        printf("Harmonic mean (scientific notation): %le \n", harm);

    }
    else {
        printf("Devision be zero. \n");
    }

    printf("Arithmetic mean: %.3lf \n", arith);
    printf("Arithmetic mean (scientific notation): %le \n", arith);

}

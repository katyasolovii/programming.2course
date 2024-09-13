#include <stdio.h>
#include <math.h>

int main() {

    long double x, x8;

    printf("Enter x (0 < x > 10_000): ");
    scanf("%Lf", &x);

    if (x > 0 && x < 10000) {
        x8 = pow(x, 8);
        printf("x^8 with 20 symbols: %.20Lf \n", x8);
        printf("x^8 with 4 symbols: %.4Lf \n", x8);
    }
    else{
        printf("The number is out of bounds. \n");
    }

}
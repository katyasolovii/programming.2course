#include <stdio.h>
#include <math.h>

int main() {

    double x, lg;

    printf("Enter x: ");
    scanf("%lf", &x);

    // log(n) , n > 0
    if (x > 0) {
        lg = log10(x);
        printf("Result: %.3lf \n", lg);
    }
    else {
        printf("The number must be > 0 or = 0. \n");
    }

}
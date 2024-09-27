#include <stdio.h>
#include <math.h>


int main() {
    
    double a, b, c;
    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);
    if (a > 0 && b > 0) {
        c = sqrt(pow(a, 2) + pow(b, 2));
        printf("Hypotenuse c = %.3lf \n", c);
    }
    else{
        printf("Sides can't be negative. \n");
    }
    
}
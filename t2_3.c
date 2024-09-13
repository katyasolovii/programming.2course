#include <stdio.h>
#include <math.h>


double area(double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {

    double a, b, c;

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    if (a < (b + c) && b < (a + c) && c < (a + b)) {
        double result = area(a, b, c);
        printf("Area of triangle = %.3lf \n", result);
    }
    else{
        printf("Such a triangle doesn't exist. \n");
    }

}
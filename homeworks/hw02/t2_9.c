#include <stdio.h>
#include <math.h>


double area(double A, double B, double C, double r) {
    double p = (A + B + C) / 2;
    return p * r;
}

double side(double x, double r) {
    return r * (1 / tan(x / 2));
}

int main() {

    double a, b, c, r;
    double A, B, C;

    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    printf("r = ");
    scanf("%lf", &r);

    A = side(a, r) + side(c, r);
    B = side(b, r) + side(a, r);
    C = side(c, r) + side(b, r);

    printf("Area of triangle = %.3lf \n", area(A, B, C, r));

}
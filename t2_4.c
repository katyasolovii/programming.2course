#include <stdio.h>
#include <math.h>


double task4d(double x) {
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x2 * x2;
    return ((((16 * x + 8) * x + 4) * x + 2) * x + 1);
}

double task4a(double x) {
    double x2 = x * x;
    double t = x2 + 1;
    return t * t;
}

int main() {

    double x, result_a, result_d;

    printf("x = ");
    scanf("%lf", &x);

    result_a = task4d(x);
    printf("Result: %.3lf \n", result_a);

    result_d = task4a(x);
    printf("Result: %.3lf \n", result_d);

}

#include <stdio.h>

int main() {

    double x;

    printf("x = "); 
    scanf("%lf", &x);

    /* 5(a) */

    double x2 = x * x;
    double x4 = x2 *x2;
    printf("x^2 : %lf \n", x4);

    /* 5(б) */

    // double x2 = x * x;
    // double x4 = x2 * x2;
    double x6 = x4 * x4;
    printf("x^6 : %lf \n", x6);

    /* 5(в) */

    // double x2 = x * x;
    // double x4 = x2 * x2;
    double x3 = x2 * x;
    double x9 = x6 * x3;
    printf("x^9 : %lf \n", x9);

    /* 5(г) */

    // double x2 = x * x;
    // double x4 = x2 * x2;
    // double x6 = x4 * x2;
    // double x9 = x6 * x3;
    double x15 = x9 * x6;
    printf("x^15 : %lf \n", x15);

    /* 5(д) */

    // double x2 = x * x;
    // double x4 = x2 * x2;
    double x8 = x4 * x4;
    double x16 = x8 * x8;
    double x24 = x16 * x8;
    double x28 = x24 * x4;
    printf("x^28: %lf\n", x28);

    /* 5(е) */

    // double x2 = x * x;
    // double x4 = x2 * x2;
    // double x8 = x4 * x4;
    // double x16 = x8 * x8;
    double x32 = x16 * x16;
    double x64 = x32 * x32;
    printf("x^64: %lf\n", x64);

}
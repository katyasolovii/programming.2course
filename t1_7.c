#include <stdio.h>
#include <math.h>

int main() {

    double x;
    int ceil_x, floor_x, round_x, z;
    double fraction_part;

    printf("x = ");
    scanf("%lf", &x);

    ceil_x = (int)ceil(x); // округлення зверху
    floor_x = (int)floor(x); // округлення знизу
    round_x = (int)round(x); 
    z = (int)x; // Ціла частина x
    fraction_part = fabs(x - z); // дробова частина, fabs - модуль (abs)

    printf("ceil: %d\n", ceil_x);
    printf("floor: %d\n", floor_x);
    printf("round: %d\n", round_x);
    printf("int part: %d\n", z);
    printf("fraction part: %.2lf\n", fraction_part);

}

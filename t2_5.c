#include <stdio.h>
#include <math.h>


double Rosenbrock2d(double x, double y) {
    double t = pow(x, 2) - pow(y, 2);
    return 100 * pow(t, 2) + pow((x - 1), 2);
}

int main() {

    printf("%.3lf \n", Rosenbrock2d(0, 1));
    printf("%.3lf \n", Rosenbrock2d(2, 4));
    printf("%.3lf \n", Rosenbrock2d(1, 0));

}
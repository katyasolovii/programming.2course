#include <stdio.h>
#include <math.h>


double bent(double x) {
    return ((sqrt(pow(x, 2) + 1) - 1) / 2) + x;
}

double bent_derivative(double x) {
    return x / 2 * sqrt(pow(x, 2) + 1) + 1;
}

int main() {
    
    printf("f(3) = %.3lf \n", bent(3));
    printf("f'(4) = %.3lf \n", bent_derivative(4));
    printf("f(0) = %.3lf \n", bent(0));
    printf("f'(6) = %.3lf \n", bent_derivative(6));
    printf("f(0) = %.3lf \n", bent(45));
    printf("f'(6) = %.3lf \n", bent_derivative(3.2));

}
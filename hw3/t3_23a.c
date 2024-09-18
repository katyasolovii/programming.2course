#include <stdio.h>
#include <math.h>
#include <float.h>


double onestep(double x){
    const double eps = 1e-9;
    if (x > 0 || fabs(x) < eps){
        return 1;
    }
    else{
        return 0;
    }
}

double derivative_onestep(double x){
    const double eps = 1e-9;
    if (fabs(x) < eps) {
        return DBL_MAX;
    }
    else{
        return 0;
    }
}

int main(){

    double x;
    
    printf("x = ");
    scanf("%lf", &x);

    printf("onestep(%lf) = %lf \n", x, onestep(x));
    printf("f'(%lf) = %lf \n", x, derivative_onestep(x));

}
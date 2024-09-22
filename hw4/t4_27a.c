#include <stdio.h>
#include <math.h>
#include <float.h>

void task27a(){

    const double esp = DBL_EPSILON;
    double sum=0, res, p;
    int k=1;

    do{
        p = 1 / pow(k, 2);
        sum += p;
        k++;
    } while (p > esp);

    res = sqrt(6 * sum);
    printf("Result: %lf \n", sum);

}

int main(){

    task27a();

}
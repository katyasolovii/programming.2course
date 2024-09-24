#include <stdio.h>
#include <math.h>

void task9b(){

    double v_0=0, v_1=0, v_2=3.0/2.0;
    double v_i;
    int n;

    printf("n = ");
    scanf("%d", &n);

    if (n == 0){
        printf("v(%d) = %lf \n", n, v_0);
    }
    else if (n == 1)
    {
        printf("v(%d) = %lf \n", n, v_1);
    }
    else if (n == 2)
    {
        printf("v(%d) = %lf \n", n, v_2);
    }
    else{
        for (int i=3; i <= n; i++){
        v_i = ((i - 2) / (pow((i - 3), 2) + 1)) * v_2 - v_1 * v_0 + 1.0;
        v_0 = v_1;
        v_1 = v_2;
        v_2 = v_i;
        }
        printf("Result: %lf \n", v_i);
    }

}

int main(){

    task9b();

}
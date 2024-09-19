#include <stdio.h>
#include <math.h>


void task13_b(double a, double b, double c){
    const double eps= 1e-9;
    if (fabs(a - b) > eps){
        double x1 = (-b - c) / (a - b);
        double x2 = (b - c) / (a - b);
        double y1 = 1 - x1;
        double y2 = -1 - x2;
        printf("x1 = %lf, y1 = %lf \n", x1, y1);
        printf("x2 = %lf, y2 = %lf \n", x2, y2);
    }
    else{
        printf("There are no solutions. \n");
    }
    
}

int main(){

    double a, b, c;

    printf("a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    task13_b(a, b, c);

}

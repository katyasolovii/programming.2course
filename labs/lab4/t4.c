#include <stdio.h>
#include <math.h>
#include <float.h>

void task1(){

    double x, y;
    int n;

    printf("x = ");
    scanf("%lf", &x);

    printf("n = ");
    scanf("%d", &n);

    y = x;
    for (int i=0; i < n; i++){
        y = sin(y);
    }

    printf("Result: %lf \n", y);

}

void task2(){

    unsigned int n;

    printf("n = ");
    scanf("%u", &n);

    for (int i=1; i < n; i++){
        printf("%d * ", i);
    }
    printf("%u \n", n);

    unsigned int m;

    printf("m = ");
    scanf("%u", &m);

    for (int i=m; i > 1; i--){
        printf("%u * ", i);
    }

    printf("%u \n", 1);

}

void task3(){

    int n = 3, x = 2;
    int y = 1;

    for (int i=1; i < n + 1; i++){
        y += pow(x, i);
    }

    printf("y = %d \n", y);

}

void task4(){

    double x, y;
    unsigned int n, power=1;
    printf("x, n: ");
    scanf("%lf %d", &x, &n);

    y = 0;
    for (int i=1; i <= n; i++){
        power *= x;
        y += i * power;
    }

    printf("y = %lf \n", y);

}

void task5(){

    unsigned int n, y=1;

    printf("n = ");
    scanf("%u", &n);

    if (n % 2 == 0){
        for (int i=2; i <= n; i+=2){
            y *= i;
        }
        printf("y = n!! = %u \n", y);
    }
    else{
        for (int i=1; i <= n; i+=2){
            y *= i;
        }
        printf("y = n!! = %u \n", y);
    }

}

void task6_a(){

    unsigned int n;
    double y;

    printf("n = ");
    scanf("%u", &n);

    y = sqrt(2);

    for (int i=1; i < n; i++){
        y += sqrt(y);
    }

    printf("y = %lf \n", y);

}

void task6_b(){

    unsigned int n;
    double y;

    printf("n = ");
    scanf("%u", &n);

    y = sqrt(3 * (n - 1) + sqrt(3*n));;

    for (int i=1; i < n; i++){
        y += sqrt(y);
    }

    printf("y = %lf \n", y);

}

void task7(){

    unsigned int n;
    double x, y=1.0, power=1.0, fact=1.0;

    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);

    for (int i = 1; i <= n; i++) {
        power *= x; 
        fact *= i; 
        y += power / fact;
    }
    printf("y = %lf \n", y);

}

void task8(){

    unsigned int m, k=0, res=1;

    printf("m >=1: ");
    scanf("%u", &m);

    while (res <= m){
        k++;
        res = pow(4, k);
    }
    printf("max(k) = %u \n", k - 1);

}

void task9(){

    unsigned int n, r=0, res=1;

    printf("n = ");
    scanf("%u", &n);

    while (res <= n){
        r++;
        res = pow(2, r);
    }
    printf("min = %u \n", res);

}

void task10(){

    float a = 1.0f;
    float eps = DBL_EPSILON;

    while (1.0f + a != 1.0f) {
        a /= 2.0f; 
    }
    printf("Result: %.5e\n", 2 * a); 
    printf("Machine epsilon for type float: %.5e \n", eps);

}

void task11(){

    int count = 0, i = 0;
    double sum = 0, product = 1, num;

    do {
        printf("a[%d] = ", i++);
        scanf("%lf", &num);
        if (num > DBL_EPSILON){
            sum += num;
            product *= num;
            count++;
        }
    } while (fabs(num) > DBL_EPSILON);

    double average = sum / count;
    double geometric_mean = pow(product, 1.0 / count);

    printf("The sum: %.2lf \n", sum);
    printf("Arithmetic average: %.2lf \n", average);
    printf("Geometric mean: %.2lf \n", geometric_mean);

}


void task12(){
    
    unsigned int n;
    double subfact = 1;

    printf("n < 25 = ");
    scanf("%u", &n);

    for (int i=1; i <= n; i++){
        subfact = subfact * i + pow(-1, i);
    }
    printf("!%u = %.0f\n", n, subfact);

}

int main(){

    int task;

    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task1();
    }
    else if (task == 2)
    {
        task2();
    }
    else if (task == 3)
    {
        task3();
    }
    else if (task == 4)
    {
        task4();
    }
    else if (task == 5)
    {
        task5();
    }
    else if (task == 61)
    {
        task6_a();
    }
    else if (task == 62)
    {
        task6_b();
    }
    else if (task == 7)
    {
        task7();
    }
    else if (task == 8)
    {
        task8();
    }
    else if (task == 9)
    {
        task9();
    }
    else if (task == 10)
    {
        task10();
    }
    else if (task == 11)
    {
        task11();
    }
    else if (task == 12)
    {
        task12();
    }

}
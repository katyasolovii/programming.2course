#include <stdio.h>
#include <math.h>


void task1(){

    double a, sum = 1.0;
    int n;

    printf("a = ");
    scanf("%lf", &a);

    while (sum <= a){
        n++;
        sum += 1.0 / n;
    }

    printf("The sum: %lf \n", sum);
    printf("n = %d \n", n);

}

void task2() {

    unsigned long long F0, F1, F;
    int i, n;
    F0 = 0;
    F1 = 1;
    printf("n = ");
    scanf("%d", &n);

    for (int i=2; i <= n; i++){
        F = F0 + F1;
        F0= F1;
        F1 = F;
    }
    printf("F(%d) = %llu \n", n , F);

}

void task2_b(){
    
    unsigned long long F0, F1, F;
    int a, i;

    F0 = 0;
    F1 = 1;

    printf("a = ");
    scanf("%d", &a);

    for (int i=2; i > 0; i++){
        F = F0 + F1;
        F0= F1;
        F1 = F;
        if (F > a){
            printf("The index of min number: %d \n", i);
            break;
        }
    }

}

void task3(){
    
    unsigned a0, steps, max_steps, max_num;

    for (int n=1; n < 1000; n++){
        a0 = n;
        steps = 0;
        
        while (a0 != 1){
            if (a0 % 2 ==0){
                a0 = a0 / 2;
            }
            else{
                a0 = 3 * a0 + 1;
            }
            steps++;
        }
        if (steps > max_steps){
            max_steps = steps;
            max_num = n;
        }
    }
    printf("Number with max steps: %u ==> steps = %u \n", max_num, max_steps);

}

void task4_a(){

    unsigned int n;
    double p=1.0, fact=1.0;
    
    printf("n = ");
    scanf("%u", &n);

    for (int i=1; i <= n; i++){
        fact *= i;
        p *= (1 + 1.0 / fact);
    }
    printf("P(%u) = %lf \n", n, p);

}

void task4_b(){

    unsigned int n;
    double p=1.0, ak;
    
    printf("n = ");
    scanf("%u", &n);

    for (int i=1; i <= n; i++){
        ak = (pow((-1), i + 1) * pow(i, 2)) / pow(2, i);
        p *= (1 + ak);

    }
    printf("P(%u) = %lf \n", n, p);

}

void task5(){

    int x1=-99, x2=-99, x3=-99, xn, n;

    printf("n = ");
    scanf("%d", &n);

    while (1){
        xn = x3 + x1 + 100;
        if (xn > 0) break;
        x1 = x2;
        x2 = x3;
        x3 = xn;
        n++;
    }
    printf("x(%d) = %d \n", n, xn);

}

void task6_c(){

    unsigned int n, index;
    double res=0.0;

    printf("n = ");
    scanf("%u", &n);
    index = 2 * n;

    if (n == 0){
        printf("x(%u) = 1.0 \n", index);
    }
    else{
        for (int i=n; i > 0; i--){
            if (i % 2 == 0){
                res = 1.0 / (2 + res);
            }
            else{
                res = 1.0 / (1 + res);
            }
        }
        printf("x(%u) = %lf \n", index, res+1.0);
    }

}

void task7(){

    double a1=0, a2=1, ak, b1=1, b2=0, bk;
    double sn=0.0;
    int n;

    printf("n = ");
    scanf("%d", &n);

    for (int i=1; i<= n; i++){
        if (i == 1){
            ak = 0;
            bk = 1;
        }
        else if (i == 2)
        {
            ak = 1;
            bk = 0; 
        }
        else{
            bk = b1 + a1;
            ak = (a2 / i) + (a1 * bk);
            a1 = a2;
            a2 = ak;
            b1 = b2;
            b2 = bk;
        }
        sn += pow(2, i) / (ak + bk);
    }
    printf("S(%d): %lf \n", n, sn);

}

void task8_a(){

    double x, eps, y, t;
    int i;

    printf("x = ");
    scanf("%lf", &x);
    
    do{
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    t = 1;
    y = t;
    i = 1;
    while (t > eps){
        t *= (x / i);
        y += t;
        i++;
    }
    printf("y = %lf, math e^x = %lf, eps = %lf\n", y, exp(x), eps);

}

void task8_b(){

    double x, eps, y, t;
    int i;

    printf("x = ");
    scanf("%lf", &x);
    
    do{
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    t = x;
    y = t;
    i = 1;
    while (fabs(t) > eps){
        t *= (-pow(x, 2)) / (i * (2 * i + 1));
        y += t;
        i++;
    }
    printf("y = %lf, eps = %lf \n", y, eps);

}

int main(){

    unsigned int task;

    printf("task = ");
    scanf("%u", &task);

    if (task == 1){
        task1();
    }
    else if (task == 2)
    {
        task2();
        task2_b();
    }
    else if (task == 3)
    {
        task3();
    }
    else if (task == 4)
    {
        task4_a();
        task4_b();
    }
    else if (task == 5)
    {
        task5();
    }
    else if (task == 6)
    {
        task6_c();
    }
    else if (task == 7)
    {
        task7();
    }
    else if (task == 8)
    {
        task8_a();
        task8_b();
    }

}
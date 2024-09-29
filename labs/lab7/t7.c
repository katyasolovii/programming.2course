#include <stdio.h>
#include <math.h>
// #define SIZE 5 - визначає розмір масиву, створення макросу

void task1(){

    int mas[] = {1, 2, 3, 4, 5};
    double a;

    printf("a = ");
    scanf("%lf", &a);

    int cnt=0;
    for (int i=0; i < 5; i++){
        if (mas[i] < a){
            cnt++;
        }
    }
    printf("k = %d \n", cnt);

}

void task2(){

    int mas[] = {5, 112, 4, 3};

    for (int i=3; i >= 0; i--){
        printf("%d ", mas[i]);
    }
    printf("\n");
    
}

double summ(double arr[], int SIZE){

    double sum=0.0;

    for (int i=0; i < SIZE; i++){
        if (arr[i] > M_E){
            sum += arr[i];
        }
    }
    return sum;

}

void task3(){

    int SIZE = 10;
    double a[SIZE];

    for (int k=0; k < SIZE; k++){
        printf("a[%d] = ", k);
        scanf("%lf", &a);
    }
    printf("%lf \n", summ(a, SIZE));

}

int input_arr(int a[], int SIZE){

    for (int i=0; i < SIZE; i++){
            printf("a[%d] = ", i);
            int arr = scanf("%d", &a[i]);
            if (arr != 1) return i;
        }
    return SIZE;
    
}

int max(int a[], int SIZE){

    int max=a[0];
    for (int i=1; i < SIZE; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;

}

int min(int a[], int SIZE){

    int min=a[0];
    for (int i=1; i < SIZE; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    return min;
    
}

void task4(){

    int SIZE = 5;
    int a[SIZE];
    int m = input_arr(a, SIZE);

    if (m != SIZE){
        printf("ERROR! \n");
        return;
    }

    printf("max = %d \n", max(a, SIZE));
    printf("min = %d \n", min(a, SIZE));

}

int input_a(int a[], int SIZE){

    for(int i=0; i < SIZE; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        if (a[i] == 0) return i;
    }
    return SIZE;

}

void odd_even(int a[], int n){

    int odd=0, even=0;
    for (int i=0; i < n; i++){
        if (a[i] % 2 == 0 && a[i] != 0){
            odd++;
        }
        else{
            even++;
        }
    }
    printf("Even numbers: %d \n", even);
    printf("Odd numbers: %d \n", odd);

}

void task5(){

    int SIZE = 50;
    int arr[SIZE];
    int m = input_a(arr, SIZE);
    odd_even(arr, m);

}

int input_vector(double v[], int n){

    for (int i=0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%lf", &v[i]);
    }

}

void output_vector(const double v[], int n){
    
    for (int i=0; i < n; i++){
        printf("%lf ", v[i]);
    }
    printf("\n");

}

void add_vector(const double v1[], const double v2[], double v3[], int n){

    for (int i=0; i < n; i ++){
        v3[i] = v1[i] + v2[i];
    }

}

double mult_vector(const double v1[], const double v2[], int n){

    double product=0.0;

    for (int i=0; i < n; i++){
        product += v1[i] * v2[i];
    }
    return product;

}

void task6(){

    int n;
    printf("n < 20 = ");
    scanf("%d", &n);

    if (n > 20){
        printf("n must be less than 20 \n");
        return;
    }

    double v1[n], v2[n], v3[n];

    input_vector(v1, n);
    input_vector(v2, n);
    output_vector(v1, n);
    output_vector(v2, n);

    add_vector(v1, v2, v3, n);
    printf("The sum of vertors = ");
    output_vector(v3, n);

    printf("Scalar product = %lf \n", mult_vector(v1, v2, n));

}

int main(){

    int task;
    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task1();
    }
    if (task == 2){
        task2();
    }
    else if (task == 3){
        task3();
    }
    else if (task == 4){
        task4();
    }
    else if (task == 5){
        task5();
    }
    else if (task == 6){
        task6();
    }

}
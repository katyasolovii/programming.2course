#include <stdio.h>
#include <math.h>

int input_arr(int a[], int SIZE){

    for (int i=0; i < SIZE; i++){
            printf("a[%d] = ", i);
            int arr = scanf("%d", &a[i]);
            if (arr != 1) return i;
        }
    return SIZE;
    
}

int is_prime(int num){

    if (num < 2){
        return 0;
    }
    for (int i=2; i <= sqrt(num); i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;

}

void task8_e(){

    int N;
    printf("N = ");
    scanf("%d", &N);
    int count=0;

    int a[N];
    int m = input_arr(a, N);

    for (int i=0; i < m; i++){
        count += is_prime(a[i]); 
    }

    printf("The count of prime numbers: %d \n", count);

}

int main(){

    task8_e();

}
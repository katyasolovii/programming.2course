#include <stdio.h>

int input_arr(int a[], int SIZE){

    for (int i=0; i < SIZE; i++){
            printf("a[%d] = ", i);
            int arr = scanf("%d", &a[i]);
            if (arr != 1) return i;
        }
    return SIZE;
    
}

void task10_bb(){

    int n;
    printf("n = ");
    scanf("%d", &n);

    int a[n];
    int m = input_arr(a, n);
    int max_pr=1;

    for (int i=0; i < m; i++){
        if (a[i] != 0){
            max_pr *= a[i];
        }
    }

    printf("The max product = %d \n", max_pr);

}

int main(){

    task10_bb();

}
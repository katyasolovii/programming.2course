#include <stdio.h>
#define MAX_SIZE 20

void input_matrix(double matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Enter value of matrix [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]); 
        }
    }
}

void output_matrix(double matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void reflect_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size){

    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            double element = matrix[i][j];
            if (i + j < size - 1) {
                matrix[i][j] = matrix[size - 1 - j][size - 1 - i];
                matrix[size - 1 - j][size - 1 - i] = element;
            }
        }
    }

}

void task16(){

    int n, size;
    double matrix[MAX_SIZE][MAX_SIZE];

    printf("n = ");
    scanf("%d", &n);

    size = 2 * n + 1;

    input_matrix(matrix, size, size);
    reflect_matrix(matrix, size);
    output_matrix(matrix, size, size);

}

int main(){
    task16();
}
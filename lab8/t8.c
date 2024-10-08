#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20
#define EPSILON 1e-6 

void task1(){

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int M, N;
    printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

    for (int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if (matrix[i][j] == M){
                matrix[i][j] = N;
            }
        }
    }

    for (int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}

void task2(){

    double matrix[3][3] = {{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;
    double a;
    printf("i, j = ");
    scanf("%d %d", &i, &j);
    printf("a = ");
    scanf("%lf", &a);

    for (int k=0; k < 3; k++){
        for (int n=0; n < 3; n++){
            if (k == i && j == n){
                matrix[k][n] = a;
            }
        }
    }

    for (int k=0; k < 3; k++){
        for (int n=0; n < 3; n++){
            printf("%lf ", matrix[k][n]);
        }
        printf("\n");
    }

}

void input_matrix3(double matrix[20][20], int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter value of matrix [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]); 
        }
    }

}

void task3(){

    int m, n;
    printf("Enter (m n): ");  
    scanf("%d %d", &m, &n);

    double matrix[20][20]; 
    input_matrix3(matrix, m, n);

    printf("Entered matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }

}

void input_matrix4(double matrix[25][25], int m, int n) {

    for (int i = 0; i < m; i++) {
        printf("matrix [%d]: \n", i);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]); 
        }
    }

}

void task4(){

    int m, n;
    printf("Enter (m n): ");  
    scanf("%d %d", &m, &n);

    double matrix[25][25]; 
    input_matrix4(matrix, m, n);

    printf("Entered matrix: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }

}

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

void transpose_matrix(double matrix[MAX_SIZE][MAX_SIZE], double transposed[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            transposed[i][j] = matrix[j][i];
        }
    }
}

void task5() {
    
    int M, N;
    printf("M, N: ");
    scanf("%d %d", &M, &N);
    
    double matrix[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    
    printf("Enter matrix elements:\n");
    input_matrix(matrix, M, N);
    
    printf("Original matrix:\n");
    output_matrix(matrix, M, N);

    transpose_matrix(matrix, transposed, M, N);

    printf("Transposed matrix:\n");
    output_matrix(transposed, M, N);

}

double calculate_sum(double A[MAX_SIZE][MAX_SIZE], int N, int M, int k){

    double sum=0.0;
    int count=0; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i - j == k) {
                sum += A[i][j];
                count++; 
            }
        }
    }

    if (count == 0){
        return 0;
    }
    else{
        return sum;
    }

}

void task6(){

    int N, M, k;
    printf("N, M (<100) = ");
    scanf("%d %d", &N, &M);
    double A[MAX_SIZE][MAX_SIZE];
    
    input_matrix(A, M, N);

    printf("Enter value of k: ");
    scanf("%d", &k);

    printf("The sum of elements where i - j = %d is: %.2lf \n", k, calculate_sum(A, N, M, k));

}

void upper_matrix(double matrix[MAX_SIZE][MAX_SIZE], int n){
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            for (int k = i + 1; k < n; k++) {
                if (matrix[k][i] != 0) {
                    // треба поміняти рядки місцями
                    for (int j = 0; j < n; j++) {
                        double temp = matrix[i][j];
                        matrix[i][j] = matrix[k][j];
                        matrix[k][j] = temp;
                    }
                }
            }
        }
        // перетворимо рядки нижче на нулі
        for (int j = i + 1; j < n; j++) {
            //  знайдемо потрібний множник
            double num = (matrix[j][i] / matrix[i][i]);
            for (int k = i; k < n; k++){
                // жомножимо num на весь рядок даного рядка і від цього рядка віднімаємо рядок інший
                matrix[j][k] -= num * matrix[i][k];
            }
        }
    }
}

double determinant(double matrix[MAX_SIZE][MAX_SIZE], int n){
    upper_matrix(matrix, n);
    double det = 1;
    for (int i = 0; i < n; i++) {
        det *= matrix[i][i];
    }
    return det;
}

void task7(){

    int n;
    double matrix[MAX_SIZE][MAX_SIZE];

    printf("n = ");
    scanf("%d", &n);
    
    input_matrix(matrix, n, n);

    printf("The determinant of the matrix is: %.2lf \n", determinant(matrix, n));

}

int equal_with_epsilon(double a, double b) {
    return fabs(a - b) < EPSILON;
}

void test_task7(){
    double matrix1[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
    if (equal_with_epsilon((determinant(matrix1, 3)), 1)){
        printf("Test1 passed successfully. \n");
    }
    double matrix2[MAX_SIZE][MAX_SIZE] = {{2, 3}, {1, 4}};
    if (equal_with_epsilon((determinant(matrix2, 2)), 5)){
        printf("Test2 passed successfully. \n");
    }
    double matrix3[MAX_SIZE][MAX_SIZE] = {{1, 2, 5, 3}, {4, 5, 6, 12}, {7, -21, 9, 0}, {10, -9, 23, 12}};
    if (equal_with_epsilon((determinant(matrix3, 4)), 591)){
        printf("Test3 passed successfully. \n");
    }
    double matrix4[MAX_SIZE][MAX_SIZE] = {{1, 2, 5, 3, 5}, {4, 5, 6, 12, 1}, {7, -21, 9, 0, 1}, {10, -9, 23, 0, 1}, {-2, -7, -2, 3, 4}};
    if (equal_with_epsilon((determinant(matrix4, 5)), -51858.00)){
        printf("Test4 passed successfully. \n");
    }
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
    else if (task == 7){
        task7();
        test_task7();
    }

}

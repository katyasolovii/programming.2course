#include <stdio.h>
#include <stdlib.h>

void input_mas(double** mas, size_t N, size_t M){
    for (size_t i=0; i < N; i++){
        for (size_t j=0; j < M; j++){
            printf("mas[%zu][%zu] = ", i, j);
            scanf("%lf", &mas[i][j]);
        }
        printf("\n");
    }
}

void output_mas(double** mas, size_t N, size_t M){
    for (size_t i=0; i < N; i++){
        for (size_t j=0; j< M; j++){
            printf("%lf ", mas[i][j]);
        }
        printf("\n");
    }
}

int zero_in_row(double* row, size_t M) {
    for (size_t j=0; j < M; j++) {
        if (row[j] == 0) {
            return 1;
        }
    }
    return 0;
}

void copy_row(double* current, double* new, size_t M) {
    for (size_t j=0; j < M; j++) {
        new[j] = current[j]; 
    }
}

double** delete_row_with_zero(double** mas, size_t* N, size_t M){
    size_t new_size = 0, new_row = 0;

    for (size_t i=0; i < *N; i++){
        if (!zero_in_row(mas[i], M)){
            new_size++;
        }
    }

    double** new_mas = (double**)calloc(new_size, sizeof(double*));
    for (size_t i=0; i < *N; i++){
        if (!zero_in_row(mas[i], M)){
            new_mas[new_row] = (double*)calloc(M, sizeof(double));
            copy_row(mas[i], new_mas[new_row], M);
            new_row++;
        }
        free(mas[i]);
    }
    free(mas);
    *N = new_size;
    return new_mas;
}

void deleted_mas(double** mas, size_t N){
    for (size_t i = 0; i < N; i++) {
        free(mas[i]);
    }
    free(mas);
}
int main(){
    size_t N, M;
    printf("N, M = ");
    scanf("%zu %zu", &N, &M);

    double** mas = (double**)calloc(N, sizeof(double*));
    for (size_t i = 0; i < N; i++) {
        mas[i] = (double*)calloc(M, sizeof(double));
    }
    input_mas(mas, N, M);
    output_mas(mas, N, M);

    double** result = delete_row_with_zero(mas, &N, M);
    printf("\nResult: \n");
    output_mas(result, N, M);
    deleted_mas(result, N);
}

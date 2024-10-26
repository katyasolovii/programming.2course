#include <stdio.h>
#include <stdlib.h>

// *** - вказує на масив матриць
// ** - вказує на кожну окрему матрицю(на масив вказівників на рядки)

void input_matrix(double** matr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("matrix[%zu][%zu] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
        printf("\n");
    }
}

void output_matrix(double** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void delete_matrix(double** matr, size_t rows) {
    if (matr != NULL) {
        for (int i=0; i < rows; i++){
            free(matr[i]);
        }
        free(matr);
    }
}

int create_matrix(double*** matr, size_t rows, size_t cols) {
    *matr = (double**)calloc(rows, sizeof(double*));
    if (!*matr) {
        return 1;
    }
    for (size_t i = 0; i < rows; i++) {
        (*matr)[i] = (double*)calloc(cols, sizeof(double));
    }
    return 0;
}

void sum_matrices(double** result, double*** matrs, int matrix_count, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (size_t k = 0; k < matrix_count; k++) {
                result[i][j] += matrs[k][i][j];
            }
        }
    }
}

int main() {
    size_t rows, cols, prev_rows = 0, prev_cols = 0;
    int matrix_count;

    printf("Enter the count of matrices: ");
    scanf("%d", &matrix_count);
 
    double*** matrs = (double***)calloc(matrix_count, sizeof(double**));

    for (int i = 0; i < matrix_count; i++) {
        printf("Enter the number of rows and columns for matrix %d: ", i + 1);
        scanf("%zu %zu", &rows, &cols);

        if (i > 0 && (rows != prev_rows || cols != prev_cols)){
            printf("Error! Matrices have different sizes! \n");
            // видаляємо пам'ять для матриць, які були введені раніше
            for (int j=0; j < i; j++){
                delete_matrix(matrs[j], prev_rows);
            }
            free(matrs);
            return 1;
        }
        prev_rows = rows;
        prev_cols = cols;

        create_matrix(&matrs[i], rows, cols);
        printf("Enter matrix %d:\n", i + 1);
        input_matrix(matrs[i], rows, cols);
    }

    double** result;
    create_matrix(&result, rows, cols);

    sum_matrices(result, matrs, matrix_count, rows, cols);

    printf("The sum of matrices is:\n");
    output_matrix(result, rows, cols);

    delete_matrix(result, rows);
}

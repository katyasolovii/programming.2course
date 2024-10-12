#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

void input_array(double *array, unsigned n){
    for (unsigned i=0; i < n; i++){
        printf("Enter elenemt %d: ", i);
        scanf("%lf", &array[i]);
    }
}

double sum_of_squares(const double *array, int n){
    double sum=0;
    for (unsigned i=0; i < n; i++){
        sum += pow(array[i], 2);
    }
    return sum;
}

void task1(){
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    double *array;
    array = (double*)malloc(n*sizeof(*array));
    // * - вказує шо ми працює з вказівниками
    if (array == NULL){
        printf("Memory allocation failed! \n");
        return;
    }
    input_array(array, n);
    double res = sum_of_squares(array, n);
    printf("The sum of squares: %.2lf \n", res);
    free(array);
}

// структура для зберігання елементів стека
typedef struct Stack {
    int data;
    struct Stack *addr;
} Stack;

int input_a(int *array){
    int x;
    int i=0;
    do{
        if (i >= MAX_SIZE) break;
        printf("Enter element [%d]:", i);
        scanf("%d", &x);
        if (x != 0){
            array[i++] = x;
        }
    } while (x != 0);
    return i;
}

int square(int x) {
    int sqrt_x = (int)sqrt(x);
    return (pow(sqrt_x, 2) == x);
}

int cube(int x) {
    int cbrt_x = (int)cbrt(x);
    return (pow(cbrt_x, 3) == x);
}

void task2(){

    int array[MAX_SIZE];
    int n = input_a(array);

    int count_squares=0, count_cubes=0;

    for (int i=0; i < n; i++){
        if (square(array[i])){
            count_squares++;
        }
        if (cube(array[i])){
            count_cubes++;
        }
    }

    printf("Number of squares: %d \n", count_squares);
    printf("Number of cubes: %d \n", count_cubes);

}

int input_vec(double **arr, size_t n) {
    double *arr2 = (double*)malloc(n * sizeof(*arr));
    if (arr2 == NULL) {
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        printf("Enter vector element [%zu]: ", i);
        scanf("%lf", &arr2[i]);
    }
    *arr = arr2;
    return 0;
}

void delete_vec(double *arr) {
    if(arr){free(arr);}
}

int subt_vec(const double *arr1, const double *arr2, double **arr3, size_t n) {
    if(arr1 == NULL || arr2 == NULL) {
        return 1;
    }
    *arr3 = (double*)malloc(n * sizeof(*arr3));
    if(*arr3 == NULL) {
        return 1;
    }
    for(size_t i = 0; i < n; i++) {
        (*arr3)[i] = arr1[i] - arr2[i];
    }
    return 0;
}

void output_vec(const double *arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void task3(){

    size_t n;
    double *vec1, *vec2, *vec3;
    printf("n = ");
    scanf("%zu", &n);

    input_vec(&vec1, n);
    output_vec(vec1, n);
    input_vec(&vec2, n);
    output_vec(vec2, n);

    printf("The difference of the vectors is:\n");
    subt_vec(vec1, vec2, &vec3, n);
    output_vec(vec3, n);
    
    delete_vec(vec1);
    delete_vec(vec2);

}

// Функції для двовимірного масиву

void output_mart2(const double **matr, size_t n){
    for (size_t i=0; i < n; i++){
        for (size_t j=0; j < n; j++){
            printf("%lf ", matr[i][j]);
        }
        printf("\n");
    }
}

void input_matr2(double **matr, size_t n){
    for(size_t i=0; i < n; i++){
        for (size_t j=0; j< n; j++){
            printf("matrix[%zu][%zu] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
    }
}

int create_matr2(double ***matr, size_t n){
    *matr = (double**)(calloc(n, sizeof **matr));
    if (!*matr){
        return 1;
    }
    for(size_t i=0; i < n; i++){
        (*matr)[i] = (double*)calloc(n, sizeof(double));
    }
    return 0;
}

void delete_matr2(double **matr, size_t n){
    if (matr != NULL) {
        free(matr);
    }
}

int mult_matr2(const double **matr1, const double **matr2, double **matr3, size_t n){
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            matr3[i][j] = 0; 
            for (size_t k = 0; k < n; k++) {
                matr3[i][j] += matr1[i][k] * matr2[k][j]; 
            }
        }
    }
    return 0;
}

void task4_2(){
    size_t n;
    printf("n = ");
    scanf("%zu", &n);
    double **matr1, **matr2, **matr3;

    create_matr2(&matr1, n);
    create_matr2(&matr2, n);
    create_matr2(&matr3, n);

    input_matr2(matr1, n);
    input_matr2(matr2, n);
    
    mult_matr2((const double**)matr1, (const double**)matr2, matr3, n);
    printf("Resultant matrix: \n");
    output_mart2((const double**)matr3, n);

    delete_matr2(matr1, n);
    delete_matr2(matr2, n);
    delete_matr2(matr3, n);
}

// Функції для лінійного масиву

void output_mart1(const double *matr, size_t n){
    for (size_t i=0; i < n; i++){
        for (size_t j=0; j < n; j++){
            printf("%lf ", matr[i * n + j]);
        }
        printf("\n");
    }
}

void input_matr1(double *matr, size_t n){
    for (size_t i=0; i < n; i++){
        for (size_t j=0; j < n; j++){
            printf("matrix[%zu][%zu] = ", i, j);
            scanf("%lf", &matr[i * n + j]);
        }
    }
}

int create_matr1(double **matr, size_t n){
    *matr = (double*)(calloc(n*n, sizeof *matr));
    if (!matr){
        return 1;
    }
    return 0;
}

void delete_matr1(double *matr){
    if (matr != NULL) {
        free(matr);
    }
}

int mult_matr1(const double *matr1, const double *matr2, double **matr3, size_t n){
    if (matr1 == NULL || matr2 == NULL){
        return 1;
    }
    *matr3 = (double*)calloc(n * n, sizeof(double));
    if (!*matr3){
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            (*matr3)[i * n + j] = 0;
            for (size_t k = 0; k < n; k++) {
                (*matr3)[i * n + j] += matr1[i * n + k] * matr2[k * n + j];
            }
        }
    }
    return 0;
}

void task4_1(){
    size_t n;
    printf("n = ");
    scanf("%zu", &n);
    double *matr1, *matr2, *matr3;

    create_matr1(&matr1, n);
    create_matr1(&matr2, n);
    create_matr1(&matr3, n);

    input_matr1(matr1, n);
    input_matr1(matr2, n);
    
    mult_matr1((const double*)matr1, (const double*)matr2, &matr3, n);
    printf("Resultant matrix: \n");
    output_mart1((const double*)matr3, n);

    delete_matr1(matr1);
    delete_matr1(matr2);
    delete_matr1(matr3);
}

int main(){
    int task;
    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task1();
    }
    else if (task == 2){
        task2();
    }
    else if (task == 3){
        task3();
    }
    else if (task == 4){
        task4_2();
        task4_1();
    }
}

// malloc (size_t size) - один параметр, що вказує розмір пам'яті в байтах, який потрібно виділити
// malloc (size_t size) - просто виділяє вказану кількість байтів, але не ініціалізує цю пам'ять
// collac (size_t num, size_t size) - виділяє пам'ять та ініціалізує всі біти в цій пам'яті до нуля
// collac (size_t num, size_t size) - два параметри: num - кількість елементів, які потрібно виділити
// size: розмір кожнго елемента в байтах
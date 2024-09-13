#include <stdio.h>

int main() {

    /* Переведення градусів Цельсія в градусах Фаренгейта */
    
    double d_C;
    printf("Enter degrees C:");
    scanf("%lf", &d_C);

    double f = (9 * d_C) / 5 + 32;
    printf("Dergees F: %.2lf \n", f);

}
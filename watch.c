#include <stdio.h>
#include <math.h>


int main() {
    
    double radian;
    int hours, minute;

    printf("Enter radian: ");
    scanf("%lf", &radian);

    double degree = (radian * 180 / M_PI);
    printf("%lf \n", degree);

    // 1 година = 30 градусів
    hours = (int)(degree / 30) % 12; 
    // віднімаємо від загального години і знаходимо хвилин (60 хв / 30 градусів = 2 градуса)
    minute = (int)((degree - (hours * 30)) * 2);

    printf("Time is: %02d:%02d \n", hours, minute);

}

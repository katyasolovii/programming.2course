#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>


void task1(){

    unsigned number, units, tens, hundreds, sum, revesnumber;
    
    printf("n = ");
    scanf("%u", &number);

    if (number > 99 && number <= 999 ){
        units = number % 10;
        tens = (number / 10) % 10;
        hundreds = number / 100;
        printf("Units of number: %u \n", units);
        printf("Tens of number: %u \n", tens);
        printf("Hundreds of number: %u \n", hundreds);
        sum = units + tens + hundreds;
        printf("Sum of digits of the number: %u \n", sum);
        revesnumber = units * 100 + tens * 10 + hundreds;
        printf("Reversed number: %u \n", revesnumber);
    }
    else{
        printf("This number doesn't have three digits. \n");
    }

}

void task2(){

    unsigned number, units, tens, hundreds; 

    printf("n = ");
    scanf("%u", &number);

    units = number % 10;
    tens = (number / 10) % 10;
    hundreds = number / 100;

    if (units != tens && units != hundreds && tens != hundreds){
        printf("%u%u%u \n", units, tens, hundreds);
        printf("%u%u%u \n", units, hundreds, tens);
        printf("%u%u%u \n", hundreds, units, tens);
        printf("%u%u%u \n", hundreds, tens, units);
        printf("%u%u%u \n", tens, hundreds, units);
        printf("%u%u%u \n", tens, units, hundreds);
    }
    else{
        printf("The digits are not different. \n");
    }
    
}

void task3(){

    int a, b, c, pr1, pr2;

    printf("Enter a, b, c = ");
    scanf("%d, %d, %d", &a, &b, &c);

    pr1 = (int) a * b * c;
    pr2 = (long long) a * b * c;
    printf("Product: %d \n", pr1);
    printf("Product: %d \n", pr2);

}

uint16_t mult(uint8_t x, uint8_t y){
    uint16_t z = x * y;
    return z;
}

void task4(){

    uint8_t x, y;
    uint16_t z;

    printf("x, y : ");
    scanf("%hhu %hhu", &x, &y);
    z = mult(x, y);
    printf("z = %hu \n", z);

}

void task5(){

    int a, b, max, min;

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    // if (a > b) {
    //     printf("%d > %d\n", a, b);
    // }
    // else if (a < b) {
    //     printf("%d < %d\n", a, b);
    // }
    // else {
    //     printf("%d = %d\n", a, b);
    // }

    max = a > b ? a : b;
    printf("Max = %d \n", max);

    min = a < b ? a : b;
    printf("Min = %d \n", min);

}

void task6(){

    int a, b, c;

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("c = ");
    scanf("%d", &c);

    if (abs(a) > abs(b) && abs(a) > abs(c)){
        printf("Max = %d \n", a);
    }
    else if (abs(b) > abs(a) && abs(b) > abs(c)){
        printf("Max = %d \n", b);
    }
    else{
        printf("Max = %d \n", c);
    }

    if (abs(a) < abs(b) && abs(a) < abs(c)){
        printf("Min = %d \n", a);
    }
    else if (abs(b) < abs(a) && abs(b) < abs(c)){
        printf("Min = %d \n", b);
    }
    else{
        printf("Min = %d \n", c);
    }

}

void task7_a(){

    double a, b, c;

    printf("a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0 && b != 0 && c != 0){
        double x = - c / b;
        printf("x1 = %lf \n", x);
    }
    if (c == 0 && a != 0 && c != 0){
        int x1 = 0;
        double x2 = - a / b;
        printf("x1 = %d, x2 = %lf \n", x1, x2);
    }
    if (b == 0 && a != 0 && c != 0){
        int x = - c / a;
        if (x > 0){
            double x1 = sqrt(x);
            double x2 = - sqrt(x);
            printf("x1 = %lf, x2 = %lf \n", x1, x2);
        }
        if (x < 0){
            printf("No real roots.\n");
        }
    }
    if (a > 0 && b > 0 && c >0){
        int d = pow(b, 2) - 4 * a * c;
        if (d > 0){
            double x1 = ( -b + sqrt(d)) / (2 * a);
            double x2 = ( -b - sqrt(d)) / (2 * a);
            printf("x1 = %lf, x2 = %lf \n", x1, x2);
        }
        else if (d == 0){
           double x = -b / (2 * a);
           printf("x1 = %lf \n", x);
        }
        else if (d < 0){
            printf("No real roots.\n");
        }
    }
    if (b == 0 && c == 0 && a != 0){
        if (a > 0){
            double x1 = sqrt(a);
            double x2 = - sqrt(a);
            printf("x1 = %lf, x2 = %lf \n", x1, x2);
        }
        if (a < 0){
            printf("No real roots.\n");
        }
    }
    if (a == 0 && c == 0 && b != 0){
        double x1 = -b;
        printf("x1 = %lf \n", x1);
    }
    if (a == 0 && b == 0){
        printf("No equation exists.\n");
    }
}

void task7_b(){

    double a, b, c;
    printf("a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0 && b == 0){
        printf("No equation exists.\n");
    }
    if (a == 0 && b != 0 && c != 0){
        double x = - c / a;
        if (x > 0){
            double x1 = sqrt(x);
            double x2 = - sqrt(x);
            printf("x1 = %lf, x2 = %lf \n", x1, x2);
        }
        if (x < 0){
            printf("No real roots.\n");
        }
    }
    if (b == 0 && a != 0 && c != 0){
        double x = - c / a;
        if (x > 0){
            double x1 = pow(x1, 1/4);
            double x2 = - pow(x2, 1/4);
            printf("x1 = %lf, x2 = %lf \n", x1, x2);
        }
        if (x < 0){
            printf("No real roots.\n");
        }
    }
    if (c == 0 && a != 0 && b != 0){
        int x1 = 0;
        double x = - b / a;
        if (x > 0){
            double x2 = sqrt(x);
            double x3 = - sqrt(x);
            printf("x1 = %d, x2 = %lf, x3 = %lf \n", x1, x2, x3);
        }
        if (x < 0){
            printf("x1 = %d \n", x1);
        }
    }
    if (a == 0 && c == 0 && b != 0){
        if (b < 0){
            printf("No equation exists.\n");
        }
        if (b > 0){
            double x1 = sqrt(b);
            double x2 = - sqrt(b);
            printf("x1 = %lf, x2 = %lf \n", x1, x2);
        }
    }
    if (a != 0 && b == 0 & c == 0){
        printf("x1 = 0 \n");
    }
    if (a != 0 && b != 0 && c != 0){
        double d = pow(b, 2) - 4 * a * c;
        if (d < 0){
            printf("No real roots.\n");
        }
        if (d == 0){
            double x = - b / (2 * a);
            if (x < 0){
                printf("No real roots.\n");
            }
            if (x > 0){
                double x1 = sqrt(x);
                double x2 = -sqrt(x);       
                printf("x1 = %lf, x2 = %lf \n", x1, x2);    
            }
        }
        if (d > 0){
            double y1 = (-b + sqrt(d)) / (2 * a);
            double y2 = (-b - sqrt(d)) / (2 * a);
            if (y1 >= 0 && y2 >= 0){
                double x1 = sqrt(y1);
                double x2 = -sqrt(y1);
                double x3 = sqrt(y2);
                double x4 = -sqrt(y2);
                printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf \n", x1, x2, x3, x4);
            }
            if (y1 >= 0 && y2 < 0){
                double x1 = sqrt(y1);
                double x2 = -sqrt(y1);
                printf("x1 = %lf, x2 = %lf \n", x1, x2);
            }
            if (y1 < 0 && y2 >= 0){
                double x1 = sqrt(y2);
                double x2 = -sqrt(y2);
                printf("x1 = %lf, x2 = %lf \n", x1, x2);
            }
            if (y1 < 0 && y2 < 0){
                printf("No real roots. \n");
            }
        }
    }
}

int main(){

    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7_a();
    task7_b();
    
}
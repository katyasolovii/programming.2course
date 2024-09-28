#include <stdio.h>

void task12(){

    unsigned int m, i, j;


    printf("m = ");
    scanf("%u", &m);
    printf("i = ");
    scanf("%u", &i);
    printf("j = ");
    scanf("%u", &j);
    
    m ^= (1 << i);
    m ^= (1 << j);

    printf("Decimal value = %u \n", m);
    printf("Hexadecimal value = %X \n", m);

}

int main(){

    task12();

}
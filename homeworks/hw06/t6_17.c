#include <stdio.h>

void task17(){

    unsigned int n, inverted=0, bit;

    printf("n = ");
    scanf("%u", &n);

    for (int i = 0; i < 32; i++){
        bit = (n >> i) & 1;           // зсув вправо на i позицій + отримуємо найменший біт(0 or 1) в даній позиції
        inverted |= bit << (31 - i);  // розміщуємо (зберігаємо "|") біт в потрібній позиції
    }

    printf("Binary value = ");
    for (int i = 31; i >= 0; i--){
        printf("%u", (inverted >> i) & 1);
    }
    printf("\n");

    printf("Decimal value = %u \n", inverted);

}

int main(){

    task17();

}
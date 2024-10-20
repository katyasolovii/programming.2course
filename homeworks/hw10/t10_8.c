#include <stdio.h>
#define MAX_JURNALS 100

typedef struct Jurnal{
    double price;
    int count;
} Jurnal;

int main(){
    Jurnal journals[MAX_JURNALS];
    int n;
    printf("n = ");
    scanf("%d", &n);
    float t_price=0;
    int t_count=0;

    for (int i=0; i < n; i++){
        printf("Jurnal %d: \n", i+1);
        printf("Enter the price of a jurnal: ");
        scanf("%lf", &journals[i].price);
        printf("Enter the magazine circulation: ");
        scanf("%d", &journals[i].count);
        if (journals[i].count < 10000){
            t_price += journals[i].price;
            t_count++;
        }
    }
    if (t_count > 0){
        float aver_price = t_price / t_count;
        printf("The average price of magazines with a circulation < 10_000 : %lf \n", aver_price);
    }
    else{
        printf("There are no magazines with a circulation < 10_000. \n");
    }
}

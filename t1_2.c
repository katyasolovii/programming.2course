#include <stdio.h>
#include <math.h>

int main(){
    
    double deg_value = pow(10, -4);
    double value = 24.33E5; // 24.33 * 10 ^ 5
    double pi = M_PI; 
    double exp_value = exp(1); 
    double sqrt_value = sqrt(5);
    double ln_value = log(100);

    printf("10^(-4) = %lf\n", deg_value);   
    printf("24.33E5 = %lf\n", value);   
    printf("Число pi = %lf\n", pi);
    printf("Експонента e = %lf\n", exp_value);
    printf("sqrt(5)= %lf\n", sqrt_value);  
    printf("ln(100)  = %lf\n", ln_value); 

}
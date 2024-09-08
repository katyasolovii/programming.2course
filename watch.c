#include <stdio.h>

int main() {
    
    double degree_hour, degree_minute;
    int hours, minutes;

    printf("Enter degree of hour: ");
    scanf("%lf", &degree_hour);

    printf("Enter degree of minute: ");
    scanf("%lf", &degree_minute);

    // Кожна година це 15 градусів (45 / 3 = 15, всього 12 годин)
    // Кожна хвилина це 3 градуса (5 поділок між годинами, тому 15 / 5 = 3 градуса, всього 60 хвилин)
    hours = (int)(degree_hour / 15) % 12; 
    minutes = (int)(degree_minute / 3) % 60; 

    printf("Time is: %02d:%02d \n", hours, minutes); 

}
#include <stdio.h>
#include <math.h>

int main() {
    
    double radian_hour, radian_minute;
    int hours, minute;

    printf("Enter radian of hour: ");
    scanf("%lf", &radian_hour);

    printf("Enter radian of minute: ");
    scanf("%lf", &radian_minute);


    // Кожна година це 30 градусів (90 / 3 = 30, всього 12 годин)
    // Кожна хвилина це 6 градуса (5 поділок між годинами, тому 30 / 5 = 6 градуса, всього 60 хвилин)

    double degree_hour = (radian_hour * 180 / M_PI);
    double degree_minute = (radian_minute * 180 / M_PI);

    hours = (int)(degree_hour / 30) % 12; 
    minute = (int)(degree_minute / 6) % 60; 

    printf("Time is: %02d:%02d \n", hours, minute); 

}

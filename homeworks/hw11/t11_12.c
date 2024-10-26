#include <stdio.h>
#include <stdlib.h>

typedef struct Toy{
    char name[50];
    float price;
    int age_min;
    int age_max;
} Toy;

void write_file(const char* filename){
    FILE *file = fopen(filename, "wb");
    int n;
    printf("Thern the count of toys: ");
    scanf("%d", &n);
    Toy t;
    for (int i=0; i < n; i++){
        printf("Enter name of toy: ");
        scanf("%s", t.name);
        printf("Enter price of toy: ");
        scanf("%f", &t.price);
        printf("Enter min age: ");
        scanf("%d", &t.age_min);
        printf("Enter max age: ");
        scanf("%d", &t.age_max);
        fwrite(&t, sizeof(Toy), 1, file);
    }
    fclose(file);
}

void search_toys_by_age(const char* filename, int min_age, int max_age) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
    
    Toy t;
    printf("Toys for children from %d to %d years:\n", min_age, max_age);
    while (1) {
        if (fread(&t, sizeof(Toy), 1, file) != 1) break;
        if (t.age_min <= max_age && t.age_max >= min_age) {
            printf("Name: %s, price: %.2f, age range: %d - %d years \n", t.name, t.price, t.age_min, t.age_max);
        }
    }
    
    fclose(file);
}

void task12(){
    const char* toys_f = "toys.dat";
    int min_age, max_age;
    printf("Enter minimum age: ");
    scanf("%d", &min_age);
    printf("Enter maximum age: ");
    scanf("%d", &max_age);
    write_file(toys_f);
    search_toys_by_age(toys_f, min_age, max_age);
}

int main() {
    task12();
}

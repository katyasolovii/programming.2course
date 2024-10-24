#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_file(double mas[], int n) {
    char fileName[] = "task1.dat";
    FILE *out = fopen(fileName, "wb"); 
    fwrite(mas, sizeof(double), n, out); 
    fclose(out); 
}

void read_file(double mas[], int n) {
    char fileName[] = "task1.dat";
    FILE *inFile = fopen(fileName, "rb");
    fread(mas, sizeof(double), n, inFile);
    fclose(inFile); 
    for (int i = 0; i < n; i++) {
        printf("%lf", mas[i]);
        printf(", "); 
    }
    printf("\n");
}

void task1(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    double mas[n];
    for (int i = 0; i < n; i++) {
        printf("mas[%d] = ", i);
        scanf("%lf", &mas[i]);
    }
    write_file(mas, n);
    read_file(mas, n);
}

void task2(){
    const char* Fname = "F.dat";
    const char* Gname = "G.dat";

    FILE *F = fopen(Fname, "wb");
    if (F == NULL){
        fprintf(stderr, "Error opening file %s \n", Fname);
        return;
    }

    int n; 
    printf("n = ");
    scanf("%d", &n);

    double x;

    for (int i=0; i < n; i++){
        printf("x = ");
        scanf("%lf", &x);
        fwrite(&x, sizeof(double), 1, F);
    }
    fclose(F);

    double a;
    printf("a = ");
    scanf("%lf", &a);

    F = fopen(Fname, "rb");
    if (F == NULL) {
        fprintf(stderr, "Error opening file %s \n", Fname);
        return;
    }

    double mas[n];
    int i=0, k=0;

    FILE *G = fopen(Gname, "wb");
    if (G == NULL) {
        fprintf(stderr, "Error opening file %s \n", Gname);
        fclose(F);
        return;
    }

    while(1){
        if (feof(F)) break;
        fread(&x, sizeof(double), 1, F);
        if (fabs(x) < a){
            fwrite(&x, sizeof(double), 1, G);
        }
        else{
            mas[k++] = x;
        }
        i++;
    }
    fclose(F);
    fclose(G);

    printf("The of file G: \n");
    G = fopen(Fname, "rb");
    while (1){
        if (feof(G)) break;
        fread(&x, sizeof(double), 1, G);
        printf("x%d = %lf \n", i++, x);
    }
    fclose(G);

    F = fopen(Fname, "wb");
    fwrite(mas, sizeof(double), k, F);
    fclose(F);

    printf("The file F: \n");
    F = fopen(Fname, "rb");
    i = 0;
    while (1) {
        if (feof(F)) break;
        fread(&x, sizeof(double), 1, F);
        printf("x%d = %lf \n", i++, x);
    }
    fclose(F);

}

void task3_a(){
    const char* Fname = "F_3a.dat";
    const char* Gname = "G_3a.dat";  

    FILE *F = fopen(Fname, "wb");
    if (F == NULL){
        fprintf(stderr, "Error opening file %s \n", Fname);
        return;
    }

    int num;
    printf("Enter numbers: \n");

    while(1){
        scanf("%d", &num);
        if (num == 0) break;
        fwrite(&num, sizeof(int), 1, F);
    }
    fclose(F);

    F = fopen(Fname, "rb");
    FILE *G = fopen(Gname, "wb");
    while(1) {
        if (fread(&num, sizeof(int), 1, F) != 1) {
            if (feof(F)) break;
            fprintf(stderr, "Error reading file \n");
            break;
        }
        int temp = num;
        if (temp % 2 == 0) {
            fwrite(&num, sizeof(int), 1, G);
        }
    }
    fclose(F);
    fclose(G);

    printf("The contents of file G: \n");
    G = fopen(Gname, "rb");
    if (G == NULL){
        fprintf(stderr, "Error opening file %s \n", Gname);
        return;
    }
    while(1) {
        if (fread(&num, sizeof(int), 1, G) != 1) {
            if (feof(G)) break;
            fprintf(stderr, "Error reading file\n");
            break;
        }
        printf("%d\n", num);
    }
}

void task3_b(){
    const char* Fname = "F_3b.dat";
    const char* Gname = "G_3b.dat";  

    FILE *F = fopen(Fname, "wb");
    if (F == NULL){
        fprintf(stderr, "Error opening file %s \n", Fname);
        return;
    }

    int num;
    printf("Enter numbers: \n");

    while(1){
        scanf("%d", &num);
        if (num == 0) break;
        fwrite(&num, sizeof(int), 1, F);
    }
    fclose(F);

    F = fopen(Fname, "rb");
    FILE *G = fopen(Gname, "wb");
    while(1) {
        if (fread(&num, sizeof(int), 1, F) != 1) {
            if (feof(F)) break;
            fprintf(stderr, "Error reading file \n");
            break;
        }
        int temp = num;
        while (temp % 3 == 0 && temp != 0) {
            temp /= 3;
        }
        if (temp == 1) {
            fwrite(&num, sizeof(int), 1, G);
        }
    }
    fclose(F);
    fclose(G);

    printf("The contents of file G: \n");
    G = fopen(Gname, "rb");
    if (G == NULL){
        fprintf(stderr, "Error opening file %s \n", Gname);
        return;
    }
    while(1) {
        if (fread(&num, sizeof(int), 1, G) != 1) {
            if (feof(G)) break;
            fprintf(stderr, "Error reading file\n");
            break;
        }
        printf("%d\n", num);
    }
}

typedef struct Rectangle {
    int n;
    double x1, y1, x2, y2;
} Rectangle;


void input(Rectangle *r) {
    printf("Enter rectangle number: ");
    scanf("%d", &r->n);
    printf("Enter (x1, y1): ");
    scanf("%lf %lf", &r->x1, &r->y1);
    printf("Enter (x2, y2): ");
    scanf("%lf %lf", &r->x2, &r->y2);
}

double area(const Rectangle *r) {
    return (r->x2 - r->x1) * (r->y2 - r->y1);
}

void write_file4(const char* fname, int count) {
    FILE *fp = fopen(fname, "wb");
    for (int i = 0; i < count; i++) {
        Rectangle r;
        input(&r);
        fwrite(&r, sizeof(Rectangle), 1, fp);
    }
    fclose(fp);
}

void find_largest_rectangle(const char* fname) {
    FILE *fp = fopen(fname, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s \n", fname);
        return;
    }

    Rectangle r;
    double max_area = 0;
    int max_index = -1;
    int index = 0;

    while (1) {
        if (fread(&r, sizeof(Rectangle), 1, fp) != 1) break;
        double current_area = area(&r);
        if (current_area > max_area) {
            max_area = current_area;
            max_index = index;
        }
        index++;
    }
    fclose(fp);
    printf("Rectangle with the largest area -> number %d, area %.2lf \n", max_index, max_area);
}

void delete_rectangle(const char* fname, int index_to_delete) {
    FILE *fp = fopen(fname, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s \n", fname);
        return;
    }
    // тимчасовий файл temp.dat
    FILE *temp_fp = fopen("temp.dat", "wb");
    Rectangle r;
    int index = 0;
    while (1) {
        if (fread(&r, sizeof(Rectangle), 1, fp) != 1) break;
        if (index != index_to_delete) {
            fwrite(&r, sizeof(Rectangle), 1, temp_fp);
        }
        index++;
    }

    fclose(fp);
    fclose(temp_fp);
    remove(fname);
    rename("temp.dat", fname);
}

void replace_rectangle(const char* fname, int index_to_replace) {
    FILE *fp = fopen(fname, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s \n", fname);
        return;
    }

    FILE *temp_fp = fopen("temp.dat", "wb");
    Rectangle r;
    int index = 0;
    while (1) {
        if (fread(&r, sizeof(Rectangle), 1, fp) != 1) break;
        if (index == index_to_replace) {
            printf("Replacing rectangle at index %d\n", index_to_replace);
            input(&r);
        }
        fwrite(&r, sizeof(Rectangle), 1, temp_fp);
        index++;
    }

    fclose(fp);
    fclose(temp_fp);
    remove(fname);
    rename("temp.dat", fname);
}

void task4() {
    const char *fname = "rectangles.dat";
    int count;

    printf("The number of rectangles: ");
    scanf("%d", &count);
    write_file4(fname, count);

    find_largest_rectangle(fname);
    int delete_index;
    printf("Enter rectangle index to delete: ");
    scanf("%d", &delete_index);
    delete_rectangle(fname, delete_index);

    int replace_index;
    printf("Enter rectangle index to replace: ");
    scanf("%d", &replace_index);
    replace_rectangle(fname, replace_index);
}

int main(){
    int task;
    printf("task = ");
    scanf("%d", &task);
    if (task == 1){
        task1();
    }
    else if (task == 2)
    {
        task2();
    }
    else if (task == 3)
    {
        task3_a();
        task3_b();
    }
    else if (task == 4)
    {
        task4();
    }
}

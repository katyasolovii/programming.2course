#include <stdio.h>

void write_file(const char* fileName) {
    FILE *file = fopen(fileName, "wb");

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s \n", fileName);
        return;
    }

    char input[100];
    int num;

    printf("Enter numbers: \n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break; 
        fwrite(&num, sizeof(int), 1, file);
    }
    fclose(file);
}

void output_file(const char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s \n", fileName);
        return;
    }

    int num;
    printf("The file %s:\n", fileName);
    while (1) {
        if (fread(&num, sizeof(int), 1, file) != 1) break;
        printf("%d ", num);
    }
    printf("\n");
    fclose(file);
}

void task8(){
    const char* Fname = "F.dat";
    const char* Gname = "G.dat"; 

    int n;
    printf("n = ");
    scanf("%d", &n);

    write_file(Fname);
    output_file(Fname);

    FILE *file_F = fopen(Fname, "rb");
    if (file_F == NULL) {
        fprintf(stderr, "Error opening file %s \n", Fname);
        return;
    }

    int num, count = 0;
    while (fread(&num, sizeof(int), 1, file_F) == 1) {
        count++;
    }
    fclose(file_F);

    printf("The count of numbers in file: %d\n", count);
    if (count % n == 0) {
        printf("The count of numbers is divisible by %d \n", n);
    } else {
        printf("The count of numbers isn't divisible by %d \n", n);
    }

    file_F = fopen(Fname, "rb");
    FILE *file_G = fopen(Gname, "wb");
    if (file_G == NULL) {
        fprintf(stderr, "Error opening file %s \n", Gname);
        fclose(file_F);
        return;
    }

    int group_size = 0, max_value;
    for (int i = 0; i < count; i++) {
        fread(&num, sizeof(int), 1, file_F);
        if (group_size == 0) {
            max_value = num;
        } else if (num > max_value) {
            max_value = num;
        }
        group_size++;
        if (group_size == n || i == count - 1) {
            fwrite(&max_value, sizeof(int), 1, file_G);
            group_size = 0;
        }
    }

    fclose(file_F);
    fclose(file_G);
    output_file(Gname);
}

int main(){
    task8();
}

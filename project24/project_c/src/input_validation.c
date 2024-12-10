#include "../headers/input_validation.h"

int find_specialty_index(char specialties[][200], int num_specialties, const char* specialty) {
    for (int i = 0; i < num_specialties; i++) {
        if (strcmp(specialties[i], specialty) == 0) {
            return i;
        }
    }
    return -1;
}

int is_valid_string(const char* str) {
    if (strlen(str) == 0 || strspn(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ") != strlen(str)) {
        return 0;
    }
    return 1;
}

void get_valid_string(const char* m, char* str, size_t max_length) {
    char b[100];

    while (1) {
        printf("%s", m);
        if (fgets(b, sizeof(b), stdin)) {
            b[strcspn(b, "\n")] = '\0';
            if (is_valid_string(b) && strlen(b) < max_length) {
                strcpy(str, b);
                return;
            } 
            else {
                printf("Invalid input. Please try again. \n");
            }
        } 
        else {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
        }
    }
}

int is_valid_degree(const char* str) {
    return strcmp(str, "Bachelor") == 0 || strcmp(str, "Master") == 0;
}

void get_valid_degree(const char* m, char* deg, size_t max_length) {
    char b[50];

    while (1) {
        printf("%s", m);
        if (fgets(b, sizeof(b), stdin)) {
            b[strcspn(b, "\n")] = '\0';
            if (is_valid_degree(b) && strlen(b) < max_length) {
                strcpy(deg, b);
                return;
            }
        }
        printf("Invalid input. Please try again. \n");
    }
}

double get_valid_double(const char* m) {
    double num;
    char b[50];
    while (1) {
        printf("%s", m);
        if (fgets(b, sizeof(b), stdin)) {
            if (sscanf(b, "%lf", &num) == 1 && num > 0) {
                return num;
            }
        }
        printf("Invalid input. Please try again. \n");
    }
}

int get_valid_int(const char* m) {
    int num;
    while (1) {
        printf("%s", m);
        if (scanf("%d", &num) != 1 || num <= 0) {
            printf("Invalid input. Please try again. \n");
            while (getchar() != '\n');
        } 
        else {
            break;
        }
    }
    return num;
}

int is_profession(const char* profession) {
    for (int i = 0; i < sizeof(ADMINISTRATIVE_MANAGEMENT) / sizeof(ADMINISTRATIVE_MANAGEMENT[0]); i++) {
        if (strcmp(profession, ADMINISTRATIVE_MANAGEMENT[i]) == 0) {
            return 1;
        }
    }

    for (int i = 0; i < sizeof(SCIENTIFIC_PEDAGOGICAL) / sizeof(SCIENTIFIC_PEDAGOGICAL[0]); i++) {
        if (strcmp(profession, SCIENTIFIC_PEDAGOGICAL[i]) == 0) {
            return 1;
        }
    }

    for (int i = 0; i < sizeof(SUPPORTING_STAFF) / sizeof(SUPPORTING_STAFF[0]); i++) {
        if (strcmp(profession, SUPPORTING_STAFF[i]) == 0) {
            return 1;
        }
    }

    for (int i = 0; i < sizeof(ADMINISTRATIVE_HOUSEHOLD) / sizeof(ADMINISTRATIVE_HOUSEHOLD[0]); i++) {
        if (strcmp(profession, ADMINISTRATIVE_HOUSEHOLD[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void get_valid_profession(const char* m, char* prof, size_t size) {
    while (1) {
        printf("%s", m);
        fgets(prof, size, stdin);
        prof[strcspn(prof, "\n")] = '\0';
        if (is_profession(prof)) {
            break;
        }
        printf("Invalid profession. Please try again. \n");
    }
}

int is_lecturer(Employee* employee) {
    for (int i = 0; i < sizeof(SCIENTIFIC_PEDAGOGICAL) / sizeof(SCIENTIFIC_PEDAGOGICAL[0]); i++) {
        if (strcmp(employee->profession, SCIENTIFIC_PEDAGOGICAL[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

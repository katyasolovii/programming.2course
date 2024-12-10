// university.c
#include "../headers/university.h"
#include "input_validation.c"

int get_number_of_students() {
    return get_valid_int("How many students do you want to enter? ");
}

void input_student_data(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter data for student #%d: \n", i + 1);
        getchar();
        get_valid_string("First name: ", students[i].person.first_name, sizeof(students[i].person.first_name));
        get_valid_string("Last name: ", students[i].person.last_name, sizeof(students[i].person.last_name));
        get_valid_string("Specialty: ", students[i].specialty, sizeof(students[i].specialty));
        get_valid_degree("Degree level (Bachelor/Master): ", students[i].degree_level, sizeof(students[i].degree_level));
        students[i].year_of_study = get_valid_int("Year of study: ");
        getchar();
        students[i].average_grade = get_valid_double("Average grade: ");
        students[i].num_of_lecturers = get_valid_int("Number of lecturers teaching this student: ");

        students[i].lecturers = malloc(students[i].num_of_lecturers * sizeof(Lecturer));
        if (students[i].lecturers == NULL) {
            printf("Error: Unable to allocate memory for lecturers of student. \n");
            return;
        }
        
        for (int j = 0; j < students[i].num_of_lecturers; j++) {
            printf("\nEnter data for Lecturer #%d: \n", j + 1);
            getchar();
            get_valid_string("First name: ", students[i].lecturers[j].first_name, sizeof(students[i].lecturers[j].first_name));
            get_valid_string("Last name: ", students[i].lecturers[j].last_name, sizeof(students[i].lecturers[j].last_name));
        }
        students[i].type_scholarship = 'N';
    }
}

void sorted_students(Student* students, int num_students, Record_book* recordBook, char specialties[][200]) {
    recordBook->students_by_degree_specialty_and_year = malloc(2 * sizeof(Student****)); // Bachelor 0 і Master 1
    for (int level = 0; level < 2; level++) {
        recordBook->students_by_degree_specialty_and_year[level] = malloc(recordBook->num_specialties * sizeof(Student***));
        for (int i = 0; i < recordBook->num_specialties; i++) {
            recordBook->students_by_degree_specialty_and_year[level][i] = malloc(6 * sizeof(Student**));
            for (int year = 0; year < 6; year++) {
                recordBook->students_by_degree_specialty_and_year[level][i][year] = malloc(num_students * sizeof(Student*));
            }
        }
    }
    // вказує на масив цілих чисел (вказівник на масив вказівників)
    int** group_sizes[2] = {malloc(recordBook->num_specialties * sizeof(int*)), malloc(recordBook->num_specialties * sizeof(int*))};
    for (int level = 0; level < 2; level++) {
        for (int i = 0; i < recordBook->num_specialties; i++) {
            group_sizes[level][i] = calloc(4, sizeof(int));
        }
    }

    for (int i = 0; i < num_students; i++) {
        int level = strcmp(students[i].degree_level, "Master") == 0 ? 1 : 0;
        int specialty_index = find_specialty_index(specialties, recordBook->num_specialties, students[i].specialty);
        // індексація в масиві з 0 починається
        int year_index = students[i].year_of_study - 1;

        recordBook->students_by_degree_specialty_and_year[level][specialty_index][year_index][group_sizes[level][specialty_index][year_index]++] = &students[i];
    }

    for (int level = 0; level < 2; level++) {
        free(group_sizes[level]);
    }
}

void calculate_scholarships(Student* students, int num_students, Record_book* recordBook, char specialties[][200]) {
    for (int level = 0; level < 2; level++) {  // 0 - Bachelor, 1 - Master
        for (int specialty_index = 0; specialty_index < recordBook->num_specialties; specialty_index++) {
            for (int year = 0; year < 4; year++) {
                int num_students_in_group = 0;
                // Підраховуємо кількість студентів в поточній групі
                for (int i = 0; i < num_students; i++) {
                    if (strcmp(students[i].degree_level, level == 0 ? "Bachelor" : "Master") == 0 &&
                        strcmp(students[i].specialty, specialties[specialty_index]) == 0 &&
                        students[i].year_of_study == year + 1) {
                        num_students_in_group++;
                    }
                }

                // створення масиву для студентів цієї групи
                Student** group_students = malloc(num_students_in_group * sizeof(Student*));
                int idx = 0;
                for (int i = 0; i < num_students; i++) {
                    if (strcmp(students[i].degree_level, level == 0 ? "Bachelor" : "Master") == 0 &&
                        strcmp(students[i].specialty, specialties[specialty_index]) == 0 &&
                        students[i].year_of_study == year + 1) {
                        group_students[idx++] = &students[i];
                    }
                }

                // сортування студентів цієї групи за середнім балом (від найвищого до найнижчого)
                for (int i = 0; i < num_students_in_group - 1; i++) {
                    for (int j = i + 1; j < num_students_in_group; j++) {
                        if (group_students[i]->average_grade < group_students[j]->average_grade) {
                            Student* temp = group_students[i];
                            group_students[i] = group_students[j];
                            group_students[j] = temp;
                        }
                    }
                }

                // розрахунок стипендії для 45% найкращих студентів
                int regular_scholarship_count = (int)(num_students_in_group * 0.45);
                for (int i = 0; i < regular_scholarship_count; i++) {
                    group_students[i]->type_scholarship = 'R';
                }

                // розрахунок підвищеної стипендії для 20% серед тих, хто отримує звичайну
                int increased_scholarship_count = (int)(regular_scholarship_count * 0.20);
                for (int i = 0; i < increased_scholarship_count; i++) {
                    group_students[i]->type_scholarship = 'I';
                }
                free(group_students);
            }
        }
    }

    printf("Scholarships have been calculated successfully.\n");
}

void generate_filename(const char *ind, const char *form, char *filename) {
    int num = 1;
    char temp_filename[50];

    while (1) {
        // обєднує значення змінних ind, num, form +записує в temp_filname
        snprintf(temp_filename, sizeof(temp_filename), "%s_%d.%s", ind, num, form);
        if (!file_exists(temp_filename)) {
            strcpy(filename, temp_filename);
            break;
        }
        num++;
    }
}

void save_students_to_json(Student* students, int num_students) {
    char filename[100];
    generate_filename("students", "json", filename); 

    // Створюємо кореневий JSON-об'єкт
    cJSON *json_root = cJSON_CreateObject();

    //  масив студентів
    cJSON *json_students = cJSON_CreateArray();
    for (int i = 0; i < num_students; i++) {
        // для кожного студента створюю окремий JSON-об'єкт 
        cJSON *json_student = cJSON_CreateObject();
        cJSON_AddStringToObject(json_student, "first_name", students[i].person.first_name);
        cJSON_AddStringToObject(json_student, "last_name", students[i].person.last_name);
        cJSON_AddStringToObject(json_student, "specialty", students[i].specialty);
        cJSON_AddStringToObject(json_student, "degree_level", students[i].degree_level);
        cJSON_AddNumberToObject(json_student, "year_of_study", students[i].year_of_study);
        cJSON_AddNumberToObject(json_student, "average_grade", students[i].average_grade);
        cJSON_AddStringToObject(json_student, "type_scholarship", 
            (students[i].type_scholarship == 'N') ? "None" : 
            (students[i].type_scholarship == 'R') ? "Regular" : "Increased");

        cJSON *json_lecturers = cJSON_CreateArray();
        for (int j = 0; j < students[i].num_of_lecturers; j++) {
            cJSON *json_lecturer = cJSON_CreateObject();
            cJSON_AddStringToObject(json_lecturer, "first_name", students[i].lecturers[j].first_name);
            cJSON_AddStringToObject(json_lecturer, "last_name", students[i].lecturers[j].last_name);
            cJSON_AddItemToArray(json_lecturers, json_lecturer);
        }
        cJSON_AddItemToObject(json_student, "lecturers", json_lecturers);
        // кожен студент додається до загального списку студентів
        cJSON_AddItemToArray(json_students, json_student);
    }

    cJSON_AddItemToObject(json_root, "students", json_students);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file \n");
        cJSON_Delete(json_root);
        return;
    }
    char *json_string = cJSON_Print(json_root);
    // записує текст у файл
    fprintf(file, "%s\n", json_string);
    fclose(file);

    cJSON_Delete(json_root);
    free(json_string);

    printf("Student data has been saved to %s\n", filename);
}

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    // переміщення вказівник (читання) на кінець файлу
    fseek(file, 0, SEEK_END);
    // визначення довжини файлу
    long length = ftell(file);
    // переміщення вказівника назад на початок файлу
    rewind(file);

    char* content = malloc(length + 1);
    if (content) {
        fread(content, 1, length, file);
        // щоб потім перетворити вміст файлу в рядок і працювати далі з ним
        content[length] = '\0';
    }
    fclose(file);
    return content;
}

// завантаження json даних із файлу
cJSON* load_json_from_file(const char* filename, const char* key) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // вказівник типу char* (масив символів)
    char* file_content = (char*)malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        return NULL;
    }

    fread(file_content, 1, file_size, file);
    file_content[file_size] = '\0';

    cJSON* json = cJSON_Parse(file_content);
    if (json == NULL) {
        printf("Error parsing JSON.\n");
        free(file_content);
        fclose(file);
        return NULL;
    }

    // пошук значення за відповідним ключем
    cJSON* array = cJSON_GetObjectItem(json, key);
    if (array == NULL) {
        printf("No data found for key: %s\n", key);
        cJSON_Delete(json);
        free(file_content);
        fclose(file);
        return NULL;
    }

    free(file_content);
    fclose(file);

    return array;
}

// Відображення студентів у таблиці
void display_students_from_json(cJSON* students) {
    // ініціалізація бібліотека
    initscr();
    // режим raw input, який не відображає натискання клавіатури
    raw();
    //  standard screen (вікно, де відображається таблиця)
    keypad(stdscr, TRUE);
    // заборона виведення на екран введених символів
    noecho();
    clear();

    int row, col;
    // отримання розміру терміналу (к-ст рядків, стовпців)
    getmaxyx(stdscr, row, col);
    int start_row = 1;
    // виводить текст у конкретному місці екрана
    mvprintw(0, 0, "%-15s %-15s %-20s %-20s %-10s %-15s %-15s %-40s",
             "First Name", "Last Name", "Specialty", "Degree Level", "Year", "Average Grade", "Scholarship", "Lecturer");

    // к-сть елементів у масиві студентів
    int num_of_students = cJSON_GetArraySize(students);
    for (int i = 0; i < num_of_students; i++) {
        // конкретний студент з масиву
        cJSON* student = cJSON_GetArrayItem(students, i);

        // витягання значення з json за ключем, отримання значення як рядок, число, float
        const char* first_name = cJSON_GetObjectItem(student, "first_name")->valuestring;
        const char* last_name = cJSON_GetObjectItem(student, "last_name")->valuestring;
        const char* specialty = cJSON_GetObjectItem(student, "specialty")->valuestring;
        const char* degree_level = cJSON_GetObjectItem(student, "degree_level")->valuestring;
        int year_of_study = cJSON_GetObjectItem(student, "year_of_study")->valueint;
        double average_grade = cJSON_GetObjectItem(student, "average_grade")->valuedouble;
        const char* scholarship = cJSON_GetObjectItem(student, "type_scholarship")->valuestring;

        cJSON* lecturers = cJSON_GetObjectItem(student, "lecturers");
        int num_of_lecturers = cJSON_GetArraySize(lecturers);

        char lecturer_name[50];
        // об'єднує ім'я та прізвище і формує це як один рядок
        snprintf(lecturer_name, sizeof(lecturer_name), "%s %s",
                cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, 0), "first_name")->valuestring,
                cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, 0), "last_name")->valuestring);
        mvprintw(start_row, 0, "%-15s %-15s %-20s %-20s %-10d %-15.2f %-15s %-40s",
                first_name, last_name, specialty, degree_level, year_of_study, average_grade, scholarship, lecturer_name);
        start_row++;

        for (int j = 1; j < num_of_lecturers; j++) {
            char lecturer_name[50];
            snprintf(lecturer_name, sizeof(lecturer_name), "%s %s",
                     cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, j), "first_name")->valuestring,
                     cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, j), "last_name")->valuestring);

            mvprintw(start_row, 0, "%-15s %-15s %-20s %-20s %-10s %-15s %-15s %-40s",
                     "", "", "", "", "", "", "", lecturer_name);

            start_row++;
        }

        mvprintw(start_row, 0, "\n");
        start_row++;
        // для перевірки чи перевищено макс рядків терміналу
        if (start_row >= row - 1) {
            break;
        }
    }
    // відображення таблиці
    refresh();
    // очікування на натискання клавіші
    getch();
    endwin();
}

int get_number_of_employees() {
    return get_valid_int("How many employees do you want to enter? ");
}

void input_data(Employee* employee) {
    getchar();
    get_valid_string("First name: ", employee->person.first_name, sizeof(employee->person.first_name));
    get_valid_string("Last name: ", employee->person.last_name, sizeof(employee->person.last_name));
    get_valid_profession("Profession: ", employee->profession, sizeof(employee->profession));
    employee->base_salary = get_valid_double("Base salary: ");
    employee->years_of_experience = get_valid_int("Years of experience: ");
    calculate_salary(employee);
}

void input_employees_data(Employee* employees, int num_of_employees) {
    for (int i = 0; i < num_of_employees; i++) {
        printf("Enter data for employee %d: \n", i + 1);
        input_data(&employees[i]);
    }
}

void calculate_salary(Employee* employee) {
    double experience_multiplier = 1.0 + (0.05 * employee->years_of_experience);
    double group_multiplier = 1.0;

    // ділимо загальний розмір масиву на розмір одного елемента з нього і так можна дізнатися к-сть елементів в масиві
    for (int i = 0; i < sizeof(ADMINISTRATIVE_MANAGEMENT) / sizeof(ADMINISTRATIVE_MANAGEMENT[0]); i++) {
        if (strcmp(employee->profession, ADMINISTRATIVE_MANAGEMENT[i]) == 0) {
            group_multiplier = 2.0; 
            break;
        }
    }

    for (int i = 0; i < sizeof(SCIENTIFIC_PEDAGOGICAL) / sizeof(SCIENTIFIC_PEDAGOGICAL[0]); i++) {
        if (strcmp(employee->profession, SCIENTIFIC_PEDAGOGICAL[i]) == 0) {
            group_multiplier = 1.5;
            break;
        }
    }

    for (int i = 0; i < sizeof(SUPPORTING_STAFF) / sizeof(SUPPORTING_STAFF[0]); i++) {
        if (strcmp(employee->profession, SUPPORTING_STAFF[i]) == 0) {
            group_multiplier = 1.2;
            break;
        }
    }

    for (int i = 0; i < sizeof(ADMINISTRATIVE_HOUSEHOLD) / sizeof(ADMINISTRATIVE_HOUSEHOLD[0]); i++) {
        if (strcmp(employee->profession, ADMINISTRATIVE_HOUSEHOLD[i]) == 0) {
            group_multiplier = 1.0;
            break;
        }
    }
    employee->salary = employee->base_salary * experience_multiplier * group_multiplier;
}

void save_employees_to_json(Employee* employees, int num_of_employees, const char* base_filename) {
    char filename[50];
    generate_filename(base_filename, "json", filename);

    cJSON* root = cJSON_CreateObject();
    cJSON* employees_array = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "employees", employees_array);

    for (int i = 0; i < num_of_employees; i++) {
        cJSON* employee_json = cJSON_CreateObject();
        cJSON_AddStringToObject(employee_json, "first_name", employees[i].person.first_name);
        cJSON_AddStringToObject(employee_json, "last_name", employees[i].person.last_name);
        cJSON_AddStringToObject(employee_json, "profession", employees[i].profession);
        cJSON_AddNumberToObject(employee_json, "base_salary", employees[i].base_salary);
        cJSON_AddNumberToObject(employee_json, "years_of_experience", employees[i].years_of_experience);
        cJSON_AddNumberToObject(employee_json, "salary", employees[i].salary);
        cJSON_AddItemToArray(employees_array, employee_json);
    }

    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        char* json_string = cJSON_Print(root);
        fprintf(file, "%s\n", json_string);
        fclose(file);
        free(json_string);
        printf("Employee data successfully saved to file: %s\n", filename);
    } 
    else {
        printf("Error writing to file: %s\n", filename);
    }

    cJSON_Delete(root);
}

void save_lecturers_to_json(Employee* employees, int num_of_employees, const char* base_filename) {
    char filename[50];
    generate_filename(base_filename, "json", filename); 

    cJSON* root = cJSON_CreateObject();
    cJSON* lecturers_array = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "lecturers", lecturers_array);

    for (int i = 0; i < num_of_employees; i++) {
        if (is_lecturer(&employees[i])) {
            cJSON* lecturer_json = cJSON_CreateObject();
            cJSON_AddStringToObject(lecturer_json, "first_name", employees[i].person.first_name);
            cJSON_AddStringToObject(lecturer_json, "last_name", employees[i].person.last_name);
            cJSON_AddStringToObject(lecturer_json, "profession", employees[i].profession);
            cJSON_AddNumberToObject(lecturer_json, "base_salary", employees[i].base_salary);
            cJSON_AddNumberToObject(lecturer_json, "years_of_experience", employees[i].years_of_experience);
            cJSON_AddNumberToObject(lecturer_json, "salary", employees[i].salary);
            cJSON_AddItemToArray(lecturers_array, lecturer_json);
        }
    }

    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        char* json_string = cJSON_Print(root);
        fprintf(file, "%s\n", json_string);
        fclose(file);
        free(json_string);
        printf("Lecturer data successfully saved to file: %s\n", filename);
    } 
    else {
        printf("Error writing to file: %s\n", filename);
    }

    cJSON_Delete(root);
}

float calculate_average_grade_for_lecturer(const cJSON *students_json, const char *lecturer_first_name, const char *lecturer_last_name) {
    cJSON *students_array = cJSON_GetObjectItem(students_json, "students");
    int student_count = cJSON_GetArraySize(students_array);
    float total_grade = 0.0;
    int student_found = 0;

    for (int i = 0; i < student_count; i++) {
        cJSON *student = cJSON_GetArrayItem(students_array, i);
        cJSON *lecturers = cJSON_GetObjectItem(student, "lecturers");
        int lecturer_count = cJSON_GetArraySize(lecturers);
        for (int j = 0; j < lecturer_count; j++) {
            cJSON *lecturer = cJSON_GetArrayItem(lecturers, j);
            cJSON *first_name = cJSON_GetObjectItem(lecturer, "first_name");
            cJSON *last_name = cJSON_GetObjectItem(lecturer, "last_name");
            if (strcmp(first_name->valuestring, lecturer_first_name) == 0 && strcmp(last_name->valuestring, lecturer_last_name) == 0) {
                total_grade += cJSON_GetObjectItem(student, "average_grade")->valuedouble;
                student_found++;
                break;
            }
        }
    }

    if (student_found > 0) {
        return total_grade / student_found;
    } else {
        return -1;
    }
}

void update_lecturers_file(const char *filename, cJSON *lecturers_json) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    char *updated_json = cJSON_Print(lecturers_json);
    fprintf(file, "%s", updated_json);
    fclose(file);
    free(updated_json);
}

void update_lecturers(const char *students_file, const char *lecturers_file) {
    char* students_content = read_file(students_file);
    if (!students_content) {
        printf("Error reading students file.\n");
        return;
    }

    cJSON *students_json = cJSON_Parse(students_content);
    free(students_content); 
    if (!students_json) {
        printf("Error parsing students JSON.\n");
        return;
    }

    char* lecturers_content = read_file(lecturers_file);
    if (!lecturers_content) {
        printf("Error reading lecturers file.\n");
        cJSON_Delete(students_json);
        return;
    }

    cJSON *lecturers_json = cJSON_Parse(lecturers_content);
    free(lecturers_content); 
    if (!lecturers_json) {
        printf("Error parsing lecturers JSON.\n");
        cJSON_Delete(students_json);
        return;
    }

    cJSON *lecturers_array = cJSON_GetObjectItem(lecturers_json, "lecturers");
    int lecturer_count = cJSON_GetArraySize(lecturers_array);
    for (int i = 0; i < lecturer_count; i++) {
        cJSON *lecturer = cJSON_GetArrayItem(lecturers_array, i);
        cJSON *first_name = cJSON_GetObjectItem(lecturer, "first_name");
        cJSON *last_name = cJSON_GetObjectItem(lecturer, "last_name");
        float average_grade = calculate_average_grade_for_lecturer(students_json, first_name->valuestring, last_name->valuestring);
        if (average_grade >= 0) {
            cJSON_AddNumberToObject(lecturer, "average_grade", average_grade);
        }
    }
    update_lecturers_file(lecturers_file, lecturers_json);

    cJSON_Delete(students_json);
    cJSON_Delete(lecturers_json);
    printf("Lecturers file has been successfully updated.\n");
}

void display_lecturers_from_json(cJSON *lecturers) {
    initscr(); 
    raw(); 
    keypad(stdscr, TRUE); 
    noecho();
    clear();

    int row, col;
    getmaxyx(stdscr, row, col);
    int start_row = 1;
    mvprintw(0, 0, "%-15s %-15s %-20s %-15s %-20s %-15s %-15s", 
             "First Name", "Last Name", "Profession", "Experience", "Base Salary", "Salary", "Average Grade");

    int num_of_lecturers = cJSON_GetArraySize(lecturers);
    for (int i = 0; i < num_of_lecturers; i++) {
        cJSON *lecturer = cJSON_GetArrayItem(lecturers, i);
        const char *first_name = cJSON_GetObjectItem(lecturer, "first_name")->valuestring;
        const char *last_name = cJSON_GetObjectItem(lecturer, "last_name")->valuestring;
        const char *profession = cJSON_GetObjectItem(lecturer, "profession")->valuestring;
        double base_salary = cJSON_GetObjectItem(lecturer, "base_salary")->valuedouble;
        int years_of_experience = cJSON_GetObjectItem(lecturer, "years_of_experience")->valueint;
        double salary = cJSON_GetObjectItem(lecturer, "salary")->valuedouble;
        double average_grade = cJSON_GetObjectItem(lecturer, "average_grade")->valuedouble;
        mvprintw(start_row, 0, "%-15s %-15s %-20s %-15d %-20.2f %-15.2f %-15.2f", 
                 first_name, last_name, profession, years_of_experience, base_salary, salary, average_grade);
        start_row++; 
        if (start_row >= row - 1) {
            break;
        }
    }

    refresh();
    getch();
    endwin();
}

void display_employees_from_json(cJSON *employees) {
    initscr();
    raw(); 
    keypad(stdscr, TRUE);  
    noecho();
    clear();

    int row, col;
    getmaxyx(stdscr, row, col);  
    int start_row = 1;
    mvprintw(0, 0, "%-15s %-15s %-20s %-20s %-15s %-15s", 
             "First Name", "Last Name", "Profession", "Base Salary", "Experience", "Salary");

    int num_of_employees = cJSON_GetArraySize(employees);
    for (int i = 0; i < num_of_employees; i++) {
        cJSON *employee = cJSON_GetArrayItem(employees, i);
        const char *first_name = cJSON_GetObjectItem(employee, "first_name")->valuestring;
        const char *last_name = cJSON_GetObjectItem(employee, "last_name")->valuestring;
        const char *profession = cJSON_GetObjectItem(employee, "profession")->valuestring;
        double base_salary = cJSON_GetObjectItem(employee, "base_salary")->valuedouble;
        int years_of_experience = cJSON_GetObjectItem(employee, "years_of_experience")->valueint;
        double salary = cJSON_GetObjectItem(employee, "salary")->valuedouble;
        mvprintw(start_row, 0, "%-15s %-15s %-20s %-20.2f %-15d %-15.2f", 
                 first_name, last_name, profession, base_salary, years_of_experience, salary);
        start_row++;
        if (start_row >= row - 1) {
            break;
        }
    }

    refresh();
    getch();
    endwin();
}

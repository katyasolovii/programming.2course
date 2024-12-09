#include "src/university.c"

int main() {
    int choice;

    while (1) {
        system("clear");

        printf("Welcome to the program! \n");
        printf("Options menu: \n");
        printf("1. Enter student data and save to file \n");
        printf("2. Enter employee and lecturer data and save to file \n");
        printf("3. Display student data from file \n");
        printf("4. Display employee data from file \n");
        printf("5. Display lecturer data from file \n");
        printf("6. Exit \n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please try again. \n");
            while (getchar() != '\n');
            printf("Press 'Enter' to continue.");
            getchar();
            continue;
        }

        if (choice < 1 || choice > 6) {
            printf("Error: Invalid choice. Please enter a number between 1 and 6. \n");
            while (getchar() != '\n');
            printf("Press 'Enter' to continue.");
            getchar();
            continue;
        }

        if (choice == 1) {
            int num_students = get_number_of_students();
            Student* students = malloc(num_students * sizeof(Student));
            input_student_data(students, num_students);

            char specialties[200][200];
            int num_specialties = 0;
            
            for (int i = 0; i < num_students; i++) {
                if (find_specialty_index(specialties, num_specialties, students[i].specialty) == -1) {
                    // копіювання спеціальності студента в масив specialties
                    strcpy(specialties[num_specialties], students[i].specialty);
                    num_specialties++;
                }
            }

            Record_book recordBook;
            recordBook.num_specialties = num_specialties;
            calculate_scholarships(students, num_students, &recordBook, specialties);

            save_students_to_json(students, num_students);

            free(students);
        } 
        else if (choice == 2) {
            int num_employees = get_number_of_employees();
            Employee* employees = malloc(num_employees * sizeof(Employee));
            input_employees_data(employees, num_employees);

            save_employees_to_json(employees, num_employees, "employees");
            save_lecturers_to_json(employees, num_employees, "lecturers");

            free(employees);

            printf("Enter file names for calculating the average grade of students for each lecturer: \n");

            char students_file[100];
            char lecturers_file[100];

            printf("Enter the student file name: \n");
            getchar();
            fgets(students_file, sizeof(students_file), stdin);
            students_file[strcspn(students_file, "\n")] = '\0';

            printf("Enter the lecturer file name: \n");
            fgets(lecturers_file, sizeof(lecturers_file), stdin);
            lecturers_file[strcspn(lecturers_file, "\n")] = '\0'; 

            update_lecturers(students_file, lecturers_file);
            printf("All operations completed successfully.\n");
        } 
        else if (choice == 3) {
            char student_file[100];
            printf("Enter the filename to read student data: ");
            scanf("%s", student_file);

            cJSON* students_array = load_json_from_file(student_file, "students");
            if (students_array == NULL) {
                printf("Failed to load student data.\n");
            } 
            else {
                display_students_from_json(students_array);
                cJSON_Delete(students_array);
            }
        } 
        else if (choice == 4) {
            char employee_file[100];
            printf("Enter the filename to read employee data: ");
            scanf("%s", employee_file);

            cJSON* employees_array = load_json_from_file(employee_file, "employees");

            if (employees_array != NULL) {
                display_employees_from_json(employees_array);
                cJSON_Delete(employees_array);
            } else {
                printf("Failed to load employee data.\n");
            }
        } 
        else if (choice == 5) {
            char lecturer_file[100];
            printf("Enter the filename to read lecturer data: ");
            scanf("%s", lecturer_file);

            cJSON* lecturers_array = load_json_from_file(lecturer_file, "lecturers");

            if (lecturers_array != NULL) {
                display_lecturers_from_json(lecturers_array);
                cJSON_Delete(lecturers_array);
            } else {
                printf("Failed to load lecturer data.\n");
            }
        } 
        else if (choice == 6) {
            printf("Program completed! \n");
            break; 
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}
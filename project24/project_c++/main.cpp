#include "src/uni.cpp"

using namespace std;

int main() {
    int choice;

    while (true) {
        system("clear");

        cout << "Welcome to the program! \n";
        cout << "Options menu: \n";
        cout << "1. Enter student data and save to file \n";
        cout << "2. Enter employee and lecturer data and save to file \n";
        cout << "3. Display student data from file \n";
        cout << "4. Display employee data from file \n";
        cout << "5. Display lecturer data from file \n";
        cout << "6. Exit \n";

        cout << "Enter your choice: ";
        string input_choice;
        getline(cin, input_choice);

        if (is_valid_Int(input_choice, choice)) {
            if (choice == 1) {
                vector<Student> students;
                int numStudents;
                cout << "How many students do you want to enter? ";
                cin >> numStudents;
                cin.ignore();
                for (int i = 0; i < numStudents; ++i) {
                    input_students_data(i, students); 
                }
                sort(students.begin(), students.end(), compare);
                calculate_Scholarships(students);
                save_Student_to_json(students);
            }
            else if (choice == 2) {
                string students_filename;
                string lecturers_filename;

                get_file_name(students_filename, "students");
                get_file_name(lecturers_filename, "lecturers");

                update_lecturer_average_grades(students_filename, lecturers_filename);
            }
            else if (choice == 3) {
                string f_name;
                cout << "Enter the file name (e.g., students.json) to display: ";
                cin >> f_name;

                ifstream file(f_name);
                if (!file) {
                    cout << "File not found!" << endl;
                    continue;
                }

                cJSON* students_json = load_json_from_file(f_name.c_str(), "students");
                if (students_json == NULL) {
                    cout << "Failed to load data from the file!" << endl;
                    continue;
                }

                display_students_from_json(students_json);
            }
            else if (choice == 4) {
                char employee_file[50];
                cout << "Enter the filename to read employee data: ";
                cin >> employee_file;

                cJSON* employees_array = load_json_from_file(employee_file, "employees");

                if (employees_array != NULL) {
                    display_Employees(employees_array);
                    cJSON_Delete(employees_array);
                } else {
                    cout << "Failed to load employee data." << endl;
                }
            }
            else if (choice == 5) {
                char lecturer_file[50];
                cout << "Enter the filename to read lecturer data: ";
                cin >> lecturer_file;

                cJSON* lecturers_array = load_json_from_file(lecturer_file, "lecturers");

                if (lecturers_array != NULL) {
                    display_Lecturers(lecturers_array);
                    cJSON_Delete(lecturers_array);
                } else {
                    cout << "Failed to load lecturer data." << endl;
                }
            }
            else if (choice == 6) {
                cout << "Program completed!" << endl;
                break;
            }
            else {
                cout << "Invalid choice, please try again!" << endl;
            }
        } else {
            cout << "Invalid input. Please enter a valid option (1-6)." << endl;
        }

        cout << "\n Press Enter to continue...";
        cin.ignore(); 
    }
}

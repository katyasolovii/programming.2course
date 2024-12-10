#include "../headers/uni.h"
#include "check.cpp"

/*
Фунція сортує студентів, повірнюючи на основі кількох критеріїв: спеціальності, освітнього рівня, року навчання та середнього балу. 
Спочатку порівнюються спеціальності студентів, потім рівень освіти, рік навчання, і, якщо ці параметри однакові, порівнюється середній бал студентів.

Input: 
    const Student& s1 - перший студент.
    const Student& s2 - другий студент.

Output:
    bool: повертає true, якщо s1 < s2, інакше - false.
*/
bool compare(const Student& s1, const Student& s2) {
    if (s1.specialty != s2.specialty) return s1.specialty < s2.specialty;
    if (s1.degree_level != s2.degree_level) return s1.degree_level < s2.degree_level;
    if (s1.year_of_study != s2.year_of_study) return s1.year_of_study < s2.year_of_study;
    return s1.average_grade > s2.average_grade; 
}

/*
Функція обчислює стипендії для студентів. Студентам, які належать до однакової спеціальності, ступеня та року навчання, 
присвоюються стипендії: звичайні, збільшені або без стипендії.

Input: 
    vector<Student>& students - вектор студентів, для яких потрібно обчислити стипендії.

Result:
    вектор students буде оновлений з новими значеннями стипендій.
*/
void calculate_Scholarships(vector<Student>& students) {
    for (int i = 0; i < students.size(); ++i) {
        int count = 0;
        int regular_Count = 0;
        int increased_Count = 0;
        // студенти, які мають однакову спеціальність, курс, освітній ступень
        vector<Student> common_student;
        for (int j = i; j < students.size(); ++j) {
            if (students[i].specialty == students[j].specialty && 
                students[i].degree_level == students[j].degree_level && 
                students[i].year_of_study == students[j].year_of_study) {
                common_student.push_back(students[j]);
                count++;
            } 
            else {
                break;
            }
        }
        int regular_count = count * 0.45;
        int increased_count = regular_count * 0.20;
        for (int j = 0; j < common_student.size(); ++j) {
            if (j < regular_count) {
                common_student[j].scholarship_type = "Regular";
            } 
            else if (j < (regular_count + increased_count)) {
                common_student[j].scholarship_type = "Increased";
            } 
            else {
                common_student[j].scholarship_type = "None";
            }
        }
        for (int j = 0; j < common_student.size(); ++j) {
            // оновлення стипендій в основому vector students
            students[i + j].scholarship_type = common_student[j].scholarship_type;
        }
        // пропускаємо вже оброблених студентів
        i += common_student.size() - 1; 
    }
}

/*
Функція перевіряє, чи існує файл з вказаним ім'ям.

Input: 
    const string& fileName - ім'я файлу, який потрібно перевірити.

Output:
    bool: повертає true, якщо файл існує, інакше повертає false.
*/
bool file_Exists(const string& fileName) {
    ifstream file(fileName);
    return file.good();
}

/*
Функція створює унікальне ім'я файлу на основі переданого ключа. 
Якщо файл з таким ім'ям вже існує, додається індекс до імені файлу.

Input: 
    const string& key - ключ, який буде використаний для формування імені файлу.

Output:
    string: повертає унікальне ім'я файлу
*/
string create_filename(const string& key) {
    string base_name = key + ".json";
    int index = 1;
    while (file_Exists(base_name)) {
        stringstream fn;
        fn << key << "_" << index++ << ".json";
        base_name = fn.str();
    }
    return base_name;
}

/*
Функція зберігає дані студентів у форматі JSON в файл. 
Для кожного студента виводяться ім'я, прізвище, спеціальність, рівень освіти, 
рік навчання, середній бал, тип стипендії та викладачі.

Input: 
    const vector<Student>& students - вектор студентів, дані яких потрібно зберегти.

Result:
    дані зберігаються у файл у форматі JSON.
*/
void save_Student_to_json(const vector<Student>& students) {
    cJSON *r = cJSON_CreateObject();
    cJSON *students_array = cJSON_CreateArray();
    // майбутній ключ
    cJSON_AddItemToObject(r, "students", students_array);
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];
        cJSON *student_json = cJSON_CreateObject();
        // json - с-бібліотека, вона працює з с рядками, тому треба використовувати c_str(), щоб рядок мав вигляl const char*
        cJSON_AddStringToObject(student_json, "first_name", student.first_name.c_str());
        cJSON_AddStringToObject(student_json, "last_name", student.last_name.c_str());
        cJSON_AddStringToObject(student_json, "specialty", student.specialty.c_str());
        cJSON_AddNumberToObject(student_json, "year_of_study", student.year_of_study);
        cJSON_AddStringToObject(student_json, "degree_level", student.degree_level.c_str());
        cJSON_AddNumberToObject(student_json, "average_grade", student.average_grade);
        cJSON_AddStringToObject(student_json, "scholarship_type", student.scholarship_type.c_str());
        cJSON *lecturers_array = cJSON_CreateArray();
        for (size_t j = 0; j < student.lecturers.size(); ++j) {
            const Person& lecturer = student.lecturers[j];
            cJSON *lecturerJson = cJSON_CreateObject();
            cJSON_AddStringToObject(lecturerJson, "first_name", lecturer.first_name.c_str());
            cJSON_AddStringToObject(lecturerJson, "last_name", lecturer.last_name.c_str());
            cJSON_AddItemToArray(lecturers_array, lecturerJson);
        }
        cJSON_AddItemToObject(student_json, "lecturers", lecturers_array);
        cJSON_AddItemToArray(students_array, student_json);
    }
    string fileName = create_filename("students");
    FILE *f = fopen(fileName.c_str(), "w");
    if (f == NULL) {
        cout << "Error opening file!" << endl;
        return;
    }
    char *jsonString = cJSON_Print(r);
    // запис рядка jsonString у файл f
    fputs(jsonString, f);
    fclose(f);
    cJSON_Delete(r);
    free(jsonString);
    cout << "Data saved to " << fileName << endl;
}

/*
Функція запитує у користувача інформацію про студента, зокрема ім'я, прізвище, спеціальність,
рівень освіти, рік навчання, середній бал, кількість викладачів та їхні дані. 
Потім ця інформація додається до вектора студентів.

Input: 
    int student_index -  індекс студента в списку.
    vector<Student>& students - вектор студентів, до якого буде додано нового студента.

Result:
    вектор студентів буде оновлений.
*/
void input_students_data(int student_index, vector<Student>& students) {
    string first_name, last_name, specialty, degree_level;
    int year_of_study;
    double average_grade;
    vector<Person> lecturers;
    cout << "Enter first name of student " << (student_index + 1) << ": ";
    while (true) {
        // зчитує введене з клавіатури, зберігає в fisrt_name
        getline(cin, first_name);
        if (is_valid_String(first_name)) break;
        cout << "First name must contain only letters. Please enter again: ";
    }
    cout << "Enter last name of student " << (student_index + 1) << ": ";
    while (true) {
        getline(cin, last_name);
        if (is_valid_String(last_name)) break;
        cout << "Last name must contain only letters. Please enter again: ";
    }
    cout << "Enter specialty: ";
    while (true) {
        getline(cin, specialty);
        if (is_valid_String(specialty)) break;
        cout << "Specialty cannot be empty. Please enter again: ";
    }
    cout << "Enter degree level (Bachelor or Master): ";
    while (true) {
        getline(cin, degree_level);
        if (is_valid_Degree(degree_level)) break;
        cout << "Degree level must be either 'Bachelor' or 'Master'. Please enter again: ";
    }
    cout << "Enter year of study: ";
    while (true) {
        string st;
        getline(cin, st);
        if (is_valid_Int(st, year_of_study)) {
            if ((degree_level == "Bachelor" && year_of_study >= 1 && year_of_study <= 4) ||
                (degree_level == "Master" && year_of_study >= 1 && year_of_study <= 2)) {
                break;
            }
        }
        cout << "Invalid year of study for " << degree_level << ". Please enter a valid year: ";
    }
    cout << "Enter average grade: ";
    while (true) {
        string st1;
        getline(cin, st1);
        if (is_valid_Double(st1, average_grade) && is_valid_average_grade(average_grade)) break;
        cout << "Invalid average grade. Please enter a valid number between 60 and 100: ";
    }
    int count_lecturers;
    cout << "Enter number of lecturers for this student: ";
    while (true) {
        string c_l;
        getline(cin, c_l);
        if (is_valid_Int(c_l, count_lecturers) && count_lecturers >= 0) break;
        cout << "Invalid number of lecturers. Please enter again: ";
    }
    for (int j = 0; j < count_lecturers; ++j) {
        string lecturerFirst_name, lecturerLast_name;
        cout << "Enter first name of lecturer " << (j + 1) << ": ";
        while (true) {
            getline(cin, lecturerFirst_name);
            if (is_valid_String(lecturerFirst_name)) break;
            cout << "Lecturer's first name must contain only letters. Please enter again: ";
        }
        cout << "Enter last name of lecturer " << (j + 1) << ": ";
        while (true) {
            getline(cin, lecturerLast_name);
            if (is_valid_String(lecturerLast_name)) break;
            cout << "Lecturer's last name must contain only letters. Please enter again: ";
        }
        lecturers.push_back(Person(lecturerFirst_name, lecturerLast_name));
    }
    students.push_back(Student(first_name, last_name, specialty, year_of_study, degree_level, average_grade, lecturers));
}

/*
Функція завантажує дані JSON-файлу і повертає елемент JSON, відповідний вказаному ключу.

Input: 
    const char* filename - ім'я файлу для зчитування.
    const char* key - ключ для знаходження потрібних даних у JSON.

Output:
    cJSON* - вказівник на елемент JSON, що відповідає ключу.
*/
cJSON* load_json_from_file(const char* filename, const char* key) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
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

/*
Функція виводить список студентів, зчитаних з JSON-файлу, на екран за допомогою бібліотеки ncurses 
у вигляді таблиці. 

Input: 
    cJSON* students - вказівник на масив студентів у JSON.

Result:
    студенти виводяться на екран у консоль у вигялді таблиці.
*/
void display_students_from_json(cJSON* students) {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    clear();
    int row, col;
    getmaxyx(stdscr, row, col);
    int start_row = 1;

    mvprintw(0, 0, "%-15s %-15s %-20s %-20s %-10s %-15s %-15s %-40s",
             "First Name", "Last Name", "Specialty", "Degree Level", "Year", "Average Grade", "Scholarship", "Lecturer");

    int num_of_students = cJSON_GetArraySize(students);
    for (int i = 0; i < num_of_students; i++) {
        cJSON* student = cJSON_GetArrayItem(students, i);
        const char* first_name = cJSON_GetObjectItem(student, "first_name")->valuestring;
        const char* last_name = cJSON_GetObjectItem(student, "last_name")->valuestring;
        const char* specialty = cJSON_GetObjectItem(student, "specialty")->valuestring;
        const char* degree_level = cJSON_GetObjectItem(student, "degree_level")->valuestring;
        int year_of_study = cJSON_GetObjectItem(student, "year_of_study")->valueint;
        double average_grade = cJSON_GetObjectItem(student, "average_grade")->valuedouble;
        const char* scholarship = cJSON_GetObjectItem(student, "scholarship_type")->valuestring;

        cJSON* lecturers = cJSON_GetObjectItem(student, "lecturers");
        int num_of_lecturers = cJSON_GetArraySize(lecturers);
        string lecturer_name = string(cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, 0), "first_name")->valuestring) + " " +
                               string(cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, 0), "last_name")->valuestring);
        mvprintw(start_row, 0, "%-15s %-15s %-20s %-20s %-10d %-15.2f %-15s %-40s",
                 first_name, last_name, specialty, degree_level, year_of_study, average_grade, scholarship, lecturer_name.c_str());
        start_row++; 

        for (int j = 1; j < num_of_lecturers; j++) {
            lecturer_name = string(cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, j), "first_name")->valuestring) + " " +
                            string(cJSON_GetObjectItem(cJSON_GetArrayItem(lecturers, j), "last_name")->valuestring);
            mvprintw(start_row, 0, "%-15s %-15s %-20s %-20s %-10s %-15s %-15s %-40s",
                     "", "", "", "", "", "", "", lecturer_name.c_str());
            start_row++;
        }
        //  вставляє порожній рядок (переходить на новий рядок) на екрані (пропуск між виведеними даними)
        mvprintw(start_row, 0, "\n");
        start_row++;
        if (start_row >= row - 1) {
            break;
        }
    }
    refresh();
    getch();
    endwin();
}

/*
Функція перевіряє, чи є передана професія правильною, перевіряючи її в списках професій.

Input: 
    const string& profession - професія, яку потрібно перевірити.

Output:
    bool: true, якщо професія є правильною, інакше false.
*/
bool is_valid_Profession(const string& profession) {
    for (int i = 0; i < sizeof(ADMINISTRATIVE_MANAGEMENT) / sizeof(ADMINISTRATIVE_MANAGEMENT[0]); i++) {
        if (profession == ADMINISTRATIVE_MANAGEMENT[i]) {
            return true;
        }
    }
    for (int i = 0; i < sizeof(SCIENTIFIC_PEDAGOGICAL) / sizeof(SCIENTIFIC_PEDAGOGICAL[0]); i++) {
        if (profession == SCIENTIFIC_PEDAGOGICAL[i]) {
            return true;
        }
    }
    for (int i = 0; i < sizeof(SUPPORTING_STAFF) / sizeof(SUPPORTING_STAFF[0]); i++) {
        if (profession == SUPPORTING_STAFF[i]) {
            return true;
        }
    }
    for (int i = 0; i < sizeof(ADMINISTRATIVE_HOUSEHOLD) / sizeof(ADMINISTRATIVE_HOUSEHOLD[0]); i++) {
        if (profession == ADMINISTRATIVE_HOUSEHOLD[i]) {
            return true;
        }
    }
    return false;
}

/*
Функція розраховує заробітну плату працівника, враховуючи його стаж роботи та професію.

Input: 
    Employee* employee - вказівник на об'єкт працівника, для якого потрібно обчислити заробітну плату.

Result:
    обчислена заробітна плата буде збережена в полі salary об'єкта працівника.
*/
void calculate_salary(Employee* employee) {
    double experience_multiplier = 1.0 + (0.05 * employee->years_of_experience); 
    double group_multiplier = 1.0; 

    for (int i = 0; i < sizeof(ADMINISTRATIVE_MANAGEMENT) / sizeof(ADMINISTRATIVE_MANAGEMENT[0]); i++) {
        if (strcmp(employee->profession.c_str(), ADMINISTRATIVE_MANAGEMENT[i]) == 0) {
            group_multiplier = 2.0; 
            break;
        }
    }
    for (int i = 0; i < sizeof(SCIENTIFIC_PEDAGOGICAL) / sizeof(SCIENTIFIC_PEDAGOGICAL[0]); i++) {
        if (strcmp(employee->profession.c_str(), SCIENTIFIC_PEDAGOGICAL[i]) == 0) {
            group_multiplier = 1.5;
            break;
        }
    }
    for (int i = 0; i < sizeof(SUPPORTING_STAFF) / sizeof(SUPPORTING_STAFF[0]); i++) {
        if (strcmp(employee->profession.c_str(), SUPPORTING_STAFF[i]) == 0) {
            group_multiplier = 1.2;
            break;
        }
    }
    for (int i = 0; i < sizeof(ADMINISTRATIVE_HOUSEHOLD) / sizeof(ADMINISTRATIVE_HOUSEHOLD[0]); i++) {
        if (strcmp(employee->profession.c_str(), ADMINISTRATIVE_HOUSEHOLD[i]) == 0) {
            group_multiplier = 1.0; 
            break;
        }
    }
    employee->salary = employee->base_salary * experience_multiplier * group_multiplier;
}

/*
Функція зберігає дані працівників у JSON файл.

Input: 
    Employee* employee - масив працівників, дані яких потрібно зберегти.
    int num_employees - кількість працівників

Result:
    дані працівників зберігаються в файлі JSON.
*/
void saveToJsonFile(Employee* employees, int num_employees) {
    string filename = create_filename("employees");
    cJSON* json_root = cJSON_CreateObject();
    cJSON* json_array = cJSON_CreateArray();
    for (int i = 0; i < num_employees; i++) {
        cJSON* json_employee = cJSON_CreateObject();
        cJSON_AddStringToObject(json_employee, "first_name", employees[i].first_name.c_str());
        cJSON_AddStringToObject(json_employee, "last_name", employees[i].last_name.c_str());
        cJSON_AddStringToObject(json_employee, "profession", employees[i].profession.c_str());
        cJSON_AddNumberToObject(json_employee, "years_of_experience", employees[i].years_of_experience);
        cJSON_AddNumberToObject(json_employee, "base_salary", employees[i].base_salary); 
        cJSON_AddNumberToObject(json_employee, "salary", employees[i].salary); 
        cJSON_AddItemToArray(json_array, json_employee);
    }

    cJSON_AddItemToObject(json_root, "employees", json_array);
    char* json_string = cJSON_Print(json_root);
    // створення file_out для запису даних у файл з іменем filename 
    ofstream file_out(filename);
    if (file_out.is_open()) {
        // запис даних
        file_out << json_string;
        cout << "Data saved to " << filename << endl;
    }
    file_out.close();
    cJSON_Delete(json_root);
    free(json_string);
}

/*
Функція зчитує дані працівника з консолі та зберігає їх у відповідних полях структури Employee.

Input: 
    Employee& employee - об'єкт працівника, в який будуть записані введені дані.
    int index - індекс працівника (для відображення виводу)

Result:
    всі поля працівника будуть заповнені введеними даними.
*/
void inputEmployeeData(Employee& employee, int index) {
    string str;
    while (true) {
        cout << "Enter first name of employee " << index + 1 << ": ";
        getline(cin, str);
        if (is_valid_String(str)) {
            employee.first_name = str;
            break;
        } 
        else {
            cout << "Invalid input. Please enter a valid name (only letters and spaces)." << endl;
        }
    }
    while (true) {
        cout << "Enter last name of employee " << index + 1 << ": ";
        getline(cin, str);
        if (is_valid_String(str)) {
            employee.last_name = str;
            break;
        } 
        else {
            cout << "Invalid input. Please enter a valid last name (only letters and spaces)." << endl;
        }
    }
    while (true) {
        cout << "Enter profession of employee " << index + 1 << ": ";
        getline(cin, str);
        if (is_valid_Profession(str)) {
            employee.profession = str;
            break;
        } 
        else {
            cout << "Invalid input. Please enter a valid profession." << endl;
        }
    }
    while (true) {
        cout << "Enter years of experience of employee " << index + 1 << ": ";
        getline(cin, str);
        int experience;
        if (is_valid_Int(str, experience)) {
            employee.years_of_experience = experience;
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid number for years of experience (positive integer)." << endl;
        }
    }
    while (true) {
        cout << "Enter base salary of employee " << index + 1 << ": ";
        getline(cin, str);
        double base_salary;
        if (is_valid_Double(str, base_salary)) {
            employee.base_salary = base_salary;
            break;
        } 
        else {
            cout << "Invalid input. Please enter a valid salary (number with decimal points)." << endl;
        }
    }
}

/*
Функція зберігає дані про викладачів(SCIENTIFIC_PEDAGOGICAL_SIZE) у JSON файл, перевіривши, чи є викладачі серед працівників.

Input: 
    Employee* employees - масив працівників
    int num_employees - кількість працівників

Result:
    дані про викладачів зберігаються в JSON-файлі.
*/
void saveLecturersToJsonFile(Employee* employees, int num_employees) {
    // спочатку перевірка чи взагалі є лектори перед тим як зберігати дані про них у файл
    bool lecturers_exist = false;
    for (int i = 0; i < num_employees; i++) {
        for (int j = 0; j < SCIENTIFIC_PEDAGOGICAL_SIZE; j++) {
            if (strcmp(employees[i].profession.c_str(), SCIENTIFIC_PEDAGOGICAL[j]) == 0) {
                lecturers_exist = true;
                break;
            }
        }
        if (lecturers_exist) break;
    }
    if (!lecturers_exist) return; 
    string filename = create_filename("lecturers");
    cJSON* json_root = cJSON_CreateObject();
    cJSON* json_array = cJSON_CreateArray();

    for (int i = 0; i < num_employees; i++) {
        bool is_lecturer = false;
        for (int j = 0; j < SCIENTIFIC_PEDAGOGICAL_SIZE; j++) {
            if (strcmp(employees[i].profession.c_str(), SCIENTIFIC_PEDAGOGICAL[j]) == 0) {
                is_lecturer = true;
                break;
            }
        }
        if (is_lecturer) {
            cJSON* json_employee = cJSON_CreateObject();
            cJSON_AddStringToObject(json_employee, "first_name", employees[i].first_name.c_str());
            cJSON_AddStringToObject(json_employee, "last_name", employees[i].last_name.c_str());
            cJSON_AddStringToObject(json_employee, "profession", employees[i].profession.c_str());
            cJSON_AddNumberToObject(json_employee, "years_of_experience", employees[i].years_of_experience);
            cJSON_AddNumberToObject(json_employee, "base_salary", employees[i].base_salary); 
            cJSON_AddNumberToObject(json_employee, "salary", employees[i].salary); 
            cJSON_AddItemToArray(json_array, json_employee);
        }
    }
    cJSON_AddItemToObject(json_root, "lecturers", json_array);
    char* json_string = cJSON_Print(json_root);
    ofstream file_out(filename);
    if (file_out.is_open()) {
        file_out << json_string;
        cout << "Lecturers data saved to " << filename << endl;
    }
    file_out.close();
    cJSON_Delete(json_root);
    free(json_string);
}

/*
Функція обчислює середній бал для викладача на основі оцінок студентів, яких він викладає.

Input: 
    const cJSON* students_json - JSON об'єкт, що містить дані про студентів.
    const char* lecturer_first_name - ім'я викладача.
    const char* lecturer_last_name - прізвище викладача.

Output:
    float: середній бал студентів, які відвідували цього викладача, або -1, якщо даних немає.
*/
float calculate_average_grade_for_lecturer(const cJSON* students_json, const char* lecturer_first_name, const char* lecturer_last_name) {
    cJSON* students_array = cJSON_GetObjectItem(students_json, "students");
    int student_count = cJSON_GetArraySize(students_array);
    float total_grade = 0.0;
    int student_found = 0;

    for (int i = 0; i < student_count; i++) {
        cJSON* student = cJSON_GetArrayItem(students_array, i);
        cJSON* lecturers = cJSON_GetObjectItem(student, "lecturers");
        int lecturer_count = cJSON_GetArraySize(lecturers);
        for (int j = 0; j < lecturer_count; j++) {
            cJSON* lecturer = cJSON_GetArrayItem(lecturers, j);
            cJSON* first_name = cJSON_GetObjectItem(lecturer, "first_name");
            cJSON* last_name = cJSON_GetObjectItem(lecturer, "last_name");
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

/*
Функція додає середній бал для кожного викладача, зберігаючи оновлені дані в файл.

Input: 
    const string& students_filename - файл з даними студентів
    const string& lecturers_filename - файл з даними викладачів

Result:
    дані викладачів оновлюються в JSON-файлі
*/
void update_lecturer_average_grades(const string& students_filename, const string& lecturers_filename) {
    ifstream students_file(students_filename);
    stringstream students_stream;
    string line;
    while (getline(students_file, line)) {
        students_stream << line << "\n";
    }
    string students_json_string = students_stream.str();
    cJSON* students_json = cJSON_Parse(students_json_string.c_str());

    ifstream lecturers_file(lecturers_filename);
    stringstream lecturers_stream;
    while (getline(lecturers_file, line)) {
        lecturers_stream << line << "\n";
    }
    string lecturers_json_string = lecturers_stream.str();
    cJSON* lecturers_json = cJSON_Parse(lecturers_json_string.c_str());

    cJSON* lecturers_array = cJSON_GetObjectItem(lecturers_json, "lecturers");
    int lecturer_count = cJSON_GetArraySize(lecturers_array);

    // для кожного викладача порахуємо середній бал студентів
    for (int i = 0; i < lecturer_count; i++) {
        cJSON* lecturer = cJSON_GetArrayItem(lecturers_array, i);
        cJSON* first_name = cJSON_GetObjectItem(lecturer, "first_name");
        cJSON* last_name = cJSON_GetObjectItem(lecturer, "last_name");
        float avg_grade = calculate_average_grade_for_lecturer(students_json, first_name->valuestring, last_name->valuestring);
        if (avg_grade != -1) {
            cJSON_AddNumberToObject(lecturer, "average_grade_of_students", avg_grade);
        }
    }
    char* updated_json_string = cJSON_Print(lecturers_json);
    ofstream out_file(lecturers_filename);
    if (out_file.is_open()) {
        out_file << updated_json_string;
        cout << "Data saved to " << lecturers_filename << endl;
    }
    out_file.close();
    cJSON_Delete(students_json);
    cJSON_Delete(lecturers_json);
    free(updated_json_string);
}

/*
Функція запитує у користувача назву файлу та зберігає його в змінній file_name.

Input: 
    string& file_name - змінна, куди буде збережено файл
    const string& file_type - тип файлу

Result:
    зберігає файл у змінній file_name.
*/
void get_file_name(string &file_name, const string &file_type) {
    cout << "Please enter the path to the " << file_type << " file: ";
    getline(cin, file_name);
}

/*
Функція виводить інформацію про викладачів у консоль у вигляді таблиці.

Input: 
    cJSON *lecturers - JSON об'єкт, що містить дані про викладачів

Result:
    дані викладачів виводяться у вигляді таблиці у консолі.
*/
void display_Lecturers(cJSON *lecturers) {
    initscr();
    raw();   
    keypad(stdscr, TRUE); 
    noecho();
    clear();

    int row, col;
    getmaxyx(stdscr, row, col);
    int start_row = 1;
    mvprintw(0, 0, "%-15s %-15s %-30s %-15s %-20s %-15s %-15s", 
             "First Name", "Last Name", "Profession", "Experience", "Base Salary", "Salary", "Average Grade Of Students");
    int num_of_lecturers = cJSON_GetArraySize(lecturers);
    for (int i = 0; i < num_of_lecturers; i++) {
        cJSON *lecturer = cJSON_GetArrayItem(lecturers, i);
        const char *first_name = cJSON_GetObjectItem(lecturer, "first_name")->valuestring;
        const char *last_name = cJSON_GetObjectItem(lecturer, "last_name")->valuestring;
        const char *profession = cJSON_GetObjectItem(lecturer, "profession")->valuestring;
        double base_salary = cJSON_GetObjectItem(lecturer, "base_salary")->valuedouble;
        int years_of_experience = cJSON_GetObjectItem(lecturer, "years_of_experience")->valueint;
        double salary = cJSON_GetObjectItem(lecturer, "salary")->valuedouble;
        double average_grade = cJSON_GetObjectItem(lecturer, "average_grade_of_students")->valuedouble;
        mvprintw(start_row, 0, "%-15s %-15s %-30s %-15d %-20.2f %-15.2f %-15.2f", 
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

/*
Функція виводить інформацію про працівників у консоль у вигляді таблиці.

Input: 
    cJSON* employees - JSON об'єкт, що містить дані про працівників

Result:
    дані працівників виводяться у вигляді таблиці у консолі.
*/
void display_Employees(cJSON *employees) {
    initscr(); 
    raw();   
    keypad(stdscr, TRUE);  
    noecho(); 
    clear();

    int row, col;
    getmaxyx(stdscr, row, col);
    int start_row = 1;
    mvprintw(0, 0, "%-15s %-15s %-30s %-20s %-15s %-15s", 
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
        mvprintw(start_row, 0, "%-15s %-15s %-30s %-20.2f %-15d %-15.2f", 
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

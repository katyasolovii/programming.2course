#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../cJSON/cJSON.h"
#include <ncurses.h>

const char* ADMINISTRATIVE_MANAGEMENT[] = { "Dean", "Deputy Dean", "Head of Department"};

const char* SCIENTIFIC_PEDAGOGICAL[] = {"Professor", "Associate Professor", "Senior Lecturer", "Assistant", 
                                        "Lecturer", "Postgraduate Student", "Doctoral Candidate"};

const char* SUPPORTING_STAFF[] = {"Librarian", "Laboratory Assistant", "Methodologist", "IT Specialist"};

const char* ADMINISTRATIVE_HOUSEHOLD[] = {"HR Staff", "Accountant", "Chief Accountant",
                                          "Cleaner", "Electrician", "Plumber", "Security Guard"};

typedef struct Person {
    char first_name[100];
    char last_name[100];
} Person;

typedef struct Employee {
    Person person;
    double base_salary;
    int years_of_experience;
    double salary;
    char profession[100];
} Employee;

typedef struct Lecturer {
    Employee employee;
    int num_of_students;
    double average_mark_students;
} Lecturer;

typedef struct Student {
    Person person;
    char specialty[200];
    int year_of_study;
    double average_grade;
    int num_of_lecturers;
    Person* lecturers;
    char type_scholarship;    // 'N' - None, 'R' - Regular, 'I' - Increased
    char degree_level[10];    // "Bachelor" або "Master"
} Student;

typedef struct Record_book {
    Student***** students_by_degree_specialty_and_year;
    int num_specialties;
} Record_book;

/*
Отримує кількість студентів від користувача.

Output:
    int: кількість студентів, введена користувачем.
*/
int get_number_of_students();

/*
Запитує дані про студентів та їх викладачів, перевіряє правильність введення та зберігає їх.

Input:
    Student* students: масив структур Student, в якому буде зберігатися інформація про студентів.
    int num_students: еількість студентів.

Output:
    void: дані зберігаються у масиві `students`.
*/
void input_student_data(Student* students, int num_students);

/*
Сортує студентів за освітнім ступенем ("Bachelor"/"Master"), спеціальністю та курсом.

Input:
    Student* students: масив структур студентів.
    int num_students: кількість студентів.
    Record_book* recordBook: структура для зберігання впорядкованих студентів.
    char specialties[][200]: масив назв спеціальностей.
    (двовимірний масив спеціальностей. (перший вимір - к-сть спеціальностей, другий - фіксована довжина рядка))

Output:
    void: Студенти зберігаються у впорядкованому вигляді в `recordBook`.
*/
void sorted_students(Student* students, int num_students, Record_book* recordBook, char specialties[][200]);

/*
Розраховує стипендії для студентів на основі середнього балу.
Звичайну стипендію отримують 45% вд к-сті студентів;
підвищену отримують 20% від к-сті студнтів, які отримують звичайну стипендію.

Input:
    Student* students: масив структур студентів.
    int num_students: кількість студентів.
    Record_book* recordBook: структура з впорядкованими студентами.
    char specialties[][200]: масив назв спеціальностей.

Output:
    void: Тип стипендії зберігається у полі `type_scholarship` кожного студента.
*/
void calculate_scholarships(Student* students, int num_students, Record_book* recordBook, char specialties[][200]);

/*
Генерує унікальне ім'я файлу з відповідним індексом і розширенням.

Input:
    const char *ind: індекс для імені файлу.
    const char *form: розширення файлу (json).
    char *filename: буфер для збереження згенерованого імені файлу.

Output:
    void: унікальне ім'я файлу зберігається у `filename`.
*/
void generate_filename(const char *ind, const char *form, char *filename);

/*
Зберігає дані про студентів у JSON-файл.

Input:
    Student* students: масив структур студентів.
    int num_students: кількість студентів.

Output:
    void: дані зберігаються у JSON-файлі.
*/
void save_students_to_json(Student* students, int num_students);

/*
Ця функція читає вміст файлу і повертає його у вигляді рядка.

Input:
    const char* filename: шлях до файлу, який потрібно прочитати.

Output:
    Повертає динамічно виділений рядок із вмістом файлу. 
    У разі виникнення помилки під час читання файлу повертає NULL.
*/
char* read_file(const char* filename);

/*
Ця функція завантажує JSON-масив із файлу за вказаним ключем (students, lecturers, employees).

Input:
    const char* filename: шлях до файлу, з якого потрібно завантажити JSON-дані.
    const char* key: ключ для отримання JSON-масиву з файлу.

Output:
    Повертає вказівник на об'єкт cJSON, який представляє JSON-масив. 
    У разі виникнення помилки (наприклад, файл не знайдено, ключ не існує) повертає NULL.
*/
cJSON* load_json_from_file(const char* filename, const char* key);

/*
Ця функція відображає список студентів із JSON-файла за допомогою бібліотеки ncurses.
ncurses- текстовий інтерфейс.

Input:
    cJSON* students: вказівник на cJSON-масив, що містить дані про студентів.

Result:
    Відображає дані студентів у табличному форматі в терміналі.
*/
void display_students_from_json(cJSON* students);

/*
Ця функція розраховує зарплату працівника на основі його 
професії, базової ставки та досвіду.

Input:
    Employee* employee: вказівник на структуру працівника, яка містить
    його особисті дані, професію, базову ставку та досвід.

Result: оновлює `salary` у структурі `employee`.
*/
void calculate_salary(Employee* employee);

/*
Ця функція запитує користувача про кількість працівників, дані 
про яких потрібно ввести.

Output: повертає кількість працівників.
*/
int get_number_of_employees();

/*
Ця функція забезпечує введення даних для одного працівника.

Input:
    Employee* employee: вказівник на структуру працівника, яка буде
    заповнена користувачем.

Result: оновлює структуру `employee` на основі введених користувачем даних.
*/
void input_data(Employee* employee);

/*
Ця функція забезпечує введення даних для працівників.

Input:
    Employee* employees: масив структур працівників, які потрібно заповнити.
    int num_of_employees: кількість працівників, дані яких потрібно ввести.

Result: оновлює масив структур `employees` на основі введених користувачем даних.
*/
void input_employees_data(Employee* employees, int num_of_employees);

/*
Ця функція зберігає дані про працівників у JSON-файл.

Input:
    Employee* employees: масив структур працівників.
    int num_of_employees: кількість працівників у масиві.
    const char* filename: ім'я файлу для збереження.

Result: створює JSON-файл з даними працівників.
*/
void save_employees_to_json(Employee* employees, int num_of_employees, const char* filename);

/*
Ця функція зберігає окремо дані про викладачів (SCIENTIFIC_PEDAGOGICAL) у JSON-файл.

Input:
    Employee* employees: масив структур працівників.
    int num_of_employees: кількість працівників у масиві.
    const char* filename: ім'я файлу для збереження.

Result: створює JSON-файл з даними викладачів.
*/
void save_lecturers_to_json(Employee* employees, int num_of_employees, const char* filename);

/*
Ця функція обчислює середній бал студентів відповідного викладача.

Input:
    const cJSON* students_json: JSON-об'єкт зі студентами.
    const char* lecturer_first_name: ім'я викладача.
    const char* lecturer_last_name: прізвище викладача.

Output:
    double: середній бал для викладача як число double, або -1, якщо викладача не знайдено.
*/
float calculate_average_grade_for_lecturer(const cJSON *students_json, const char *lecturer_first_name, const char *lecturer_last_name);

/*
Ця функція додай (оновлює) середній бал стуентів відповідного
викладача до файлу про викладачів.

Input:
    const char* filename: ім'я файлу викладачів.
    cJSON* lecturers_json: JSON-об'єкт з даними про викладачів.

Result: перезаписує файл викладачів з новими даними.
*/
void update_lecturers_file(const char *filename, cJSON *lecturers_json);

/*
Ця функція оновлює дані викладачів, обчислюючи середній бал 
на основі інформації про студентів.

Input:
    const char* students_file: ім'я файлу студентів.
    const char* lecturers_file: ім'я файлу викладачів.

Result: оновлює файл викладачів новими даними про середні бали студентів.
*/
void update_lecturers(const char *students_file, const char *lecturers_file);

/*
Ця функція відображає дані про викладачів із JSON у вигляді таблиці за допомогою бібліотеки ncurses.
ncurses- текстовий інтерфейс.

Input:
    cJSON* lecturers: JSON-об'єкт з даними про викладачів.

Result: виводить інформацію у вигляді таблиці.
*/
void display_lecturers_from_json(cJSON *lecturers);

/*
Ця функція відображає дані про працівників із JSON у вигляді таблиці за допомогою бібліотеки ncurses.
ncurses- текстовий інтерфейс.

Input:
    cJSON* employees: JSON-об'єкт з даними про працівників.

Result: виводить інформацію у вигляді таблиці.
*/
void display_employees_from_json(cJSON *employees);

/* 
Ця функція знаходить індекс спеціальності в заданому списку спеціальностей.
Якщо спеціальність знайдена, функція повертає її індекс у списку; 
в іншому випадку повертається -1.

Input:
    char specialties[][200]: двовимірний масив спеціальностей. (перший вимір - к-сть спеціальностей, другий - фіксована довжина рядка)
    int num_specialties: кількість спеціальностей у масиві.
    const char* specialty: назва спеціальності, яку потрібно знайти. 

Output:
    int: індекс спеціальності, якщо знайдено, або -1, якщо не знайдено.
*/
int find_specialty_index(char specialties[][200], int num_specialties, const char* specialty);

/* 
Ця функція перевіряє, чи є рядок достовірним(правильним). Цей рядок містить лише 
літери (як великі, так і малі) та пробіли, і не є порожнім.

Input:
    const char* str: рядок, який потрібно перевірити.

Output:
    int: повертає 1, якщо рядок достовірний, інакше повертає 0.
*/
int is_valid_string(const char* str);

/* 
Ця функція просить користувача ввести і перевіряє, чи є введений рядок достовірним.

Input:
    const char* m: повідомлення, яке відображається користувачу.
    char* str: тимчасова пам'ять для вводу.
    size_t max_length: максимальна фіксована довжина вводу.

Output:
    void: введений рядок зберігається у тимчасовій пам'яті для вводу `str` після перевірки.
*/
void get_valid_string(const char* m, char* str, size_t max_length);

/* 
Ця функція перевіряє, чи є введений рядок "Bachelor" або "Master".

Input:
    const char* str: рядок, який потрібно перевірити.

Output:
    int: повертає 1, якщо рядок є "Bachelor" або "Master", інакше повертає 0.
*/
int is_valid_degree(const char* str);

/* 
Ця функція запитує у користувача ввід рівня освіти ("Bachelor" або "Master")
і зберігає результат у буфері (тимчасова пам'ять для вводу).

Input:
    const char* m: повідомлення, яке відображається користувачу.
    char* deg: буфер для збереження правильного рівня освіти.
    size_t max_length: максимальна фіксована довжина вводу.

Output:
    void: рівень освіти зберігається у буфері `deg` після перевірки.
*/
void get_valid_degree(const char* m, char* deg, size_t max_length);

/* 
Ця функція запитує у користувача ввід числа і перевіряє,
чи воно є типом double, потім повертає його.

Input:
    const char* num: повідомлення, яке відображається користувачу.
 
Output:
    double: введене число double.
*/
double get_valid_double(const char* num);

/* 
Ця функція запитує у користувача ввід числа і перевіряє,
чи воно є типом int, потім повертає його.

Input:
    const char* m: повідомлення, яке відображається користувачу.

Output:
    int: введене число int.
*/
int get_valid_int(const char* m);

/* 
Ця функція перевіряє, чи є введена професія достовірним, порівнюючи її з
попередньо визначеними списками професій.

Input:
    const char* profession: професія, яку потрібно перевірити.

Output:
    int: повертає 1, якщо така професія є у списку, інакше повертає 0.
*/
int is_profession(const char* profession);

/* 
Ця функція запитує у користувача ввід професії, перевіряє чи правильна професія,
викликаючи функцію is_profession() і зберігає результат у буфері.

Input:
    const char* prompt: повідомлення, яке відображається користувачу.
    char* prof: буфер для збереження професії.
    size_t size: розмір буфера.

Output:
    void: введена професія зберігається у буфері `prof` після перевірки.
*/
void get_valid_profession(const char* m, char* prof, size_t size);

/*
Ця функція перевіряє, чи існує файл з заданою назвою.

Input:
    const char *filename: ім'я файлу для перевірки.

Result:
    int: 1, якщо файл існує, і 0, якщо не існує.
*/
int file_exists(const char *filename);

#endif // UNIVERSITY_H
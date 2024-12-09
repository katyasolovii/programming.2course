// input_validation.h
#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#include "university.h"

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
Ця функція перевіряє, чи є рядок достовірним(правильним). Цей рядок має містить лише 
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

#endif // INPUT_VALIDATION_H

#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <sstream>
#include <string>
#include "../src/check.cpp"
using namespace std;

/*
Функція перевіряє, чи є рядок типом string.

Input:
    const string& input: посилання на рядок, який потрібно перевірити.

Output:
    Повертає true, якщо рядок праивльним, і false в іншому випадку.
*/
bool is_valid_String(const string& input);

/*
Функція перевіряє, чи можна перетворити рядок `input` на ціле число.

Input:
    const string& input: посилання на рядок, який потрібно перевірити.
    int& output: посилання на змінну, куди буде записано результат перетворення.
    
Output:
    Повертає true, якщо рядок містить ціле число, і false в іншому випадку.
*/
bool is_valid_Int(const string& input, int& output);

/*
Функція перевіряє, чи можна перетворити рядок на тип float.

Input:
    const string& input: посилання на рядок, який потрібно перевірити.
    double& output: посилання на змінну, куди буде записано результат перетворення.
    
Output:
    Повертає true, якщо рядок float, і false в іншому випадку.
*/
bool is_valid_Double(const string& input, double& output);

/*
Функція перевіряє, чи рядок Master/Bachelor.

Input:
    const string& input: посилання на рядок, який потрібно перевірити.
    
Output:
    Повертає true, якщо рядок Master/Bachelor, і false в іншому випадку.
*/
bool is_valid_Degree(const string& input);

/*
Функція перевіряє, чи є середній бал студентів більше 60 і менше 100.

Input:
    double average_grade: середній бал студентів, який потрібно перевірити.
    
Output:
    Повертає true, якщо значення знаходиться відповідному діапазоні, і false в іншому випадку.
*/
bool is_valid_average_grade(double average_grade);

#endif // CHECK_H

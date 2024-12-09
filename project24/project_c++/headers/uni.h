#ifndef UNI_H
#define UNI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ncurses.h>
#include "cJSON.h"
#include "check.h" 

using namespace std;

const int ADMINISTRATIVE_MANAGEMENT_SIZE = 3;
const int SCIENTIFIC_PEDAGOGICAL_SIZE = 7;
const int SUPPORTING_STAFF_SIZE = 4;
const int ADMINISTRATIVE_HOUSEHOLD_SIZE = 7;

const char* ADMINISTRATIVE_MANAGEMENT[] = {"Dean", "Deputy Dean", "Head of Department"};
const char* SCIENTIFIC_PEDAGOGICAL[] = {"Professor", "Associate Professor", "Senior Lecturer", "Assistant", 
                                        "Lecturer", "Postgraduate Student", "Doctoral Candidate"};
const char* SUPPORTING_STAFF[] = {"Librarian", "Laboratory Assistant", "Methodologist", "IT Specialist"};
const char* ADMINISTRATIVE_HOUSEHOLD[] = {"HR Staff", "Accountant", "Chief Accountant",
                                          "Cleaner", "Electrician", "Plumber", "Security Guard"};

class Person {
public:
    string first_name;
    string last_name;

    Person(const string& first_name, const string& last_name): first_name(first_name), last_name(last_name) {}
};

class Student : public Person {
public:
    string specialty;
    int year_of_study;
    string degree_level;
    double average_grade;
    vector<Person> lecturers;
    string scholarship_type;

    Student(const string& first_name, const string& last_name, const string& specialty, int year_of_study, const string& degree_level,
            double average_grade, const vector<Person>& lecturers): Person(first_name, last_name), specialty(specialty), year_of_study(year_of_study),
          degree_level(degree_level), average_grade(average_grade), lecturers(lecturers), scholarship_type("None") {}

    bool compare(const Student& s1, const Student& s2);
    void calculate_Scholarships(vector<Student>& students);
    void save_Student_to_json(const vector<Student>& students);
    void input_students_data(int student_index, vector<Student>& students);
};

class Employee : public Person {
public:
    string profession;
    int years_of_experience;
    double base_salary;
    double salary;   

    Employee(const string& first_name, const string& last_name, const string& profession, int years_of_experience, double base_salary)
        : Person(first_name, last_name), profession(profession), years_of_experience(years_of_experience), base_salary(base_salary) {}

    void calculate_salary(Employee* employee);
    void saveToJsonFile(Employee* employees, int num_employees);
    void inputEmployeeData(Employee& employee, int index);
    void saveLecturersToJsonFile(Employee* employees, int num_employees);
};

#endif // UNI_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string first_name;
    string middle_name;
    string last_name;
    string gender;
    int age;
public:
    Person() : first_name(""), middle_name(""), last_name(""), gender(""), age(0) {}
    virtual ~Person() {}

    virtual void input() {
        cout << "Enter first name: ";
        cin >> first_name;
        cout << "Enter middle name: ";
        cin >> middle_name;
        cout << "Enter last name: ";
        cin >> last_name;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Enter age: ";
        cin >> age;
    }

    virtual void output() const {
        cout << "Name: " << first_name << " " << middle_name << " " << last_name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
    }

    virtual string getUniversity() const = 0;
};

class Student : virtual public Person {
protected:
    int course;
    int group;
    string uni_student;
public:
    Student() : course(0), group(0), uni_student("") {}

    void input() {
        Person::input();
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter group: ";
        cin >> group;
        cout << "Enter university (for student): ";
        cin >> uni_student;
    }

    void output() const {
        Person::output();
        cout << "Course: " << course << endl;
        cout << "Group: " << group << endl;
        cout << "University: " << uni_student << endl;
    }

    string getUniversity() const {
        return uni_student;
    }
};

class Lecturer : virtual public Person {
protected:
    double salary;
    string uni_lecturer;
public:
    Lecturer() : salary(0.0), uni_lecturer("") {}

    void input() {
        Person::input();
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter university (for lecturer): ";
        cin >> uni_lecturer;
    }

    void output() const {
        Person::output();
        cout << "Salary: " << salary << endl;
        cout << "University: " << uni_lecturer << endl;
    }

    string getUniversity() const {
        return uni_lecturer;
    }
};

class Postgraduate : public Student, public Lecturer {
public:
    Postgraduate() {}

    void input() {
        Student::input();
        Lecturer::input();
    }

    void output() const {
        Student::output();
        Lecturer::output();
    }

    string getUniversity() const {
        if (Student::uni_student == Lecturer::uni_lecturer)
            return Student::uni_student;
        return "Different universities";
    }
};

int main() {
    int n;
    cout << "Enter count of people: ";
    cin >> n;

    vector<Person*> people(n);

    for (int i = 0; i < n; i++) {
        int type;
        cout << "Enter type of person (1-Student, 2-Lecturer, 3-Postgraduate): ";
        cin >> type;

        if (type == 1) {
            people[i] = new Student();
        } else if (type == 2) {
            people[i] = new Lecturer();
        } else if (type == 3) {
            people[i] = new Postgraduate();
        } else {
            cout << "Invalid type!" << endl;
            i--;
            continue;
        }

        people[i]->input();
    }

    for (int i = 0; i < n; ++i) {
        people[i]->output();
        cout << "University: " << people[i]->getUniversity() << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete people[i];
    }
}

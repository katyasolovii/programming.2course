#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream> //з string читаємо string
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

void task1(){
    char fname[] = "Text4_1.txt";
    fstream f(fname);
    if (!f){
        cerr << "Error reading file" << fname << "\n";
        return;
    }
    
    char c;
    int num =  0;
    int summ = 0;
    int prev_sign = 1;

    while (f >> c) {
        if (isdigit(c)){
            int d = c - '0';
            num = num * 10 + d;
        }
        else if (c == '-'){
            if (prev_sign == 1 || prev_sign == 0){
                summ += num;
            }
            else if (prev_sign == 2){
                summ -= num;
            }
            prev_sign = 2;
            num = 0;
        }
        else if (c == '+'){
            if (prev_sign == 1 || prev_sign == 0){
                summ += num;
            }
            else if (prev_sign == 2)
            {
                summ -= num;
            }
            prev_sign = 1;
            num = 0;
        }
        else{
            cout << "Not required format: " << c << "-uncorrect synbol" << endl;
        }
    }
    summ += prev_sign * num;
    cout << "sum = " << summ << endl; 
}

void task2(){
    char fname[20] = "deutsch.txt";
    ifstream f(fname);

    string Articles[] = {"der", "die", "das"};
    string buf;
    bool isArticle = false;
    ofstream f2("tmp.txt");

    while (f >> buf){
        if (isArticle){
          buf[0] = toupper(buf[0]);  
        }
        clog << buf << " ";
        f2 << buf << " ";
        isArticle = false;
        for (int i=0; i < 3; i++){
            if (buf == Articles[i]){
                isArticle = true;
                break;
            }
        }
    }

    f.close();
    f2.close();
    rename("tmp.txt", fname);
}

void reverse(char* str){
    int n = strlen(str);
    for (int i=0; i < n/2; i++){
        char tmp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = tmp;
    }
}

void task3(){
    const char* fname = "Task4_3.txt";
    const char* outputfile = "Message.txt";

    ifstream infile(fname);
    ofstream outfile(outputfile);

    if (!infile) {
        cerr << "Error opening file: " << fname << endl;
        return;
    }

    if (!outfile) {
        cerr << "Error opening file: " << outputfile << endl;
        return;
    }

    char word[100];
    while (infile >> word) {
        reverse(word);
        outfile << word << " ";
    }
    infile.close();
    outfile.close();
}

bool checkTags(ifstream& f1, const string& openTD = "<td>", const string& closeTD = "</td>") {
    int opentag = 0;
    int closetag = 0;
    string buf;

    while (f1 >> buf) {
        if (buf == openTD) {
            opentag++;
        } else if (buf == closeTD) {
            closetag++;
            if (closetag > opentag) {
                return false;
            }
        }
    }
    return closetag == opentag;
}

void task4() {
    const char* fname = "t.txt";
    ifstream f1(fname);

    if (!f1) {
        cerr << "Error opening " << fname << endl;
        return;
    }

    cout << "\nCheck: " << boolalpha << checkTags(f1);
    f1.close();
}

void create_student_file(const char* fname) {
    ofstream f1(fname);
    if (!f1) {
        cerr << "Error opening file: " << fname << endl;
        return;
    }

    int N;
    cout << "Enter N: ";
    cin >> N;
    for (int i=0; i < N; i++){
        string surname;
        int course;
        string group;
        string marks;
        cout << "Enter surname: ";
        cin >> surname;
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter group: ";
        cin >> group;
        cout << "Enter marks: ";
        cin >> marks;
        f1 << setw(8) << surname << setw(8) << course << setw(8) << group << setw(20) << marks << endl;
    }
    f1.close();
}

double average_mark(const string& marks) {
    double sum = 0.0;
    int counter = 0;
    int tmp;
    char coma = ',';
    stringstream str(marks);
    while (str >> tmp) {
        sum += tmp;
        counter++;
        str >> coma;
    }
    return sum / counter;
}

string find_student(const char* fname) {
    ifstream f1(fname);
    string loser;
    double min_mark = 101;
    while (!f1.eof()){
        string surname, course, group, marks;
        f1 >> surname >> course >> group >> marks;
        double worst = average_mark(marks);
        if (worst < min_mark){
            min_mark = worst;
            loser = surname;
        }
    }
    return loser;
}

void task5() {
    create_student_file("task5.txt");
    cout << "Student with the worst average mark: " << find_student("task5.txt") << endl;
}

int main(){
    int task = 1;
    cout << "task = ";
    cin >> task;
    if (task == 1){
        task1();
    }
    else if (task == 2)
    {
        task2();
    }
    else if (task == 3){
        task3();
    }
    else if (task == 4)
    {
        task4();
    }
    else if (task == 5)
    {
        task5();
    }
}
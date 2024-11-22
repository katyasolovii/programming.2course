#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string task1_out(const string& s) {
    size_t p1 = s.find(":");
    if (p1 == string::npos) {
        return s;
    }
    size_t p2 = s.find(",", p1 + 1);
    if (p2 == string::npos) {
        return s.substr(p1 + 1);
    }
    return s.substr(p1 + 1, p2 - p1 - 1);
}


int task1_inplace(string& s) {
    size_t p1 = s.find(":");
    if (p1 == string::npos) {
        return 0;
    }
    s.erase(0, p1 + 1);

    size_t p2 = s.find(",");
    if (p2 == string::npos) {
        return 1;
    }
    s.erase(p2);
    return 2;
}

string task2(const string& s) {
    size_t p1 = s.find(".");
    size_t f1 = s.find(" ");
    if (p1 == string::npos) {
        // Немає крапок — видаляємо пробіли на початку тексту
        return f1 == string::npos ? "" : s.substr(f1 + 1);
    }
    size_t p2 = s.rfind(".");
    if (p1 == p2) {
        return s.substr(p1 + 1);
    }
    return s.substr(0, p1 + 1) + s.substr(p2 + 1);
}

void task3(string s){
    size_t p1=0, p2;
    while(p1 < s.length()){
        p2 = s.find(' ', p1);
        if (p2 == string::npos) {
            p2 = s.length();
        }
        for (size_t i = p1; i < p2 - 1; i++) {
            cout << s[i];
        }
        cout << " ";
        p1 = p2 + 1;
    }
}

void task4(string s, int n, char del, double* mas) {
    string tmp;
    stringstream ss(s);
    int k=0;
    while(getline(ss, tmp, del)){
        size_t p;
        double x = stod(tmp, &p);
        mas[k++] = x;
    }
}

void task5(string s, int n, char d, string* result) {
    stringstream ss(s);
    string tmp;
    int count = 0;
    while (getline(ss, tmp, d) && count < n) {
        result[count++] = tmp;
    }
}

void task6(){
    string s;
    cout << "Enter string: " << endl;
    getline(cin, s);
    stringstream ss(s);
    string word;
    string shortestWord;
    int minLength = 1000;
    bool f = false;
    string first_word, last_word;
    string all_words = "";
    while (ss >> word){
        int len = word.length();
        if (len < minLength){
            minLength = len;
            first_word = word;
            last_word = word;
            all_words = word + " ";
            f = true;
        } else if (len == minLength){
            last_word = word;
            all_words += word + " ";
        }
    }
    if (f){
        cout << "First shortest word: " << first_word << endl;
        cout << "Last shortest word: " << last_word << endl;
        cout << "All shortest words: " << all_words << endl;
    } else {
        cout << "No words found." << endl;
    }
}

int main() {
    string s1 = "gdfsg:fg,sg";
    string s2 = "sdfg:gfd";
    string s3 = "sfghgfh";
    cout << "task1_exp_1" << endl;
    cout << task1_out(s1) << endl; 
    cout << task1_out(s2) << endl;
    cout << task1_out(s3) << endl;
    cout << "task1_exp_2" << endl;
    cout << s1 << task1_inplace(s1) << " -> " << s1 << endl;
    cout << s2 << task1_inplace(s2) << " -> " << s2 << endl;
    cout << s3 << task1_inplace(s3) << " -> " << s3 << endl;


    string s1_2 = "gcfhgh.ghjjj.";
    string s2_2 = " fdgh";
    string s3_2 = "dghj.";
    string s4_2 = "dghf.gfdh.fhgd.hfgnb.";
    
    cout << "\ntask2" << endl;
    cout << task2(s1_2) << endl;
    cout << task2(s2_2) << endl;
    cout << task2(s3_2) << endl;
    cout << task2(s4_2) << endl; 

    cout << "\ntask3" << endl;
    string s_3 = "Hello World";
    task3(s_3);

    cout << "\ntask4" << endl;
    int n;
    string s;
    char w = ' ';
    double* mas;
    cout << "Enter n: " << endl;
    cin >> n;
    cin.ignore();
    mas = new double[n];
    cout << "Enter string: " << endl;
    getline(cin, s);
    task4(s, n, w, mas);
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    delete[] mas;

    cout << "\ntask5" << endl;
    string s5;
    int m;
    char d = ' ';
    cout << "Enter m: " << endl;
    cin >> m;
    cin.ignore();
    cout << "Enter string: " << endl;
    getline(cin, s5);
    string* res = new string[m];
    task5(s5, m, d, res);
    cout << "First " << m << " words: ";
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    delete[] res; 
    cout << "\ntask6" << endl;
    task6();
}

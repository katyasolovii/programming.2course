#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void task1(){ 
    cout << "x = " ;
    double x=0, y=0;
    cin >> x;
    cout << "y = " ;
    cin >> y;
    double z = pow(x, y);
    cout << "Result in decimal: " << z << endl;
    cout << "Result in scientific notation: " << scientific << z << endl;
}

void task2() {
    char str[11];
    unsigned long long sum = 0UL;
    cout << "Enter n: ";
    unsigned n = 0;
    cin >> n;
    unsigned long long mas[1000];
    unsigned count = 0;
    cin.ignore();
    while (count < n) {
        cin.get(str, 11);
        cin.ignore();
        unsigned long long a = stoull(str);
        mas[count] = a;
        sum += a;
        count++;
    }
    cout << "sum = " << sum << "\n";
}

void task3(){
    unsigned n=0;
    cout << "Enter n: ";
    cin >> n;
    int line_length = (n+1) * 8;
    string line(line_length, '+');
    cout << line << endl;

    for (unsigned i=1; i <= n; i++) {
        if (i == 1){
            cout << i << " ";
        }
        else{
            cout << setw(8) << i << " ";
        }
    }

    cout << endl;
    cout << line << endl;

    for (unsigned i=1; i <= n; i++) {
        if (i == 1){
            double root = sqrt(i);
            cout << fixed << setprecision(0) << root << " ";
        }
        else{
            double root = sqrt(i);
            if (root == floor(root)){
                cout << setw(8) << fixed << setprecision(0) << root << " ";
            }
            else{
                cout << setw(8) << fixed << setprecision(2) << root << " ";
            }
        }
    }
    cout << endl;
    cout << line << endl;
}

void task4(){
    unsigned n;
    cout << "Enter n: ";
    cin >> n;

    int* m = new int[n];
    double* x = new double[n];

    for (unsigned i=0; i < n; i++){
        cout << "m[" << i << "]= ";
        cin >> m[i];
    }

    // ifstream - читає файл
    ifstream f1("input.txt");
    unsigned i=0;
    // eof - кінець файла
    while (!f1.eof()){
        if (f1 >> x[i]){
            i++;
        }
        if (i >= n){
            break;
        }
    }
    f1.close();

    if (i < n){
        cout << "not enough data in file" << endl;
    }

    ofstream f2("output.txt");
    for (unsigned j = 0; j < n; j++) {
        double z = pow(x[j], m[j]);
        f2 << z << endl;
    }
    f2.close();
    delete[] x;
    delete[] m;
}

void task5(){
    double mas[1<<16]; // 2^16;
    ifstream f1("input_1.txt");

    unsigned i=0;
    while (!f1.eof()){
        if (f1 >> mas[i]){
            i++;
        }
    }
    f1.close();

    for (unsigned j=i; j > 0; j--){
        double res = sqrt(mas[j - 1]);
        cout << fixed << setprecision(4) << res << endl;
    }
}

int main(){
    int task = 1;
    cout << "task = ";
    cin >> task;
    if (task == 1){
        task1();
    }
    if (task == 2)
    {
        task2();
    }
    else if (task == 3){
        task3();
    }
    else if (task == 4){
        task4();
    }
    else if (task == 5){
        task5();
    }
}

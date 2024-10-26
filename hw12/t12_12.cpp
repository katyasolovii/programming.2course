#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void task12(){
    string A, B, C;
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter B: ";
    cin >> B;
    cout << "Enter C: ";
    cin >> C;

    try{
        double a = stod(A);
        double b = stod(B);
        double c = stod(C);
        double harmonic = 3.0 / (1.0 / a + 1.0 / b + 1.0 / c);
        cout << "Harmonic mean in decimal: " << setprecision(4) << harmonic << endl;
        cout << "Harmonic mean in scientific notation: " << scientific << setprecision(4) << harmonic << endl;
    }
    catch (invalid_argument) {
        cout << "Error: Invalid input format." << endl;
    }
}

int main(){
    task12();
}

#include <iostream>
#include <iomanip>  // бібліотека для форматування виводу/вводу
using namespace std;

int sequence(int a) {
    int i = 0;
    int count = 0;
    while (a != 1) {
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = 3 * a + 1;
        }
        cout << setw(3) << a << ", ";
        i++;
        count++;
        if (count % 8 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    return i;
}

void task3() {
    int max_step = 0, max_num = 0, n, steps;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cout << "Sequence for n = " << i << ": " << endl;
        steps = sequence(i);
        cout << endl;
        if (steps > max_step) {
            max_step = steps;
            max_num = i;
        }
    }
    cout << "Number with max steps: " << max_num << endl;
}

int main() {
    task3();
    return 0;
}

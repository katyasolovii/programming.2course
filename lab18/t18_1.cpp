#include <iostream>
#include "Rational.h"

template <typename T>
T* out_max(T* a, T* b) {
    int n = strlen(a);
    int m = strlen(b);
    int k = std::min(n, m);
    for (int i = 0; i < k; i++) {
        if (a[i] > b[i]) {
            return b;
        } else if (a[i] < b[i]) {
            return a;
        }
    }
    return n >= m ? a : b; 
}

template <typename T>
T out_max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int x = 5;
    int y = 3;
    int z = out_max(x, y);
    std::cout << z << "\n";

    double a = 7.5;
    double b = 3.4;
    std::cout << out_max(a, b) << "\n";

    std::string s1("32");
    std::string s2("52");
    std::cout << out_max(s1, s2) << "\n";
    std::cout << out_max("ca", "ba") << "\n";

    Rational r1(3, 4);
    Rational r2(5, 6);
    std::cout << out_max(r1, r2) << "\n";
}
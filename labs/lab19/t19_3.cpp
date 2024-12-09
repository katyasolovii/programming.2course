#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class Polynome {
private:
    int deg;
    std::vector<T> coefficients;

public:
    Polynome();
    Polynome(const std::vector<T>& c);
    void input();
    void output() const;
    Polynome<T> add(const Polynome<T>& other) const;
    Polynome<T> multiply(const Polynome<T>& other) const;
    T evaluate(T x) const;
};

template <typename T>
Polynome<T>::Polynome() : deg(0) {}

template <typename T>
Polynome<T>::Polynome(const std::vector<T>& c) {
    deg = c.size() - 1;
    coefficients = c;
}

template <typename T>
void Polynome<T>::input() {
    int degree;
    std::cout << "Enter degree of the polynomial: ";
    std::cin >> degree;
    deg = degree;
    coefficients.clear();
    
    for (int i = 0; i <= degree; i++) {
        T coeff;
        std::cout << "Enter coefficient for x^" << i << ": ";
        std::cin >> coeff;
        coefficients.push_back(coeff);
    }
}

template <typename T>
void Polynome<T>::output() const {
    for (int i = deg; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (i != deg) {
                std::cout << " + ";
            }
            std::cout << coefficients[i];
            if (i > 0) std::cout << "x^" << i;
        }
    }
    std::cout << std::endl;
}

template <typename T>
Polynome<T> Polynome<T>::add(const Polynome<T>& other) const {
    int max_deg = std::max(deg, other.deg);
    std::vector<T> result_coeffs(max_deg + 1, 0);

    for (int i = 0; i <= deg; i++) {
        result_coeffs[i] += coefficients[i];
    }
    for (int i = 0; i <= other.deg; i++) {
        result_coeffs[i] += other.coefficients[i];
    }

    return Polynome<T>(result_coeffs);
}

template <typename T>
Polynome<T> Polynome<T>::multiply(const Polynome<T>& other) const {
    int result_deg = deg + other.deg;
    std::vector<T> result_coeffs(result_deg + 1, 0);

    for (int i = 0; i <= deg; ++i) {
        for (int j = 0; j <= other.deg; j++) {
            result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynome<T>(result_coeffs);
}

template <typename T>
T Polynome<T>::evaluate(T x) const {
    T result = 0;
    for (int i = deg; i >= 0; i--) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

int main() {
    std::vector<int> lst1;
    lst1.push_back(5);
    lst1.push_back(1);
    lst1.push_back(3);
    lst1.push_back(4);
    Polynome<int> p(lst1);
    p.output();
    int res = p.evaluate(2);
    std::cout << res << std::endl;
}

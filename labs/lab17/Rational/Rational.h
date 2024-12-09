#ifndef __RATIONAL__
#define __RATIONAL__

#include <iostream>
#include <cmath>
#include <exception>
#include <string>

class WrongRatioException : public std::exception {
    int nom;
public:
    WrongRatioException() : nom(0) {}
    WrongRatioException(int x) : nom(x) {}

    const char* what(){
	     return "Denominator can't be 0";
	} 

    void show() const {
        std::cerr << "Ratio Exception\nNumerator: " << nom << "\n";
    }
};

class Rational {
private:
    int nom;
    unsigned denom;

public:
    Rational() : nom(1), denom(1U) {}
    Rational(int x, unsigned y) : nom(x), denom(y) {
        if (denom == 0) throw WrongRatioException(nom);
        reduce();
    }

    void show() const;
    int input();

    int setNom(int x) {
        nom = x;
        return 0;
    }

    int setDenom(unsigned y) {
        if (y != 0) {
            denom = y;
            return 0;
        }
        throw WrongRatioException(nom);
    }

    Rational add(const Rational& x) const;
    Rational mult(const Rational& x) const;

    Rational operator+(const Rational& x) const {
        return add(x);
    }

    Rational operator*(const Rational& x) const {
        return mult(x);
    }

    Rational operator-(const Rational& x) const {
        int ch = static_cast<int>(nom * x.denom - x.nom * denom);
        unsigned zn = denom * x.denom;
        return Rational(ch, zn);
    }

    Rational operator/(const Rational& x) const {
        if (x.nom == 0) throw WrongRatioException(0);
        int ch = static_cast<int>(nom * x.denom);
        unsigned zn = denom * x.nom;
        return Rational(ch, zn);
    }

    Rational operator-() const {
        return Rational(-nom, denom);
    }

    bool operator<(const Rational& x) const {
        return (nom * x.denom < denom * x.nom);
    }

    bool operator>(const Rational& x) const {
        return !(*this < x) && (*this != x);
    }

    bool operator==(const Rational& x) const {
        return (nom * x.denom == denom * x.nom);
    }

    bool operator!=(const Rational& x) const {
        return !(*this == x);
    }

    static unsigned gcd(unsigned x, unsigned y);
    double toDouble() const;

    friend std::ostream& operator<<(std::ostream& output, const Rational& r) {
        output << r.nom << "/" << r.denom;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, Rational& r) {
        input >> r.nom >> r.denom;
        if (r.denom == 0) throw WrongRatioException(r.nom);
        r.reduce();
        return input;
    }

    friend void writeToFile(const std::string& fname, const Rational& r);

private:
    void reduce();
};

#endif // __RATIONAL__

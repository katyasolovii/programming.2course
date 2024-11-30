#include "Rational.h"
#include <fstream>

double Rational::toDouble() const {
    return static_cast<double>(nom) / denom;
}

void Rational::show() const {
    std::cout<< nom<< "/"<<denom<<"\n";
}

int Rational::input() {
    int ch;
   unsigned zn=0;		
   std::cout<<"Input nom:";
   std::cin>>ch;	
   while(!zn){	
   	std::cout<<"Input denom:";
   	std::cin>>zn;
   }
   nom = ch;
   denom = zn;
   reduce();	
   return 0;	
}

Rational Rational::add(const Rational& x) const {
    int t = (int)(this->nom * x.denom + denom * x.nom);
	unsigned y = x.denom * denom;
	return Rational(t,y);
}

Rational Rational::mult(const Rational& x) const {
    int t = nom * x.nom;
	unsigned y = x.denom * denom;
	return Rational(t,y);
}

unsigned Rational::gcd(unsigned x, unsigned y) {
    if(y==0||x==0) return x+y;
	if(x>=y) return gcd(x%y,y);
	return gcd(y%x,x);
}

void Rational::reduce() {
    int nsd; 
	if(nom>=0)
	 nsd = (int)gcd(nom,denom);
	else
	 nsd = (int)gcd(-nom,denom);

	nom /= nsd;
	denom /= nsd;
}

Rational Hregory(double eps) {
    Rational s;
    int sign = -1;
    for (int i = 2; eps * i * i < 1; i++) {
        Rational tmp(sign, i * i);
        sign = -sign;
        s = s + tmp;
        if (1.0 / (i * i) < eps) break;
    }
    return s;
}

void writeToFile(const std::string& fname, const Rational& r) {
    try {
        std::ofstream file(fname, std::ios::app);
        if (!file) throw std::ios_base::failure("File could not be opened.");
        file << r.nom << "/" << r.denom << std::endl;
    } catch (...) {
        std::cerr << "Error writing to file" << std::endl;
    }
}

int main() {
    Rational r1, r2(2, 3), r5;
    r1.input();

    Rational r3 = -r1 + r2;
    Rational r4 = r1 * r2;
    r3.show();
    std::cout << r4;

    unsigned p = Rational::gcd(60, 35);
    std::cout << p;

    int ch;
    unsigned zn;
    std::cin >> ch >> zn;
    r5.setNom(ch);
    try {
        r5.setDenom(zn);
    } catch (const WrongRatioException& e) {
        std::cout << "Division by zero: ";
        e.show();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Rational q = Hregory(0.01);
    q.show();

    std::cout << std::boolalpha << (q.toDouble() < (M_PI * M_PI / 12.0)) << std::endl;
}

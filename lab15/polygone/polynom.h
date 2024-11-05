#include <iostream>

class Polynom{
    size_t n;
    double *p;

public:
    Polynom(){n = 0;}
    Polynom(size_t n);
    Polynom(size_t n, double *arr);
    ~Polynom();
    Polynom &operator=(const Polynom &a);
    Polynom(const Polynom &p);
    int set(size_t k, double a);
    double get(size_t k);
    void show();
    friend int saveFile(const char *fname, const Polynom &P);
    friend int readFile(const char *fname, Polynom &P);
};
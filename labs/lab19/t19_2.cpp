#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> input_vect(int dimension);
double norma(const vector<double>& v);

int main(){
    int d, n;
    cin >> d;
    vector<double> a = input_vect(d);
    cin >> n;
    vector<vector<double> > matr;

    for (int i = 0; i < n; i++) {
        a = input_vect(d);
        matr.push_back(a);
    }

    double st = 0;
    for (size_t i = 0; i < matr.size(); i++) {
        st += norma(matr[i]);
    }

    cout << st;
}

vector<double> input_vect(int dimension){
    vector<double> r;
    for (int i = 0; i < dimension; i++) {
        double x;
        cin >> x;
        r.push_back(x);
    }
    return r;
}

double norma(const vector<double>& v){
    double s = 0;
    for (int i = 0; i < v.size(); i++) {
        s += v[i] * v[i];
    }
    return sqrt(s);
}

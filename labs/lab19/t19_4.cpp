#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <map>
using namespace std;

vector<list<double> > input_matrix(int n, int m);
// модуль вектора
double norm(const vector<double>& v);
// сортування списку за спаданням
bool compare_pairs(const pair<double, int>& a, const pair<double, int>& b);

vector<list<double> > input_matrix(int n, int m) {
    vector<list<double> > matrix(n);
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ":\n";
        list<double> l;
        double temp;
        for (int j = 0; j < m; j++) {
            cout << "V[" << j + 1 << "]: ";
            cin >> temp;
            l.push_back(temp);
        }
        matrix[i] = l;
    }
    return matrix;
}

double norm(const vector<double>& v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += pow(v[i], 2);
    }
    return sqrt(sum);
}

bool compare_pairs(const pair<double, int>& a, const pair<double, int>& b) {
    return a.first > b.first;
}

int main() {
    int n, m;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;
    // ствоюємо матрицю n × m
    vector<list<double> > matrix = input_matrix(n, m);
    // контейнер (два списка)
    list<pair<double, int> > M;

    for (int j = 0; j < n; j++) {
        // *matrix[j].begin() - вказує на перший елемент списку
        double max_value = *matrix[j].begin(); 
        // проходимось по елементах списку, не змінюючи їх
        for (list<double>::const_iterator it = matrix[j].begin(); it != matrix[j].end(); it++) {
            if (*it > max_value) {
                max_value = *it;
            }
        }
        M.push_back(make_pair(max_value, j));
    }

    M.sort(compare_pairs);
    vector<list<double> > matrix_res(n);
    int i = 0;
    for (list<pair<double, int> >::iterator it = M.begin(); it != M.end(); it++) {
        // копіюємо рядок матриці за індексом
        matrix_res[i] = matrix[it->second];
        i++;
    }

    cout << "Result:\n";
    for (int i = 0; i < n; i++) {
        for (list<double>::const_iterator it = matrix_res[i].begin(); it != matrix_res[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

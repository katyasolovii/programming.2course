#include <iostream>
#include <math.h>
using namespace std;

class Point {
    double x;
    double y;
    static int count;

public:
    Point(){
        count++;
    }
    ~Point(){
        count--;
    }
    void input() {
        cout << "Enter x and y: ";
        cin >> x >> y;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    static int counter(){
        return count;
    }
};

double length(Point a, Point b) {
    double x = a.getX() - b.getX();
    double y = a.getY() - b.getY();
    return sqrt(x*x + y*y);
}

int Point::count = 0;

int main() {
    char answer;
    // масив показників на Point(s)
    Point* points[10];
    int i = 0;
    do {
        cout << "Input vertex?(Y/N):";
        cin >> answer;
        if (answer == 'N') {
            break;
        }
        points[i] = new Point(); 
        points[i]->input();
        i++;
    }while (answer == 'Y');

    cout << "The nuber of vectices: " << Point::counter() << endl;

    double perimeter = 0;
    for(int j = 1; j < i; j++) {
        perimeter += length(*points[j], *points[j - 1]);
    }
    perimeter += length(*points[i - 1], *points[0]);
    cout << "Perimeter: " << perimeter << endl;
}
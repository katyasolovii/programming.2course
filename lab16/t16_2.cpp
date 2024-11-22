#include <iostream>
#include <cmath>
using namespace std;

class Point {
protected:
    int n;
public:
    virtual void input() {}
    virtual void show() const {}
    virtual double length(const Point &other) const {
        return 0.0;
    }
    virtual int get_dimension() const {
        return n;
    }
    virtual ~Point() {}
};

class Point2D : public Point {
protected:
    double x, y;
public:
    Point2D() {
        n = 2;
    }
    void input() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }
    void show() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
    double length(const Point &other) const {
        const Point2D* p = dynamic_cast<const Point2D*>(&other);
        return sqrt(pow(x - p->x, 2) + pow(y - p->y, 2));
    }
};

class Point3D : public Point2D {
    double z;
public:
    Point3D() {
        n = 3;
    }
    void input() {
        Point2D::input();
        cout << "Enter z: ";
        cin >> z;
    }
    void show() const {
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }
    double length(const Point &other) const {
        const Point3D* p = dynamic_cast<const Point3D*>(&other);
        return sqrt(pow(x - p->x, 2) + pow(y - p->y, 2) + pow(z - p->z, 2));
    }
};

class Segment {
private:
    Point *p1, *p2;
public:
    Segment(Point* p1, Point* p2) : p1(p1), p2(p2) {}
    void input() {
        p1->input();
        p2->input();
    }
    void show() const {
        p1->show();
        p2->show();
    }
    double length() const {
        return p1->length(*p2);
    }
};

int main() {
    Point2D p1_2d, p2_2d;
    Point3D p1_3d, p2_3d;

    Segment segment2D(&p1_2d, &p2_2d);
    segment2D.input();
    segment2D.show();
    cout << "Length of 2D segment: " << segment2D.length() << endl;

    Segment segment3D(&p1_3d, &p2_3d);
    segment3D.input();
    segment3D.show();
    cout << "Length of 3D segment: " << segment3D.length() << endl;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
};

struct Segment {
    Point p1;
    Point p2;
    double length;

    Segment(Point p1 = Point(), Point p2 = Point()) {
        this->p1 = p1;
        this->p2 = p2;
        calculateLength();
    }

    void calculateLength() {
        length = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
};

void sort_segments(vector<Segment>& segments) {
    for (size_t i = 0; i < segments.size(); ++i) {
        for (size_t j = 0; j < segments.size() - 1 - i; ++j) {
            if (segments[j].length > segments[j + 1].length) {
                Segment temp = segments[j];
                segments[j] = segments[j + 1];
                segments[j + 1] = temp;
            }
        }
    }
}

int main() {
    ifstream inputFile("points.txt");
    ofstream outputFile("segments.txt");

    vector<Point> points;
    vector<Segment> segments;

    char ch;
    int x, y;
    while (inputFile >> ch >> x >> ch >> y >> ch) {
        points.push_back(Point(x, y));
    }

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            segments.push_back(Segment(points[i], points[j]));
        }
    }

    sort_segments(segments);

    for (size_t i = 0; i < segments.size(); ++i) {
        const Segment& segment = segments[i];
        outputFile << "(" << segment.p1.x << ", " << segment.p1.y << ") -> (" << segment.p2.x << ", " << segment.p2.y << ") Length: " << segment.length << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Successfully saved in file." << endl;
    return 0;
}

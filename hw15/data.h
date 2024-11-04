#pragma once
#include <iostream>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    void input();
    void difference(const Date& other) const;
    bool isLeapYear() const;
    int daysInMonth() const;
};

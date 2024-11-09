#include "data.h"

void Date::input() {
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
}

// методи з lab10(10.3)
bool Date::isLeapYear() const{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth() const{
    int MONTHDAY[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear()) {
        return 29;
    }
    return MONTHDAY[month - 1];
}

void Date::difference(const Date& other) const{
    if (this->year < 0 || other.year < 0 || this->month < 1 || this->month > 12 || other.month < 1 || other.month > 12 || this->day < 1 || this->day > this->daysInMonth() || other.day < 1 || other.day > other.daysInMonth()) {
        cout << "Invalid date!!!" << endl;
        return;
    }

    Date start_date = *this;
    Date end_date = other;

    // start_date завжди має бути меншою датою ніж end_date
    if (end_date.year < start_date.year || (end_date.year == start_date.year && end_date.month < start_date.month) || (end_date.year == start_date.year && end_date.month == start_date.month && end_date.day < start_date.day)) {
        Date temp = end_date;
        start_date = end_date;
    }

    int yearsDiff = end_date.year - start_date.year;
    int monthsDiff = end_date.month - start_date.month;
    int daysDiff = end_date.day - start_date.day;

    if (daysDiff < 0) {
        monthsDiff -= 1;
        daysDiff += start_date.daysInMonth();
    }
    if (monthsDiff < 0) {
        yearsDiff -= 1;
        monthsDiff += 12;
    }

    cout << "Difference: " << yearsDiff << " years, " << monthsDiff << " months, " << daysDiff << " days." << endl;
}

int main() {
    Date date1;
    date1.input();
    Date date2;
    date2.input();
    date1.difference(date2);
}

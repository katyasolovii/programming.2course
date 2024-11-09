#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Time{
public:
    int hour;
    int minute;
    int second;

    public: void input(){
        cout << "Enter hour: ";
        cin >> hour;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter second: ";
        cin >> second;
    }

    void different(const Time& other){
        int time1 = hour * 3600 + minute * 60 + second;
        int time2 = other.hour * 3600 + other.minute * 60 + other.second;
        int difference = abs(time1 - time2);
        int diff_hour = difference / 3600;
        int diff_minute = difference / 60;
        int diff_second = difference % 60;
        cout << "Difference: " << diff_hour << " hours, " << diff_minute << " minutes, " << diff_second << " seconds." << endl;
    }
};

int main(){
    Time t1;
    t1.input();
    Time t2;
    t2.input();
    t1.different(t2);
}

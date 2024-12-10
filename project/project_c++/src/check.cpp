#include "../headers/check.h"

bool is_valid_String(const string& input) {
    if (input.empty()) return false;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!isalpha(input[i]) && input[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool is_valid_Int(const string& input, int& output) {
    if (input.empty()) return false;
    stringstream ss(input);
    ss >> output;
    return ss.eof() && !ss.fail() && output > 0;
}

bool is_valid_Double(const string& input, double& output) {
    if (input.empty()) return false; 
    stringstream ss(input);
    ss >> output;
    return ss.eof() && !ss.fail() && output > 0;
}

bool is_valid_Degree(const string& input) {
    return input == "Bachelor" || input == "Master";
}

bool is_valid_average_grade(double average_grade) {
    return average_grade >= 60.0 && average_grade <= 100.0;
}

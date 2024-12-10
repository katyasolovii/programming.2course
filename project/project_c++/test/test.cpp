#include <iostream>
#include <cassert>
#include <sstream>
#include "../src/check.cpp"
#include "../headers/uni.h"
#include "../src/uni.cpp"

using namespace std; 

void test_is_valid_String() {
    assert(is_valid_String("Maria") == true); 
    assert(is_valid_String("Maria534645") == false); 
    assert(is_valid_String("") == false);
}

void test_is_valid_Int() {
    int output;
    assert(is_valid_Int("123", output) == true && output == 123);
    assert(is_valid_Int("0", output) == false); 
    assert(is_valid_Int("-5", output) == false);  
    assert(is_valid_Int("abc", output) == false);
}

void test_is_valid_Double() {
    double output;
    assert(is_valid_Double("123.45", output) == true && output == 123.45); 
    assert(is_valid_Double("0.0", output) == false && output == 0.0); 
    assert(is_valid_Double("-5.5", output) == false); 
    assert(is_valid_Double("abc", output) == false); 
}

void test_is_valid_Degree() {
    assert(is_valid_Degree("Bachelor") == true);
    assert(is_valid_Degree("Master") == true); 
    assert(is_valid_Degree("ggfdgd") == false); 
    assert(is_valid_Degree("master") == false); 
    assert(is_valid_Degree("bachelor") == false); 
}

void test_is_valid_average_grade() {
    assert(is_valid_average_grade(75.0) == true); 
    assert(is_valid_average_grade(59.9) == false); 
    assert(is_valid_average_grade(100.0) == true); 
    assert(is_valid_average_grade(101.0) == false);
}

void test_file_Exists() {
    ofstream test_file("test_file.txt");
    test_file << "Test file content.";
    test_file.close();

    assert(file_Exists("test_file.txt") == true);  
    assert(file_Exists("dgdfh.txt") == false); 
    remove("test_file.txt");
}

void test_create_filename() {
    ofstream file1("test.json");
    file1.close();
    ofstream file2("test_1.json");
    file2.close();
    
    string filename = create_filename("test");
    assert(filename == "test_2.json"); 

    remove("test.json");
    remove("test_1.json");
}

void test_is_valid_Profession() {
    assert(is_valid_Profession("Lecturer") == true); 
    assert(is_valid_Profession("Laboratory Assistant") == true);
    assert(is_valid_Profession("Electrician") == true); 
    assert(is_valid_Profession("Head of Department") == true); 
    assert(is_valid_Profession("fgdfgdgdf") == false); 
    assert(is_valid_Profession("Lecturerss") == false);
    assert(is_valid_Profession("gf54") == false);
}

int main() {
    test_is_valid_String();
    test_is_valid_Int();
    test_is_valid_Double();
    test_is_valid_Degree();
    test_is_valid_average_grade();
    test_file_Exists();
    cout << "All tests passed! \n" << endl;
}

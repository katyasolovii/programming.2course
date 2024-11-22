#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void task25(){
    string s;
    ifstream file("text25.txt");
    if (!file.is_open()){
        cout << "Error opening file." << endl;
        return;
    }
    string vowels = "aeiouAEIOU"; 
    int vowels_count[10] = {0};

    while (getline(file, s)) {
        stringstream ss(s);
        char letter;
        while (ss >> letter) {
            size_t found = vowels.find(letter);
            if (found != string::npos){
                vowels_count[found]++;
            }
        }
    }
    file.close();

    int max_count = 0;
    char most_frequent_vowel;
    for (int i = 0; i < 10; ++i) {
        if (vowels_count[i] > max_count) {
            max_count = vowels_count[i];
            most_frequent_vowel = vowels[i];
        }
    }
    cout << "Most frequent vowel: " << most_frequent_vowel << ", count = " << max_count << endl;
}

int main(){
    task25();
}
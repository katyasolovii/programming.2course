#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void task19(){
    string s;
    cout << "Enter string: " << endl;
    getline(cin, s);
    
    stringstream ss(s);
    string word;

    while (ss >> word) {
        if (word.length() > 4 && word.substr(word.length() - 4) == "ings") {
            cout << word << endl;
        }
    }
}

int main(){
    task19();
}
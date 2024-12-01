#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <map>
#include <fstream>
using namespace std;

int main() {
    const char* filename = "text.txt";
    fstream f(filename);
    
    if (!f) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string r;
    map<string, int> fr;
    
    while (f >> r) {
        if (fr.find(r) == fr.end()) {
            fr[r] = 1;
        } else {
            fr[r]++;
        }
    }
    for (map<string, int>::const_iterator it = fr.begin(); it != fr.end(); it++) {
        cout << it->first << "_" << it->second << "\n";
    }

    f.close();
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void task25() {
    const char* fname = "english.txt";
    const char* outputfile = "result.txt";
    const int line_width = 90;

    ifstream infile(fname);
    ofstream outfile(outputfile);

    if (!infile) {
        cerr << "Error opening file: " << fname << endl;
        return;
    }

    if (!outfile) {
        cerr << "Error opening file: " << outputfile << endl;
        return;
    }

    string word, line, curr_line;
    char space = ' ';
    while (getline(infile, line)) {
        istringstream str(line);
        while (str >> word) {
            if (curr_line.length() + space + word.length() > line_width) {
                outfile << curr_line << endl;
                curr_line = word;
            } else {
                if (!curr_line.empty()) {
                    curr_line += space;
                }
                curr_line += word;
            }
        }
    }
    if (!curr_line.empty()) {
        outfile << curr_line << endl;
    }

    infile.close();
    outfile.close();
}

int main() {
    task25();
}

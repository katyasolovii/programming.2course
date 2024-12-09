#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int find_min(const vector<int>& vec) {
    int min_num = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < min_num) {
            min_num = vec[i];
        }
    }
    return min_num;
}

int find_max(const vector<int>& vec) {
    int max_num = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max_num) {
            max_num = vec[i];
        }
    }
    return max_num;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Can't open file input.txt" << endl;
        return 1;
    }

    vector<int> V;
    int num;

    while (inputFile >> num) {
        V.push_back(num);
    }
    inputFile.close();

    if (V.size() < 3) {
        cout << "The vector must contain at least 3 different numbers." << endl;
        return 1;
    }

    int min = find_min(V);
    int max = find_max(V);

    // без використання множини
    vector<int> res_without_set;
    for (size_t i = 0; i < V.size(); ++i) {
        if (V[i] != min && V[i] != max) {
            bool uniq = true;
            for (size_t j = 0; j < res_without_set.size(); ++j) {
                if (res_without_set[j] == V[i]) {
                    uniq = false;
                    break;
                }
            }
            if (uniq) {
                res_without_set.push_back(V[i]);
            }
        }
    }

    for (size_t i = 0; i < res_without_set.size(); ++i) {
        for (size_t j = i + 1; j < res_without_set.size(); ++j) {
            if (res_without_set[i] < res_without_set[j]) {
                int temp = res_without_set[i];
                res_without_set[i] = res_without_set[j];
                res_without_set[j] = temp;
            }
        }
    }

    cout << "Result (without set): ";
    for (size_t i = 0; i < res_without_set.size(); ++i) {
        cout << res_without_set[i] << " ";
    }
    cout << endl;

    // з використанням множини
    set<int> uniqueSet(V.begin(), V.end());
    uniqueSet.erase(min);
    uniqueSet.erase(max);

    vector<int> res_with_set(uniqueSet.begin(), uniqueSet.end());
    for (size_t i = 0; i < res_with_set.size(); ++i) {
        for (size_t j = i + 1; j < res_with_set.size(); ++j) {
            if (res_with_set[i] < res_with_set[j]) {
                int temp = res_with_set[i];
                res_with_set[i] = res_with_set[j];
                res_with_set[j] = temp;
            }
        }
    }

    cout << "Result (with set): ";
    for (size_t i = 0; i < res_with_set.size(); ++i) {
        cout << res_with_set[i] << " ";
    }
    cout << endl;
}

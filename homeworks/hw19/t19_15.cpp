#include <iostream>
#include <vector>

int main() {
    std::vector<int> L;
    int n;

    std::cout << "Enter numbers:" << std::endl;

    while (std::cin >> n) {
        L.push_back(n);
    }

    std::cout << "Initial list:" << std::endl;
    for (int i = 0; i < L.size(); ++i) {
        std::cout << L[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Reversed list:" << std::endl;
    for (int i = L.size() - 1; i >= 0; i--) {
        std::cout << L[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < L.size() - 1; i++) {
        for (int j = 0; j < L.size() - 1 - i; j++) {
            if (L[j] > L[j + 1]) {
                int temp = L[j];
                L[j] = L[j + 1];
                L[j + 1] = temp;
            }
        }
    }

    std::cout << "Reverse sorted list:" << std::endl;
    for (int i = L.size() - 1; i >= 0; i--) {
        std::cout << L[i] << " ";
    }
    std::cout << std::endl;
}

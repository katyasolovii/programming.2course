#include <iostream>
#include <fstream>
#include <vector>

class BinaryFile {
private:
    std::string filename;
    size_t count;
public:
    BinaryFile(const std::string& filename) : filename(filename), count(0) {}

    void input(size_t n) {
        std::ofstream f(filename, std::ios::binary | std::ios::trunc);
        if (!f) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }
        int number;
        for (size_t i = 0; i < n; i++) {
            std::cout << "Enter number " << i << ": ";
            std::cin >> number;
            // <char*>(&number) - вказівник на змінну number (int*) -> char*
            f.write(reinterpret_cast<char*>(&number), sizeof(int));
        }
        count = n;
    }

    // файл з масиву чисел
    void create_file(const std::vector<int>& numbers) {
        std::ofstream f(filename, std::ios::binary | std::ios::trunc);
        if (!f) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }
        for (size_t i = 0; i < numbers.size(); i++) {
            f.write(reinterpret_cast<const char*>(&numbers[i]), sizeof(int));
        }
        count = numbers.size();
    }

    void show_file() const {
        std::ifstream f(filename, std::ios::binary);
        if (!f) {
            std::cerr << "Error opening file for reading.\n";
            return;
        }
        int number;
        size_t index = 0;
        while (f.read(reinterpret_cast<char*>(&number), sizeof(int))) {
            std::cout << number << " ";
            index++;
        }
        std::cout << "\n";
    }

    int number_by_index(size_t index) const {
        if (index >= count) {
            std::cerr << "Index out of range.\n";
            return -1; 
        }
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            std::cerr << "Error opening file for reading.\n";
            return -1;
        }
        std::vector<int> numbers;
        int number;
        while (in.read(reinterpret_cast<char*>(&number), sizeof(int))) {
            numbers.push_back(number);
        }
        if (index < numbers.size()) {
            return numbers[index];
        } else {
            std::cerr << "Index out of range.\n";
            return -1;
        }
    }

    void added_numbers(const std::vector<int>& numbers) {
        std::ofstream f(filename, std::ios::binary | std::ios::app);
        if (!f) {
            std::cerr << "Error opening file for appending.\n";
            return;
        }

        for (size_t i = 0; i < numbers.size(); i++) {
            f.write(reinterpret_cast<const char*>(&numbers[i]), sizeof(int));
        }
        count += numbers.size();
    }

    void delete_number(size_t index) {
        if (index >= count) {
            std::cerr << "Index out of range.\n";
            return;
        }
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            std::cerr << "Error opening file for reading.\n";
            return;
        }
        std::vector<int> numbers;
        int number;
        while (in.read(reinterpret_cast<char*>(&number), sizeof(int))) {
            numbers.push_back(number);
        }
        if (index >= numbers.size()) {
            std::cerr << "Index out of range.\n";
            return;
        }
        numbers.erase(numbers.begin() + index);
        std::ofstream out(filename, std::ios::binary);
        if (!out) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }
        for (size_t i = 0; i < numbers.size(); ++i) {
            out.write(reinterpret_cast<const char*>(&numbers[i]), sizeof(int));
        }
        count = numbers.size();
    }
};

int main() {
    BinaryFile file("numbers.dat");
    
    file.input(5);
    std::cout << "File:\n";
    file.show_file();

    std::vector<int> new_num;
    new_num.push_back(76);
    new_num.push_back(20);
    new_num.push_back(35);
    file.added_numbers(new_num);
    std::cout << "File after appending:\n";
    file.show_file();

    int number = file.number_by_index(2);
    std::cout << "Number at index 2: " << number << std::endl;

    file.delete_number(1);
    std::cout << "File after deletion:\n";
    file.show_file();
}

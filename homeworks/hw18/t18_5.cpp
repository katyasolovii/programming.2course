#include <iostream>

template <typename T> class Array {
    private:
        T* data;
        size_t size;
    public:
        Array(size_t size) : size(size), data(new T[size]) {}
        ~Array() {delete[] data;}

        size_t getSize() const {
            return size;
        }

        T& operator[](size_t index) {
            return data[index];
        }

        void quickSort(size_t left, size_t right) {
            quickSortHelper(data, left, right);
        }

        // статичний метод
        static void quickSort(T array[], size_t left, size_t right) {
            quickSortHelper(array, left, right);
        }

    private:
        static void quickSortHelper(T array[], size_t left, size_t right) {
            if (left >= right) return;

            size_t i = left, j = right;
            T pivot = array[left + ((right - left) >> 1)]; 

            while (i <= j) {
                while (array[i] < pivot) i++;
                while (array[j] > pivot) j--;

                if (i <= j) {
                    std::swap(array[i], array[j]);
                    i++;
                    j--;
                }
            }

            if (j > left)
                quickSortHelper(array, left, j);
            if (i < right)
                quickSortHelper(array, i, right);
        }
};


int main() {
    Array<int> arr(5);
    arr[0] = 10;
    arr[1] = 7;
    arr[2] = 3;
    arr[3] = 8;
    arr[4] = 5;

    std::cout << "Origin array:\n";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.quickSort(0, arr.getSize() - 1);
    std::cout << "Sorted array:\n";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int arr2[] = {10, 7, 3, 8, 5};
    Array<int>::quickSort(arr2, 0, 4);
    std::cout << "Sorted array (static method):\n";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
}

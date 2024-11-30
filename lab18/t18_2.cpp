#include <iostream>
#include <stack>

// будь-який тип даних
template <class T>
int input_stack(std::stack<T>& s) {
    T x;
    int count = 0;
    while (true) {
        std::cin >> x;
        if (x == 0) {
            return count;
        }
        count++;
        s.push(x);
    }
}

namespace Our {
    template <class T = int>
    struct Noole {
        T data;
        Noole* prt;
    };

    template <typename T = int>
    class Stack {
        size_t n;
        Noole<T>* current;

    public:
        Stack() : n(0), current(nullptr) {}

        void push(T x) {
            Noole<T>* z = new Noole<T>();
            z->data = x;
            z->prt = current;
            current = z;
            n++;
        }

        // видаляє верхній елемент зі стека
        void pop() {
            Noole<T>* temp = current;
            current = current->prt;
            delete temp;
            n--;
        }

        size_t len() {
            return n;
        }

        T top() {
            if (n == 0) {
                std::cerr << "Stack is empty!" << std::endl;
                return T();
            }
            return current->data;
        }

        bool isempty() {
            return n == 0;
        }

        void show() {
            while (!isempty()) {
                std::cout << top() << " ";
                pop();
            }
            std::cout << std::endl;
        }
    };
}

int main() {
    std::stack<int> s;
    std::cout << "Enter stack elements (0 to stop):\n";
    input_stack(s);

    if (s.empty()) {
        std::cout << "The stack is empty!" << std::endl;
    } else {
        std::cout << "Standard stack contents: ";
        std::stack<int> temp_stack = s;
        while (!temp_stack.empty()) {
            std::cout << temp_stack.top() << " ";
            temp_stack.pop();
        }
        std::cout << std::endl;
        std::cout << "Length of stack: " << s.size() << std::endl;
    }

    Our::Stack<int> our_stack;
    our_stack.push(1);
    our_stack.push(2);
    our_stack.push(3);
    std::cout << "Our Stack contents: ";
    our_stack.show();
}

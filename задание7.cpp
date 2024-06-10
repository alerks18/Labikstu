#include <iostream>

class Stack {
public:
    static bool isEmpty(int size) { return size == 0; }
};

int main() {
    std::cout << "Is stack empty? " << Stack::isEmpty(0) << std::endl;
    return 0;
}

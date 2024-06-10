#include <iostream>

class Stack {
public:
    static bool isEmpty(int size) { return size == 0; }
};

int main() {
    int stackSize = 0;
    std::cout << "Is stack empty? " << Stack::isEmpty(stackSize) << std::endl;
    return 0;
}

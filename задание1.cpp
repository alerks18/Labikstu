#include <iostream>

class Calculator {
public:
    static int add(int a, int b) { return a + b; }
    static int subtract(int a, int b) { return a - b; }
    static int multiply(int a, int b) { return a * b; }
    static double divide(int a, int b) {
        if (b == 0) throw std::runtime_error("Division by zero is not allowed");
        return static_cast<double>(a) / b;
    }
};

int main() {
    try {
        std::cout << "Addition of 5 and 3: " << Calculator::add(5, 3) << std::endl;
        std::cout << "Subtraction of 5 from 3: " << Calculator::subtract(5, 3) << std::endl;
        std::cout << "Multiplication of 5 and 3: " << Calculator::multiply(5, 3) << std::endl;
        std::cout << "Division of 5 by 3: " << Calculator::divide(5, 3) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

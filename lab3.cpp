#include <iostream>
#include <limits> // Для использования std::numeric_limits

int main() {
    int numerator, denominator;
    double result;

    // Включаем исключение badbit для cin, чтобы обработать некорректный ввод данных
    std::cin.exceptions(std::istream::failbit | std::istream::badbit);

    try {
        std::cout << "Please enter the numerator: ";
        std::cin >> numerator;

        // Проверка на некорректный ввод
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input for numerator");
        }

        std::cout << "Please enter the denominator: ";
        std::cin >> denominator;

        // Проверка на некорректный ввод
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input for denominator");
        }

        // Проверка деления на ноль
        if (denominator == 0) {
            throw std::runtime_error("Division by zero is not allowed");
        }

        // Выполняем деление
        result = static_cast<double>(numerator) / denominator;
        std::cout << "The result of the division is: " << result << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Сбрасываем флаг ошибки ввода
        std::cin.clear();
        // Очищаем буфер ввода до новой строки, чтобы избежать зацикливания ввода
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}

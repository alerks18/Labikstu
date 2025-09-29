#include <iostream>
#include <string>

class Clock {
public:
    // Статическая переменная для хранения текущего времени
    static std::string currentTime;

    // Метод для обновления текущего времени
    static void updateCurrentTime(const std::string& newTime) {
        currentTime = newTime;
    }
};

// Инициализация статической переменной currentTime
std::string Clock::currentTime = "00:00";

int main() {
    // Вывод текущего времени, доступного через статическую переменную currentTime
    std::cout << "Current time: " << Clock::currentTime << std::endl;

    // Обновление текущего времени
    Clock::updateCurrentTime("12:00");

    // Вывод обновленного текущего времени
    std::cout << "Updated current time: " << Clock::currentTime << std::endl;

    return 0;
}

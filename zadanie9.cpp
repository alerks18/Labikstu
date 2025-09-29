#include <iostream>

class Planet {
private:
    const double radius; // Радиус планеты, объявленный как константа, чтобы он не мог быть изменен после создания объекта
public:
    // Конструктор класса, который устанавливает радиус планеты при создании объекта
    Planet(double r) : radius(r) {} 
    
    // Метод класса, отвечающий за вывод радиуса планеты
    void printRadius() const { 
        std::cout << "The radius of the planet is: " << radius << " kilometers." << std::endl;
    }
};

int main() {
    Planet earth(6371); // Создание объекта класса Planet с радиусом Земли
    earth.printRadius(); // Вывод информации о радиусе планеты Земля
    return 0;
}

#include <iostream>

class Queue {
private:
    static const int maxSize = 50; // Максимальный размер очереди, определенный как константа
public:
    // Метод для проверки, заполнена ли очередь
    static bool isFull(int size) { 
        return size == maxSize; // Возвращает true, если размер очереди равен максимальному
    }
};

int main() {
    int queueSize = 0; // Начальный размер очереди
    std::cout << "Is queue full? " << Queue::isFull(queueSize) << std::endl; // Выводим результат проверки на заполненность очереди
    return 0;
}

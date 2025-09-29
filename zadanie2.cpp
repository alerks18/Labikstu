#include <iostream>
#include <string>

class Student {
private:
    const std::string name;
public:
    Student(const std::string& n) : name(n) {}
    
    void printName() const {
        std::cout << "Name: " << name << std::endl;
    }

    std::string getName() const {
        return name;
    }
};

int main() {
    Student student("John");
    student.printName();
    std::cout << "Retrieved name: " << student.getName() << std::endl;
    return 0;
}

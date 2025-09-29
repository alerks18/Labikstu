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
};

int main() {
    Student student("John");
    student.printName();
    return 0;
}

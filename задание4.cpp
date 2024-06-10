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
    Student student1("John");
    Student student2("Alice");
    Student student3("Bob");

    student1.printName();
    student2.printName();
    student3.printName();

    return 0;
}

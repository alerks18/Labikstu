#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

struct Script {
    std::string filename;
    std::string description;
};

void display_menu(const std::vector<Script>& scripts) {
    std::cout << "Please select a script to run:\n";
    for (size_t i = 0; i < scripts.size(); ++i) {
        std::cout << i + 1 << ". " << scripts[i].filename << std::endl;
    }
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void show_script_details(const Script& script) {
    clear_screen();
    std::cout << "You have selected: " << script.filename << std::endl;
    std::cout << "Description: " << script.description << std::endl;

    std::string image_path = "images/" + script.filename;
    image_path.replace(image_path.find(".cpp"), 4, ".png");

    std::cout << "\nAttempting to open image: " << image_path << std::endl;

    // Command to open the image with the default system viewer
#ifdef _WIN32
    std::string command = "start " + image_path;
#elif __APPLE__
    std::string command = "open " + image_path;
#else
    std::string command = "xdg-open " + image_path;
#endif

    // We use a temporary file to check existence because system() return codes for file opening are not reliable.
    FILE* file = fopen(image_path.c_str(), "r");
    if (file) {
        fclose(file);
        system(command.c_str());
        std::cout << "If the image did not open, please ensure you have a default image viewer configured." << std::endl;
    } else {
        std::cout << "Image not found at " << image_path << ". Please add it to the 'images' directory." << std::endl;
    }
    std::cout << "-------------------------------------------\n\n";
}

bool confirm_execution() {
    char choice;
    std::cout << "Do you want to run this script? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

void run_script(const std::string& filename) {
    std::string compile_command = "g++ -std=c++11 " + filename + " -o temp_executable";
    std::cout << "Compiling: " << compile_command << std::endl;

    int compile_result = system(compile_command.c_str());

    if (compile_result == 0) {
        std::cout << "\n--- Running " << filename << " ---\n" << std::endl;
        system("./temp_executable");
        std::cout << "\n--- " << filename << " finished ---\n" << std::endl;
        remove("./temp_executable");
    } else {
        std::cerr << "Compilation failed for " << filename << std::endl;
    }
}

int main() {
    std::vector<Script> scripts = {
        {"zadanie1.cpp", "A simple calculator that can add, subtract, multiply, and divide."},
        {"zadanie2.cpp", "Demonstrates a simple Student class with a name."},
        {"zadanie3.cpp", "Similar to zadanie2, demonstrates a Student class."},
        {"zadanie4.cpp", "Creates multiple instances of the Student class."},
        {"zadanie5.cpp", "A simple BankAccount class with a balance."},
        {"zadanie6.cpp", "Checks if a simple Stack is empty."},
        {"zadanie7.cpp", "Also checks if a Stack is empty."},
        {"zadanie8.cpp", "A Clock class with a static time variable."},
        {"zadanie9.cpp", "A Planet class with a constant radius."},
        {"zadanie10.cpp", "Checks if a simple Queue is full."},
        {"lab2.cpp", "A movie database that can be queried by director, studio, and year."},
        {"lab3.cpp", "A division calculator with exception handling for invalid input and division by zero."}
    };

    int choice = 0;
    while (true) {
        clear_screen();
        display_menu(scripts);
        std::cout << "Enter your choice (1-" << scripts.size() << "), or 0 to exit: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 0 || choice > static_cast<int>(scripts.size())) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (choice == 0) {
            break;
        }

        const Script& selected_script = scripts[choice - 1];
        show_script_details(selected_script);

        if (confirm_execution()) {
            run_script(selected_script.filename);
        } else {
            std::cout << "Execution cancelled." << std::endl;
        }

        std::cout << "\nPress Enter to return to the menu...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }

    std::cout << "Exiting." << std::endl;
    return 0;
}
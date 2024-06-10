#include <iostream>

class BankAccount {
private:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    double getBalance() const { return balance; }
};

int main() {
    BankAccount account(1000);
    std::cout << "Balance: " << account.getBalance() << std::endl;
    return 0;
}

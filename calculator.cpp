#include <iostream>
#include <string>
#include <cstdlib>

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {
    std::string op;
    while (true) {
        op = input("operation: ");
        int a;
        int b;
        if (op.empty()){
            break;
        } else if (op == "add" || op == "subtract" || op == "divide" || op == "multiply" || op == "mod"){
            std::cout << "left operand: ";
            std::cin >> a;
            while (std::cin.get() != '\n') {
            }
            std::cout << "right operand: ";
            std::cin >> b;
            while (std::cin.get() != '\n') {
            }
            if (op == "add") {
                std:: cout << a + b << std::endl;
            } else if (op == "subtract") {
                std:: cout << a - b << std::endl;
            } else if(op == "divide") {
                std::cout << a / b << std::endl;
            } else if (op == "multiply") {
                std:: cout<< a * b << std::endl;
            }else if (op == "mod") {
                std::cout << a % b << std::endl;
            }
        } else{
            std::cout << op << " isn't a valid operation" << std::endl;
        }
}
    return 0;
}

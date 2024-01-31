/*
 * ImplementationB.cpp
 *
 * Brian Conley
 * DSA Assgn-1A
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include "ImplementationBClass.hpp"

int main() {
    dsa::Stack myStack;
    int choice;
    char input[3];
    while (true) {
        std::cout << "Choose an operation:\n"
                  << "\t1) Push" << '\n'
                  << "\t2) Pop " << '\n'
                  << "\t3) Chew" << '\n'
                  << "\t4) Quit" << "\n\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Type two characters to push:\n";
                std::cin >> std::setw(3) >> input;
                myStack.push(input);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 2:
                std::cout << '\"' << myStack.pop() << "\"\n";
                break;
            case 3:
                while (true) {
                    char* poppedArray = myStack.pop();
                    if (poppedArray != nullptr) {
                        std::cout << '\"' << poppedArray << "\"\n";
                        delete[] poppedArray;
                    } else {
                        delete[] poppedArray;
                        choice = 4;
                        break;
                    }
                }
                break;
            case 4:
                std::cout << "Quit\n";
                break;
            default:
                std::cout << "Try again\n\n";
                break;
        }
        if (choice == 4)
            break;
    }

    return 0;
}

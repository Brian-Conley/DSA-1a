/*
 * ImplementationB.cpp
 *
 * Brian Conley
 * DSA Assgn-1A
 */
#include <iostream>
#include <iomanip>
#include <limits>

namespace dsa {
    class Stack {
        private:
            struct stackNode {
                // Contains two chars, must be size 3 for null terminator
                char data[3];
                stackNode* next;
            };
            stackNode* top;
        public:
            Stack() {
                top = nullptr;
            }

            ~Stack() {
                stackNode* tmp;
                while (top) {
                    tmp = top;
                    top = top->next;
                    delete tmp;
                }
            }

            void push(const char value[]) {
                stackNode* tmp = new stackNode;
                int i = 0;
                while (value[i] != '\0' && i < 2) {
                    tmp->data[i] = validateChar(value[i]);
                    ++i;
                }
                tmp->data[i] = '\0';
                tmp->next = top;
                top = tmp;
            }

            char* pop() {
                char* poppedArray = new char[3];
                if (top) {
                    stackNode* tmp = top;
                    int i = 0;
                    while (top->data[i] != '\0' && i < 2) {
                        poppedArray[i] = top->data[i];
                        ++i;
                    }
                    poppedArray[i] = '\0';
                    top = top->next;
                    delete tmp;
                } else {
                    delete[] poppedArray;
                    std::cerr << "Error: Stack underflow\n";
                    return nullptr;
                }
                return poppedArray;
            }
        // Helper functions
        private:
            // Ensures a char is upper alphabetic. Invalid char converts to space
            char validateChar(char c) {
                if (0x41 <= c && c <= 0x5A) {
                    // ASCII bounds for A-Z
                    return c;
                } else if (0x61 <= c && c <= 0x7A) {
                    // ASCII bounds for a-z
                    return c - 0x20;
                } else {
                    return ' ';
                }
            }
    };
}

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

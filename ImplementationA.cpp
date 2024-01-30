#include <iostream>
#include <iomanip>
#include <limits>

namespace dsa {
    class Stack {
        private:
            char* stackArr[10];
            int stackCounter;

        public:
            Stack() {
                stackCounter = -1;
            }
            ~Stack() {

                for (int i = stackCounter; i > -1; i--) {
                    delete[] stackArr[stackCounter];
                    stackCounter--;
                }
            }
            void push(char* value) {
                if (stackCounter >= 9) {
                    std::cerr << "Error: Stack overflow\n";
                    delete[] value;
                    return;
                } else {
                    ++stackCounter;
                    stackArr[stackCounter] = new char[3];
                    int i = 0;
                    while (value[i] != '\0' && i < 2) {
                        stackArr[stackCounter][i] = validateChar(value[i]);
                        ++i;
                    }
                    stackArr[stackCounter][i] = '\0';
                    delete[] value;
                    return;
                }
            }
            char* pop() {
                char* poppedArray = new char[3];
                if (stackCounter >= 0) {
                    int i = 0;
                    while (stackArr[stackCounter][i] != '\0' && i < 2) {
                        poppedArray[i] = stackArr[stackCounter][i];
                        ++i;
                    }
                    poppedArray[i] = '\0';
                    delete[] stackArr[stackCounter];
                    stackCounter--;
                } else {
                    delete[] poppedArray;
                    std::cerr << "Error: Stack underflow\n";
                    return nullptr;
                }
                return poppedArray;
            }
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
    char* input;
    while (true) {
        std::cout << "Choose an operation:\n"
                  << "\t1) Push" << '\n'
                  << "\t2) Pop " << '\n'
                  << "\t3) Chew" << '\n'
                  << "\t4) Quit" << "\n\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                input = new char[3];
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

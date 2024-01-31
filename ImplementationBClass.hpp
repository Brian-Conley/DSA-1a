#ifndef IMP_B_CLASS_HPP
#define IMP_B_CLASS_HPP

#include <iostream>

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
                // Terminates after 2 chars OR null terminator
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
                    // Terminates after 2 chars OR null terminator
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

#endif

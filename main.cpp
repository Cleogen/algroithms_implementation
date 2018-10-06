#include <iostream>
#include "Stack/LinkedStack.h"

int main() {
    auto linkedStack = LinkedStack();

    for (int i = 0; i < 10; ++i) {
        linkedStack.push(i);
        std::cout << linkedStack.top() << ", ";
    }
    std::cout << "\n";
    auto linkedStack2 = LinkedStack(linkedStack);
    auto linkedStack3 = linkedStack2;
    for (int j = 0; j < 10; ++j) {
        std::cout << linkedStack.top() << ", ";
        linkedStack.pop();
    }
    std::cout << "\n";
    std::cout << linkedStack2.top() << "\n";
    std::cout << linkedStack3.top() << "\n";
    return 0;
}

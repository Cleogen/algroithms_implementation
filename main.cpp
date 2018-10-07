#include <iostream>
#include "Stack/LinkedStack.h"
#include "Queue/LinkedQueue.h"

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
    for (int j = 0; j < 10; ++j) {
        std::cout << linkedStack2.top() << ", ";
        linkedStack2.pop();
    }
    std::cout << "\n";
    for (int j = 0; j < 10; ++j) {
        std::cout << linkedStack3.top() << ", ";
        linkedStack3.pop();
    }
    std::cout << "\n\n\n";

    auto linkedQueue = LinkedQueue();

    for (int i = 0; i < 10; ++i) {
        linkedQueue.push(i);
        std::cout << linkedQueue.head() << ", ";
    }
    std::cout << "\n";
    auto linkedQueue2 = LinkedQueue(linkedQueue);
    auto linkedQueue3 = linkedQueue2;
    for (int j = 0; j < 10; ++j) {
        std::cout << linkedQueue.head() << ", ";
        linkedQueue.pop();
    }
    std::cout << "\n";
    std::cout << linkedQueue2.head() << "\n";
    std::cout << linkedQueue3.head() << "\n";
    for (int j = 0; j < 10; ++j) {
        std::cout << linkedQueue2.head() << ", ";
        linkedQueue2.pop();
    }
    std::cout << "\n";
    for (int j = 0; j < 10; ++j) {
        std::cout << linkedQueue3.head() << ", ";
        linkedQueue3.pop();
    }
    return 0;
}

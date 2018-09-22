#include <iostream>
#include "Queue/Queue.h"

int main() {
    auto queue = new Queue(5);
    for (int i = 1; i <= 5; ++i) {
        queue->push(i);
        queue->display_queue();
    }
    std::cout << queue->size() << " :size\n";
    for (int j = 0; j < 5; ++j) {
        queue->pop();
        queue->display_queue();
    }
    std::cout << queue->size() << " :size\n";
    for (int i = 1; i <= 5; ++i) {
        queue->push(i);
        queue->display_queue();
    }
    std::cout << queue->size() << " :size\n";
    queue->display_queue();
    std::cout << queue->front() << "\n";
    return 0;
}

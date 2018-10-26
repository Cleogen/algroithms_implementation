#include <iostream>
#include "Lists/SequencedList.h"
#include "Lists/LinkedList.h"

int main() {
    auto *linkedList = new LinkedList();
    linkedList->push(20);
    linkedList->push(20);
    linkedList->push(10);
    linkedList->push_at_index(1,15);
    linkedList->push_at_index(-1,20);

    std::cout << *linkedList;


    std::cout << linkedList[1];

    return 0;
}

#include <iostream>
#include "Lists/SequencedList.h"

int main() {
    auto *seqList = new SequencedList();

    for (int i = 0; i < 45; ++i) {
        seqList->push_back(i);
        seqList->push_back(6);
    }
    seqList->removeAll(6);
    seqList->add(40, 846);

    std::cout << *seqList;
    return 0;
}

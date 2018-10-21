#include <iostream>
#include "SequencedList/SeqList.h"

int main() {
    auto *seqList = new SeqList();

    for (int i = 0; i < 45; ++i) {
        seqList->push_back(i);
        seqList->push_back(6);
    }
    seqList->removeAll(6);
    seqList->add(40, 846);

    std::cout << *seqList;
    return 0;
}

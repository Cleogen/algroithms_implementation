#include <iostream>
#include "Trees/Heap.h"

int main() {
    Heap heap = Heap();
    int x = 0;
    std::cout << "\n\ninsert\n\n";

    for (int i = 0; i < 20; ++i) {
        std::cin >> x;
        heap.insert(x);
        std::cout << heap;
    }
    std::cout << "\n\nremove\n\n";

    for (int j = 0; j < 5; ++j) {
        heap.remove();
        std::cout << heap;
    }
    return 0;
}

#include <iostream>
#include "Trees/SearchTree.h"

int main() {
    SearchTree tree = SearchTree();
    int x = 0;
    std::cout << "\n\ninsert\n\n";

    for (int i = 0; i < 20; ++i) {
        std::cin >> x;
        tree.insert(x);
    }
    std::cout << "\n\nremove\n\n";

    for (int j = 0; j < 5; ++j) {

    }
    return 0;
}

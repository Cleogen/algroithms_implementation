#include <iostream>
#include "Trees/SearchTree.h"

int main() {
    SearchTree tree = SearchTree();
    int x = 8;
    std::cout << "\n\ninsert\n\n";

    for (int i = 0; i < 5; ++i) {
        std::cin >> x;
        tree.insert(x);
        std::cout << tree << "\n";
    }
    std::cout << "\n\nremove\n\n";
    std::cout << tree.find(x);
    for (int j = 0; j < 5; ++j) {
        std::cin >> x;
        tree.remove(x);
        std::cout << tree << "\n";
    }
    return 0;
}

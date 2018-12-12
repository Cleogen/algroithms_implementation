#include <iostream>
#include "Trees/SearchTree.h"

int main() {
    SearchTree<int> tree = SearchTree<int>();
    int x = 8;
    int y[] = {100, 50, 110, 20, 75, 200, 40, 80, 150, 30, 45, 90, 160, 155};
    std::cout << "\n\ninsert\n\n";

    for (int i : y) {
        tree.elegant_insert(i);
        std::cout << tree << "\n";
    }
    std::cout << "\n\nremove\n\n";
    std::cout << tree.find(x);
    for (int j = 0; j < 14; ++j) {
        std::cin >> x;
        tree.elegant_remove(x);
        std::cout << tree << "\n";
    }
    return 0;
}

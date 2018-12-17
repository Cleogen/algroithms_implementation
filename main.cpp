#include "Trees/ListSearchTree.h"
#include <iostream>

int main() {
    ListSearchTree<int> tree = ListSearchTree<int>();
    int mass[10][2] = {{66, 3},
                       {43, 9},
                       {9,  2},
                       {0,  0},
                       {85, 6},
                       {37, 4},
                       {50, 8},
                       {86, 3},
                       {94, 0},
                       {7,  6}};
    std::cout << tree;
    int x = 0;
    int y = 0;
    for (auto &mas : mass) {
        tree.insert(mas[0], mas[1]);
    }
    std::cout << tree;
    for (int j = 0; j < 10; ++j) {
        std::cin >> x;
        tree.remove(x);
        std::cout << tree;
    }

    return 0;
}
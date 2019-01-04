#include "Trees/RBSTree.h"

int main() {
    RBSTree<int> tree = RBSTree<int>();
    int y[] = {100, 50, 20, 110, 75, 200, 40, 80, 150, 30, 45, 90, 160, 155};
    for (int i : y) {
        tree.elegant_insert(i);
        std::cout << tree;
    }
    return 0;
}
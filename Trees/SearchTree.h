#pragma once
#include "BTree.h"
#include "ostream"

class SearchTree {
    friend std::ostream &operator<<(std::ostream &, const SearchTree &);

public:
    SearchTree();

    ~SearchTree();

    SearchTree(const SearchTree&);

    SearchTree& operator=(const SearchTree&);

    bool find(const int&) const;

    int count() const;

    bool empty() const;

    void insert(const int&);

    void remove(const int&);

private:
    Node* m_root;
    int m_size;

    Node *find_node(const int &) const;

    void copy(const SearchTree &);

    void clear();
};

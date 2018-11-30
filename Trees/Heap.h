#pragma once

#include <ostream>

class Heap {
    friend std::ostream &operator<<(std::ostream &, const Heap &);

public:

    Heap(int maxsize = 42);

    ~Heap();

    Heap(const Heap &);

    Heap &operator=(const Heap &);

    void insert(const int &);

    void remove();

    const int &max() const;

private:
    int *m_tree;
    int m_size;
    int m_maxsize;

    void copyTree(const int[]);
};
#include <stdexcept>
#include "Heap.h"

Heap::Heap(int maxsize)
        : m_tree(nullptr), m_size(0), m_maxsize(maxsize) {
    m_tree = new int[m_maxsize];
}

Heap::~Heap() {
    delete[] m_tree;
}

Heap::Heap(const Heap &heap)
        : m_tree(nullptr), m_size(0), m_maxsize(heap.m_maxsize) {
    copyTree(heap.m_tree);
}

Heap &Heap::operator=(const Heap &heap) {
    delete[] m_tree;
    m_size = heap.m_size;
    m_maxsize = heap.m_maxsize;
    copyTree(heap.m_tree);
    return *this;
}

void Heap::insert(const int &value) {
    if (m_size == m_maxsize) {
        m_maxsize *= 2;
        int *old_tree = m_tree;
        copyTree(old_tree);
        delete[] old_tree;
    }
    int i = m_size;
    int j = 0;
    m_tree[m_size++] = value;

    while (i > 0) {
        j = (i - 1) / 2;
        if (m_tree[i] > m_tree[j]) {
            swap(m_tree[i], m_tree[j]);
            i = j;
        } else {
            break;
        }
    }
}

void Heap::remove() {
    if (m_size > 0) {
        m_tree[0] = 0;
        --m_size;

        int i = 0;
        int j = 0;
        while (i < m_size) {
            j = (m_tree[2 * i + 1] > m_tree[2 * i + 2]) ? (2 * i + 1) : (2 * i + 2);
            if (m_tree[j] > m_tree[i]) {
                swap(m_tree[i], m_tree[j]);
                i = j;
            } else {
                break;
            }
        }
    } else {
        throw std::out_of_range("!! No elements in Heap !!");
    }
}

const int &Heap::max() const {
    if (m_size > 0) {
        return m_tree[0];
    } else {
        throw std::out_of_range("!! No elements in Heap !!");
    };
}

void Heap::copyTree(const int *tree) {
    m_tree = new int[m_maxsize];
    for (int i = 0; i < m_size; ++i) {
        m_tree[i] = tree[i];
    }
}

void Heap::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

std::ostream &operator<<(std::ostream &out, const Heap &heap) {
    out << "[ ";
    for (int i = 0; i < heap.m_size; ++i) {
        out << heap.m_tree[i] << ", ";
    }
    out << "]\n";
    return out;
}

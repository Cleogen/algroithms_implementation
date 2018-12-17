#pragma once
#include "Node.h"
#include <queue>
#include <ostream>

template <typename T>
class ListSearchTree {
    template<typename E>
    friend std::ostream &operator<<(std::ostream &, const ListSearchTree<E> &);

public:
    ListSearchTree();

    ~ListSearchTree();

    ListSearchTree(const ListSearchTree<T> &);

    ListSearchTree<T>& operator=(const ListSearchTree<T> &);

    void insert(const T &, const int &);

    void remove(const int &);

    T& getByIndex(const int&);

private:
    int m_size;
    LTNode *m_root;

    void clear();

    void copy(const ListSearchTree<T> &);

    LTNode **find_node(int);
};


template<typename T>
ListSearchTree<T>::ListSearchTree()
        : m_size(0), m_root(nullptr) {}

template<typename T>
ListSearchTree<T>::~ListSearchTree() {
    clear();
}

template<typename T>
ListSearchTree<T>::ListSearchTree(const ListSearchTree<T> &tree)
        :m_size(tree.m_size), m_root(nullptr) {
    copy(tree);
}

template<typename T>
ListSearchTree<T> &ListSearchTree<T>::operator=(const ListSearchTree<T> &tree) {
    if (this != &tree) {
        clear();
        copy(tree);
    }
    return *this;
}

template<typename T>
void ListSearchTree<T>::insert(const T &value, const int &k) {
    if (m_root == nullptr) {
        m_root = new External<T>(value);
        ++m_size;
        return;
    }

    int i = (k >= m_size) ? m_size - 1 : k;
    LTNode **tempo = &m_root;
    auto *caster = dynamic_cast<Internal *>(*tempo);
    while (caster != nullptr) {
        if (i >= caster->m_count) {
            i -= caster->m_count;
            tempo = &caster->m_right;
        } else {
            tempo = &caster->m_left;
            ++caster->m_count;
        }
        caster = dynamic_cast<Internal *>(*tempo);
    }

    LTNode *old = *tempo;
    *tempo = new Internal(1);
    if (k >= m_size) {
        (*tempo)->m_right = new External<T>(value);
        (*tempo)->m_left = old;
    } else {
        (*tempo)->m_left = new External<T>(value);
        (*tempo)->m_right = old;
    }

    ++m_size;
}

template<typename T>
void ListSearchTree<T>::remove(const int &k) {
    if (m_root == nullptr)
        return;

    int i = (k >= m_size) ? m_size - 1 : k;
    LTNode **tempo = &m_root;
    LTNode **odd = &m_root;
    auto *caster = dynamic_cast<Internal *>(*odd);

    while (caster != nullptr) {
        tempo = odd;
        if (i >= caster->m_count) {
            i -= caster->m_count;
            odd = &caster->m_right;
        } else {
            odd = &caster->m_left;
            --caster->m_count;
        }
        caster = dynamic_cast<Internal *>(*odd);
    }

    caster = dynamic_cast<Internal *>(*tempo);

    if (caster == nullptr) {
        delete *odd;
        *odd = nullptr;
    } else if (i > caster->m_count) {
        odd = &(*tempo)->m_left;
        delete (*tempo)->m_right;
    } else {
        odd = &(*tempo)->m_right;
        delete (*tempo)->m_left;
    }
    LTNode *dead = *tempo;
    *tempo = *odd;
    delete dead;
    --m_size;
}

template<typename T>
T &ListSearchTree<T>::getByIndex(const int &x) {
    return dynamic_cast<External<T> *>(*find_node(x))->m_info;
}

template<typename T>
void ListSearchTree<T>::clear() {
    if (m_root == nullptr)
        return;

    std::queue<LTNode *> tempo;
    tempo.push(m_root);
    LTNode *dead = nullptr;

    while (!tempo.empty()) {
        dead = tempo.front();

        if (dead->m_left != nullptr)
            tempo.push(dead->m_left);
        if (dead->m_right != nullptr)
            tempo.push(dead->m_right);

        delete dead;
        tempo.pop();
    }
    m_size = 0;
    m_root = nullptr;
}

template<typename T>
void ListSearchTree<T>::copy(const ListSearchTree<T> &tree) {
    if (tree.m_root == nullptr)
        return;

    std::queue<LTNode *> thatTree;
    std::queue<LTNode **> myTree;
    myTree.push(&m_root);
    thatTree.push(tree.m_root);
    LTNode *elder = nullptr;
    LTNode **newborn = nullptr;

    while (!thatTree.empty()) {
        elder = thatTree.front();
        newborn = myTree.front();

        auto *caster = dynamic_cast<Internal *>(elder);
        if (caster != nullptr)
            *newborn = new Internal(caster->m_count);
        else
            *newborn = new External<T>(dynamic_cast<External<T> *>(elder)->m_info);

        if (elder->m_left != nullptr) {
            thatTree.push(elder->m_left);
            myTree.push(&(*newborn)->m_left);
        }
        if (elder->m_right != nullptr) {
            thatTree.push(elder->m_right);
            myTree.push(&(*newborn)->m_right);
        }

        thatTree.pop();
        myTree.pop();
    }
}

template<typename T>
LTNode **ListSearchTree<T>::find_node(int k) {
    if (m_root == nullptr)
        return nullptr;

    k = (k >= m_size) ? m_size - 1 : k;
    LTNode **tempo = &m_root;
    auto *caster = dynamic_cast<Internal *>(*tempo);
    while (caster != nullptr) {
        if (k >= caster->m_count) {
            k -= caster->m_count;
            tempo = &caster->m_right;
        } else {
            tempo = &caster->m_left;
        }
        caster = dynamic_cast<Internal *>(*tempo);
    }
    return tempo;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const ListSearchTree<T> &tree) {
    if (tree.m_root != nullptr) {
        out << "{ ";
        std::queue<LTNode *> tempo;
        tempo.push(tree.m_root);
        LTNode *front = nullptr;

        while (!tempo.empty()) {
            front = tempo.front();

            if (front->m_left != nullptr)
                tempo.push(front->m_left);
            if (front->m_right != nullptr)
                tempo.push(front->m_right);

            auto *caster = dynamic_cast<Internal *>(front);
            if (caster == nullptr) {
                out << "[" << dynamic_cast<External<T> *>(front)->m_info << "], ";
            } else {
                out << "(" << caster->m_count << "), ";
            }
            tempo.pop();
        }
    }
    return out << " }\n";
}

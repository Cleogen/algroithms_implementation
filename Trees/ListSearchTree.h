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

    T &operator[](const int &);

    const T &operator[](const int &) const;

    void insert(const T &, const int &);

    void remove(const int &);

    int inline size() const { return m_size; };

private:
    int m_size;
    LTNode *m_root;
    enum Walker {
        INSERT,
        REMOVE,
        SEARCH
    };
    void clear();

    void copy(const ListSearchTree<T> &);

    LTNode **find_node(int &, Walker = SEARCH);
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
    } else {
        int i = k;
        LTNode **tempo = find_node(i, INSERT);
        LTNode *old = *tempo;
        *tempo = new Internal(1);

        if (k >= m_size) {
            (*tempo)->m_right = new External<T>(value);
            (*tempo)->m_left = old;
        } else {
            (*tempo)->m_left = new External<T>(value);
            (*tempo)->m_right = old;
        }
    }
    ++m_size;
}

template<typename T>
void ListSearchTree<T>::remove(const int &k) {
    if (m_root == nullptr)
        return;

    int i = k;
    LTNode **tempo = find_node(i, REMOVE);
    LTNode **odd = &m_root;

    if (m_size == 1) {
        delete *odd;
        *odd = nullptr;
    } else if (i == 1) {
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
LTNode **ListSearchTree<T>::find_node(int &k, Walker walker) {
    if (m_root == nullptr)
        return nullptr;

    k = (k >= m_size) ? m_size - 1 : k;
    LTNode **tempo = &m_root;
    LTNode **odd = &m_root;
    int helper = 0;
    auto *caster = dynamic_cast<Internal *>(*odd);
    while (caster != nullptr) {
        tempo = odd;
        k -= helper;

        if (k >= caster->m_count) {
            helper = caster->m_count;
            odd = &caster->m_right;
        } else {
            odd = &caster->m_left;
            helper = 0;
            if (walker == INSERT)
                ++caster->m_count;
            else if (walker == REMOVE)
                --caster->m_count;
        }
        caster = dynamic_cast<Internal *>(*odd);
    }

    if (walker == REMOVE)
        return tempo;
    return odd;
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
        out << " }\n";
    }
    return out;
}

template<typename T>
T &ListSearchTree<T>::operator[](const int &x) {
    int i = x;
    auto *tempo = dynamic_cast<External<T> *>(*find_node(i, SEARCH));
    if (tempo != nullptr)
        return tempo->m_info;
    else
        throw std::out_of_range("Tree is Empty");
}

template<typename T>
const T &ListSearchTree<T>::operator[](const int &x) const {
    int i = x;
    auto *tempo = dynamic_cast<External<T> *>(*find_node(i, SEARCH));
    if (tempo != nullptr)
        return tempo->m_info;
    else
        throw std::out_of_range("Tree is Empty");
}

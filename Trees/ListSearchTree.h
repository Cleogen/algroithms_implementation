#pragma once
#include "Node.h"
#include <queue>

template <typename T>
class ListSearchTree
{

public:
    ListSearchTree();
    ~ListSearchTree();
    ListSearchTree(const ListSearchTree<T> &);
    ListSearchTree<T>& operator=(const ListSearchTree<T> &);
    
    bool insert(const T&, const int&);
    bool remove(const int&);
    T& getByIndex(const int&);

private:
    int m_size;
    LTNode *m_root;

    void clear();
    void copy(ListSearchTree<T> &);

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
bool ListSearchTree<T>::insert(const T &value, const int &k) {
    LTNode **tempo = find_node(k);


    return false;
}

template<typename T>
bool ListSearchTree<T>::remove(const int &) {
    return false;
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
    }
}

template<typename T>
void ListSearchTree<T>::copy(ListSearchTree<T> &tree) {
    if (tree == nullptr)
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
    if (k >= m_size)
        return nullptr;

    LTNode **tempo = &m_root;
    Internal *caster = nullptr;
    do {
        caster = dynamic_cast<Internal *>(*tempo);
        if (k >= caster->m_count) {
            k -= caster->m_count;
            tempo = &caster->m_right;
        } else {
            tempo = &caster->m_left;
        }
    } while (caster != nullptr);

    return tempo;
}

//
//template<typename T>
//T& ListSearchTree<T>::find_node(int k)
//{
//    Node* p = m_root;
//    int d = k;
//
//    while(p != 0) {
//        External<T>* e = dynamic_cast<External<T>*>(p);
//        if(e != 0) {
//            return e->m_info;
//        } else {
//            Internal* i = dynamic_cast<Internal*>(p);
//            if(k <= i->m_count) {
//                p = p->m_left;
//            } else
//            {
//                d = d - p->m_count;
//                p = p->m_right;
//
//            }
//        }
//    }
//}
//

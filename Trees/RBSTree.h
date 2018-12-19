#pragma once

#include "SearchTree.h"

/*
 * Հա, ուրեմն 1. Արմատն ու տերևները, այսինքն նիլ գագաթները սև են
 * 2.Կարմիրի որդին սև ա
 * 3. Արմատից տերև գնացող ամեն ճանապարհի սև գագաթների քանակը նույնն ա
 * */

template<typename T>
class RBSTree : public SearchTree<T> {
    typename RBNode<T>::Black black;
    typename RBNode<T>::Red red;
public:
    RBSTree();

    virtual ~RBSTree();

    RBSTree(const RBSTree &);

    RBSTree &operator=(const RBSTree &);

    virtual void elegant_insert(const T &);

    virtual void elegant_remove(const T &);

private:
    RBNode<T> *m_root;
    int m_b_count;

    void balance(RBNode<T> **);

    void rotate_left(RBNode<T> **);
};

template<typename T>
RBSTree<T>::RBSTree()
        : SearchTree<T>(), m_b_count(0) {}

template<typename T>
RBSTree<T>::~RBSTree() {
    this->clear();
}

template<typename T>
RBSTree<T>::RBSTree(const RBSTree &tree)
        : SearchTree<T>::m_size(tree.m_size), m_root(nullptr), m_b_count(tree.m_b_count) {
    copy(tree);
}

template<typename T>
RBSTree<T> &RBSTree<T>::operator=(const RBSTree &tree) {
    m_b_count = tree.m_b_count;
    this = tree;
    return *this;
}

template<typename T>
void RBSTree<T>::elegant_insert(const T &x) {
    auto **tempo = dynamic_cast<RBNode <T> **>(insert_node_home(x));

    if ((*tempo)->m_parent != nullptr && (*tempo)->m_parent->m_race == red) {
        rotate_left(tempo);
    } else {
        (*tempo)->m_race = black;
    }
    (*tempo)->m_left = new RBNode<T>(*tempo, nullptr, black);
    (*tempo)->m_right = new RBNode<T>(*tempo, nullptr, black);
    (*tempo)->m_info = x;
}

template<typename T>
void RBSTree<T>::elegant_remove(const T &x) {
    SearchTree<T>::elegant_remove(x);
    balance();
}

template<typename T>
void RBSTree<T>::balance(RBNode<T> **tempo) {


}

template<typename T>
void RBSTree<T>::rotate_left(RBNode<T> **child) {
    RBNode <T> **parent = &(*child)->m_parent;
    RBNode <T> **grandpa = &(*parent)->m_parent;
    std::swap((*grandpa)->m_info, (*child)->m_info);
    (*parent)->m_left = (*grandpa)->m_left;
    (*grandpa)->m_left = *child;
    (*child)->m_race = red;

}


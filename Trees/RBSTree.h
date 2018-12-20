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
    const static RBNode<T>* nil = new RBNode<T>();
    RBNode<T> *m_root;
    int m_b_count;

    void balance(RBNode<T> *);

    void rotate_left(RBNode<T> *);

    void rotate_right(RBNode<T> *);

    void steal_darkness(RBNode<T> *);
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
    auto *child = dynamic_cast<RBNode <T> *>(*insert_node(x));
    child->m_left = nil;
    child->m_right = nil;
    balance(child);
}

template<typename T>
void RBSTree<T>::elegant_remove(const T &x) {
    SearchTree<T>::elegant_remove(x);
    balance();
}

template<typename T>
void RBSTree<T>::balance(RBNode<T> *child) {
    RBNode<T>* dad = child->m_parent;
    RBNode<T>* grandpa = dad->m_parent;

    if (dad != nullptr){
        if(dad->m_race == black){
            child->m_race = red;
        } else if (&dad->m_left == &child){

        } else if(&dad->m_right == &child){
            dynamic_cast<RBNode<T>*>(grandpa->m_left)->m_race = black;
            dad->m_race = black;
        }
    }

}

template<typename T>
void RBSTree<T>::rotate_left(RBNode<T> *child) {

}

template<typename T>
void RBSTree<T>::rotate_right(RBNode<T> *child) {
    RBNode<T>* dad = child->m_parent;
    RBNode<T>* grandpa = dad->m_parent;
    std::swap(grandpa->m_info,dad->m_info);
    dad->m_right = grandpa->m_right;
    dad->m_left = nil;
    grandpa->m_left = child;
    grandpa->m_right = dad;
    child->m_race = red;
}

template<typename T>
void RBSTree<T>::steal_darkness(RBNode<T> *) {

}


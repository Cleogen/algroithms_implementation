#pragma once
#include <queue>
#include "ostream"
#include "Node.h"

template<typename T>
class SearchTree {
    template<typename E>
    friend std::ostream &operator<<(std::ostream &, const SearchTree<E> &);

public:
    SearchTree();

    virtual ~SearchTree();

    SearchTree(const SearchTree<T> &);

    SearchTree<T> &operator=(const SearchTree<T> &);

    bool find(const T &);

    int count() const;

    bool empty() const;

    virtual void elegant_insert(const T &);

    void insert(const T &);

    virtual void elegant_remove(const T &);

protected:
    STNode<T> *m_root;

    int m_size;

    STNode<T> **find_node(const T &);

    STNode<T> **remove_node(const T &);

    void copy(const SearchTree<T> &);

    void clear();
};

template<typename T>
SearchTree<T>::SearchTree()
        : m_size(0), m_root(nullptr) {}

template<typename T>
SearchTree<T>::~SearchTree() {
    clear();
}

template<typename T>
SearchTree<T>::SearchTree(const SearchTree<T> &searchTree)
        : m_size(searchTree.m_size), m_root(nullptr) {
    copy(searchTree);
}

template<typename T>
SearchTree<T> &SearchTree<T>::operator=(const SearchTree<T> &searchTree) {
    if (this != &searchTree) {
        clear();
        m_size = searchTree.m_size;
        copy(searchTree);
    }
    return *this;
}

template<typename T>
bool SearchTree<T>::find(const T &x) {
    return find_node(x) != nullptr;
}

template<typename T>
int SearchTree<T>::count() const {
    return m_size;
}

template<typename T>
bool SearchTree<T>::empty() const {
    return m_size == 0;
}

/*
 * Gets a pointer on the pointer node with info value x
 * check if exists
 * assign the target pointer node
 * if target has right child
 * then move the pointer to the right child
 * and then while it has left child move the pointer to left
 * this way at the end of cycle tempo will point to the pointer node which is symmetric next to the target
 * change the target, by changing the info
 * now the target is the symmetric next node
 * which obviously can not have more than one child
 * if the child is right
 * connect right child with the parent of the target and deprecate parent
 * same for left
 * if the target is a leaf then make the pointer null
 * and at last delete
 * */
template<typename T>
void SearchTree<T>::elegant_remove(const T &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

    STNode<T> **tempo = find_node(x);
    if (tempo == nullptr)
        return;
    STNode<T> *dead = *tempo;
    if ((*tempo)->m_right != nullptr) {
        tempo = &(*tempo)->m_right;
        while ((*tempo)->m_left != nullptr)
            tempo = &(*tempo)->m_left;
    }

    dead->m_info = (*tempo)->m_info;
    dead = *tempo;

    if (dead->m_right != nullptr)
        *tempo = dead->m_right;
    else if (dead->m_left != nullptr)
        *tempo = dead->m_left;
    else
        *tempo = nullptr;
    delete dead;
    --m_size;
}


/*
 * Get a pointer to the pointer of the root of the tree
 * while it is not null
 * compare x with info of the tempo
 * if x is smaller then move tempo to the left child
 * otherwise move tempo to the right child
 * now when tempo points to a null, allocate a new memory with the x as info
 * */
template<typename T>
void SearchTree<T>::elegant_insert(const T &x) {
    STNode<T> **tempo = &m_root;
    while (*tempo != nullptr)
        if ((*tempo)->m_info >= x)
            tempo = &(*tempo)->m_left;
        else
            tempo = &(*tempo)->m_right;

    *tempo = new STNode<T>(x);
    ++m_size;
}

template<typename T>
STNode<T> **SearchTree<T>::remove_node(const T &) {
    return nullptr;
}

template<typename T>
void SearchTree<T>::insert(const T &x) {
//    if (m_root == nullptr) {
//        m_root = new STNode<T>(x);
//    } else {
//        STNode<T> *tempo = m_root;
//        STNode<T> *parent = m_root;
//        while (tempo != nullptr) {
//            parent = tempo;
//            if (tempo->m_info >= x)
//                tempo = tempo->m_left;
//            else
//                tempo = tempo->m_right;
//        }
//        if (parent->m_info >= x)
//            parent->m_left = new STNode<T>(x);
//        else
//            parent->m_right = new STNode<T>(x);
//    }
//    ++m_size;
    elegant_insert(x);
}

template<typename T>
STNode<T> **SearchTree<T>::find_node(const T &x) {
    STNode<T> **tempo = &m_root;
    while (*tempo != nullptr)
        if (x == (*tempo)->m_info)
            return tempo;
        else if (x > (*tempo)->m_info)
            tempo = &(*tempo)->m_right;
        else
            tempo = &(*tempo)->m_left;
    return nullptr;
}

template<typename T>
void SearchTree<T>::copy(const SearchTree<T> &searchTree) {
    if (searchTree.m_root == nullptr)
        return;
    std::queue<STNode<T> *> thatTree;
    std::queue<STNode<T> **> myTree;
    thatTree.push(searchTree.m_root);
    myTree.push(&m_root);
    STNode<T> *elder = nullptr;
    STNode<T> **birth = nullptr;

    while (!thatTree.empty()) {
        elder = thatTree.front();
        birth = myTree.front();
        *birth = new STNode<T>(elder->m_info);

        if (elder->m_left != nullptr) {
            thatTree.push(elder->m_left);
            myTree.push(&(*birth)->m_left);
        }
        if (elder->m_right != nullptr) {
            thatTree.push(elder->m_right);
            myTree.push(&(*birth)->m_right);
        }
        thatTree.pop();
        myTree.pop();
    }
}

template<typename T>
void SearchTree<T>::clear() {
    if (m_root == nullptr)
        return;
    std::queue<STNode<T> *> leafs;
    leafs.push(m_root);
    STNode<T> *temp = nullptr;

    while (!leafs.empty()) {
        temp = leafs.front();

        if (temp->m_left != nullptr)
            leafs.push(temp->m_left);
        if (temp->m_right != nullptr)
            leafs.push(temp->m_right);

        leafs.pop();
        delete temp;
    }
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const SearchTree<T> &searchTree) {
    out << "[ ";
    if (searchTree.m_root == nullptr)
        return out;

    std::queue<STNode<T> *> leafs;
    leafs.push(searchTree.m_root);
    STNode<T> *temp = nullptr;

    while (!leafs.empty()) {
        temp = leafs.front();

        if (temp->m_left != nullptr)
            leafs.push(temp->m_left);
        if (temp->m_right != nullptr)
            leafs.push(temp->m_right);

        leafs.pop();
        out << temp->m_info << ", ";
    }

    return out << "]\n";
}

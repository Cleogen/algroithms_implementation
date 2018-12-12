#include "SearchTree.h"

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
bool SearchTree<T>::find(const int &x) {
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

template<typename T>
void SearchTree<T>::remove(const int &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

}

template<typename T>
void SearchTree<T>::elegant_remove(const int &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

    Node **tempo = find_node(x);             // Get a pointer on the pointer node with info value x
    if (tempo == nullptr)                    // if exists
        return;
    Node *dead = *tempo;                     // assign the target pointer node
    if ((*tempo)->m_right != nullptr) {      // if it has right child
        tempo = &(*tempo)->m_right;          // then move the pointer to the right child
        while ((*tempo)->m_left != nullptr)  // and then while it has left child move the pointer to left
            tempo = &(*tempo)->m_left;
    }                                        // this way at the end tempo will point to the
    // pointer node which is symmetric next to the target
    dead->m_info = (*tempo)->m_info;         // change the target, by changing the info
    dead = *tempo;                           // now the target is the symmetric next node
    // which obviously can not have more than one child
    if (dead->m_right != nullptr)            // if the child is right
        *tempo = dead->m_right;              // connect right child and deprecate parent
    else if (dead->m_left != nullptr)        // same for left
        *tempo = dead->m_left;
    else                                     // if is a leaf then make the pointer null
        *tempo = nullptr;
    delete dead;                             // delete the target
    --m_size;
}

template<typename T>
void SearchTree<T>::elegant_insert(const int &x) {
    Node **tempo = &m_root;                  // A pointer on the address of the root of the tree
    while (*tempo != nullptr)                // check if that address is not null then
        if ((*tempo)->m_info >= x)           // compare x with info of the tempo
            tempo = &(*tempo)->m_left;       // if x is smaller then change tempo address to the left node
        else
            tempo = &(*tempo)->m_right;      // otherwise change tempo address to the right node
    *tempo = new Node(x);                    // now when the address to which tempo
    // points is null allocate a new memory for it
    ++m_size;
}

template<typename T>
void SearchTree<T>::insert(const int &x) {
    if (m_root == nullptr) {
        m_root = new Node(x);
    } else {
        Node *tempo = m_root;
        Node *parent = m_root;
        while (tempo != nullptr) {
            parent = tempo;
            if (tempo->m_info >= x)
                tempo = tempo->m_left;
            else
                tempo = tempo->m_right;
        }
        if (parent->m_info >= x)
            parent->m_left = new Node(x);
        else
            parent->m_right = new Node(x);
    }
    ++m_size;
}

template<typename T>
SearchTree::Node **SearchTree<T>::find_node(const int &x) {
    Node **tempo = &m_root;
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
    std::queue<Node *> leafs;
    leafs.push(searchTree.m_root);
    Node *temp = nullptr;

    while (!leafs.empty()) {
        temp = leafs.front();

        if (temp->m_left != nullptr)
            leafs.push(temp->m_left);
        if (temp->m_right != nullptr)
            leafs.push(temp->m_right);

        leafs.pop();
        insert(temp->m_info);
    }
}

template<typename T>
void SearchTree<T>::clear() {
    if (m_root == nullptr)
        return;
    std::queue<Node *> leafs;
    leafs.push(m_root);
    Node *temp = nullptr;

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

    std::queue<Node *> leafs;
    leafs.push(searchTree.m_root);
    Node *temp = nullptr;

    while (!leafs.empty()) {
        temp = leafs.front();

        if (temp->m_left != nullptr)
            leafs.push(temp->m_left);
        if (temp->m_right != nullptr)
            leafs.push(temp->m_right);

        leafs.pop();
        out << temp->m_info << ", ";
    }

    return out;
}

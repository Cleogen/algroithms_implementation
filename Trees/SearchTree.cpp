#include "SearchTree.h"

SearchTree::SearchTree()
    : m_size(0), m_root(nullptr) {}

SearchTree::~SearchTree() {
    clear();
}

SearchTree::SearchTree(const SearchTree &searchTree)
        : m_size(searchTree.m_size), m_root(nullptr) {
    copy(searchTree);
}

SearchTree &SearchTree::operator=(const SearchTree &searchTree) {
    if (this != &searchTree) {
        clear();
        m_size = searchTree.m_size;
        copy(searchTree);
    }
    return *this;
}

bool SearchTree::find(const int &x) const {
    return find_node(x) != nullptr;
}

int SearchTree::count() const {
    return m_size;
}

bool SearchTree::empty() const {
    return m_size == 0;
}

void SearchTree::remove(const int &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

}

void SearchTree::elegant_remove(const int &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

    Node **tempo = &m_root;
    while (*tempo != nullptr)
        if (x == (*tempo)->m_info)
            break;
        else if (x > (*tempo)->m_info)
            tempo = &(*tempo)->m_right;
        else
            tempo = &(*tempo)->m_left;


    Node *dead = *tempo;

    if (dead->m_right != nullptr)
        *tempo = dead->m_right;
    else if (dead->m_left != nullptr)
        *tempo = dead->m_left;

    delete dead;
}

void SearchTree::elegant_insert(const int &x) {
    Node **tempo = &m_root; // A pointer on the address of the root of the tree
    while (*tempo != nullptr) { // check if that address is not null then
        if ((*tempo)->m_info >= x) { // compare x with info of the tempo
            tempo = &(*tempo)->m_left; // if x is smaller then change tempo address to the left node
        } else {
            tempo = &(*tempo)->m_right; // otherwise change tempo address to the right node
        }
    }
    *tempo = new Node(x); // now when the address to which tempo points is null allocate a new memory for it
    ++m_size;
}

void SearchTree::insert(const int &x) {
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

Node *SearchTree::find_node(const int &x) const {
    Node *temp = m_root;
    while (temp != nullptr) {
        if (x == temp->m_info)
            break;
        else if (x > temp->m_info)
            temp = temp->m_right;
        else
            temp = temp->m_left;
    }
    return temp;
}

void SearchTree::copy(const SearchTree &searchTree) {
    if (searchTree.m_root == nullptr)
        return;
    std::queue<Node *> leafs;
    leafs.push(searchTree.m_root);
    Node *temp = nullptr;
    while (!leafs.empty()) {
        temp = leafs.front();
        if (temp->m_left != nullptr) {
            leafs.push(temp->m_left);
        }
        if (temp->m_right != nullptr) {
            leafs.push(temp->m_right);
        }
        leafs.pop();
        insert(temp->m_info);
    }
}

void SearchTree::clear() {
    if (m_root == nullptr)
        return;
    std::queue<Node *> leafs;
    leafs.push(m_root);
    Node *temp = nullptr;
    while (!leafs.empty()) {
        temp = leafs.front();
        if (temp->m_left != nullptr) {
            leafs.push(temp->m_left);
        }
        if (temp->m_right != nullptr) {
            leafs.push(temp->m_right);
        }
        leafs.pop();
        delete temp;
    }
}

void SearchTree::symmetric_next(Node *root) {
    if (root->m_left != nullptr) {
        symmetric_next(root->m_left);
    } else {
        std::cout << root->m_info;
    }
}

std::ostream &operator<<(std::ostream &out, const SearchTree &searchTree) {
    out << "[ ";
    std::queue<Node *> leafs;
    leafs.push(searchTree.m_root);
    Node *temp = nullptr;
    while (!leafs.empty()) {
        temp = leafs.front();
        if (temp->m_left != nullptr) {
            leafs.push(temp->m_left);
        }
        if (temp->m_right != nullptr) {
            leafs.push(temp->m_right);
        }
        leafs.pop();
        out << temp->m_info << ", ";
    }

    return out;
}

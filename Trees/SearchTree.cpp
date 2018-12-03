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

void SearchTree::insert(const int &x) {
    insert_node(new Node(x));
    ++m_size;
}

void SearchTree::remove(const int &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

    Node *temp = find_node(x);
    Node *left = temp->m_left;
    Node *right = temp->m_right;

    delete temp;
    --m_size;

    if (left != nullptr)
        insert_node(left);
    if (right != nullptr)
        insert_node(right);
}

Node *SearchTree::find_node(const int &x) const {
    Node *temp = m_root;
    while (temp != nullptr) {
        if (x == temp->m_info)
            return temp;
        else if (x > temp->m_info)
            temp = temp->m_right;
        else
            temp = temp->m_left;
    }
    return nullptr;
}

void SearchTree::insert_node(Node *node) {
    Node *temp = m_root;
    int x = node->m_info;
    while (&temp->m_info != &x) {
        if (x >= temp->m_info) {
            if (temp->m_right != nullptr)
                temp = temp->m_right;
            else
                temp->m_right = node;
        } else {
            if (temp->m_left != nullptr)
                temp = temp->m_left;
            else
                temp->m_left = node;
        }
    }
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

//std::ostream &operator<<(std::ostream &out, const SearchTree &searchTree) {
//    Node* root = searchTree.m_root;
//    return out << root->m_info << "";
//}

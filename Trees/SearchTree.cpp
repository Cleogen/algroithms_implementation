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
    Node *temp = new Node(x);
    insert_node(temp);
    ++m_size;
}

void SearchTree::remove(const int &x) {
    if (empty())
        throw std::out_of_range("Tree is empty");

    Node *temp = m_root;
    while (temp != nullptr) {
        if (x == temp->m_info)
            break;
        else if (x > temp->m_info)
            temp = temp->m_right;
        else
            temp = temp->m_left;
    }
    if (temp == nullptr)
        return;
    remove_node(temp);
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
    if (temp == nullptr) {
        m_root = node;
    } else {
        while (temp != node) {
            if (node->m_info >= temp->m_info) {
                if (temp->m_right == nullptr) {
                    temp->m_right = node;
                }
                temp = temp->m_right;
            } else {
                if (temp->m_left == nullptr) {
                    temp->m_left = node;
                }
                temp = temp->m_left;
            }
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

void SearchTree::remove_node(Node *&node) {
    if (node->m_left == nullptr && node->m_right == nullptr) {
        delete node;
        node = nullptr;
        --m_size;
    } else if (node->m_left != nullptr) {
        node->m_info = node->m_left->m_info;
        remove_node(node->m_left);
    } else {
        node->m_info = node->m_right->m_info;
        remove_node(node->m_right);
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

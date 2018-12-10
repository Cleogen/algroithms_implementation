#include "ListSearchTree.h"
#include <queue>

template <typename T>
ListSearchTree<T>::ListSearchTree()
    : m_size(0)
    , m_root(nullptr)
{}

template <typename T>
ListSearchTree<T>::~ListSearchTree()
{
    clear();
}

template<typename T>
ListSearchTree<T>::ListSearchTree(const ListSearchTree<T>& tree)
    :m_size(tree.m_size)
    ,m_root(nullptr)
{
    copy(tree);
}

template<typename T>
ListSearchTree<T>& ListSearchTree<T>::operator=(const ListSearchTree<T>& tree)
{
    if(this != &tree)
    {
        clear();
        copy(tree);
    }
    return *this;
}

template<typename T>
bool ListSearchTree<T>::insert(const T& value, const int& k)
{
    Node** tempo = find_node(k); // External Node at index k
    
    
    return false;
}

template<typename T>
bool ListSearchTree<T>::remove(const int &)
{
    return false;
}

template<typename T>
T & ListSearchTree<T>::getByIndex(const int &)
{
    // TODO: insert return statement here
}

template<typename T>
void ListSearchTree<T>::clear()
{
    if(tree == nullptr)
        return;

    std::queue<Node*> tempo;
    tempo.push(m_root);
    Node* dead = nullptr;

    while(!tempo.empty())
    {
        dead = tempo.front();

        if(dead->m_left != nullptr)
            tempo.push(dead->m_left);
        if(dead->m_right != nullptr)
            tempo.push(dead->m_right);

        delete dead;
    }
}

template<typename T>
void ListSearchTree<T>::copy(ListSearchTree<T>& tree)
{
    if(tree == nullptr)
        return;

    std::queue<Node*> tempo;
    tempo.push(m_root);
    Node* born = nullptr;

    while(!tempo.empty())
    {
        born = tempo.front();

        if(born->m_left != nullptr)
            tempo.push(born->m_left);
        if(born->m_right != nullptr)
            tempo.push(born->m_right);

        //TODO (insert Node) can be External or Internal
        tempo.pop();
    }
}

template<typename T>
Node ** ListSearchTree<T>::find_node(const int &k)
{
    int i = (k > m_size) ? m_size : k;


    Internal** tempo = &(dynamic_cast<Internal*>(m_root));

    while(i-- != 1)
    {
        if (i <= (*tempo)->m_count)
            tempo = &(*tempo)->m_left;
        else
            tempo = &(*tempo)->m_right;
    }

    if(i == 0)
        return &(*tempo)->m_left;
    else
        return &(*tempo)->m_right;
}

template<typename T>
T& ListSearchTree<T>::find_node(int k)
{
    Node* p = m_root;
    int d = k;

    while(p != 0) {
        External<T>* e = dynamic_cast<External<T>*>(p);
        if(e != 0) {
            return e->m_info;
        } else {
            Internal* i = dynamic_cast<Internal*>(p);
            if(k <= i->m_count) {
                p = p->m_left;
            } else
            {
                d = d - p->m_count;
                p = p->m_right;

            }
        }
    }
}

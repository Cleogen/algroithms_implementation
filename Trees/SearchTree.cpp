#include "SearchTree.h"

SearchTree::SearchTree()
    :m_size(0)
    ,m_root(nullptr)
{}

SearchTree::~SearchTree()
{
    
}

SearchTree::SearchTree(const SearchTree &)
{
}

SearchTree & SearchTree::operator=(const SearchTree &)
{
    // TODO: insert return statement here
}

bool SearchTree::find(const int &x) const
{
    Node* temp = m_root;
    while(temp != nullptr)
    {
        if(x == temp->m_info)
            return true;
        else if(x > temp->m_info)
            temp = temp->m_right;
        else
            temp = temp->m_left;
    }
    return false;
}

int SearchTree::count() const
{
    return 0;
}

bool SearchTree::empty() const
{
    return false;
}

void SearchTree::insert(const int &)
{
}

void SearchTree::remove(const int &)
{
}

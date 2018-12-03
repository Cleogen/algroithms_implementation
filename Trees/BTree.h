#pragma once
#include <queue>
#include <iostream>

struct Node
{
    char m_info;
    Node* m_left;
    Node* m_right;
    
    Node(int info)
    : m_info(info)
    , m_left(nullptr)
    , m_right(nullptr)
    {}

};

void levelTR(Node* root)
{
    if(root == nullptr)
        return;
    
    std::queue<Node*> leafs;
    Node* temp = nullptr;
    leafs.push(root);
    
    while(!leafs.empty())
    {
        temp = leafs.front();
        if(temp->m_left != nullptr) {
            leafs.push(temp->m_left);
        }
        if(temp->m_right != nullptr)
        {
            leafs.push(temp->m_right);
        }
        std::cout << temp->m_info;
        leafs.pop();
    }
}

void symetricTR(Node* root){
    if(root != nullptr)
    {
        symetricTR(root->m_left);
        std::cout << root->m_info;
        symetricTR(root->m_right);
    }
}

int BtreeHeight(Node* root){
    if(root == nullptr)
        return -1;

    return std::max(BtreeHeight(root->m_left), BtreeHeight(root->m_right)) + 1;
}

int BTreeLeafs(Node* root){
    if(root == nullptr)
        return 0;

    return BTreeLeafs(root->m_left) + 
           BTreeLeafs(root->m_right) + 
           ((root->m_left == nullptr && root->m_right == nullptr) ? 1 : 0);
}

int BTreeNodes(Node* root){
    if(root == nullptr)
        return 0;

    return BTreeNodes(root->m_left) + BTreeNodes(root->m_right) + 1;
}

bool isBtreeRude(Node* root){
    if(root->m_left != nullptr && root->m_right != nullptr)
        return (isBtreeRude(root->m_left) && isBtreeRude(root->m_right));
    
    if(root->m_left == nullptr && root->m_right == nullptr)
        return true;
    
    return false;
}
//
// Created by ishkhan on 10/21/18.
//
#pragma once
#include <ostream>

class LinkedList {
  
      friend std::ostream &operator << (std::ostream &, const LinkedList &);

public:
      LinkedList();
      ~LinkedLIst();
      LinkedList(const LinkedList &);
      LinkedList &operator=(const LinkedList &);
      int &operator[](const int &);
      const int &operator[](const int &);
      
      void push(const int &);
      void push_at_index(const int &index, const int &);
      void push_all(const int[] &);
      void pop();
      void remove_all(const int &);
      void remove_at_index(const int &index);
      void clear();
      bool empty();
      int size();
      
private:
       struct Node{
          Node* m_link;
          int m_info;
          Node(info)
          : m_link(nullptr)
          , m_info(info)
          {}
       }
      int m_size;
      Node* m_head;
};

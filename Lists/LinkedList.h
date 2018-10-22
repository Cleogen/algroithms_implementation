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
      LinkedList LinkedList(const LinkedList &);
      
  
};

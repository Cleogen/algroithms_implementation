//
// Created by ishkhan on 10/6/18.
//

#ifndef ALGORITHMS_IMPLEMENTATION_LINKEDSTACK_H
#define ALGORITHMS_IMPLEMENTATION_LINKEDSTACK_H


class LinkedStack {
public:
    LinkedStack();

    ~LinkedStack();

    LinkedStack(const LinkedStack &);

    LinkedStack &operator=(const LinkedStack &);

    int top();

    int size() const;

    bool empty() const;

    void pop();

    void push(const int &);

    void display_stack() const;

private:
    struct Node {
        int m_info;
        Node *m_link;

        Node(int info = 0)
                : m_info(info), m_link(nullptr) {}
    };

    Node *m_top;
    int m_size;

};


#endif //ALGORITHMS_IMPLEMENTATION_LINKEDSTACK_H

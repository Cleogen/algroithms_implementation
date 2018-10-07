//
// Created by ishkhan on 10/7/18.
//

#ifndef ALGORITHMS_IMPLEMENTATION_LINKEDQUEUE_H
#define ALGORITHMS_IMPLEMENTATION_LINKEDQUEUE_H


class LinkedQueue {
public:
    LinkedQueue();

    ~LinkedQueue();

    LinkedQueue(const LinkedQueue &);

    LinkedQueue &operator=(const LinkedQueue &);

    int size() const;

    int &head() const;

    bool empty() const;

    void pop();

    void push(const int &);

    void display_queue() const;

private:
    struct Node {
        Node *m_link;
        int m_info;

        Node(int info)
                : m_info(info), m_link(nullptr) {}
    };

    Node *m_head;
    Node *m_rear;
    int m_size;
};


#endif //ALGORITHMS_IMPLEMENTATION_LINKEDQUEUE_H

//
// Created by ishkhan on 9/22/18.
//

#ifndef ALGORITHMS_IMPLEMENTATION_QUEUE_H
#define ALGORITHMS_IMPLEMENTATION_QUEUE_H


class Queue {
private:
    int m_maxsize;
    int m_front;
    int m_rear;
    int m_size;
    int *m_location;

    int update_pos(int m) const;

public:
    Queue(int = 10);

    Queue(const Queue &);

    ~Queue();

    Queue &operator=(const Queue &);

    bool empty() const;

    bool full() const;

    int size() const;

    int &front();

    void pop();

    void push(const int &);

    void display_queue();
};


#endif //ALGORITHMS_IMPLEMETATION_QUEUE_H

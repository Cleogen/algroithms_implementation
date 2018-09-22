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
    int *m_location;

public:
    bool empty() const;

    bool full() const;

    int size() const;

    int &front();

    void pop();

    void push(const int &);

    void display_queue();
};


#endif //ALGORITHMS_IMPLEMETATION_QUEUE_H

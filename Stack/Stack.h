//
// Created by ishkhan on 9/17/18.
//

#ifndef ALGORITHMS_IMPLEMENTATION_STACK_H
#define ALGORITHMS_IMPLEMENTATION_STACK_H


class Stack {
private:
    int max_size;
    int m_top;
    int *m_location;

public:
    Stack(int = 10);

    Stack(const Stack &);

    ~Stack();

    Stack &operator=(Stack);

    bool empty() const;

    bool full() const;

    int size() const;

    int &top();

    void pop();

    void push(const int &);

    void display_stack();
};


#endif //ALGORITHMS_IMPLEMETATION_STACK_H

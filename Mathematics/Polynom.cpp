#include "Polynom.h"

Polynom::Polynom(double* coeffs, double* powers, int size)
: m_size(size)
, m_head(nullptr)
{
    m_head = new Node(coeffs[0],powers[0]);
    m_head->m_link = m_head;

    for (int i = 1; i < size; ++i){
        Node* temp = new Node(coeffs[i],powers[i]);
        temp->m_link = m_head->m_link;
        m_head = temp;
    }
}

Polynom::~Polynom(){
    Node* temp = m_head;
    while(m_head != nullptr){
        m_head = m_head->m_link;
        delete temp;
        temp = m_head;
    }
}

Polynom::Polynom(const Polynom& polynom)
: m_size(polynom.m_size)
, m_head(nullptr)
{
    m_head = new Node(polynom.m_head->m_coeff,polynom.m_head->m_power);
    m_head->m_link = m_head;
    Node* temp = polynom.m_head->m_link;
    Node* prev = m_head;

    for(int i = 1; i < m_size; ++i){
        Node* next = new Node(temp->m_coeff,temp->m_power);
        next->m_link = prev->m_link;
        prev->m_link = next;
        prev = prev->m_link;
    }
}

Polynom& Polynom::operator=(const Polynom& polynom){
    if(this != &polynom){
        m_size = polynom.m_size;

        Node* t = m_head;
        while(m_head != nullptr){
            m_head = m_head->m_link;
            delete t;
            t = m_head;
        }

        m_head = new Node(polynom.m_head->m_coeff,polynom.m_head->m_power);
        m_head->m_link = m_head;
        Node* temp = polynom.m_head->m_link;
        Node* prev = m_head;

        for(int i = 1; i < m_size; ++i){
            Node* next = new Node(temp->m_coeff,temp->m_power);
            next->m_link = prev->m_link;
            prev->m_link = next;
            prev = prev->m_link;
        }
    }
    return *this;
}

void Polynom::add_term(const double& coeff, const double& power){
    Node* temp = m_head->m_link;
    while(temp->m_link->m_power > power){
        temp = temp->m_link;
    }
    Node* next = new Node(coeff,power);
    next->m_link = temp->m_link;
    temp->m_link = next;
}

Polynom& Polynom::operator+=(const Polynom& polynom){
    int size = (polynom.m_size > m_size) ? polynom.m_size : m_size;
    Node* one = m_head;
    Node* two = polynom.m_head;

    for (int i = 0; i < size; ++i){
        if(one->m_power == two->m_power){
            one->m_coeff += two->m_coeff;
        }
        else{
            add_term(two->m_coeff,two->m_power);
        }
    }

    return *this;
}

Polynom& Polynom::operator-=(const Polynom& polynom){
    int size = (polynom.m_size > m_size) ? polynom.m_size : m_size;
    Node* one = m_head;
    Node* two = polynom.m_head;

    for (int i = 0; i < size; ++i){
        if(one->m_power == two->m_power){
            one->m_coeff -= two->m_coeff;
        }
        else{
            add_term(-1*two->m_coeff,two->m_power);
        }
    }

    return *this;
}
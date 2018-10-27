#include "Polynom.h"

Polynom::Polynom(double* coeffs, double* powers, int size)
: m_size(size)
, m_head(nullptr)
{
	m_head = new Node();
	Node* temp = m_head;
	for (int i = 0; i < size; ++i)
	{
		temp->m_link = new Node(coeffs[i], powers[i]);
		temp = temp->m_link;
	}
	temp->m_link = m_head;
}

Polynom::~Polynom(){
	Node* temp = m_head->m_link;
	Node* prev = 0;
	while (temp != m_head)
	{
		prev = temp;
		temp = temp->m_link;
		delete prev;
	}
	delete m_head;
}

Polynom::Polynom(const Polynom& polynom)
: m_size(polynom.m_size)
, m_head(nullptr)
{
	m_head = new Node();
	Node* temp = polynom.m_head->m_link;
	Node* prev = m_head;
	while (temp != polynom.m_head)
	{
		prev->m_link = new Node(temp->m_coeff, temp->m_power);
		prev = prev->m_link;
		temp = temp->m_link;
	}
	prev->m_link = m_head;
}

Polynom& Polynom::operator=(const Polynom& polynom){
    if(this != &polynom){
        m_size = polynom.m_size;

		Node* t = m_head->m_link;
		Node* p = 0;
		while (t != m_head)
		{
			p = t;
			t = t->m_link;
			delete p;
		}

		Node* temp = polynom.m_head->m_link;
		Node* prev = m_head;
		while (temp != polynom.m_head)
		{
			prev->m_link = new Node(temp->m_coeff, temp->m_power);
			prev = prev->m_link;
			temp = temp->m_link;
		}
		prev->m_link = m_head;
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

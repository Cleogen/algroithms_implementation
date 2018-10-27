#include "Polynom.h"

Polynom::Polynom(double* coeffs, double* powers, int size)
: m_head(nullptr){
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
	Node* prev = nullptr;
	while (temp != m_head)
	{
		prev = temp;
		temp = temp->m_link;
		delete prev;
	}
	delete m_head;
}

Polynom::Polynom(const Polynom& polynom)
: m_head(nullptr){
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

		Node* t = m_head->m_link;
		Node* p = nullptr;
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

void Polynom::remove_next_term(Node* term){
	Node* dead = term->m_link;
	term->m_link = dead->m_link;
	delete dead;
}

Polynom& Polynom::operator+=(const Polynom& polynom){
    Node* one = m_head;
    Node* two = polynom.m_head;

    while(one->m_link->m_power != -1.0 && two->m_link->m_power != -1.0){
        if(one->m_link->m_power == two->m_link->m_power){
            if(one->m_link->m_coeff + two->m_link->m_coeff == 0.0){
                remove_next_term(one);
            }
            else
            {
                one->m_link->m_coeff += two->m_link->m_coeff;
            }
        }
        else{
            add_term(two->m_coeff,two->m_power);
        }
        one = one->m_link;
        two = two->m_link;
    }

    return *this;
}

Polynom& Polynom::operator-=(const Polynom& polynom){
    return *this += polynom * -1.0;
}

Polynom &Polynom::operator*=(const Polynom& polynom) {
	Node* one = m_head;
	Node* two = polynom.m_head;

	while (one != m_head){

	}
}

Polynom &Polynom::operator/=(const Polynom &) {
	return <#initializer#>;
}

double Polynom::value(int &) const {
	return 0;
}

double Polynom::exponent() const {
	return 0;
}

Polynom &Polynom::deriviative() const {
	return <#initializer#>;
}

Polynom operator+(Polynom p1, const Polynom &p2) {
	return Polynom(nullptr, nullptr, 0);
}

Polynom operator-(Polynom p1, const Polynom &p2) {
	return Polynom(nullptr, nullptr, 0);
}

Polynom operator*(Polynom p1, const Polynom &p2) {
	return Polynom(nullptr, nullptr, 0);
}

Polynom operator/(Polynom p1, const Polynom &p2) {
	return Polynom(nullptr, nullptr, 0);
}

Polynom operator+(Polynom &p1, const double p2) {
    return Polynom(nullptr, nullptr, 0);
}

Polynom operator-(Polynom &p1, const double p2) {
    return Polynom(nullptr, nullptr, 0);
}

Polynom operator*(Polynom p1, const double p2) {
    return Polynom(nullptr, nullptr, 0);
}

Polynom operator/(Polynom &p1, const double p2) {
    return Polynom(nullptr, nullptr, 0);
}

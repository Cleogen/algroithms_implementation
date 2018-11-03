
#include "Polynom.h"

Polynom::Polynom()
        : m_head(nullptr) {
    m_head = new Node();
    m_head->m_link = m_head;
}

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
    if (temp->m_power == power) {
        temp->m_coeff += coeff;
    } else {
        Node *next = new Node(coeff, power);
        next->m_link = temp->m_link;
        temp->m_link = next;
    }
}

void Polynom::remove_next_term(Node* term){
	Node* dead = term->m_link;
	term->m_link = dead->m_link;
	delete dead;
}

Polynom& Polynom::operator+=(const Polynom& polynom){
    Node *one = m_head->m_link;
    Node *two = polynom.m_head->m_link;

    while (one->m_link != nullptr && two->m_link != nullptr) {
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

Polynom &Polynom::operator*=(const Polynom &polynom) {
    Polynom copy = *this;
    Node *two = polynom.m_head->m_link;
    Node *one;

    while (two != nullptr) {
        one = copy.m_head->m_link;
        while (one != nullptr) {
            double coeff = two->m_coeff * one->m_coeff;
            double power = two->m_power + one->m_power;
            add_term(coeff, power);
            one = one->m_link;
        }
        two = two->m_link;
    }
    return *this;
}

Polynom &Polynom::operator/=(const Polynom &polynom) {
    auto *result = new Polynom();
    Node *numerator = m_head;
    Node *denominator = polynom.m_head->m_link;
    double coeff, power;

    while (numerator->m_link->m_power >= denominator->m_power) {
        coeff = numerator->m_link->m_coeff / denominator->m_coeff;
        power = numerator->m_link->m_power - denominator->m_power;
        auto *temp = new Polynom();
        temp->add_term(coeff, power);
        *this -= polynom * *temp;
    }

    return *result;
}

double Polynom::value(const double &x) const {
    double result = 0;
    Node *temp = m_head->m_link;

    while (temp != nullptr) {
        result += temp->m_coeff * pow(x, temp->m_power);
    }

    return result;
}

double Polynom::exponent() const {
    return m_head->m_link->m_power;
}

Polynom &Polynom::derivative() const {
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

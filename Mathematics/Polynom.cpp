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
    Node *temp = m_head;
    while(temp->m_link->m_power > power){
        temp = temp->m_link;
    }

    if (temp->m_link->m_power == power) {
        if ((temp->m_link->m_coeff += coeff) == 0) {
            remove_next_term(temp);
        }
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
    Node *two = polynom.m_head->m_link;

    while (two != polynom.m_head) {
        this->add_term(two->m_coeff, two->m_power);
        two = two->m_link;
    }

    return *this;
}

Polynom& Polynom::operator-=(const Polynom& polynom){
    auto *temp = new Polynom();
    temp->add_term(-1, 0);
    Polynom res = polynom * *temp;
    *this += res;
    return *this;
}

Polynom &Polynom::operator*=(const Polynom &polynom) {
    Polynom copy = *this;
    Node *two = polynom.m_head->m_link;
    Node *one;

    while (two != polynom.m_head) {
        one = copy.m_head->m_link;
        while (one != copy.m_head) {
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

    while (temp != m_head) {
        result += temp->m_coeff * pow(x, temp->m_power);
    }

    return result;
}

double Polynom::exponent() const {
    return m_head->m_link->m_power;
}

Polynom &Polynom::derivative() const {
    auto *derived = new Polynom(*this);
    Node *temp = derived->m_head;

    while (temp->m_link != derived->m_head) {
        temp->m_link->m_coeff *= temp->m_link->m_power;
        if (--temp->m_link->m_power == -1) {
            derived->remove_next_term(temp->m_link);
        }
    }

    return *derived;
}

std::ostream &operator<<(std::ostream &out, Polynom &polynom) {
    Polynom::Node *temp = polynom.m_head->m_link;
    while (temp != polynom.m_head) {
        if (temp->m_power > 1)
            out << temp->m_coeff << "x^(" << temp->m_power << ") + ";
        else if (temp->m_power == 1)
            out << temp->m_coeff << "x + ";
        else
            out << temp->m_coeff;

        temp = temp->m_link;
    }
    out << "\n";
    return out;
}

Polynom operator+(Polynom p1, const Polynom &p2) {
    return p1 += p2;
}

Polynom operator-(Polynom p1, const Polynom &p2) {
    return p1 -= p2;
}

Polynom operator*(Polynom p1, const Polynom &p2) {
    return (p1 *= p2);
}

Polynom operator/(Polynom p1, const Polynom &p2) {
    return p1 /= p2;
}

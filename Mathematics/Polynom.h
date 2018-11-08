#include <cmath>
#include <iostream>

class Polynom{
    friend std::ostream &operator<<(std::ostream &, Polynom &);

public:
    Polynom();
    /***
    * @param coeffs An non empty array of coefficients in descending order
    * @param powers An non empty array of powers in descending order
    * @param size the size of arrays
    * the coefficients and powers must respectfully have the same indexes
    */
    Polynom(double* coeffs, double* powers, int size);

    ~Polynom();

    Polynom(const Polynom&);

    Polynom& operator=(const Polynom&);

    Polynom& operator+=(const Polynom&);

    Polynom& operator-=(const Polynom&);

    Polynom& operator*=(const Polynom&);

    Polynom& operator/=(const Polynom&);

    Polynom &operator%=(const Polynom &);

    double value(const double &) const;

    double rank() const;

    Polynom &derivative();

private:
    struct Node{
        double m_coeff;
        double m_power;
        Node* m_link;

        Node(double coeff = 0.0, double power = -1.0)
                : m_coeff(coeff), m_power(power), m_link(nullptr) {}
    };

    Node* m_head;

    void add_term(const double &coeff, const double &power, const bool & = false);

    void remove_next_term(Node*);
};

Polynom operator+(Polynom p1, const Polynom& p2);
Polynom operator-(Polynom p1, const Polynom& p2);
Polynom operator*(Polynom p1, const Polynom& p2);
Polynom operator/(Polynom p1, const Polynom& p2);
Polynom operator%(Polynom p1, const Polynom &p2);


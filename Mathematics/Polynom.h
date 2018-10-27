class Polynom{
    /*
    * @param coeffs An non empty array of coefficients in descending order
    * @param powers An non empty array of powers in descending order
    * @param size the size of arrays
    * the coefficients and powers must respectfully have the same indexes
    */
public:
    Polynom(double* coeffs, double* powers, int size);
    ~Polynom();
    Polynom(const Polynom&);
    Polynom& operator=(const Polynom&);
    Polynom& operator+=(const Polynom&);
    Polynom& operator-=(const Polynom&);
    Polynom& operator*=(const Polynom&);
    Polynom& operator/=(const Polynom&);

    double value(int&) const;
    double exponent() const;
    Polynom& deriviative() const;

private:
    struct Node{
        double m_coeff;
        double m_power;
        Node* m_link;
        Node(double coeff = 0.0, double power = -1.0)
        : m_coeff(coeff)
        , m_power(power)
        , m_link(nullptr)
        {}
	};
    int m_size;
    Node* m_head;
    void add_term(const double& coeff, const double& power);
};

Polynom operator+(Polynom p1, const Polynom& p2);

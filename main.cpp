#include <iostream>
#include "Mathematics/Polynom.h"

int main() {
    double coeffs[3] = {3, 4, 5};
    double powers[3] = {2, 1, 0};
    double coeffs2[2] = {1, -1};
    double powers2[2] = {1, 0};
    Polynom polynom = Polynom(coeffs, powers, 3);
    Polynom polynom2 = Polynom(coeffs2, powers2, 2);
    Polynom polynom3 = Polynom(polynom);
    polynom -= polynom2;

    std::cout << polynom;
    return 0;
}

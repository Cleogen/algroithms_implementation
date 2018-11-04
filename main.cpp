#include <iostream>
#include "Mathematics/Polynom.h"

int main() {
    double coeffs[4] = {7, 3, -1, -1};
    double powers[4] = {6, 4, 3, 1};
    double coeffs2[3] = {-3, 1, -1};
    double powers2[3] = {6, 5, 0};
    Polynom polynom = Polynom(coeffs, powers, 4);
    Polynom polynom2 = Polynom(coeffs2, powers2, 3);
    Polynom polynom3 = polynom * polynom2;

    std::cout << polynom3;
    return 0;
}

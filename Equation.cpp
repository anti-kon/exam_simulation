#include "Equation.h"

std::vector<Root> Equation::getRoots() {
    Root discriminant = coefficients[1]*coefficients[1] - 4.0f * coefficients[0] * coefficients[2];

    std::vector<Root> roots;
    if(discriminant >= 0)
        roots.push_back((-coefficients[1] - std::sqrt(discriminant)) / (2.0f * coefficients[0]));
    if(discriminant > 0)
        roots.push_back((-coefficients[1] + std::sqrt(discriminant)) / (2.0f * coefficients[0]));

    return roots;
}
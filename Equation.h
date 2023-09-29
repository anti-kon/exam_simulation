#ifndef EXAM_SUM_EQUATION_H
#define EXAM_SUM_EQUATION_H

#include <array>
#include <vector>
#include <cmath>

typedef float Root;

class Equation {
private:
    std::array<float, 3> coefficients;
public:
    Equation (float a, float b, float c) : coefficients{a, b, c} {}

    float& operator [] (int index) {return coefficients[index];}
    std::vector<Root> getRoots ();
};

#endif //EXAM_SUM_EQUATION_H

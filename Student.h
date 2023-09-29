#ifndef EXAM_SUM_STUDENT_H
#define EXAM_SUM_STUDENT_H

#include <random>
#include <utility>
#include <vector>
#include <string>
#include "Equation.h"
#include "TaskTable.h"

typedef std::string Surname;

struct SolutionResult {
    SolutionResult(std::vector<Root> roots, std::string  surname, int task_num) :
        roots{std::move(roots)}, surname{std::move(surname)}, task_num{task_num} {}

    std::vector<Root> roots;
    std::string surname;
    int task_num;
};

class Student {
private:
    Surname surname;
    [[nodiscard]] virtual std::vector<Root> SolveEquation (Equation equation) const {
        return std::vector<Root>({0.0f});
    }

public:
    explicit Student (Surname surname) : surname(std::move(surname)) {}

    [[nodiscard]] std::vector<SolutionResult> SolveTest
                    (const std::vector<unsigned int>& task_nums, const TaskTable& tasks) const;
};

class GoodStudent : public Student {
    [[nodiscard]] std::vector<Root> SolveEquation (Equation equation) const override {return equation.getRoots();}
public:
    explicit GoodStudent (Surname surname) : Student(std::move(surname)) {}
};

class MiddleStudent : public Student {
    [[nodiscard]] std::vector<Root> SolveEquation (Equation equation) const override {
        return std::random_device()() % 2 == 0 ? std::vector<Root>({0.0f}) : equation.getRoots();
    }
public:
    explicit MiddleStudent (Surname surname) : Student(std::move(surname)) {}
};

class BadStudent : public Student {
    [[nodiscard]] std::vector<Root> SolveEquation (Equation equation) const override {
        return std::vector<Root>({0.0f});
    }
public:
    explicit BadStudent (Surname surname) : Student(std::move(surname)) {}
};

#endif //EXAM_SUM_STUDENT_H
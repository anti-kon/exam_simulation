#ifndef EXAM_SUM_TEACHER_H
#define EXAM_SUM_TEACHER_H

#include <unordered_map>
#include <random>
#include <string>
#include <iostream>
#include <algorithm>
#include "Student.h"

class Teacher {
private:
    std::unordered_map<Surname, std::pair<unsigned int, unsigned int>> results_table;
public:
    void CheckSolutionResult (const std::vector<SolutionResult>& solutions, const TaskTable& tasks);

    static std::vector<unsigned int> generateVariant (unsigned int task_quantity, unsigned int max_task_num);
    void printResultTable ();
};

#endif //EXAM_SUM_TEACHER_H

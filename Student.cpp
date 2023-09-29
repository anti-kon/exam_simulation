#include "Student.h"

std::vector<SolutionResult> Student::SolveTest
                            (const std::vector<unsigned int>& task_nums, const TaskTable& tasks) const {
    std::vector<SolutionResult> results;
    for (unsigned int task_num : task_nums)
        results.emplace_back(SolveEquation(tasks.getTask(task_num)), surname, task_num);
    return results;
}
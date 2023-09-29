#include "Teacher.h"

void Teacher::CheckSolutionResult(const std::vector<SolutionResult> &solutions, const TaskTable &tasks) {
    for (const auto& solution : solutions) {
        if (results_table.find(solution.surname) == results_table.end())
            results_table.insert(std::make_pair(solution.surname, std::make_pair(0, 0)));
        if (solution.roots == tasks.getTask(solution.task_num).getRoots()) {
            results_table.at(solution.surname).first++;
            results_table.at(solution.surname).second++;
        } else {
            results_table.at(solution.surname).second++;
        }
    }
}

std::vector<unsigned int> Teacher::generateVariant(unsigned int task_quantity, unsigned int max_task_num) {
    std::vector<unsigned int> variant;
    while (task_quantity > 0) {
        unsigned int task_num = std::random_device()() % max_task_num;
        if (std::find(variant.begin(), variant.end(), task_num) == variant.end()){
            variant.push_back(task_num);
            task_quantity--;
        }
    }
    return variant;
}

void Teacher::printResultTable() {
    std::cout << "┏";
    for (int i = 0; i < 48; i++) { std::cout << "━"; }
    std::cout << "┳";
    for (int i = 0; i < 11; i++) { std::cout << "━"; }
    std::cout << "┓\n";

    for (std::pair<std::string, std::pair<unsigned int, unsigned int>> student : results_table)
    {
        std::cout << "┃ ";
        std::cout.width(46);
        std::cout.setf(std::ios::left);
        std::cout << student.first;
        std::cout.width(0);
        std::cout << " ┃";
        std::cout.width(5);
        std::cout.unsetf(std::ios::left);
        std::cout << student.second.first;
        std::cout.width(0);
        std::cout << '/';
        std::cout.setf(std::ios::left);
        std::cout.width(5);
        std::cout << student.second.second;
        std::cout.width(0);
        std::cout.unsetf(std::ios::left);
        std::cout << "┃\n";
    }

    std::cout << "┗";
    for (int i = 0; i < 48; i++) { std::cout << "━"; }
    std::cout << "┻";
    for (int i = 0; i < 11; i++) { std::cout << "━"; }
    std::cout << "┛\n";
}
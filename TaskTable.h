#ifndef EXAM_SUM_TASKTABLE_H
#define EXAM_SUM_TASKTABLE_H

#include <vector>
#include <array>
#include <fstream>
#include "Equation.h"

class TaskTable {
public:
    explicit TaskTable (const std::string& input_filename){
        std::ifstream input_stream (input_filename);
        float coefficient_a, coefficient_b, coefficient_c;
        while (!input_stream.eof()){
            input_stream >> coefficient_a >> coefficient_b >> coefficient_c;
            tasks.emplace_back(coefficient_a, coefficient_b, coefficient_c);
        }
        input_stream.close();
    }

    [[nodiscard]] Equation getTask (unsigned int index) const { return tasks[index]; }
    unsigned long long getMaxTask () { return tasks.size(); }
private:
    std::vector<Equation> tasks;
};

#endif //EXAM_SUM_TASKTABLE_H
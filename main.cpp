#include <random>
#include "TaskTable.h"
#include "Teacher.h"

int main() {
    system("chcp 65001");

    TaskTable tasks("..\\equation.txt");

    Teacher teacher;

    std::vector<Student *> students;
    std::ifstream students_surnames_input("..\\students.txt");
    while (!students_surnames_input.eof()){
        std::string student_surname;
        students_surnames_input >> student_surname;

        switch (std::random_device()()%3) {
            case 0:
                students.push_back(new GoodStudent(student_surname));
                break;
            case 1:
                students.push_back(new MiddleStudent(student_surname));
                break;
            default:
                students.push_back(new BadStudent(student_surname));
                break;
        }
    }

    for (const auto& student : students)
        teacher.CheckSolutionResult(
                student->SolveTest(
                        Teacher::generateVariant(15, tasks.getMaxTask()), tasks),tasks);

    teacher.printResultTable();
}
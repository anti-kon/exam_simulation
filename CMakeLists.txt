cmake_minimum_required(VERSION 3.22)
project(exam_sum)

set(CMAKE_CXX_STANDARD 23)

add_executable(exam_sum main.cpp TaskTable.h Student.h Equation.h Teacher.h Equation.cpp Student.cpp Teacher.cpp)

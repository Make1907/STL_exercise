//
// Created by Michael on 2023/2/24.
//
#ifndef STL_EXERCISE_TEST_H
#define STL_EXERCISE_TEST_H

#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <unordered_set>

#include "../header/stlLearning.h"
#include "../header/ptr.h"
#include "../header/class_details.h"
// 调用所有函数

class Test{
public:
//    explicit Test(){}
//    ~Test(){}
    static void vec_test();
    static void list_test();
    static void string_test();
    static void map_test();
    static void set_test();
    static void unordered_map_test();
    static void unordered_set_test();
    static void deque_test();
    static void stack_test();

    static void ptr_test();
    static void random_string_test();
    static void class_test();
private:
};

// string algorithm test, using hash.
std::string is_match(std::vector<std::string> & vec);

// run test
void run_test();

#endif //STL_EXERCISE_TEST_H

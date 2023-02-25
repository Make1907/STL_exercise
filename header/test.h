//
// Created by Michael on 2023/2/24.
//
#ifndef STL_EXERCISE_TEST_H
#define STL_EXERCISE_TEST_H

#include "../header/stlLearning.h"

// 调用所有函数

class Test{
public:
    explicit Test(){}
    ~Test(){}
    static void vec_test();
    void list_test();
private:
};

void run_test();

// ----------------- definition ------------------

void Test::vec_test(){
    std::vector<int> v1;
    for(int i = 0; i <= 10; i++){ v1.push_back(i); }
    auto * vt1 = new VectorTest<std::vector<int>>(v1);
    vt1->vector_test();
    for(auto it: v1){
        std::cout<< "ref: "<< it << std::endl;
    }
    delete vt1;
    vt1 = NULL;

//    std::vector<char> v2;
//    std::string s = "abcdefghij";
//    for(auto it: s){ v2.push_back(it); }
//    auto * vt2 = new VectorTest<std::vector<char>>(v2);
//    vt2->vector_test();
//    delete vt2;
//    vt2 = NULL;
}

void Test::list_test(){}

void run_test(){
    Test::vec_test();
}
#endif //STL_EXERCISE_TEST_H

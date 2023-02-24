//
// Created by Michael on 2023/2/24.
//
#ifndef STL_EXERCISE_TEST_H
#define STL_EXERCISE_TEST_H

#include<vector>
#include<string>
#include "../header/stlLearning.h"

// 调用所有函数

//template<class T>
//class Test{
//public:
//    explicit Test(T& vec);
////    ~Test();
//    void vec_test();
//    void list_test();
//private:
//    T vec;
//};
//
//void run_test();
//
//// definition
//template<class T>
//Test<T>::Test(T& vec){this->vec = vec;}
//
//template<class T>
//void Test<T>::vec_test(){
//    VectorTest<T> * vectorTest = new VectorTest<T>(vec);
//    vectorTest->vector_methods_test();
//    delete vectorTest;
//}
//
//template<class T>
//void Test<T>::list_test(){}
//
//void run_test(){
//    std::vector<int> v1;
//    for(int i = 0; i <= 10; i++){
//        v1.push_back(i);
//    }
//    Test<std::vector<int>> test_v1(v1);
//    test_v1.vec_test();
//
//    std::vector<std::string> v2;
//    for(int i = 0; i <= 10; i++){
//        v2.push_back(std::to_string(i + 67));
//    }
//    Test<std::vector<std::string>> test_v2(v2);
//    test_v2.vec_test();
//}

class Test{
public:
    explicit Test(){}
    ~Test(){}
    static void vec_test();
    void list_test();
private:
};

void run_test();

// definition

void Test::vec_test(){
    std::vector<int> v1;
    for(int i = 0; i <= 10; i++){ v1.push_back(i); }
    auto * vt1 = new VectorTest<std::vector<int>>(v1);
    vt1->vector_methods_test();
    delete vt1;
    vt1 = NULL;

    std::vector<char> v2;
    std::string s = "abcdefghij";
    for(auto it: s){ v2.push_back(it); }
    auto * vt2 = new VectorTest<std::vector<char>>(v2);
    vt2->vector_methods_test();
    delete vt2;
    vt2 = NULL;
}

void Test::list_test(){}

void run_test(){
    Test::vec_test();
}
#endif //STL_EXERCISE_TEST_H

//
// Created by Michael on 2023/2/24.
//
#ifndef STL_EXERCISE_TEST_H
#define STL_EXERCISE_TEST_H

#include<vector>
#include "../header/stlLearning.h"

// 调用所有函数

template<class T>
class Test{
public:
    explicit Test(T& vec);
//    ~Test();
    void test();
    void list_test();
private:
    T vec;

};


void run_test();

// definition
template<class T>
Test<T>::Test(T& vec){this->vec = vec;}

//template<class T>
//Test<T>::~Test(){}

template<class T>
void Test<T>::test(){
    std::cout << "vec: " << this->vec[0] << std::endl;
    VectorTest<T> * vectorTest = new VectorTest<T>(vec);
    vectorTest->vector_methods_test();
    delete vectorTest;
//    VectorTest<T> vectorTest(vec);
//
//    vectorTest.vector_methods_test();

}

template<class T>
void Test<T>::list_test(){}

void run_test(){
    std::vector<int> vec;
    for(int i = 0; i <= 10; i++){
        vec.push_back(i);
    }
    Test<std::vector<int>> test(vec);
    test.test();
}
#endif //STL_EXERCISE_TEST_H

//
// Created by Michael on 2023/2/24.
//

// 调用各类方法并打印结果

#ifndef STL_EXERCISE_STLLEARNING_H
#define STL_EXERCISE_STLLEARNING_H

#include<vector>
#include<iostream>

#include "../header/tools.h"

template<class T>
class VectorTest{
public:
    explicit VectorTest(T& vec);
    void vector_methods_test();

    friend std::ostream & operator<<(std::ostream & out, VectorTest<T> container) {
        typename T::iterator it;
        std::cout << "vec: ";
        for (it = container.vec.begin(); it != container.vec.end(); it++) {
            std::cout << *it << " ";
        }
        return out;
    }

private:
    T vec;
};

// definition
template<class T>
VectorTest<T>::VectorTest(T& vec){this->vec = vec;}

//template<class T>
//VectorTest<T>::~VectorTest(){}

template<class T>
void VectorTest<T>::vector_methods_test(){
    std::cout << "--------------VectorTest-------------" << std::endl;
    std::cout << *this << std::endl;
}
#endif //STL_EXERCISE_STLLEARNING_H

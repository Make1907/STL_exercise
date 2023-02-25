//
// Created by Michael on 2023/2/24.
//

// 调用各类方法并打印结果

#ifndef STL_EXERCISE_STLLEARNING_H
#define STL_EXERCISE_STLLEARNING_H

#include<vector>
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<numeric>


#include "../header/tools.h"

template<class T>
class VectorTest{
public:
    explicit VectorTest(T& vec):v(vec){};
    void vector_test();
    void list_test();

    friend std::ostream & operator<<(std::ostream & out, VectorTest<T> container) {
        typename T::iterator it;
        std::cout << "v: ";
        for (it = container.v.begin(); it != container.v.end(); it++) {
            std::cout << *it << " ";
        }
        return out;
    }

private:
    T & v;
};

// definition
//template<class T>
//VectorTest<T>::VectorTest(T& vec){this->v = vec;}

template<class T>
void VectorTest<T>::vector_test(){
    std::cout << "--------------VectorTest-------------" << std::endl;
    std::cout << *this << std::endl;

    // algorithm
    v.push_back(-9);
    std::sort(v.begin(), v.end());
    v.erase(v.begin());
    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;
    std::cout << *this << std::endl;

    std::cout << "--------------  crud    -------------" << std::endl;
    // insert
    v.insert(v.end() - 2, 97);
    std::cout << *this      << std::endl;
    // delete
    v.erase(v.begin() + 3);
    std::cout << *this      << std::endl;
    // change
    v[0] = 100;
    std::cout << *this      << std::endl;
    // find
    std::cout << "find  : " << v[0] << std::endl;

    // other
    typename T::iterator it = v.begin();
    std::cout << *it         << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.empty() << std::endl;
    v.resize(25, 0);
    std::cout << *this       << std::endl;
    std::cout << v.at(10) << std::endl;  // 越界时候，v.at()访问会抛出异常, v[]访问会直接崩溃

    std::cout << "front : " << v.front() << std::endl;
    std::cout << "end   : " << v.back() << std::endl;

    v.push_back(-88);
    std::cout << *this      << std::endl;
    v.pop_back();
    std::cout << *this      << std::endl;

    v.assign(9, 100);
    std::cout << *this      << std::endl;
    v.assign(v.begin(), v.begin() + 3);
    std::cout << *this      << std::endl;

    std::cout << "--------------End VectorTest-------------" << std::endl;
}

template<class T>
void VectorTest<T>::list_test(){

}
#endif //STL_EXERCISE_STLLEARNING_H

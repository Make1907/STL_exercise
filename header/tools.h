//
// Created by Michael on 2023/2/24.
//

#ifndef STL_EXERCISE_TOOLS_H
#define STL_EXERCISE_TOOLS_H

#include<iostream>

template <class T>
class IoMethod{
public:
    IoMethod(T container);
    ~IoMethod();
private:
    T _container;
};

#endif //STL_EXERCISE_TOOLS_H

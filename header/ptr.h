//
// Created by Michael on 2023/2/26.
//

#ifndef STL_EXERCISE_PTR_H
#define STL_EXERCISE_PTR_H

class PtrTest{
public:
    explicit PtrTest() = default;
    ~PtrTest() = default;
    void ptr_basic();
};

class AIPtr{
public:
    AIPtr() = default;
    // copy constructor
    AIPtr(AIPtr & aiPtr) = default;
    // move constructor
    AIPtr(AIPtr && other)= default;
    ~AIPtr() = default;
    friend std::ostream & operator<<(std::ostream & output, AIPtr & aiPtr){
        std::cout << aiPtr.test << std::endl;
        return output;
    }
private:
    int test;
};

#endif //STL_EXERCISE_PTR_H

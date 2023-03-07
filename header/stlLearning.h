//
// Created by Michael on 2023/2/24.
//

// 调用各类方法并打印结果

#ifndef STL_EXERCISE_STLLEARNING_H
#define STL_EXERCISE_STLLEARNING_H
#include<iostream>

#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<stack>

#include<algorithm>
#include<numeric>


#include "../header/tools.h"

template<class T>
class DS{
public:
    explicit DS() = default;
    explicit DS(T& data): data(data){};
    ~DS() = default;
    void vector();
    void list();
    void string();
    void map();
    void set();
    void unordered_map();
    void unordered_set();
    void deque();
    void stack();

    void print_map();

    friend std::ostream & operator<<(std::ostream & out, DS<T> container) {
        typename T::iterator it;
        std::cout << "DATA: ";
        for (it = container.data.begin(); it != container.data.end(); it++) {
            std::cout << *it << " ";
        }
        return out;
    }

private:
    T & data;
};

// definition
//template<class T>
//DS<T>::DS(T& vec){this->data = vec;}

template<class T>
void DS<T>::vector(){
    std::cout << "--------------vector-------------" << std::endl;
    std::cout << *this << std::endl;

    // algorithm
    data.push_back(-9);
    std::sort(data.begin(), data.end());
    data.erase(data.begin());
    std::cout << std::accumulate(data.begin(), data.end(), 0) << std::endl;
    std::cout << *this << std::endl;

    std::cout << "--------------  crud    -------------" << std::endl;
    // insert
    data.insert(data.end() - 2, 97);
    std::cout << *this      << std::endl;
    // delete
    data.erase(data.begin() + 3);
    std::cout << *this      << std::endl;
    // change
    data[0] = 100;
    std::cout << *this      << std::endl;
    // find
    std::cout << "find  : " << data[0] << std::endl;

    // other
    typename T::iterator it = data.begin();
    std::cout << *it         << std::endl;
    std::cout << data.size() << std::endl;
    std::cout << data.empty() << std::endl;
    data.resize(25, 0);
    std::cout << *this       << std::endl;
    std::cout << data.at(10) << std::endl;  // 越界时候，data.at()访问会抛出异常, data[]访问会直接崩溃

    std::cout << "front : " << data.front() << std::endl;
    std::cout << "end   : " << data.back() << std::endl;

    data.push_back(-88);
    std::cout << *this      << std::endl;
    data.pop_back();
    std::cout << *this      << std::endl;

    data.assign(9, 100);
    std::cout << *this      << std::endl;
    data.assign(data.begin(), data.begin() + 3);
    std::cout << *this      << std::endl;

    std::cout << "--------------End vector-------------" << std::endl;
}

template<class T>
void DS<T>::list() {
    // list 有一个重要的性质，插入和删除操作都不会造成原有list迭代器的失效
    // 这在vector是不成立的，因为vector的插入操作可能会造成内存的重新配置，导致原有的迭代器全部失效
    // 而list元素的删除只会使得被删除元素的迭代器失效
    std::cout << "-------------- list  -------------" << std::endl;
    std::cout << *this      << std::endl;

    // reverse iterator
    std::cout << "reverse: ";
    for(typename T::reverse_iterator it = data.rbegin(); it != data.rend(); it++){
        std::cout << *it << " ";
    }
    std::cout << "--reverse iterator end" << std::endl;
//    typename T::iterator it;
    std::cout << "iterator:";
    for(typename T::iterator it = data.begin(); it != data.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << " --iterator end" << std::endl;;
    typename T::iterator it = data.begin();
    std::cout <<"auto: ";
    for(auto i: data){
        std::cout << i << " ";
    }

    // algorithm
    data.push_back(-9);
    data.sort();
    data.pop_front();
    std::cout << *this      << std::endl;

    // create
    data.insert(data.begin(), 99);
    std::cout << *this      << std::endl;
    // delete
    data.erase(++data.begin());
    std::cout << *this      << std::endl;
    // update
    data.assign(5, 99);
    std::cout << *this      << std::endl;
    // only using iterator to get the val of the node

    // read
    // only using iterator to get the val of the node

    std::cout << "--------------END list-------------" << std::endl;

}

template<class T>
void DS<T>::string() {

    std::cout << "-----------string---------------" << std::endl;

    typedef std::vector<std::string> v_s;
    v_s v9;
    v9.push_back("abc");
    std::cout << "v9: " << v9[0] << std::endl;

    typedef int i;
    i number = 199;
    std::cout << "number: " << number << std::endl;

    typedef Phone p;
    std::string name = "make";

    p make(name, number);
    std::cout << "*make.m_price: " << make.m_price << std::endl;
    int new_price = 890;
    make.set_price(new_price);
    std::cout << "number: " << new_price << std::endl;

    std::cout << data << std::endl;
    typename T::iterator it = data.begin();
    // create
    data.insert(3, "m");
    std::cout << data << std::endl;
    // delete
    data.erase(3, 2);
    std::cout << data << std::endl;
    // update
    data[0] = 'b';
    std::cout << data << std::endl;
    // read
    std::cout << data[0] << std::endl;

    // assign
    std::string s2(5, 'i');
    std::cout << "s2: " << s2 << std::endl;

    // slice

    std::string s1 = data + '0';
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s1: " << s1.erase(0,3) << std::endl;
    std::cout << "s1: " << s1 << std::endl;

    std::string s_sub = s1.substr(0,4);
    std::cout << "s_sub: " << s_sub << std::endl;
    std::string s_erase = s1.erase(0,1);
    std::cout << "s_era: " << s_erase << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    s1.push_back('9');
//    char * app;
//    *app = 'a';
    s1.append(1,'l');
    std::cout << "s_push: " << s1 << std::endl;
    std::cout << "s1: " << s1 << std::endl;



    std::cout << "*it: " << *it << std::endl;
    std::cout << "-----------string end-----------" << std::endl;

}

template<class T>
void DS<T>::map(){
    std::cout << "-----------  map   ---------------" << std::endl;
    this->print_map();
    std::cout << "-----------  map end  ---------------" << std::endl;

    // create
    this->data["a"] = 100;
    this->data["110"] = 100;
    this->print_map();

    // erase/delete
    this->data.erase("110");
    this->print_map();

    // updata
    this->data["a"] = 999;
    this->print_map();

    // read
    std::cout << "data[\"a\"]: " << this->data["a"] << std::endl;

}

template<class T>
void DS<T>::set(){
    std::cout << "-----------  set   ---------------" << std::endl;
    std::cout << *this << std::endl;

    // create
    this->data.insert("Michael");
    std::cout << *this << std::endl;

    // erase/delete
    this->data.erase("99");
    std::cout << *this << std::endl;

    // no updata

    // read
    std::cout << "find 5: " << *this->data.find("5") << std::endl;

    std::cout << "-----------  set end  ---------------" << std::endl;
}

template<class T>
void DS<T>::unordered_map(){}
template<class T>
void DS<T>::unordered_set(){}
template<class T>
void DS<T>::deque(){
    std::cout << "-----------  deque  ---------------" << std::endl;
    std::cout << *this << std::endl;
    // create
    this->data.push_back(21);
    this->data.push_front(9);
    std::cout << *this << std::endl;

    // delete erase
    this->data.pop_back();
    this->data.pop_front();
    std::cout << *this << std::endl;

    // update
    // read retrieve
    std::cout << this->data[1] << std::endl;
    std::cout << *this << std::endl;
    std::cout << "-----------  deque end  ---------------" << std::endl;
}
template<class T>
void DS<T>::stack(){
    std::cout << "-----------  stack  ---------------" << std::endl;
    std::cout << this->data.top() << std::endl;

    // creat
    this->data.push(99);
    std::cout <<  this->data.top() << std::endl;

    // delete erase
    this->data.pop();
    std::cout <<  this->data.top() << std::endl;

    // update
    // read retrieve
    std::cout << this->data.top() << std::endl;
    std::cout << this->data.size() << std::endl;

    std::cout << "-----------  stack end  ---------------" << std::endl;
}

template<class T>
void DS<T>::print_map(){
    typename T::iterator it;
    for(it = this->data.begin(); it != data.end(); it++){
        std::cout << "key: " << it->first << "     value: " << it->second << std::endl;
    }
    std::cout << "========== end ============" << std::endl;

}
#endif //STL_EXERCISE_STLLEARNING_H

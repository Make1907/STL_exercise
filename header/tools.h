//
// Created by Michael on 2023/2/24.
//

#ifndef STL_EXERCISE_TOOLS_H
#define STL_EXERCISE_TOOLS_H

#include<iostream>
#include<vector>

// 指针传参及类作为成员变量练习
class Phone{
public:
    Phone(){this->m_brand = "Huawei"; this->m_price = 1;}

    Phone(std::string & brand, int & price): m_brand(brand), m_price(price){}

    void set_price(int & new_price)  {this->m_price = new_price;}
public:
    std::string m_brand;
    int m_price;
};

// 引用传参练习
class Phone2{
public:
    Phone2(std::string & brand, int & price): brand(brand), price(price){}

    void set_price(int & new_price) const {this->price = new_price;}

    std::string get_brand() const {return brand;}

//    int & get_price() const {return price;}

    int * get_price() const {
        int *p;
        p = &price;
        return p;}

private:
    std::string brand;
    int & price;
};

#endif //STL_EXERCISE_TOOLS_H

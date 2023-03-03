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
    Phone(){this->m_brand = "Huawei"; this->m_price = nullptr;}

    Phone(std::string & brand, int * price): m_brand(brand), m_price(price){}

    Phone(std::string & brand, int price): m_brand(brand), m_price(&price){}

    void set_price(int & new_price) const {*this->m_price = new_price;}
public:
    std::string m_brand;
    int *m_price;
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

// 类继承多态练习
class Student{
public:
    Student(std::string &name, int &age, Phone & phone){
        this->m_name = name;
        this->m_age = age;
        this->m_phone = phone;
    }
    ~Student(){
        std::cout << "unconstructor is called" << std::endl;
    }
    std::string get_name() const {return this->m_name;}

    int get_age() const {return this->m_age;}

    void set_age(int & age){this->m_age = age;};

    // reload of set_age
    void set_age(int const * age){this->m_age = *age;};

    virtual void major(){
        this->arr = new double[5];
        this->arr[0] = 100.99;
        std::cout << "arr: " << *this->arr << std::endl;
        std::cout << this->m_name << "'s major is ..." << std::endl;
        delete this->arr;
    }

public:
    std::string m_name;
//    std::string & brand;
//    int & price;
    Phone m_phone;
private:
    int m_age;
    double * arr;

};


class Michael:public Student{
public:
    Michael(std::string &name, int &age, Phone & phone):Student(name, age, phone){}
    void major(){
        std::cout << this->m_name << "'s major is guitar" << std::endl;
    }
};

// class exercise, virtual, constuctor, unconstuctor,
// parent class, abstract base
class Animal{
public:
    Animal() = default;
    Animal(int &&){}  // move constructor
//    ~Animal(){}
    virtual void speak() = 0;
    virtual ~Animal(){}
protected:
private:
};

// child/derived class
class Cat: public Animal{
public:
    Cat(int & weight){*this->weight = weight;}
    void speak(){
        std::cout << "Cat is called" << std::endl;
    }
    ~Cat(){
        delete weight;
        weight = nullptr;
    }
private:
    int * weight;
};

//class Malloc{
//public:
//    Malloc(){}
//    void malloc(){
//
//    };
//};

// 智能指针

#endif //STL_EXERCISE_TOOLS_H

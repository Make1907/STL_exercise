//
// Created by Michael on 2023/3/5.
//

#ifndef STL_EXERCISE_CLASS_DETAILS_H
#define STL_EXERCISE_CLASS_DETAILS_H
// class exercise, virtual, constuctor, unconstuctor,
// parent class, abstract base

// 类继承多态练习
class Student{
public:

    Student(std::string const &name, int const & age, Phone const& phone):
            m_name(name), m_age(age), m_phone(phone), m_arr{}{}
    Student(Student&& other) noexcept{
        m_name = other.m_name;
        m_age = other.m_age;
        m_phone = other.m_phone;
        std::copy(std::begin(other.m_arr), std::end(other.m_arr), std::begin(m_arr));
    }

    ~Student(){
        std::cout << "unconstructor is called" << std::endl;
    }

    std::string const& get_name() const {return this->m_name;}

    int const& get_age() const {return this->m_age;}

    void set_age(int const& age){this->m_age = age;}

    // reload of set_age
    void set_age(int const * age){this->m_age = *age;}

    virtual void major(){
        this->m_arr[0] = 100.99;
        std::cout << "m_arr: " << *this->m_arr << std::endl;
        std::cout << this->m_name << "'s major is ..." << std::endl;
    }

public:
    std::string m_name;
//    std::string & brand;
//    int & price;
    Phone m_phone;
private:
    int m_age;
    double m_arr[10];

};

class Michael:public Student{
public:
    Michael(std::string &name, int &age, Phone & phone):Student(name, age, phone){}
    void major() override {
        std::cout << this->m_name << "'s major is guitar" << std::endl;
    }
};

class Animal{
public:
    Animal() = default;
    Animal(Animal && other){}  // move constructor
//    ~Animal(){}
    virtual void speak() = 0;
    virtual ~Animal() = default;
protected:
private:
};

// child/derived class
class Cat: public Animal{
public:
    Cat(int & weight):weight(new int(weight)){}
    void speak() override {
        std::cout << "Cat is called" << std::endl;
    }
    ~Cat(){
        delete weight;
        weight = nullptr;
    }
private:
    int * weight;
};

#endif //STL_EXERCISE_CLASS_DETAILS_H

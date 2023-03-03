//
// Created by Michael on 2023/2/26.
//
#include<iostream>

#include "../header/tools.h"
#include "../header/ptr.h"

void major_test(Student &student){
    std::cout << "------test outside-------" << std::endl;
    student.major();
    std::cout << "------test outside-------" << std::endl;
}

void PtrTest::ptr_basic(){
    std::cout<< "-----------------Ptr basic----------------------" << std::endl;
    // basic variable
    std::string brand = "Apple";
    int p_p = 19999;
    int *price = &p_p;
    Phone phone(brand, price);
    int new_price = 99;
    phone.set_price(new_price);

    int * p = nullptr;
    int b = 10;
    int &a = b;
    b = 100;
    p = &b;
    int **pp = &p;
    std::string name = "People";
    int age = 30;
    auto * p_stu = new Student(name, age, phone);
    int age_Michael = 18;
    p_stu->set_age(age_Michael);

    int *p_age = &age_Michael;
    p_stu->set_age(p_age);
    p_stu->major();

    name = "Michael";
    age = 10;

    auto * p_michael = new Michael(name, age, phone);
    p_michael->major();
    Michael michael(name, age, phone);
    major_test(michael);
    std::cout << "m p b: " << michael.m_phone.m_brand << std::endl;



    std::cout << "michael name: " << michael.m_name << std::endl;
    std::cout << "price: " << *price << std::endl;
    std::cout << "a: "    << a                 << std::endl;
    std::cout << "**p: "  << **pp              << std::endl;
    std::cout << "m_name: " << p_stu->get_name() << std::endl;
    std::cout << "age_now: "  << age_Michael   << std::endl;
    std::cout << "m_age: "  << p_stu->get_age()  << std::endl;
    std::cout << "*p: "   << *p                << std::endl;

//    delete p_michael;
    std::cout << "================"<< std::endl;
//    delete p_stu;
    std::cout<< "-----------------Ptr basic end------------------" << std::endl;

    std::cout<< "-----------------Ref begin------------------" << std::endl;
    std::string brand2 = "xiaomi";
    int price2 = 1234;
    Phone2 phone2(brand2, price2);
    int new_price2 = 1111;
    phone2.set_price(new_price2);
    std::cout << phone2.get_brand() << std::endl;
    std::cout << phone2.get_price() << std::endl;
    int *price_return = nullptr;
    price_return = phone2.get_price();
    *price_return = 0;

    std::cout << phone2.get_brand() << std::endl;
    std::cout << *phone2.get_price() << std::endl;

    std::cout<< "-----------------Ref end  ------------------" << std::endl;
    std::cout<< "-----------------Char test  ------------------" << std::endl;
//    char *my_char_1[3] = {"abc", "cba", "nba"};
//    const char * my_char = my_char_1;
//    *my_char = 'c';
//    my_char++;
//    std::cout << *my_char << std::endl;
//    std::cout << *my_char_1 << std::endl;
//
//    char greeting[] = "hello";
//    char * g2 = "hello";
//    std::cout << greeting << std::endl;
//    std::cout << g2 << std::endl;
//    std::cout << &greeting << std::endl;
//    std::cout << &g2 << std::endl;
//
//    char my_char2 = 'p';
//    char my_char3 = 'u';
//    char my_char4 = 'o';
//    char const  * cpp1 = &my_char2;
//    char * const cpp2 = &my_char3;
//    cpp1 = &my_char4;
//    *cpp2 = 'q';
//    std::cout << "cpp2: " << *cpp2 << std::endl;
//    std::cout << "cpp1: " << *cpp1 << std::endl;
    #ifdef __cplusplus
        printf("C++\n");
    #else
        printf("c\n");
    #endif
    std::cout<< "-----------------Char test end  ------------------" << std::endl;
}

//
// Created by Michael on 2023/2/24.
//
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <unordered_set>
# include "../header/test.h"

void Test::vec_test(){
    std::vector<int> v1;
    for(int i = 0; i <= 10; i++){ v1.push_back(i); }
    auto * vt1 = new DS<std::vector<int>>(v1);
    vt1->vector();
    for(auto it: v1){
        std::cout<< "ref: "<< it << std::endl;
    }
    delete vt1;
    vt1 = NULL;
}

void Test::list_test(){
    std::list<int> l1;
    for(int i = 0; i <= 10; i++){ l1.push_back(i); }
    auto * vt1 = new DS<std::list<int>>(l1);
    vt1->list();
    delete vt1;
    vt1 = NULL;
}

void Test::string_test() {
    std::string s = "abcdefghijklmn";
    auto * ds_string = new DS<std::string>(s);
    ds_string->string();
}

void Test::ptr_test(){
    auto * ptr_basic_test = new PtrTest();
    ptr_basic_test->ptr_basic();
}

void Test::random_string_test() {
    std::cout << "--------------random_string_test-------------" << std::endl;
//    unsigned seed = time(NULL);
    srand((int)time(NULL));
    std::string alphabeta = "abcdefghijklmnopqrstuvwhyz";
    std::vector<std::string> words;
    std::string word;

    for(int i = 0; i < 10; i++){
        word = "";
        int random_num1 = rand() % 8;
//        std::cout << "random_num1: " << random_num1 << std::endl;
        for(int j = 0; j <= random_num1; j++){
            int random_num2 = rand() % 26;
//            std::cout << "random_num2: " << random_num2 << std::endl;
            word.push_back(alphabeta[random_num2]);
        }
        words.push_back(word);
    }
//    words = {"leetcode", "leet", "code", "co", "de"};
    std::string ans = is_match(words);
//    DS<std::vector<std::string>> vec(words);
//    std::cout << "words--" << vec << std::endl;
    std::cout << "ans :" << ans << "  length:" << ans.length() << std::endl;
    std::cout << "--------------random_string_test end-------------" << std::endl;
}

void Test::class_test() {
    std::cout << "--------------class test-------------" << std::endl;

    int weight_cat = 19;
    Animal * cat = new Cat(weight_cat);
    cat->speak();
    delete cat;
    cat = nullptr;
    std::cout << "--------------class test end-------------" << std::endl;

}

std::string is_match(std::vector<std::string> & vec){
    std::unordered_set<std::string> hash;
    std::string ans_fun;
    bool flag;
    for(auto ele : vec){
        hash.insert(ele);
    }
    for(auto ele : vec){
        flag = false;
        for(int i = 0; i < ele.length(); i ++){
            std::string l = ele.substr(0, i+1);
            std::string r = ele.substr(i+1);
//            std::cout << "ele :" << l << "-" << r << std::endl;
            if(hash.find(l) != hash.end() && hash.find(r) != hash.end()){
                flag = true;
                break;
            }
        }
        if(flag){
            ans_fun.append("1");
        } else {
            ans_fun.append("0");
        }
    }
    return ans_fun;
}

void run_test(){
    Test::vec_test();
    Test::list_test();
    Test::string_test();
    Test::ptr_test();

    // calculate time
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    Test::random_string_test();
    QueryPerformanceCounter(&t2);
    auto time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    std::cout << "time = " << time << std::endl;  //输出时间（单位：ｓ）

    Test::class_test();



}













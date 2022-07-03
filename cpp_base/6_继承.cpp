/**
 * @date: 2021-01-09
 * 
 * 面向对象三大特性：封装、继承和多态
 * 派生类：全盘接收基类成员（数据成员和成员函数）[除了构造函数和析构函数]
 * 此处的构造函数是指：
 *      默认构造
 *      拷贝构造
 *      移动构造
 * 
 * 
*/

#include<iostream>
#include<string>

class Base {
public:
    void f1_base(){std::cout << "f1_base" << std::endl;};
    void f2_base(){std::cout << "f2_base" << std::endl;};
    int b_int1;
    int b_int2;
};

class D1: public Base {
public:
    void f1_d1(){std::cout << "f1_d1" << std::endl;}
    int d1_int;
};

class D2: public D1 {
public:
    void f2_d2(){std::cout << "f2_d2" << std::endl;};
    int d2_int;
};


int main(){
    Base b;
    D1 d1;
    D2 d2;
    std::cout << "size of b is: " << sizeof(b) << std::endl;
    std::cout << "size of d1 is: " << sizeof(d1) << std::endl;
    std::cout << "size of d2 is: " << sizeof(d2) << std::endl;
    return 0;
}
/**
 * date: 2020/03/22
 * 
 * 普通函数指针:返回值类型 (*指针名)(参数列表)
 * 注意:void(*p_fun)(int, int); 和 void* p_fun(int, int); 的区别。
 * 前者是定义函数指针, 后者是函数声明(返回值为指针的函数)。
 * 
 * 成员函数指针的定义:
 * 返回值类型 (A::*p)(参数列表)
 * 
 * 
 * 解引用:
 * (对象名.*p)(参数列表)
 * (对象指针->*p)(参数列表)
 * 
 * 非静态成员函数指针与普通函数指针的区别是, 隐含参数this指针。
 * 静态成员函数由于没有this指针,所以和普通函数指针是一样的, 不能 A::*p
 * 成员函数指针赋值时,不能省略 &(取地址符)
 * 
*/
#include<stdio.h>
#include<iostream>
using namespace std;
struct A {
	int add(int a, int b) { 
        std::cout << "add()" << std::endl; 
        return a + b; 
    }
	static void show() { 
        std::cout << "show()" << std::endl; 
    }
};
void f1(int a, int b) { std::cout << "f1()" << std::endl; }
void f2(int a, int b) { std::cout << "f2()" << std::endl; }

typedef void(*P_FUN)(int, int);  // 利用语法[typedef] 定义函数指针
// using P_FUN1 = void(*)(int, int);// 利用语法[using]   定义函数指针

typedef int(A::*P_ADD)(int, int);
// using P_ADD1 = int(A::*)(int, int);

int main(){
    void(*p_fun)(int, int) = &f1;  // 普通函数指针初始化，可以省略&
	p_fun(2, 2);  // f1()
	p_fun = &f2;
	p_fun(1, 2);  // f2()

	P_FUN p1 = &f1;
	p1(1, 1);  // f1()
	p1 = &f2;
	p1(2, 2);  // f2()

	// P_FUN1 p2 = &f1;
	// p2(1, 1);  // f1()
	// p2 = &f2;
	// p2(2, 2);  // f2()

	// 非静态成员函数指针，区别于普通函数，主要是由于隐含的this指针
	int(A::*p_add)(int, int) = &A::add; // 非静态成员函数指针初始化
	A a;
	std::cout << (a.*p_add)(0,2) << std::endl;     //.* 对象名调用
	A* pa = new A;
	std::cout << (pa->*p_add)(1, 2) << std::endl;  //->* 对象指针调用

	int(A::*p_add1)(int, int) = &A::add; 
	std::cout << (a.*p_add1)(2, 2) << std::endl;	//运行结果add() 4

	P_ADD p11 = &A::add;
	std::cout << (a.*p11)(3, 2) << std::endl; //运行结果add() 5
	// P_ADD1 p22 = &A::add;
	// std::cout << (pa->*p22)(2, 4) << std::endl; //运行结果add() 6

	delete pa;

	void(*p_show)() = &A::show; // 静态成员函数指针，与普通函数指针类似
	p_show();
	return 0;
}
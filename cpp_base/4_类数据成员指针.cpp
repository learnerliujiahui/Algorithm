/**
 * date :2020/03/22
 * 定义（语法）：
 * 
 * 数据类型 A::*p = &A::成员变量;
 * 
 * 解引用:
 * 对象名.*p
 * 对象指针->*p
 * 
 * 数据成员指针和普通变量指针区别：
 * 普通变量指针：指向该变量在内存中地址
 * 数据成员指针：实际上是一个指向数据成员在类内存中的[偏移量]
 * 
 * static静态成员变量不能使用数据成员指针，因为其保存在内存中data区，不属于对象
 * 
*/
#include<stdio.h>

#include<iostream>
#include<typeinfo>
using namespace std;
/**
 * struct 和 class 没有本质区别，只不过：
 * struct不声明访问限定符，则默认public
 * class 默认private
 * 
*/
struct A {
	A(double n1 = 0.0,int n2 = 0):num1(n1),num2(n2){}  // 使用初始化列表初始化
	double num1;
	int num2;
};

int main(){
	int i = 10;
	int *pi = &i;  // 指向普通变量的指针

	A a(0.1, 1), b(1.1, 2);
	int *pa = &a.num2;
	std::cout << a.num2 << std::endl;  // 输出结果：1

	int A::*p = &A::num2;  // 指向成员变量的指针
	std::cout << a.*p << b.*p << std::endl; // 输出结果： 1 2

	// 指向类数据成员的指针，是根据类定义的，是一个某成员变量在类内存中的偏移量
	printf("%p\n", p); // 00000008 ，表示一个实例化的类中，第8个字节之后才是该变量
    // std::cout << p << std::endl;  // 1 表示一个字节
	A* pA = new A(3.1, 3);
	std::cout << pA->*p << std::endl; // 输出结果： 3

	double A::*p_double = &A::num1;
	std::cout << typeid(p_double).name() << std::endl; // double A::*

	delete pA;
	return 0;
}
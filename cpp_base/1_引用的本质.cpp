/**
 * 
 * date: 2020/03/18
 * 
 * 
 * 
*/
/**
 * date: 2020/03/18
 * 引用本质就是通过指针实现，
 * 引用是指针的一种包装：类似 int* const p
 * 
*/

#include <iostream>

struct Stu {
	int age;
	char sex;
	char name[20];
};
struct A {
	int &data;
};
struct B {
	char &data;
};
struct C {
	Stu &data;
};

int main() {
	std::cout << sizeof(A) << std::endl; //4
	std::cout << sizeof(B) << std::endl; //4
	std::cout << sizeof(C) << std::endl; //4
	return 0;
}
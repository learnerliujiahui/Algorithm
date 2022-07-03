/**
 * date: 2020/02/09
 * 对象内存开辟时只有[成员变量]才开辟内存空间
 * 
 * 没有成员变量时只开辟一个字节的占位符
 * 
 * 成员函数并不占用对象的空间
 * 
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class A1{};

class A2{
    void fun(){}
};

class A3{
    void fun(){};
    int num;
};

class A4{
    int num;
    char name[6];
};
class myString {
public:
	myString(const char *str = NULL);
	~myString();
private:
	char *ps; int size;
};
myString::myString(const char *str) {
	if (str == NULL) {
		ps = new char[1];
		ps[0] = '\0';
	}
	else {
		int len = strlen(str) + 1;
		ps = new char[len];
		strcpy(ps, str);
	}
}
myString::~myString() {
	delete[] ps;
	std::cout << "~myString()" << std::endl;
}

class Person {
public:
	Person() { age = 20; p_fm = NULL; }
	void set_fm(){
		p_fm = new myString[2];
	}
	~Person() { 
		std::cout << "~Person()" << std::endl;
		delete[] p_fm; 
		std::cout << "=========" << std::endl;
	}
private:
	int age;        //ÄêÁä
	myString name;  //×ÔŒºµÄÃû×Ö
	myString *p_fm; //žžÄžµÄÃû×Ö
};

int main(){
    A1 a1;
    A2 a2;
    A3 a3;
    A4 a4;
    std::cout << sizeof(a1) << std::endl;  // 1
    std::cout << sizeof(a2) << std::endl;  // 1
    std::cout << sizeof(a3) << std::endl;  // 4
    std::cout << sizeof(a4) << std::endl;  // 12
    Person p1;
	p1.set_fm();
	return 0;
}
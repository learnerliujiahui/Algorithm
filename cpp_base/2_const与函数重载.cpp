/**
 * date: 2020/03/18
 * 
 * const和重载规则：
 * 1. 底层const可形成重载
 * 2. 顶层const不形成重载
 * 3. 底层const和非const都可以匹配底层const
 * 
*/


#include <iostream>

void f1(const int a){}
//void f1(int a){} 错误， 和顶层const分不清到底调用哪个
void f2(int * const p) {}
//void f2(int *p){} 错误， 和顶层const分不清到底调用哪个
void f3(const int *p){}
void f3(int *p){} // OK, 如果底层const 上一个，否则当前行函数
void f4(const int &r){}
void f4(int &r){} // OK, 底层const

int main() {
	int i = 10;
	int *p1 = &i;
	f3(p1); // 调用 非const
	const int *p2 = &i;
	f3(p2);	// 调用 const
	int &r1 = i;
	f4(r1); // 调用 非 const
	const int &r2 = i;
	f4(r2);	// 调用 const
	return 0;
}
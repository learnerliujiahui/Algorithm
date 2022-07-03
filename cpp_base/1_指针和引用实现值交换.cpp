/**
 * date: 2020/03/18
 * 
 * 帮助进一步理解引用
 * 
*/

#include <iostream>

/* 指针传参 */
void swap1(int *pa, int *pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
/* 引用传参 */
void swap2(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
/* 值传参：无法交换 */
void swap3(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 10, b = 20;
	swap1(&a, &b);
	std::cout << a << b << std::endl; //20 10
	swap2(a, b);
	std::cout << a << b << std::endl;//10 20
	swap3(a, b);
	std::cout << a << b << std::endl;//10 20
	return 0;
}

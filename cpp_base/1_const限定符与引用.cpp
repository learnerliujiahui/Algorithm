/**
 * 
 * date: 2020/03/18
 * 
 * const限定符通常和引用结合在一起使用
 * 
 * 
*/
#include <iostream>

int main() {
	const int i = 10;
	//int &ri = i; 错误：非常量引用指向常量
	int ii = 20;
	const int &rii = ii; // OK
	// rii = 30; 错误，常量引用无法修改值

	double fd = 1.23;
	// int &r = fd; 错误

    /**
     * 有一个隐式转换的过程
     * 相当于r绑定了一个[临时量]，临时量具有const属性
     * const int temp = fd;
     * const int &r = temp;
    */
	const int &r = fd; // OK
   	 // 观察 fd 和 r 的值
	std::cout << fd << " " << r << std::endl;
	// 观察 fd 和 r 的地址
	std::cout << &fd << std::endl;
	std::cout << &r << std::endl;

	return 0;
}
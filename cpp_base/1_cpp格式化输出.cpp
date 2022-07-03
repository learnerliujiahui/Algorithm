/**
 * 
 * date: 2020/03/18 复习C++ course 的C/C++格式化输出
 * 
*/
#include<stdio.h>
#include<iostream>
#include<iomanip>  // 用来格式化输出头文件

int main() {
    int a = 12345;
    double f = 123.4567;

    //默认输出整数
	printf("a=%d===\n", a);
	//占8格，右对齐
	printf("a=%8d===\n", a);
	//占8格，左对齐
	printf("a=%-8d===\n", a);
	//默认输出浮点数，小数显示6位
	printf("f=%f===\n", f);
	//占10格，小数显示2位，右对齐
	printf("f=%10.2f===\n", f);
	//占10格，小数显示2位，左对齐
	printf("f=%-10.2f===\n", f);

    //默认输出整数， cout函数自动识别，无需关心具体格式
	std::cout << "a=" << a << "===" << std::endl;
	//占8格，右对齐，setw(8)表示占8位，默认右对齐
	std::cout << "a=" << std::setw(8) << a << "===" << std::endl;
	//占8格，左对齐
	std::cout << "a=" << std::setw(8) << std::setiosflags(std::ios::left)
		<< a << "===" << std::endl;
	//默认输出浮点数，有效位数显示6位
	std::cout << "f=" << f << "===" << std::endl;
	//占10格，小数显示2位，右对齐， fixed表示不要用科学计数法来显示
	std::cout << "f=" << std::setw(10) << std::setprecision(2)
		<< std::setiosflags(std::ios::fixed) << std::setiosflags(std::ios::right)
		<< f << "===" << std::endl;
}
/**
 * 
 * date: 2020/03/18
 * 指针和引用：
 * 指针：就是[地址],利用指针变量来存放指针，指针变量也要占用一定的存储空间
 * 引用：给变量或对象起的一个别名，[定义时就必须初始化],一旦绑定，终身不变，引用不占用存储空间
 * 
*/

#include <iostream>

int main() {
    int i = 10, j = 20;
	int* pi = &i; // pi 是指向i的指针， 类型是(int*) 
	std::cout << *pi << " " << i << std::endl; // *pi 相当于 i
	*pi = 100;
	std::cout << *pi << " " << i << std::endl; // 通过指针改变变量值
	pi = &j;  // 指针指向其他对象pi
	std::cout << *pi << " " << j << std::endl;

	// 空指针定义
	//NULL C定义  ： ((void*)0)
	//NULL C++定义： 0
	//nullptr 在c++中用来表示空指针
	int *p = nullptr;
	if (p)
		std::cout << "p is true" << std::endl;
	else
		std::cout << "p is false" << std::endl;
    /* -------------------------------------- */
	int i = 100;
	int &ref_i = i;	// ok，这句话意思：给i起了一个别名叫ref_i
	//int &ref_i2;	// 错误：引用必须被初始化

	//注意书写方式
	int *a1 = nullptr, a2 = 0;  // a1是指针变量，a2是int变量
	int &r1 = a2, r2 = a2;  // r1是a2的引用，r2是int变量
	return 0;
}

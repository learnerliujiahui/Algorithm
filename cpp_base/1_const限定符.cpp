/**
 * 
 * date: 2020/03/18
 * 
 * C语言中：
 * const变量必须在定义是初始化
 * const变量不能修改
 * 但是通过指针可以修改const 变量 --> 无意义了
 * 
 * C++中：
 * 同样可以使用volatile关键字来解决
 * 
*/

#include <iostream>

int main() {
	const int i = 10;
	// int *pi = &i; 编译错误，C++不通过
	const int *pi = &i;	// ok
	// *pi = 20; 编译错误（指向常量的指针不能修改常量）

	// 尝试强制转换来修改常量
	int *pi2 = (int*)&i; // 将常量i的地址强转为(int*)
	*pi2 = 20;	 // 将pi2指针指向的地址修改为20
    std::cout << "强制转换后" << std::endl;
	// 观察 *pi2 和 i 对应的内存地址是否一样：地址相同
	std::cout << "pi2 = " << pi2 << " | &i = " << &i << std::endl;
	// 观察 *pi2 和 i 的值： 值不一样
	std::cout << "*pi2 = " << *pi2 << " | i = " << i << std::endl;
	// 输出 *pi2 = 20  i=10(编译器代码优化的结果，直接用10替换了i)
	// 为什么会出现这种现象？ --> 这是一个编译器的优化问题

	// 如果一定要强制转换
	volatile const int ii = 10; // 使用volatile关键字，要求每次取值必须从内存中取值
	int *pii = (int*)&ii;
	*pii = 20;
	std::cout << "*pii=" << *pii << " ii=" << ii << std::endl;
	// 输出 *pii=20 ii=20

	return 0;
}
/**
 * date: 2020/02/15
 * 
 * 内联只是一个给编译器的建议，具体是否内联由编译器而定
 * 
 * 用inline修饰的内联函数必须在.h文件中定义，否则编译器找不到
 * 
*/

#include <iostream>

// C语言做法
#define max_val_c(a,b) (((a) > (b)) ? (a) : (b))

// C++做法，inline内联函数
inline int max_val(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int a1 = 10, a2 = 20;
	int c = max_val_c(a1, a2);  // 宏定义在预编译时替换
    /* 即便声明内联，不一定，适合频繁调用，代码较短，简单 */
	int cpp = max_val(a1, a2);	// 内联编译时展开 int cpp = a1 > a2 ? a1 : a2;
	return 0;
}

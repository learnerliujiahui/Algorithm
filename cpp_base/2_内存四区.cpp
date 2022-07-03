/**
 * date: 2020/03/18
 * 内存四区：
 * 进程的地址空间
 * 
 * 栈区                   | 局部变量 等
 * 堆区                   | malloc或者new分配的空间
 * DATA区：bss段          | 没有初始化或初始化为0的全局变量或static变量
 * DATA区：rw段           | 初始化不为0的全局变量或static变量
 * DATA区：ro段（常量段）   | 常量段（如字符串常量）
 * 代码区                 | 存放函数体的二进制代码
 * 
*/

#include <stdio.h>
void fun() {
	static int k = 10; // 初始化的静态局部变量(data区的rw段)
	static int kk;	   // 未初始化的静态局部变量(data区的bss段) 默认初始化为0
	printf("data: static= %p(rw),%p(bss)\n", &k, &kk);
}
int g_int1, g_int2;	   // 未初始化的全局变量(data区的bss段)
int g_int3 = 10;	   // 初始化的全局变量(data区的rw段)
char *g_pstr1 = "abc"; // g_pstr1 初始化的全局变量(data区的rw段)
					   // "abc" 字符串常量(data区常量段)
int main() {
	printf("data: global= %p(bss),%p(bss)\n", &g_int1, &g_int2);
	printf("data: global= %p(rw)\n", &g_int3);
	printf("data: global= %p(rw)\n", &g_pstr1);
	printf("data:p_str指向的地址:%p(常量段)\n", g_pstr1);
	printf("data: abc:            %p(常量段)\n", &"abc");
	printf("code: fun= %p(code)\n", fun);
	fun();
	int i = 10, j = 20;	// 局部变量，栈区
	printf("栈区: %p(栈区),%p(栈区)\n", &i, &j);
	int *pi = new int(10); // pi 在栈区，pi指向的内容(*pi)在堆区
	printf("堆区: pi %p(堆区)\n", pi);
	delete pi;
	return 0;
}
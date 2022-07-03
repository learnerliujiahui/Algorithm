/**
 * 
 * date: 2020/03/22
 * 
 * 解决问题:
 * 一开始：拷贝构造和赋值运算符重载是浅拷贝，容易造成[重析构]和[内存泄漏]
 * 后来： 利用深拷贝，解决上述问题，但是会占用过多内存
 * 再后来：深拷贝占用过多内存，利用[引用计数]和[浅拷贝]结合解决这个问题，
 *        但是一个对象操作该资源会导致其他对象的资源也变化
 * 为解决上述问题：利用[写时拷贝]计数，任何对资源的操作函数之前先加一个深拷贝过程
 * 
 * 
 * 当对象要对指向的资源进行操作时
 * 对该资源先进行深拷贝
 * 然后再对其进行操作
 * 
 * 
*/


#include <iostream>
#include <cstring>

class myString {
public:
    /* 初始化构造函数 */
	myString(const char * pstr = NULL) {
		if (!pstr) 
			ps = new char[1]{'\0'};
		else {
			ps = new char[strlen(pstr) + 1];
			strcpy(ps, pstr);
		}
		count = new int(1);  // 开辟一个空间设置引用计数器，并设置为1
	}
    /* 拷贝构造函数 */
	myString(const myString &other) 
		:ps(other.ps), count(other.count) {
		(*count)++;  // count + 1
	}
    /* 赋值预算符重载 */
	myString &operator=(const myString &other) {
		if (this != &other) {
			(*count)--;  // 先释放本来指向的资源，即引用计数器-1
			if (*count == 0) {
				std::cout << "delete in = ." << std::endl;
				delete[] ps;
				delete count;
			}
			ps = other.ps;
			count = other.count;
			(*count)++;
		}
		return *this;
	}
    /* 析构函数 */
	~myString() { 
		(*count)--;  // 该对象的引用计数器数字 count - 1
		if (*count == 0) {  // 若该对象指向资源的引用计数器为0,则说明没有指向的对象，可以释放
			delete[] ps;
			delete count;
		}
	}
    /* 访问函数，获取对象引用计数器数值 */
	int get_count()const { return *count; }
    /* +运算符重载 */
	myString operator+(const myString &other) {
		int len = strlen(ps) + strlen(other.ps);
		char * ps_tmp = new char[len + 1]{ 0 };
		strcpy(ps_tmp, ps);
		strcat(ps_tmp, other.ps);
		myString tmp(ps_tmp);
		return tmp;
	}
    /**
	 * 操作函数
	 * reverse()
	 */

	void reverse() {
		if (*count > 1) {  // 如果除了自己之外，还有别人在用
			/* 将该对象重新拷贝之后再做处理 */
			(*count)--;  // 因为要修改对象，则把原对象的引用计数-1
			count = new int(1); // 重新开辟新的引用计数空间
			char* tmp = ps;     // 取出原来的ps指针指向的位置
			ps = new char[strlen(tmp) + 1];
			strcpy(ps, tmp);
			/* 原对象已经重新复制了一份，并且开辟了新的引用计数器 */
		}
		int len = strlen(ps) - 1;
		for (int i = 0; i < len / 2; i++) {
			char c = ps[i];
			ps[i] = ps[len - i];
			ps[len - i] = c;
		}
	}

	const char * c_str()const { 
		return ps; 
	}
private:
	char *ps;
	int *count;  // 引用计数器
};

myString fun(myString s) {
	std::cout << "fun: " << s.get_count() << std::endl;
	return s;
}
int main() {
	myString s1("abc");
	myString s2 = s1;
    std::cout << "原字符串: " << std::endl;
	std::cout << "s1=" << s1.c_str() << std::endl;
	s1.reverse();
    std::cout << "==================" << std::endl;
    std::cout << "操作后的原字符串: " << std::endl;
	std::cout << "s1=" << s1.c_str() << std::endl;
	std::cout << "s2=" << s2.c_str() << std::endl;
	return 0;
}
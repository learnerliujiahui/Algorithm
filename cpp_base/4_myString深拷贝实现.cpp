/**
 * date: 2020/03/22
 * 
 * 拷贝构造函数、赋值运算符重载深拷贝实现：
 * 
 * 解决浅拷贝中的[重析构]和[内存泄漏]问题
 * 
 * 
 * 
*/
#include <iostream>
#include <cstring>
class myString {
public:
    /* 实现深拷贝的构造函数 */
	myString(const char* pstr = NULL) {
		if(!pstr) {
			ps = new char[1];
			ps[0] = '\0';
		}
		else {
			ps = new char(strlen(pstr) + 1);
			strcpy(ps, pstr);
		}
	}

	/* 拷贝构造：用创建新对象时 */
	myString(const myString& other): ps(new char[strlen(other.ps)+1]) {
		strcpy(ps, other.ps);
	}

	/* 赋值运算符重载 */
	myString &operator=(const myString& other) {
		if(this != &other) {
			delete[] ps;
			ps = new char(strlen(other.ps) +1);
			strcpy(ps, other.ps);
		}
		return* this;
	}

	~myString() {
		delete[] ps;
	}
private:
	char *ps;
};


int main() {
	myString s1 = "abc";  // 拷贝构造
	myString s2 = s1;     // 拷贝构造
	myString s3;          // 直接默认初始化
	s3 = s1;              // 赋值运算符重载
	return 0;
}

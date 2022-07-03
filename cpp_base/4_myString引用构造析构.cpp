/**
 * date: 2020/03/22
 * 
 * [引用计数] + 浅拷贝 来解决深拷贝浪费内存过大的情况
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
		count = new int(1);  // 构造时开辟空间并设置为1，表示有一个对象已经指向这个资源
	}
    /* 拷贝构造函数 */
	myString(const myString &other) 
		:ps(other.ps), count(other.count) {
		(*count)++;  // 拷贝构造结束后 count + 1
	}
    /* 赋值运算符重载 */
    myString &operator=(const myString &other) {
		if (this != &other) {
			(*count)--;  // 本对象原来指向的资源计数器 -1
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
	~myString() { 
		(*count)--;  // 析构时count - 1
		if (*count == 0) { // 如果count == 0 ，表示已经没有对象指向这个资源，则释放内存
			delete[] ps;
			delete count;
			std::cout << "delete!" << std::endl;
		}
	}
	int get_count()const { return *count; }
private:
	char *ps;    // 资源
	int *count;  // 引用计数器
};

int main() {
	myString s1("abc");
	myString s2 = s1; // 拷贝构造
	std::cout << s1.get_count() << std::endl; //2
	myString s3("123");
	myString s4 = s3;
	std::cout << s3.get_count() << std::endl; //2
	s3 = s2;
	std::cout << s3.get_count() << std::endl; //3
	std::cout << s4.get_count() << std::endl; //1
	std::cout << "============" << std::endl;
	return 0;
}
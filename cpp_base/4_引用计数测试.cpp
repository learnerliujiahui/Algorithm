#include <iostream>
#include <cstring>
using namespace std;
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
		count = new int(1); //构造时开辟空间1
	}
	myString(const myString &other) 
		:ps(other.ps), count(other.count) {
		(*count)++;  //拷贝构造时 count + 1
		cout << "进行完拷贝构造后count= " << *count << endl;
	}
	myString &operator=(const myString &other) {
		if (this != &other) {
			(*count)--;  // 先释放当前对象所指向资源，即count-1
			if (*count == 0) {
				cout << "delete in = ." << endl;
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
		cout << "析构!" << endl;
		(*count)--;  // 析构时所指向资源的引用计数器 - 1
		if (*count == 0) {  // 若此时引用计数器为0，说明此时已经没有指向该资源的对象，可以释放
			delete[] ps;
			delete count;
			cout << "delete!" << endl;
		}
	}
	int get_count()const { return *count; }
    /* 对该类的+进行重载 */
	myString operator+(const myString &other) {
		int len = strlen(ps) + strlen(other.ps);
		char * ps_tmp = new char[len + 1]{ 0 };
		strcpy(ps_tmp, ps);
		strcat(ps_tmp, other.ps);
		myString tmp(ps_tmp);
		return tmp;
	}
private:
	char *ps;
	int *count;
};

int main() {
	myString s1("abc"),s2("123");
	//s1.operator+(s2) 会产生一个临时对象，表达式结束时销毁
	myString s3 = s1 + s2; 
	cout << s3.get_count() << endl;  // 1
	cout << "============" << endl;
	return 0;
}
////////////////////////////////////////
myString fun(myString s) {
	cout << "fun: " << s.get_count() << endl;
	return s;
}
int main1() {
	myString s1("abc");
	myString s2 = fun(s1);
	cout << s2.get_count() << endl; //2
	cout << "----" << endl;
	return 0;
}
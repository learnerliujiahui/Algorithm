/**
 * date: 2020/03/19
 * 
*/

#include <iostream>


class A{}; // 定义一个空类，占1B

class myString {
public:
	/* 最基础的构造函数，三个构造函数形成重载 */
    myString(const char* s = NULL) { 
        std::cout << "myString(const char* s)" << std::endl; 
    }

	myString(int size, char c = ' ') { 
        std::cout << "构建size个c组成的字符串" << std::endl;
    }

	explicit myString(A a) { 
        std::cout << "explicit myString(A a)" << std::endl; 
    }
	
    /* 拷贝构造 */
    myString(const myString& other) { 
        std::cout << "copy初始化" << std::endl;
    }

	/* 赋值运算符重载 */
    myString &operator=(const myString& other) { 
        std::cout << "赋值函数" << std::endl; return *this; 
    }
};

int main() {
    /* 以int 整形数字初始化为例 */
	// int a{ 1.2 }; //错误，列表初始化
	// 观察下面的隐式转换类型
	int a1(1.2);  // 直接初始化
	int a2 = 1.2; // 拷贝初始化
	int a3;
	a3 = 1.2;     // 赋值运算符重载

	// 自己定义的类如何实现这些？
	myString s1("abc");  // 直接初始化
	std::cout << "--------" << std::endl;
	// 拷贝构造初始化[拷贝前先隐式转换类型](编译器可能会优化，即调用直接初始化)
	myString s2 = "abc"; 
	std::cout << "========" << std::endl;
	s2 = "abc";  // 先将"abc"隐式转换成string类型，再利用赋值运算符重载
	// 调用 myString(const char*) 进行隐式转换
	std::cout << "--------" << std::endl;
	myString s3 = 20;  // 直接调用赋值运算符重载也是可以的
	// 调用了 myString(int size,char c=' ')
	// 实际上是创建了一个 20 个空格的字符串
	// 仅仅是看起来像是数字 20 赋值给 myString
	// 因为这种方式容易引起混乱，因此前面要加explicit
	std::cout << "========" << std::endl;
	A a;
	// s3 = a; //错误， 由于explicit修饰，A类型无法隐式转换为myString
	s3 = myString(a);  // 显式转换
	s3 = (myString)a;			   // 只能显示转换
	s3 = static_cast<myString>(a); // 强制转换
	std::cout << "--------" << std::endl;

	// 要实现A -> B 的隐式转换， B中必须有非explicit声明的构造函数，且参数是A
	// 1. explicit作用: 抑制构造函数定义的隐式转换 
	// 2. explicit构造函数：只能用于直接初始化
	// 3. explicit关键字：只能在类内声明使用，类外不能加

	// 不能用 explicit 来实现 myString s = xxx; 这样的拷贝构造
	// 也就是说：假如 explicit myString(const char* s = NULL)
	// 那么： myString S("abc"); //ok  
    // myString S = "abc"; //error

	return 0;
}
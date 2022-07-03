/**
 * 
 * date:2020/03/22
 * 
 * 默认构造函数,拷贝构造函数,赋值运算符重载,析构函数,系统可自动合成。(自己没有定义的时候)
 * 
 * 三法则：
 * [拷贝构造函数,赋值运算符重载,析构函数],一般情况下,要么都自己定义,要么都是系统合成。
 * 有资源时,都自定义,没资源时,不必自己定义。
 * 
 * 三个当中,只要有一个需要自定义,意味着其他两个也要自定义!
 * 
 * 使用 =default; 显式要求编译器生成合成默认版本
 * 使用 =delete; 定义为删除的函数。通知编译器不需要该函数。
 * 
 * private 也可以阻止拷贝,阻止赋值。
 * 构造或析构函数定义为 private将无法在类外创建对象。
 * 但是:构造public,析构private是可以用new创建对象的。
 * 
*/

#include <iostream>
using namespace std;

class A {
public:
	A() = default;
	~A() = default;
	A(const A&) = default;
	A& operator=(const A&) = default;
};
class B {
public:
	B() = default;
	B(const B&) = delete;
	B& operator=(const B&) = delete;
};
class C {
    /* 公有构造函数， 但是私有析构函数 */
public:
	void destroy() { delete this; }
private:
	~C() {};
};
int main() {
	A a1;
	A a2 = a1;
	B b1;
	//B b2 = b1; //错误，拷贝构造函数认为delete了
	//C c1; //错误，虽然公有构造函数，但是自动析构无法完成
	C* pc = new C;
	pc->destroy();
	return 0;
}
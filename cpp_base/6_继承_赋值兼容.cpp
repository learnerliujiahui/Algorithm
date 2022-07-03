/**
 * @date: 2021-01-08
 * 
 * 拷贝构造中：
 * Base(const Base& other): num(other.num) {}             // Base拷贝构造函数
 * D1(const D1& other): Base(other), num2(other.num2) {}  // D1拷贝构造函数
 * 
 * D1的拷贝构造中，调用了父类的构造函数Base(other),其中other的类型是 const D1&，
 * 但是Base拷贝构造函数的参数是'const Base&',显然是不同的类型，为啥可以这样做？-->此处涉及"隐式转换"
 * 
 * 【赋值兼容】：派生类对象（引用或指针类型变量均可），可以赋给基类对象（引用或指针）【隐式转换】
 * 包含以下三种情况:
 * 1. 派生类的对象可以赋值给基类对象
 * 2. 派生类的对象可以初始化基类的应用
 * 3. 派生类对象的地址可以赋给指向基类的指针
 * 
 * 以上3条的前提：public继承
 * 
*/
#include <iostream>

class Base {
public:
    Base() = default;                           // 显式定义无参构造函数
    Base(const Base& other): num(other.num) {   // 拷贝构造
        std::cout << "Base copy construct" << std::endl;
    }
    void fun(){
        std::cout << "Base fun()" << std::endl;
    }
private:
    int num;
};

class D1: public Base{
public:
    D1() = default;
    D1(const D1& other): Base(other), num2(other.num2) {
        std::cout << "D1 copy construct" << std::endl;
    }
    // override
    void fun() {
        std::cout << "D1 fun() [override]" << std::endl;
    }
private:
    int num2;  // 派生类D1除了继承了父类的num变量，还有自己的num2变量
};


int main() {
    /**
     * 1. 基类对象和派生类对象之间的拷贝赋值
     * 只能将派生类对象拷贝或赋值给基类对象，反之不行
     * 
    */
    D1 d1;
    Base b1(d1);  // 显式初始化
    Base b2 = d1; // 拷贝初始化
    b2 = d1;      // 可以将派生类对象赋值给基类对象
    b1.fun();
    d1.fun();

    /**
     * 2.基类的引用：用派生类对象来初始化
    */
    Base& rb1 = d1;  // ok,利用派生类对象初始化基类引用变量
    std::cout << &rb1 << " | " << &d1 << std::endl;  // 输出地址相同，说明没有临时量
    rb1.fun();
    /**
     *  3.基类的指针：指向派生类对象
    */
    Base* pb1 = &d1; // ok, 利用基类指针指向派生类对象
    pb1->fun();
    return 0;
}
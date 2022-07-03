/**
 * @ date:2021-01-09
 * 
 * |-----------------------|
 * |   Base作用域           |
 * |   int d   |--------|  |   
 * |           | D1作用域|  |
 * |           | int d  |  |
 * |           |--------|  |
 * |-----------------------|
 * 
 * - 对于成员函数：
 *   声明在内层作用域的函数不会重载声明在外层作用域的函数
 *   - 和重写(overrides)区别？
 * - 对于数据成员：
 *   若派生类中的成员与基类成员同名，则无论参数列表是否相同，基类成员都将被遮住(shadow)
 * 
*/
#include<iostream>

struct Base{
    Base(): d(0) {}  // 初始化列表，默认无参构造
    void base_show(){
        std::cout << "base d:" << d << std::endl;
    }
    void fun() {std::cout << "base fun()" << std::endl;}
    int d;
};

struct D1: Base {
    D1(int i): d(i) {}
    void d1_show() {std::cout << "D1 d:" << d << std::endl;}  // 此处的变量d是哪个？
    void d1_show2() {std::cout << "d1_show2: base::d:" << Base::d << std::endl;}
    void fun(int i) {std::cout << "D1 fun()" << std::endl;}
    int d;  // 这个d和Base类中的d变量不是一个变量
};

int main() {
    Base b1;
    b1.base_show(); 
    std::cout << b1.d << std::endl;
    b1.fun();
    std::cout << "---------------" << std::endl;
    D1 d1(10);
    d1.d1_show();
    std::cout << d1.d << std::endl;
    d1.d1_show2();
    std::cout << b1.Base::d << std::endl;
    d1.fun(10);
    return 0;
}

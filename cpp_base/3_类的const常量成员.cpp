/**
 * date:2020/02/18
 * 
 * [类的const常量成员]
 * 
 * const成员函数
 * 1. const放在函数声明之后，实现体之前,如： 
 *                void fun() const {...;}
 * 
 * 2. 承诺在本函数内部不会修改类内的数据成员，不会调用其他非const成员函数，即仅仅是[访问函数]
 * 3. const构成函数重载(因为this指针属于底层const)
 * 
 * const对象
 * 只能调用const成员函数，可访问所有数据成员，不可修改
*/


#include<iostream>
class A{
public:
    A(int i = 0): ci(i), num(i) {}
    /**
     * const 成员变量，只能通过初始值列表初始化
     * A(int i = 0) {ci = i; }  利用构造函数赋值，错误！！！
     * void set_ci(int i){ ci = i;}  利用成员函数赋值，错误！！！
    */
   int get_ci() const { return ci; }
   void show() const {
       // set_num(0); 调用非const成员函数， 错误！！
       // num = 0; 修改数据成员，错误！！
       std::cout << num*ci << std::endl;
       get_ci();  //正确，调用const函数
       std::cout << "show() const" << std::endl;
   }
   void show() { std::cout << "show()" <<std::endl; }  //构成重载
   int set_num(int i){ num = i; }
private:
    const int ci;  // 初始化就要赋值，必须用初始化列表进行初始化
    int num;
};

int main(){
    A a;  //普通对象
    const A ca;  //const对象
    // ca.set_num(1);  错误，const对象只能调用const成员函数
    ca.show();  // show const
    a.show();  // show 非const
    /* 非const对象也可以调用const成员函数 */
    return 0;
}
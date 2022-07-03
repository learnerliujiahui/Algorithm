/**
 * @date: 2021-01-09
 * 继承方式规定了如何访问基类继承的成员。继承的方式有public,protected,private
 * 继承方式影响从基类继承来的成员的访问权限
 * public继承：基类的public成员和protected成员在派生类中保持原有访问属性，基类private成员在派生类中不可见
 * protected继承：基类的public成员和protected成员在派生类中变成protected属性，基类private成员在派生类中不可见
 * private继承：基类的public成员和protected成员在派生类中变成private属性，基类private成员在派生类中不可见
 * 
*/
#include<iostream>
class Base{
public:
    void f_pub(){std::cout << "Base f_pub()" << std::endl;}
    int i_pub;
protected:
    void f_pro(){std::cout << "Base f_pro()" << std::endl;}
    int i_pro;
private:
    void f_pri(){std::cout << "Base f_pri()" << std::endl;}
    int i_pri;
};


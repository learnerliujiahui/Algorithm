/**
 * 
 * date = 2020/02/09
 * [构造函数初始值列表]
 * 初始化的先后次序和成员变量的出现次序一致
 * 
 * A类在创建对象时，先分别对成员变量调用默认初始化，再进行赋值；
 * B类，创建时直接初始化
 * 
*/

#include<iostream>
class A{
public:
    A(int n, int f){
        num = n;
        fd = f;
    }
private:
    int num;
    double fd;
};

class B{
public:
    B(int n, double f): num(n), fd(f){}
private:
    int num;
    double fd;
};

int main(){
    A a(10, 1.2);
    B b(10, 1.2);
    return 0;
}
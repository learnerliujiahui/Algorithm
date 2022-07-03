/**
 * 
 * date: 2020/02/09
 * 类[构造函数]与[析构函数][次序]
 * 1. 多个对象，按顺序构造，并按逆序析构
 * 2. 类中有成员变量也是类对象，先运行该成员变量对象的构造函数，再运行本类构造函数，析构顺序相反
 * 3. 类中成员变量为类指针，并未真正创建实例对象，不运行构造函数
 * 
*/

#include<iostream>
#include<string.h>  // C
#include<string>  //C++

class A{
public:
    A(int i = 0){
        num = i;
        std::cout << "A()" << num << std::endl;
    }
    ~A(){
        std::cout << "~A()" << num << std::endl;
    }
private:
    int num;
};


class B{
public:
    B(){
        std::cout << "B()" << std::endl;
    }
    ~B(){
        std::cout << "~B()" << std::endl;
    }
};


class myString{
public:
    myString(const char* str = NULL){
        if(str == NULL){
            ps = new char[1];
            ps[0] = '\0';
        }
        else{
            const int len = strlen(str) + 1;
            ps = new char[len];
            strcpy(ps, str);
        }
        std::cout << "myString()" << std::endl;
    }
    ~myString(){
        delete[] ps;
        std::cout << "~myString()" << std::endl;
    }
private:
    char* ps;
};

class Stu{
public:
    Stu(){
        std::cout << "Stu()" << std::endl;
    }
    ~Stu(){
        std::cout << "~Stu()" << std::endl;
    }
private:
    myString name;
    int age;
};

class C{
public:
    C(){
        std::cout << "C()" << std::endl;
    }
    ~C(){
        std::cout << "~C()" << std::endl;
    }
};

void fun(){
    C c2;
}


int main(){
    A a1;
    A a2(1);
    B b;
    A* pa = new A[2]{2, 3};  //连续构造两次
    delete[] pa;  //连续析构两次
    std::cout << "------------------" << std::endl;
    Stu stu1;
    {
        C c1;
    }
    fun();
    std::cout << "----------" <<std::endl;
    int i = 0;
    for(C c3; i < 3; i++){
        std::cout << i << std::endl;
    }
    std::cout << "----------" <<std::endl;
    for(int j = 0; j<3;j++){
        C c4;
        std::cout << j << std::endl;
    }
    std::cout << "----------" <<std::endl;
    C *pc = new C;
    delete pc;
    return 0;
}
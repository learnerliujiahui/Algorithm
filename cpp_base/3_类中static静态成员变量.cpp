/**
 * date: 2020/02/18
 * [static成员变量]
 * 1. 同类对象间信息共享(多个对象公用同一个static变量)，
 * 2. 类外存储，必须类外初始化，
 * 3. 可通过类名访问，也可通过对象访问
 * 静态成员函数：管理静态数据成员，对静态数据成员封装(对外提供接口)
 *             只能访问静态数据成员。静态成员函数属于类， 没有this指针。
 * 
 * static成员变量和全局变量的区别
 * static成员变量并不是所有人都可以用
 * 
*/
#include<iostream>
class Person{
public:
    Person(int _age): age(_age) { sum += _age; count++;}
    /**
     * 静态成员函数
     * [相当于全局函数]
     * 普通成员函数会有默认this指针参数
     * 而static成员函数没有this指针默认参数，因此不能访问非静态成员函数
     * 因为不知道访问哪个
    */
    static int get_count();
    static double get_avg(){
        return double(sum)/count;
    }
private:
    int age;
    /**
     * static变量不在对象内存中，而是在data区
     * 此时也并没有开辟static变量的内存空间
     * 需要在类外初始化
     */
    static int count;  // 私有静态成员变量，不可类外通过 类名::变量名 访问
public:
    //不能 static int sum = 0;
    static int sum;  // 公有静态成员变量，可类外通过 类名::变量名 访问
public:
};

int Person::get_count() {return count;}
int Person::sum = 0;    //必须初始化
int Person::count = 0;  // 在数据区初始化，bss

int main(){
    /**
     * 类的static静态成员不属于对象
     * 静态成员变量也不占用对象的内存空间
     * 可在外部直接访问， 类名::静态变量名
    */
    std::cout << Person::sum << std::endl;
    //std::cout << Person::count << std::endl;  错误
    std::cout << "sizeof(Person) is: " <<sizeof(Person) << std::endl;

    Person p1(10);
    Person p2(10);
    // 静态变量也可以通过 对象.变量名 来访问
    // 静态函数也可以通过 类名::函数名 来访问
    std::cout << p1.sum <<std::endl; //不能访问p1.count
    std::cout << Person::get_avg() << std::endl;

    // 静态函数也可以通过 对象.函数名 来访问
    std::cout << p1.get_count() << std::endl;
    std::cout << p2.get_count() << std::endl;
    return 0;
}
/**
 * [单例模式]
 * date:2020/02/19
 * 1. 将默认构造函数和析构函数声明为[私有]，外部无法创建，无法销毁(只能自己销毁自己)
 * 2. 使用一个私有的静态本类类型的指针变量，用来指向该类的[唯一实例]
 * 3. 用一个公有的静态方法来获取该实例，第一次调用该方法时，创建实例并返回(懒汉式)，以后调用直接返回
 * 4. 用一个公有的静态方法来删除该实例，以保证该实例只会被删除一次
*/
#include<iostream>
class A{
private:
    /* 类的构造和析构函数私有 */
    A() {};
    ~A() {};
public:
    /* 公有静态方法，可以获取该唯一实例, 返回值为指向类A的指针 */
    static A* GetInstance(){
        if(m_pInstance == NULL)
            /* 多线程需要加锁 */
            m_pInstance = new A;
        return m_pInstance;
    }
    /* 公有静态方法，可以删除该实例 */
    static void DeleteInstance() {
        if(m_pInstance != NULL)
            delete m_pInstance;
        m_pInstance = NULL;
    }
private:
    static A* m_pInstance;  // 私有静态指针变量，指向类的唯一实例
    int count;  // 其他成员变量
};

/* static数据成员必须在类外初始化 */
A *A::m_pInstance = NULL;  //懒汉式: 先不创建，谁第一个调用谁创建
// A *A::m_pInstance = new A;  // 饿汉式：程序一运行就积极创建好

int main(){
    // A a;  // 错误，由于构造函数私有 -> 导致外部无法创建该对象
    A* pa = A::GetInstance();  //通过调用 类静态成员函数 来获取类对象
    A* pb = A::GetInstance();  //可多次调用
    // pa,pb指向同一个地址
    std::cout << pa << std::endl << pb << std::endl;
    // delete pa;  // 错误，外部无法直接销毁该类对象
    A::DeleteInstance();  //通过调用 类静态成员函数 来析构类对象
    return 0;
}
/**
 * 
 * date: 2020/02/15
 * 
 * [封装定义]: 类的数据成员一般都定义为私有成员，
 *            外部要访问类的私有成员只能通过接口(如get,set方法)
 * 
 * [特殊情况]: 类外有些函数需要频繁的访问类的数据成员，此时可以将这些函数定义为该类的友元函数。
 * [友元的好处]: 提高了程序的运行效率(减少类型和安全性检查及调用的时间开销)
 * [友元的副作用]: 破坏了类的封装性和隐藏性，使得非成员函数可以直接访问类的私有成员。
 * 
 * 友元可以是一个函数， 称为[友元函数]
 * 友元也可以是一个类， 称为[友元类]
 * 
 * 同类之间可以直接访问，例如(拷贝构造): A (const A& other){ num = other.num}
 * 
 * 全局函数，类成员函数可作为友元函数
 * 类的所有成员函数都可直接访问：友元类
 * 
*/
#include<iostream>
#include<cmath>

class Person{
public:
    /** 
     * 友元的声明仅仅指定了访问的权限
     * 通常把友元函数本身的声明和类的头文件放在一起
     */
    friend void set_Person(Person& person, double m, int t);
    friend double calc_Person(const Person& person);
    void set_m_p_piece(int m){
        if(m > 10.0 && m <= 100.0)
            m_p_piece = m;
        else
            m_p_piece = 10.0;
    }
    double get_m_p_piece() const {
        return m_p_piece;
    }
    void set_t_piece(int t){
        if(t <= 0)
            t_piece = 0;
        else
            t_piece = t;
    }
    int get_t_piece() const {
        return t_piece;
    }
private:
    double m_p_piece;  //单件工资
    int t_piece;  //总件数
};

void set_Person(Person& person, double m, int t){
        person.set_m_p_piece(m);
        person.set_t_piece(t);
    }

double calc_Person(const Person& person){
    return person.get_m_p_piece()*person.get_t_piece();
}


/**
 * 
 * 关于前向声明：
 * 1. 不能定义类的对象
 * 2. 可以用于定义指向这个类类型的指针或引用
 * 3. 用于声明，使用该类类型作为星灿类型或者返回值类型
 * 
 * 
*/
class Point;  // 前向声明

class ManagerPoint{
public:
    double distance(Point& a, Point& b);
};
class Point{
public:
    friend double ManagerPoint::distance(Point&a, Point&b);  // 友元函数
    Point(double x, double y): x(x), y(y) {}
    void print() const;
    const double& get_x() const{
        return x;
    }
    const double& get_y() const{
        return y;
    }
private:
    double x, y;
};

void Point::print() const {
    std::cout << "(" << x << "," << y << ")" <<std::endl;
}

double ManagerPoint::distance(Point& a, Point& b){
    double dx = a.x - b.x;
    double dy = a.y = b.y;
    return sqrt(dx*dx + dy*dy);
}


int main(){
    // Person person1;
    // for(int i = 0; i < 10000; i++){
    //     set_Person(person1, i, i);
    //     std::cout << calc_Person(person1) << std::endl;
    // }
    Point p1(1.0, 1.0), p2(4.0, 5.0);
    p1.print();
    p2.print();
    ManagerPoint mp;
    double d = mp.distance(p1, p2);
    std::cout << "Distance = " << d << std::endl;
    
    return 0;
}
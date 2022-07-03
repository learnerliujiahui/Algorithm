/**
 * date: 2020/02/09
 * this指针：指向本对象地址, 相当于[顶层const]
 * 
*/
#include<iostream>
class A{
public:
    A(int num){
        this->num = num;
    }
    /* 通过返回对象this指针，可实现连加操作 */
    A& add(int n){
        num +=n;
        return *this;
    }
    /* 将函数变为[访问函数]，加const */
    int get_num() const {
        return num;
    }
private:
    int num;
};

int main(){
    A a1(1);
    a1.add(2).add(3).add(4).add(5);
    std::cout << a1.get_num() << std::endl;
    return 0;
}
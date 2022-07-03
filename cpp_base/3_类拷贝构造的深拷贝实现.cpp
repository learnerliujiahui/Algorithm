#include<iostream>
#include<stdlib.h>
#include<string.h>

class myString{
public:
    myString(const char* str = NULL){
        if(str == NULL){
            ps = new char[1];
            ps[0] = '\0';
        }
        else{
            int len = strlen(str) + 1;
            ps = new char[len];
            strcpy(ps, str);
        }
    }
    /* 浅拷贝构造 */
    myString(const myString& other);
    /* 赋值运算符重载 */
    myString& operator=(const myString& other);

    /* 深拷贝实现 */
    myString(const myString& other){
        /* 重新开辟一段新堆空间 */
        ps = new char[strlen(other.ps)+1];
        strcpy(ps, other.ps);
    }
    myString& operator=(const myString& other){
        if(this == &other)
            /* 防止用自己拷贝构造自己 */
            return* this;
        /* 先释放当前对象中指针变量成员指向堆空间，再开辟新空间 */
        delete[] ps;
        ps = new char[strlen(other.ps)+1];
        strcpy(ps, other.ps);
        return* this;
    }
    ~myString(){
        delete[] ps;
    }
private:
    char* ps;
};
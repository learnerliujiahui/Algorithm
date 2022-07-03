/**
 * 
 * date: 2020/03/26
 * 
 * C++多线程[编译命令]:
 * g++ thread1.cpp -o thread1 -std=c++11 -pthread
 * 
 * 线程创建：
 * 主要是给线程传入可调用对象
 * 1. 函数
 * 2. 函数对象:会将对象进行深拷贝，即从主线程复制一份到子线程
 * 3. lambda表达式
 * 4. bind...
 * 
*/

#include<iostream>
#include<thread>
#include<unistd.h>

/* 函数创建 */
void fun1() {
    int k = 0;
    while(k < 3) {
        k++;
        std::cout << "fun1()" << std::endl;
        sleep(1);
    }
}

/* 函数对象创建 */
class Fun {
public:
    Fun() {
        std::cout << "construct!" << std::endl;
    }
    /* 函数调用符重载 */
    void operator()(){
        std::cout << "函数对象线程开始执行" << std::endl;
        std::cout << "函数对象线程结束执行" << std::endl;
    }
    ~Fun() {
        std::cout << "destruct!" << std::endl;
    }
};

/* 利用lambda表达式创建线程 */
auto lamThread = []{
    std::cout << "lambda得线程开始了" << std::endl;
    std::cout << "lambda得线程结束了" << std::endl;
};

void fun2() {
    int k = 0;
    while(k < 3) {
        k++;
        std::cout << "fun2()" << std::endl;
        sleep(1);
    }
}


int main(int argc, char *argv[]) {
    /* 新建线程, 会自动调用线程内容 */
    std::thread thread1(&fun1);
    std::thread thread2(&fun2);
    Fun clfun;
    std::thread thread3(clfun());
    std::thread thread4(lamThread);
    /**
     * 在一个线程中，开了另一个线程去干另一件事，
     * 使用join函数后，原始线程会等待(进入阻塞态)新线程执行结束之后，
     * 再去销毁线程对象。
    */
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    return 0;
}
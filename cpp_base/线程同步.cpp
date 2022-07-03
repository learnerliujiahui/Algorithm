/**
 * 
 * date: 2020/03/26
 * 
 * unique_lock中的unique表示独占所有权
 * unique_lock独占的是mutex对象，就是对mutex锁的独占
 * 
 * 使用方法：
 * 1. 新建unique_lock对象
 * 2. 给对象传入一个std::mutex对象作为参考
 *      std::mutex mutex1;
 *      unique_lock(mutex1); // mutex1对象生命周期结束后自动解锁
 * 
 * 程序运行过程：
 * 1. 同时运行threa1和thread2两个线程
 * 2. 先进入thread1现成的fun1函数，加锁;
 *    则另一个thread2线程进入后发现锁没有被释放，只能等待
 * 3. 过去两个循环，thread1线程结束，unique_lock(metux1)生命周期结束，
 *    metux锁释放，再执行thread2线程
 * 
*/

#include<iostream>
#include<thread>
#include<mutex>
#include<unistd.h>

std::mutex mutex1; // 创建一个信号量

void fun1() {
    int k = 0;
    std::unique_lock<std::mutex> lock(mutex1);
    while(k < 3) {
        k++;
        std::cout << "fun1()" << std::endl;
        sleep(1);        
    }
}

void fun2() {
    int k = 0;
    std::unique_lock<std::mutex> lock(mutex1);
    while(k < 3) {
        k++;
        std::cout << "fun2()" << std::endl;
        sleep(1);
    }
}

int main() {
    std::thread threa1(&fun1);
    std::thread threa2(&fun2);
    threa1.join();
    threa2.join();
    return 0;
}
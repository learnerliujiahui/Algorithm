#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

/* 先创建一个信号量 */
std::mutex g_mutex;
int g_count = 0;

void Counter() {
    g_mutex.lock();  // 上锁

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

    // 前面代码如有异常，unlock 就调不到了。
    g_mutex.unlock();  // 释放
}

int main() {
    const std::size_t SIZE = 4;

    // 创建一组线程。
    std::vector<std::thread> v;
    v.reserve(SIZE);

    for (std::size_t i = 0; i < SIZE; ++i) {
        v.emplace_back(&Counter);
    }

    // 等待所有线程结束。
    for (std::thread& t : v) {
        t.join();
    }
    return 0;
}
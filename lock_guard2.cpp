#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard, std::adopt_lock

std::mutex mtx;           // mutex for critical section

/**
 * 在 print_thread_id 中，我们首先对 mtx 进行上锁操作(mtx.lock();)，
 * 然后用 mtx 对象构造一个 lock_guard 对象(std::lock_guard lck(mtx, std::adopt_lock);)，
 * 注意此时 Tag 参数为 std::adopt_lock，表明当前线程已经获得了锁，
 * 此后 mtx 对象的解锁操作交由 lock_guard 对象 lck 来管理，在 lck 的生命周期结束之后，mtx 对象会自动解锁。 
 * lock_guard 最大的特点就是安全易于使用，请看下面例子(参考)，
 * 在异常抛出的时候通过 lock_guard 对象管理的 Mutex 可以得到正确地解锁。
 * 
*/
void print_thread_id (int id) {
    mtx.lock();
    /* lock_guard对象的adopting 初始化，当前mutex对象已经被当前线程锁住 */
    std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
    std::cout << "thread #" << id << '\n';
}


int main () {
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_thread_id, i+1);
 
    for (auto& th : threads) th.join();
 
    return 0;
}
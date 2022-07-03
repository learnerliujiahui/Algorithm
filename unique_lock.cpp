/**
 * date: 2020/03/26
 * 
 * https://blog.csdn.net/zzhongcy/article/details/85230200?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
 * 
 *  但是 lock_guard 最大的缺点也是简单，没有给程序员提供足够的灵活度，
 * 因此，C++11 标准中定义了另外一个与 Mutex RAII 相关类 unique_lock，
 * 该类与 lock_guard 类相似，也很方便线程对互斥量上锁，但它提供了更好的
 * 上锁和解锁控制。顾名思义，unique_lock对象以独占所有权的方式（unique owership）
 * 管理 mutex 对象的上锁和解锁操作，所谓独占所有权，就是没有其他的
 * unique_lock对象同时拥有某个mutex对象的所有权。在构造(或移动(move)赋值)时，
 * unique_lock对象需要传递一个Mutex对象作为它的参数，新创建的unique_lock对
 * 象负责传入的 Mutex 对象的上锁和解锁操作。
 * 
 * std::unique_lock对象也能保证在其自身析构时它所管理的Mutex对象能够被正确地解锁
 * （即使没有显式地调用 unlock 函数）。因此，和lock_guard一样，这也是一种简单而又
 * 安全的上锁和解锁方式，尤其是在程序抛出异常后先前已被上锁的Mutex对象可以正确进行
 * 解锁操作，极大地简化了程序员编写与 Mutex 相关的异常处理代码。
 * 
 * 
 * 
 * 
*/
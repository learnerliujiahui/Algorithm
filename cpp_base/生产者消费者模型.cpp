/**
 * date: 2020/03/26
 * 
 * 以往：不同操作系统多线程代码不可移植(不可跨平台)
 * C11开始语言本身增加了对多线程支持: thread
 * 
 * 明确两个区别
 * std::unique_lock<std::mutex> lock(myMetux);
 * 
 * std::lock_guard<std::mutex> lock(myMetux);
 * ---------------------------------------------------------------
 * lock_guard 对象通常用于管理某个锁(Lock)对象，因此与 Mutex RAII 相关，
 * 方便线程对互斥量上锁，即在某个 lock_guard 对象的声明周期内，它所管理的
 * 锁对象会一直保持上锁状态；而 lock_guard 的生命周期结束之后，它所管理的
 * 锁对象会被解锁(注：类似shared_ptr等智能指针管理动态分配的内存资源)。
 * 
 * 在 lock_guard 对象构造时，传入的Mutex对象(即它所管理的Mutex对象)
 * 会被当前线程锁住。在lock_guard对象被析构时，它所管理的Mutex对象会自动解锁，
 * 由于不需要程序员手动调用 lock 和 unlock 对 Mutex 进行上锁和解锁操作，
 * 因此这也是最简单安全的上锁和解锁方式，尤其是在程序抛出异常后先前已被上锁的
 * Mutex对象可以正确进行解锁操作，极大地简化了程序员编写与Mutex相关的异常处理代码
 * 值得注意的是，lock_guard对象并不负责管理Mutex对象的生命周期，
 * lock_guard对象只是简化了 Mutex 对象的上锁和解锁操作，方便线程对互斥量上锁,
 * 即在某个 lock_guard 对象的声明周期内，它所管理的锁对象会一直保持上锁状态；
 * 而 lock_guard的生命周期结束之后，它所管理的锁对象会被解锁。
 * ---------------------------------------------------------------
 * 
*/

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

/* 商品队列大小 */
static const int K_ItemRepositorySize = 3;
/* 待生产商品数量 */
static const int K_ItemToProduce = 10;

/**
 * 初始化一个互斥量,多线程输出同步锁
 * 这里的锁是为了防止多个线程向屏幕输出的时候会出现打印错乱交叉的情况。
 * 加上此锁，一个线程输出的同时，另一个线程就在等着，
 * 这样有效的避免了输出混乱。
 */
std::mutex mutex1;

typedef struct tagItemRepository {
    /* 初始化队列 */
    int item_buffer[K_ItemRepositorySize];
    int read_pos;
    int write_pos;
    /* 缓冲区读写锁 */
    std::mutex myMutex;
    /* 条件变量设置： 生产者生产的数据存满了缓冲区，要进行通知消费者进行消费。 */
    std::condition_variable repo_not_full; // 条件变量
    std::condition_variable repo_not_empty; //条件变量
}ItemRepository;

ItemRepository Repo;
/**
 * 生产者
*/
void produceItem(ItemRepository* p_repo, int item) {
    /* 上锁, 之后会自动释放 */
    std::unique_lock<std::mutex> lock(p_repo->myMutex);
    while((p_repo->write_pos+1)%K_ItemRepositorySize == p_repo->read_pos) {
        {
            /*  */
            std::lock_guard<std::mutex> lock(mutex1);
            std::cout << "缓冲区已满，等待..." << std::endl;
        }
        /* 等待repo_not_full条件 */
        p_repo->repo_not_full.wait(lock);
    }
    /* 写入 */
    (p_repo->item_buffer)[p_repo->write_pos] = item;
    p_repo->write_pos++;  // 写入位置+1

    if(p_repo->write_pos == K_ItemRepositorySize)
        p_repo->write_pos = 0;
    
    /* 通知消费者产品库不空 */
    p_repo->repo_not_empty.notify_all();
    // lock.unlock(); //解锁
}


int consumeItem(ItemRepository* p_repo) {
    int data;
    std::unique_lock<std::mutex> lock(p_repo->myMutex);
    while(p_repo->write_pos == p_repo->read_pos) {
        {
            std::lock_guard<std::mutex> lock(mutex1);
            std::cout << "缓存区空，等待..."<<std::endl;
        }
        /* 等待repo_not_empty不空条件的产生 */
        p_repo->repo_not_empty.wait(lock);
    }
    /* 从缓存队列中读取一个产品 */
    data = p_repo->item_buffer[p_repo->read_pos];
    p_repo->read_pos++; // 下一个读取位置后移

    /* 若读取到最后一个位置，则重新设置 */
    if(p_repo->read_pos >= K_ItemRepositorySize)
        p_repo->read_pos = 0;

    /* 此时已经拿走一个产品，生产者可以生产 */
    p_repo->repo_not_full.notify_all();
    // lock.unlock();
    return data;
}

/**
 * 生产者任务
*/
void producerTask() {
    for(int i = 0; i < K_ItemToProduce; i++) {
        /* 不断生产产品 */
        produceItem(&Repo, i);
        {
            std::lock_guard<std::mutex> lock(mutex1);
            std::cout << "生产第" << i+1 << "个产品" << std::endl;
        }
    }
}

void consumerTask() {
    static int cnt = 0;
    while(1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int item = consumeItem(&Repo);
        {
            std::lock_guard<std::mutex> lock(mutex1);
            std::cout << "消费第" << item+1 <<"个产品"<<std::endl;
        }
        if(++cnt == K_ItemToProduce)
            break;
    }
}


void initItemRepository(ItemRepository* p_repo) {
    p_repo->write_pos = 0;
    p_repo->read_pos = 0;
}

int main(){
    initItemRepository(&Repo);
    std::thread producer(producerTask);
    std::thread consumer(consumerTask);

    producer.join();
    consumer.join();
    return 0;
}
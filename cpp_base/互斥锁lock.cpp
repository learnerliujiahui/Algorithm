/**
 * 
 * 
 * 互斥锁：
 * lock() ：第一个线程进去后，后面的线程会进入阻塞休眠状态，被放入到阻塞队列中。
 * unlock()：加锁的线程执行完后，会解锁，然后去阻塞队列中唤醒阻塞线程
 * 适用于锁的粒度大的场景
 * 
 * 自旋锁：
 * lock()：第一个线程进去，后面的线程在循环空转检查。
 * unlock()：第一个加锁的线程解锁，后面的线程检测到就可以被cpu调度。
 * 
 * 举个例子就很好理解：快递。
 * 互斥锁就好比，你去取快递的地方问了一下，你的快递还有1天才能到，
 * 你就可以先把电话留在取快递的地方，等你的快递到了，快递公司的工作人员会打电话通知你，
 * 而这种场景如果使用自旋锁，就好比每隔几分钟就去询问快递工作人员，
 * 
 * 
 * 自旋锁就像，你去问的时候，你的快递还有大概20分钟就到了，
 * 那这20分钟也干不了啥，还不如就在快递点等着，玩玩猴急，
 * 每隔5分钟去问一下，快递到了没。而这种场景如果使用互斥锁，
 * 那你就会觉的还有20分钟，不如回家等着快递人员给我打电话吧，
 * 结果你刚走到家门口，把钥匙插入锁，快递公司打电话告知：你的快递到了。
 * 
 * 
 * 而类比到计算机：使用互斥锁就好比让其他线程阻塞，进入阻塞队列，就类似你回家等通知。
 * 用自旋锁就让其它线程空转(比如可以给该线程设置在一定时间段内让出cpu使用权)，
 * 每隔10秒检查，就类似你在快点的门口等待，每隔5分钟去问一下，快递到了没。

 * 
*/

#include<thread>
#include<mutex>
#include<iostream>
#include<ctime>
/**
 * 
 * Add1和Add2加锁的位置不同
*/

void Add1(int* px, int n,std::mutex* pmt) {
	(*pmt).lock();
	for (int i = 0; i < n; i++) {
		(*px)++;
	}
	(*pmt).unlock();
}

void Add2(int* px, int n, std::mutex* pmt) {
	for (int i = 0; i < n; i++) {
		(*pmt).lock();
		(*px)++;
		(*pmt).unlock();
	}
}

void Fun1() {
	int x = 0;
	std::cout << "Before Add:x=" << x << std::endl;
	std::mutex mt;
	std::thread t1(Add1, &x, 10000000, &mt);
	std::thread t2(Add1, &x, 10000000, &mt);
	t1.join();
	t2.join();
	std::cout << "After Add:x=" << x << std::endl;
}
void Fun2() {
	int y = 0;
	std::cout << "Before Add:y=" << y << std::endl;
	std::mutex mt;
	std::thread t1(Add2, &y, 10000000, &mt);
	std::thread t2(Add2, &y, 10000000, &mt);
	t1.join();
	t2.join();
	std::cout << "After Add:y=" << y << std::endl;
}

int main() {
	int start1 = clock();
	Fun1();
	int end1 = clock();
	std::cout << "Fun1 Time Spend:" << end1 - start1 << std::endl;

	int start2 = clock();
	Fun2();
	int end2 = clock();
	std::cout << "Fun2 Time Spend:" << end2 - start2 << std::endl;
	// system("pause");
	return 0;
}
// 执行结果
// Before Add:x=0
// After Add:x=20000000
// Fun1 Time Spend:89
// Before Add:y=0
// After Add:y=20000000
// Fun2 Time Spend:7795

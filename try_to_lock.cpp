/**
 * date: 2020/03/26
 * 
*/

#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<list>
#include<mutex>
 

class A {
public:
void inMsgRecvQueue() {
	for (int i = 0; i < 10000; i++) {
		std::cout << "inMsgRecvQueue()执行，插入一个元素" << i << std::endl;
        { 
			std::unique_lock<std::mutex> sbguard(my_mutex, std::try_to_lock);
			if (sbguard.owns_lock()) {
				//拿到了锁
				msgRecvQueue.push_back(i); 
				//...
				//其他处理代码
			}
			else {
				//没拿到锁
				std::cout << "inMsgRecvQueue()执行，但没拿到锁头，只能干点别的事" << i << std::endl;
			}
		}
	}
}
 
	bool outMsgLULProc(int &command) {
        /* 要先lock(),后续才能用unique_lock的std::adopt_lock参数 */
		my_mutex.lock();
		std::unique_lock<std::mutex> sbguard(my_mutex, std::adopt_lock);
 
		std::chrono::milliseconds dura(20000);
		std::this_thread::sleep_for(dura);  //休息20s
 
		if (!msgRecvQueue.empty()) {
			//消息不为空
			int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在
			msgRecvQueue.pop_front();//移除第一个元素。但不返回；
			return true;
		}
		return false;
	}
	// 把数据从消息队列取出的线程
	void outMsgRecvQueue() {
		int command = 0;
		for (int i = 0; i < 10000; i++) {
			bool result = outMsgLULProc(command);
 
			if (result == true) {
				std::cout << "outMsgRecvQueue()执行，取出一个元素" << std::endl;
				//处理数据
			}
			else {
				//消息队列为空
				std::cout << "inMsgRecvQueue()执行，但目前消息队列中为空！" << i << std::endl;
			}
		}
		std::cout << "end!" << std::endl;
	}
 
private:
    /* 容器（消息队列），代表玩家发送过来的命令。 */
	std::list<int> msgRecvQueue;
    /* 创建一个互斥量（一把锁） */
	std::mutex my_mutex;
};
 
int main() {
	A myobja;
 
	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
 
	myOutMsgObj.join();
	myInMsgObj.join();
 
	std::cout << "主线程执行！" << std::endl;
 
	return 0;
}
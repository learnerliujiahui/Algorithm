/**
 * 
 * C++11中提供了std::mute锁，共包含两种类型：
 * std::lock_guard：方便线程对互斥量上锁。lock_guard取代了mutex的lock()和unlock();
 * std::unique_lock：方便线程对互斥量上锁，但提供了更好的上锁和解锁控制。
 * 以及相关的函数：
 * 
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<string>

std::mutex mt;

void PrintEven(int x) {
	if (x % 2 == 0)
		std::cout << x << "is even\n";
	else
		throw ("not even");
}

/**
 * 有可能会死锁
*/
void PrintThreadId1(int id) {
	try {
		mt.lock();
		PrintEven(id);
		mt.lock();
	}
	catch (std::string& e) {
		std::cout << "[" << e << "]\n";
	}
}


void PrintThreadId(int id) {
	try{
		std::lock_guard<std::mutex> lg(mt);
		PrintEven(id);
	}
	catch (...)
	{
		std::cout << "[exception caught]\n";
	}
}


int main() {
	std::thread threads[5];
	for (int i = 0; i < 5; i++)
		threads[i] = std::thread(PrintThreadId, i + 1);
	for (auto& th : threads)
		th.join();
	return 0;
}

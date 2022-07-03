/**
 * date: 2020/03/22
 * 
 * 应用举例:Game类的方向移动函数的封装。
 * 
 * using Action = void(Game::*)(); //定义别名 成员函数指针
 * 相当于 typedef void(Game::*Action)();
 * 
 * enum Direction { LEFT, RIGHT, UP, DOWN }; //枚举
 * 默认从0开始,相当于LEFT=0, RIGHT=1, UP=2, DOWN=3
 * 
 * static Action menu[];
 * 数组中存放的是 成员函数指针
 * 
*/

#include <iostream>
using namespace std;

class Game {
public:
	// using Action = void(Game::*)();  // 定义成员函数指针
    typedef void(Game::*Action)();
	enum Direction { LEFT, RIGHT, UP, DOWN }; //枚举类型
	void move(Direction d) {
		(this->*menu[d])();
	}
private:
	void left() { cout << "left" << endl; }
	void right() { cout << "right" << endl; }
	void up() { cout << "up" << endl; }
	void down() { cout << "down" << endl; }
	static Action menu[]; //函数指针 数组
};

Game::Action Game::menu[] = {	&Game::left,
								&Game::right,
								&Game::up,
								&Game::down };

int main(){
	Game g;
	g.move(Game::LEFT);
	g.move(Game::RIGHT);
	g.move(Game::UP);
	g.move(Game::DOWN);
	return 0;
}
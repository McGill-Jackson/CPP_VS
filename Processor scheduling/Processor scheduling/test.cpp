#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;
enum State {
	R,
	E
};
struct PCB {
	int _name;
	PCB* _next_p;
	int _time;
	int _priority;
	State _state;

	PCB(int name = 0, int time = 0, int priority = 0)
		:_name(name)
		,_next_p(nullptr)
		,_time(time)
		,_priority(priority)
		,_state(R)
	{}
};
class List_PCB {
	typedef PCB* pPCB;
public:
	List_PCB(int n = 5)
		:_PCB_n(n)
		,_header(new PCB)
	{
		Creat_List(n);
	}
	void scheduling();
	void Printf_List();
private:
	void Creat_List(int n);
	void Find_location(pPCB p);
	pPCB _header;
	int _PCB_n;
};
void List_PCB::Creat_List(int n) {
	for (int i = n; i > 0; i--) {
		//创建PCB
		srand((unsigned int)time(0));
		int priority = rand() % 50;
		int time = 0;
		while (1) {
			time = rand() % 50;
			if (time == 0)continue;
			else break;
		}
		pPCB p = new PCB(i, time, priority);
		//找插入位置
		Find_location(p);
		Sleep(1000);
	}
}
void List_PCB::Find_location(pPCB p) {
	if (_header->_next_p == nullptr) { 
		_header->_next_p = p;
		return;
	}
	pPCB first = _header;
	pPCB second = _header->_next_p;
	while (1) {
		if (second == nullptr||p->_priority >= second->_priority) {
			first->_next_p = p;
			p->_next_p = second;
			return;
		}
		else {
			first = first->_next_p;
			second = second->_next_p;
		}
	}
}
void List_PCB::scheduling() {
	pPCB cur = _header->_next_p;
	while (cur) {
		cout << "*******************************" << endl;
		cout << "进程名 : P" << cur->_name << endl;
		cout << "运行前" << endl;
		Printf_List();
		_header->_next_p = cur->_next_p;
		--cur->_priority;
		--cur->_time;
		if (cur->_time == 0) {
			cur->_state = E;
			delete cur;
			cur = _header->_next_p;
		}
		else {
			Find_location(cur);
			cur = _header->_next_p;
		}
		cout << "运行后" << endl;
		Printf_List();
		cout << endl;
	}
}
void List_PCB::Printf_List() {
	cout << "进程名\t||" << "时间\t||" << "优先数||" << "状态" << endl;
	pPCB cur = _header->_next_p;
	while (cur) {
		cout << "P"<<cur->_name <<"\t||"<<cur->_time << "\t||"<<cur->_priority << "\t||" << (State)cur->_state << endl;
		cur = cur->_next_p;
	}
}
void test() {
	List_PCB L;
	L.Printf_List();
	L.scheduling();
	return;
}
int main() {
	test();
	return 0;
}
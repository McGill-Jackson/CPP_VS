#include <iostream>
using namespace std;
enum State {
	Empty,
	Exist
};
struct Partition {
	int _address;//初始地址
	int _length;//长度
	State _state;//状态
	Partition* _np;//下一块空间地址
	int _name;//正在占用的进程名

	Partition(int address = 0,int length = 0,State state = Empty,int name = 0)
		:_address(address)
		,_length(length)
		,_state(state)
		,_np(nullptr)
		,_name(name)
	{}
};
class PartitionTable {
	typedef Partition Node;
	typedef Node* pNode;
public:
	PartitionTable(int address = 0, int length = 512)
		:_pnode(new Node(address,length,Empty,0))
	{}
	bool Insert(int name,int l) {
		pNode cur = _pnode;
		while (cur != nullptr) {
			if (cur->_state == Empty && cur->_length >= l) {
				int poor = cur->_length - l;
				cur->_name = name;
				cur->_length = l;
				cur->_state = Exist;
				if (poor > 0) {
					pNode nnode = new Node(cur->_address + l, poor,Empty,0);
					nnode->_np = cur->_np;
					cur->_np = nnode;
					//合并空
					Merge();
					return true;
				}
			}
			cur = cur->_np;
		}
		return false;
	}
	bool Delete(int name) {
		pNode cur = _pnode;
		while (cur) {
			if (cur->_name == name) {
				cur->_state = Empty;
				cur->_name = 0;
				//合并空
				Merge();
				return true;
			}
			cur = cur->_np;
		}
		return false;
	}
	bool Merge() {
		if (_pnode->_np == nullptr)return false;
		pNode left = _pnode;
		pNode right = _pnode->_np;
		while (right) {
			if (left->_state == Empty && right->_state == Empty) {
				left->_length = left->_length + right->_length;
				left->_np = right->_np;
				delete right;
				return true;
			}
			left = left->_np;
			right = right->_np;
		}
		return false;
	}
	void Printf() {
		cout << "进程名\t||" << "地址\t||" << "长度||" << "状态" << endl;

		pNode cur = _pnode;
		while (cur) {
			cout << cur->_name << "\t||" << cur->_address << "\t||" << cur->_length << "\t||" << (State)cur->_state << endl;
			cur = cur->_np;
		}
	}
private:
	pNode _pnode;
};
void Test() {
	PartitionTable pt; pt.Printf();
	pt.Insert(1, 300); pt.Printf();
	pt.Insert(2, 100); pt.Printf();
	pt.Delete(1); pt.Printf();
	pt.Insert(3, 150); pt.Printf();
	pt.Insert(4, 30); pt.Printf();
	pt.Insert(5, 40); pt.Printf();
	pt.Insert(6, 60); pt.Printf();
	pt.Delete(4); pt.Printf();
}
int main() {
	Test();
	return 0;
}
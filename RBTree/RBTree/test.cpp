#include <iostream>
#include <utility>
using namespace std;
enum Color {
	RED,
	BLACK
};
template <class K,class V>
struct RBTreeNode {
	RBTreeNode<K, V>* _left;	//left child
	RBTreeNode<K, V>* _right;	//right child
	RBTreeNode<K, V>* _parent;	//parent
	pair<K, V> _kv;//key-value
	Color _color; //color

	RBTreeNode(const pair<K,V>& kv = pair<K,V>())
		:_kv(kv)
		,_color(RED)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};

template <class K,class V>
class RBTree {
	typedef RBTreeNode<K, V> Node;
	typedef Node* pNode;
public:
	RBTree()
		:_header(new Node)
	{
		//The leftand right sides of the head are the 
		//leftmostand rightmost parts of the tree.
		_header->_left = _header->_right = _header;
	}
	bool insert(const pair<K, V>& kv);
	void _validation() {
		_inOrder(_header->_parent);
	}
private:
	void _RotateL(pNode pParent);
	void _RotateR(pNode pParent);
	void swap(pNode& A, pNode& B);
	void most();
	void _inOrder(pNode parent);
	pNode _header;
};
template <class K, class V>
void RBTree<K, V>::_inOrder(pNode parent) {
	if (parent == nullptr) return;
	_inOrder(parent->_left);
	cout << parent->_kv.first << " ";
	_inOrder(parent->_right);
}
template <class K, class V>
void RBTree<K, V>::most() {
	pNode most_L = nullptr;
	pNode most_R = nullptr;
	pNode most = _header->_parent;
	while (most) {
		most_L = most;
		most = most->_left;
	}
	_header->_left = most_L;
	most = _header->_parent;
	while (most) {
		most_R = most;
		most = most->_right;
	}
	_header->_right = most_R;
}
template <class K, class V>
void RBTree<K, V>::swap(pNode& A, pNode& B) {
	pNode N;
	N = A;
	A = B;
	B = N;
}
template <class K,class V>
void RBTree<K, V>::_RotateR(pNode pParent) {
	pNode pSubL = pParent->_left;
	pNode pSubLR = pSubL->_right;

	pSubL->_right = pParent;
	pParent->_left = pSubLR;

	if (pSubLR)
		pSubLR->_parent = pParent;
	if (pParent == _header->_parent) {
		_header->_parent = pSubL;
		pSubL->_parent = nullptr;
	}
	else {
		pNode pParent_p = pParent->_parent;
		if (pParent_p->_left == pParent)
			pParent_p->_left = pSubL;
		else
			pParent_p->_right = pSubL;//
		pSubL->_parent = pParent_p;
	}
	pParent->_parent = pSubL;
}
template <class K,class V>
void RBTree<K,V>::_RotateL(pNode pParent) {
	pNode pSubR = pParent->_right;
	pNode pSubRL = pSubR->_left;

	pSubR->_left = pParent;
	pParent->_right = pSubRL;
	if (pSubRL)
		pSubRL->_parent = pParent;
	if (pParent == _header->_parent) {
		_header->_parent = pSubR;
		pSubR->_parent = nullptr;
	}
	else {
		pNode pParent_p = pParent->_parent;
		if (pParent_p->_left == pParent)
			pParent_p->_left = pSubR;
		else
			pParent_p->_right = pSubR;
		pSubR->_parent = pParent_p;
	}
	pParent->_parent = pSubR;
}
template <class K, class V>
bool RBTree<K,V>::insert(const pair<K, V>& kv) {
	//insert
	//1.When the tree is empty
	if (_header->_parent == nullptr) {
		pNode root = new Node(kv);
		_header->_parent = root;
		root->_parent = _header;
		_header->_left = _header->_right = root;

		root->_color = BLACK;
		return true;
	}
	pNode parent = nullptr;
	pNode cur = _header->_parent;
	while (cur) {
		parent = cur;
		if (kv.first == cur->_kv.first) return false;
		else if (kv.first < cur->_kv.first) cur = cur->_left;
		else cur = cur->_right;
	}
	cur = new Node(kv);
	if (parent->_kv.first > kv.first)
		parent->_left = cur;
	else
		parent->_right = cur;
	cur->_parent = parent;

	//adjust
	while (cur != _header->_parent && cur->_parent->_color == RED) {
		pNode grandfather = parent->_parent;

		if (parent == grandfather->_left) {
			pNode unclue = grandfather->_right;
			if (unclue && RED == unclue->_color) {
				parent->_color = BLACK;
				unclue->_color = BLACK;
				grandfather->_color = RED;
				cur = grandfather;
				parent = cur->_parent;
			}
			else {
				if (cur == parent->_right) {
					_RotateL(parent);
					swap(parent, cur);
				}
				grandfather->_color = RED;
				parent->_color = BLACK;
				_RotateR(grandfather);
			}
		}
		else {
			pNode unclue = grandfather->_left;
			if (unclue && RED == unclue->_color) {
				parent->_color = BLACK;
				unclue->_color = BLACK;
				grandfather->_color = RED;
				cur = grandfather;
				parent = cur->_parent;
			}
			else {
				if (cur == parent->_left) {
					_RotateR(parent);
					swap(parent, cur);
				}
				grandfather->_color = RED;
				parent->_color = BLACK;
				_RotateL(grandfather);
			}
		}
	}
	most();
	_header->_parent->_color = BLACK;
	_header->_parent->_parent = _header;
}
void test() {
	RBTree<int, int >rbt;
	int arr[9] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < 9; i++) {
		rbt.insert(make_pair(arr[i], arr[i]));
	}
	rbt._validation();
}
int main() {
	test();
	return 0;
}
#include <iostream>
#include <utility>
using namespace std;
enum Color {
	RED,
	BLACK
};
template <class V>
struct RBTreeNode {
	RBTreeNode<V>* _left;	//left child
	RBTreeNode<V>* _right;	//right child
	RBTreeNode<V>* _parent;	//parent
	V _val;//key-value
	Color _color; //color

	RBTreeNode(const V& val = V())
		:_val(val)
		,_color(RED)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};
template <class V>
struct RBTreeIterator {
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V> Self;
	typedef Node* pNode;
	RBTreeIterator(pNode node)
		:_node(node)
	{}
	pNode _node;

	//解引用
	V& operator*{
		return _node->val;
	}

	Self operator--{
		if (_node->_left) {
			_node = _node->_left;
			while (_node->_right) {
				_node = _node->_right;
			}
		}
		else {
			pNode parent = _node->_parent;
			while (parent->_left == _node) {
				_node = parent;
				parent = _node->parent;
			}
			if (_node->_left != parent)
				_node = parent;
		}
	}

};
template <class K,class V,class KeyOfValue>
class RBTree {
	typedef RBTreeNode<V> Node;
	typedef Node* pNode;
public:
	RBTree()
		:_header(new Node)
	{
		//The leftand right sides of the head are the 
		//leftmostand rightmost parts of the tree.
		_header->_left = _header->_right = _header;
	}
	bool insert(const V& val);
	void _validation() {
		_inOrder(_header->_parent);
		bool is = IsValidRBTree();
		if (is == true) {
			cout << "Meet" << endl;
		}
		else {
			cout << "Not meet" << endl;
		}
	}
private:
	void _RotateL(pNode pParent);
	void _RotateR(pNode pParent);
	void swap(pNode& A, pNode& B);
	void most();
	void _inOrder(pNode parent);
	bool IsValidRBTree();
	bool _IsValidRBTree(pNode root, size_t k, const size_t blackCount);

	pNode _header;
};
template <class K, class V, class KeyOfValue>
bool RBTree<K,V,KeyOfValue>::_IsValidRBTree(pNode root, size_t k, const size_t blackCount) {
	if (root == nullptr) {
		if (k != blackCount) {
			cout << "有路径上的黑色结点的个数不相同" << endl;
			return false;
		}
		return true;
	}
	if (root->_color == BLACK)
		++k;

	pNode parent = root->_parent;
	if (parent && parent->_color == RED && root->_color == RED) {
		cout << "有红色结点相连" << endl;
		return false;
	}
	return _IsValidRBTree(root->_left, k, blackCount) &&
		_IsValidRBTree(root->_right, k, blackCount);
}
template <class K, class V, class KeyOfValue>
bool RBTree<K, V, KeyOfValue>::IsValidRBTree() {
	pNode root = _header->_parent;
	if (root == nullptr)return true;

	if (BLACK != root->_color) {
		cout << "根节点不是黑色" << endl;
		return false;
	}

	size_t blackCount = 0;
	pNode cur = root;
	while (cur) {
		if (BLACK == cur->_color)
			++blackCount;
		cur = cur->_left;
	}
	size_t k = 0;
	return _IsValidRBTree(root, k, blackCount);
}
template <class K, class V, class KeyOfValue>
void RBTree<K, V, KeyOfValue>::_inOrder(pNode parent) {
	if (parent == nullptr) return;
	_inOrder(parent->_left);
	cout << parent->_val.first << " ";
	_inOrder(parent->_right);
}
template <class K, class V, class KeyOfValue>
void RBTree<K, V, KeyOfValue>::most() {
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
template <class K, class V, class KeyOfValue>
void RBTree<K, V, KeyOfValue>::swap(pNode& A, pNode& B) {
	pNode N;
	N = A;
	A = B;
	B = N;
}
template <class K,class V, class KeyOfValue>
void RBTree<K, V, KeyOfValue>::_RotateR(pNode pParent) {
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
template <class K,class V, class KeyOfValue>
void RBTree<K,V, KeyOfValue>::_RotateL(pNode pParent) {
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
template <class K, class V, class KeyOfValue>
bool RBTree<K,V, KeyOfValue>::insert(const V& val) {
	//insert
	//1.When the tree is empty
	if (_header->_parent == nullptr) {
		pNode root = new Node(val);
		_header->_parent = root;
		root->_parent = _header;
		_header->_left = _header->_right = root;

		root->_color = BLACK;
		return true;
	}
	pNode parent = nullptr;
	pNode cur = _header->_parent;
	KeyOfValue kov;
	while (cur) {
		parent = cur;
		if (kov(val) == kov(cur->_val)) return false;
		else if (kov(val) < kov(cur->_val)) cur = cur->_left;
		else cur = cur->_right;
	}
	cur = new Node(val);
	if (kov(parent->_val) > kov(val))
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
template <class K,class T>
class Map {
	struct MapKeyOfValue{
		const K& operator()(const pair<K, T>& val) {
			return val.first;
		}
	};
public:
	bool insert(const pair<K, T>& kv) {
		return _rbt.insert(kv);
	}
	/*T& oprator[](const K& key) {
		bool ret = _rbt.insert(make_pair(key, T()));
	}*/
private:
	typedef RBTree<K, pair<K, T>, MapKeyOfValue> rbt;
	rbt _rbt;
};
template <class K>
class Set {
	struct SetKeyOfValue {
		const K& operator()(const K& val) {
			return val;
		}
	};
public:
	bool insert(const K& val) {
		return _rbt.insert(val);
	}
private:
	typedef RBTree<K, K, SetKeyOfValue> rbt;
	rbt _rbt;
};
void test() {
	Map<int, int >m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(3, 1));
	m.insert(make_pair(4, 1));

	Set<int>s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

}
//void test() {
//	RBTree<int, int >rbt;
//	int arr[9] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	for (int i = 0; i < 9; i++) {
//		rbt.insert(make_pair(arr[i], arr[i]));
//	}
//	rbt._validation();
//}
int main() {
	test();
	return 0;
}
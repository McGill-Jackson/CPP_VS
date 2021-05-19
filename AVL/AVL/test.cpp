#include <iostream>
using namespace std;

template <class T>
struct AVLNode {
	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _bf(0)
	{}
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	T _val;
	//平衡因子
	int _bf;
};
template <class T>
class AVLTree {
	typedef AVLNode<T> Node;
	typedef Node* PNode;
public:
	bool Insert(const T& val);
	void _validation() {
		_inOrder(_root);
		cout << endl;
		cout << _IsBalanceTree(_root) << endl;
	}
private:
	void _RotateL(PNode pParent);
	void _RotateR(PNode pParent);
	void _RotateRL(PNode pParent);
	void _RotateLR(PNode pParent);
	void _inOrder(PNode pParent);
	int _Height(PNode pRoot);
	bool _IsBalanceTree(PNode pRoot);
	PNode _root = nullptr;
};

template <class T>//插入
bool AVLTree<T>::Insert(const T& val) {
	//插入
	if (_root == nullptr) {
		_root = new Node(val);
		return true;
	}
	PNode parent = nullptr;
	PNode cur = _root;
	while (cur) {
		parent = cur;
		if (cur->_val == val)
			return false;
		else if (cur->_val > val)
			cur = cur->_left;
		else
			cur = cur->_right;
	}
	cur = new Node(val);
	if (parent->_val > val)
		parent->_left = cur;
	else
		parent->_right = cur;
	cur->_parent = parent;
	//调整
	while (parent) {
		if (parent->_left == cur)
			--parent->_bf;
		else
			++parent->_bf;
		if (parent->_bf == 0)
			break;
		else if (parent->_bf == 1 || parent->_bf == -1) {
			cur = parent;
			parent = parent->_parent;
		}
		else {
			if (parent->_bf == -2) {
				if (cur->_bf == -1) {
					//左左(右单旋)
					_RotateR(parent);
					break;
				}
				else {
					//左右(先左后右)
					_RotateLR(parent);
					break;
				}
			}
			else {
				if (cur->_bf == 1) {
					//右右(左单旋)
					_RotateL(parent);
					break;
				}
				else {
					//右左(先右后左)
					_RotateRL(parent);
					break;
				}
			}
		}
	}
	return true;
}
template <class T>//右单旋
void AVLTree<T>::_RotateR(PNode pParent) {
	PNode pSubL = pParent->_left;
	PNode pSubLR = pSubL->_right;

	pSubL->_right = pParent;
	pParent->_left = pSubLR;

	if (pSubLR)
		pSubLR->_parent = pParent;
	if (pParent == _root) {
		_root = pSubL;
		pSubL->_parent = nullptr;
	}
	else {
		PNode pParent_p = pParent->_parent;
		if (pParent_p->_left == pParent)
			pParent_p->_left = pSubL;
		else
			pParent_p->_right = pSubL;//
		pSubL->_parent = pParent_p;
	}
	pParent->_parent = pSubL;
	pSubL->_bf = pParent->_bf = 0;
}
template <class T>//左单旋
void AVLTree<T>::_RotateL(PNode pParent) {
	PNode pSubR = pParent->_right;
	PNode pSubRL = pSubR->_left;

	pSubR->_left = pParent;
	pParent->_right = pSubRL;
	if (pSubRL)
		pSubRL->_parent = pParent;
	if (pParent == _root) {
		_root = pSubR;
		pSubR->_parent = nullptr;
	}
	else {
		PNode pParent_p = pParent->_parent;
		if (pParent_p->_left == pParent)
			pParent_p->_left = pSubR;
		else
			pParent_p->_right = pSubR;
		pSubR->_parent = pParent_p;
	}
	pParent->_parent = pSubR;
	pParent->_bf = pSubR->_bf = 0;
}
template <class T>//左右
void AVLTree<T>::_RotateLR(PNode pParent) {
	PNode pSubR = pParent->_left;
	PNode pSubRL = pSubR->_right;

	int bf = pSubRL->_bf;
	_RotateL(pSubR);
	_RotateR(pParent);

	if (bf == 1)
		pSubR->_bf = -1;
	else if (bf == -1)
		pParent->_bf = 1;
}
template <class T>//右左
void AVLTree<T>::_RotateRL(PNode pParent) {
	PNode pSubR = pParent->_right;
	PNode pSubRL = pSubR->_left;

	int bf = pSubRL->_bf;
	_RotateR(pSubR);
	_RotateL(pParent);

	if (bf == 1)
		pParent->_bf = -1;
	else if (bf == -1)
		pSubR->_bf = 1;
}
template <class T>//验证搜索
void AVLTree<T>::_inOrder(PNode pRoot) {
	if (pRoot == nullptr)return;
	_inOrder(pRoot->_left);
	cout << pRoot->_val << " ";
	_inOrder(pRoot->_right);
}
template <class T>//Height
int AVLTree<T>::_Height(PNode pRoot) {
	if (pRoot == nullptr)return 0;
	int left = _Height(pRoot->_left);
	int right = _Height(pRoot->_right);
	if (left == right)return left + 1;
	else if (left > right)return left + 1;
	else return right + 1;
}
template <class T>//is_bf
bool AVLTree<T>::_IsBalanceTree(PNode pRoot) {
	if (pRoot == nullptr)return true;

	int leftHeight = _Height(pRoot->_left);
	int rightHeight = _Height(pRoot->_right);
	int diff = rightHeight - leftHeight;

	if (diff != pRoot->_bf || (diff > 1 || diff < -1))
		return false;

	return _IsBalanceTree(pRoot->_left) && _IsBalanceTree(pRoot->_right);
}
void test() {
	AVLTree<int> avl;
	const int max = 9;
	int ary[max] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < max; i++) {
		avl.Insert(ary[i]);
	}
	avl._validation();
}
int main(){
	test();
	return 0;
}
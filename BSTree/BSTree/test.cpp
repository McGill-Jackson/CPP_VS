#include <iostream>
#include <string>
using namespace std;

template<class K,class V>
struct BSTreeNode {
	BSTreeNode(const K& key = k(),const V& value = V())
		:_pLeft(nullptr),_pRight(nullptr),_key(key),__value(value)
	{}
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	K _key;
	V _value;
};

template<class K, class V>
class BSTree {
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value);
	Node* Find(const K& key);
	boll Erase(const K& key);
	void _InOrder(Node* root);
	void InOrder();
private:
	Node* _root = nullptr;
};

void TestBSTree()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "²åÈë");
	dict.Insert("erase", "É¾³ý");
	dict.Insert("left", "×ó±ß");
	dict.Insert("string", "×Ö·û´®");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "µ¥´ÊÆ´Ð´´íÎó" << endl;
		}
	}
	string strs[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û" };
	// Í³¼ÆË®¹û³öÏÖµÄ´Î
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}
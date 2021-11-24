
#pragma once
namespace bite {
	//My_List的节点类
	template<typename T>
	struct ListNode {
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;

	};
}

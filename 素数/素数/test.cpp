//#include <iostream>
//using namespace std;
//
//class prime {
//public:
//	prime(long max_n =0)
//		:_max_n(max_n)
//	{
//		_prime[4096] = { 0 };
//		creat_ary();
//	}
//	void creat_ary() {
//		int n = 0;
//		for (long i = 11; i < 10000; i+=10) {
//			int flag = 0;
//			for (int j = 2; j * j <= i; j++) {
//				if (i % j == 0 || i % (j + 2) == 0) {
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0) {
//				_prime[n] = i;
//				n++;
//			}
//		}
//	}
//	void Find() {
//		int flag = 0;
//		for (int i = 0; _prime[i] < _max_n; i++) {
//			cout << _prime[i] << " ";
//			flag++;
//		}
//		if (flag == 0) {
//			cout << -1;
//		}
//	}
//private:
//	long _max_n;
//	long _prime[4096];
//};
//
//int main() {
//	long n;
//	while (cin>>n) {
//		prime num(n);
//		num.Find();
//	}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//void findn() {
//	long num = 0;
//	cin >> num;
//	if (num < 0)num = 0 - num;
//	long n[10];
//	for (int i = 0; i < 10; i++) {
//		n[i] = -1;
//	}
//	for (int i = 0; i < 10; i++) {
//		int count = 0;
//		count = num % 10;
//		n[i] = count;
//		num = num / 10;
//		if (num == 0)break;
//	}
//	int count = 0;
//	for (int i = 0; i < 10; i++) {
//		if (n[i] == -1) {
//			break;
//		}
//		count++;
//	}
//	int flag = 0;
//	int j = count - 1;
//	for (int i = 0 ; i < j; i++, j--) {
//		if (n[i] == n[j])continue;
//		else {
//			flag = -1;
//			break;
//		}
//	}
//	if (flag == 0) {
//		cout << "Yes";
//	}
//	else {
//		cout << "NO";
//	}
//}
//
//int main() {
//	findn();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//class XiaoYi {
//public:
//    XiaoYi(int initial = 50, int num = 3)
//        :_initial(initial)
//        , _num(num)
//    {}
//    int exercise() {
//        for (int i = _num; i > 0; i--) {
//            int bi = 0;
//            cin >> bi;
//            if (_initial >= bi) {
//                _initial += bi;
//            }
//            else {
//                _initial += measure(bi, _initial);
//            }
//        }
//        return _initial;
//    }
//    int measure(int x, int y) {
//        int z = y;
//        while (x % y != 0) {
//            z = x % y;
//            x = y;
//            y = z;
//        }
//        return z;
//    }
//protected:
//    int _initial;
//    int _num;
//};
//
//int main() {
//    int initial = 0;
//    int num = 0;
//    while (cin >> num >> initial) {
//        XiaoYi yi(initial, num);
//        cout << yi.exercise() << endl;
//    }
//    return 0;
//}
#include <iostream>
using namespace std;

struct NR_Node {
	NR_Node(char node = 0,int num = 0)
		:_node(node)
		,_num(num)
	{}
	char _node;
	int _num;
};

class NR_string {
	typedef NR_Node node;
public:
	NR_string(int size = 0)
		:_size(size)
	{}

	void first_char(string original) {
		for (int i = 0; i < original.size(); ++i) {
			int j = 0;
			for (; j <= _size; ++j) {
				if (original[i] != _ary[j]._node)
					continue;
				else {
					++_ary[j]._num;
					break;
				}
			}
			if (j > _size) {
				_ary[j]._node = original[i];
				++_ary[j]._num;
				++_size;
			}
		}
		if (_size != 0) {
			int count = 0;
			for (int i = 0; i <= _size; ++i) {
				if (_ary[i]._num == 1) {
					cout << _ary[i]._node;
					++count;
					break;
				}
			}
			if (count == 0) {
				cout << "-1";
			}
			cout << endl;
		}
	}
private:
	node _ary[128];
	int _size;
};

int main() {
	string st;
	while (cin>>st) {
		NR_string s;
		s.first_char(st);
		st.clear();
	}
	return 0;
}
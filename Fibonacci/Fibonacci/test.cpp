#include <iostream>
using namespace std;
class Fibonacci_Atr {
public:
	Fibonacci_Atr(int lift = 1,int right = 2,int new_num = 3)
		:_lift(lift)
		,_right(right)
		,_new_num(new_num)
	{}
	void Padding();
	
	int Finding(long);
private:
	long _atr[50] = {0};
	int _lift;
	int _right;
	int _new_num;
};
void Fibonacci_Atr::Padding() {
	_atr[_lift] = 0;
	_atr[_right] = 1;
	while (1) {
		_atr[_new_num] = _atr[_lift] + _atr[_right];
		if (_atr[_new_num] > 1000000) {
			_atr[_new_num] = 0;
			break;
		}
		_lift++;
		_right++;
		_new_num++;
	}
}
int Fibonacci_Atr::Finding(long num) {
	for (int i = 1; (i < 49) && (_atr[i] < 1000000); i++) {
		if (num > _atr[i])continue;
		if ((_atr[i] - num) > (num - _atr[i - 1]))return num - _atr[i - 1];
		else return _atr[i] - num;
	}
}
void Test() {
	Fibonacci_Atr a;
	a.Padding();
	long num;
	cin >> num;
	int R = a.Finding(num);
	cout << R;
}
int main() {
	Test();
	return 0;
}
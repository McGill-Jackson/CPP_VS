#include <iostream>
using namespace std;
class C_C {
public:
	void Get() {
		cin >> _chr;
	}
	void Put() {
		for (int i = 0; _chr[i] != '\0'&&i<100; i++) {
			int j = 0;
			for (; _col[j] != 0; j++) {
				if (_chr[i] == _col[j]) {
					i++;
					continue;
				}
			}
			_col[j] = _chr[i];
		}

	}

	void Printf() {
		cout << _col;
	}
private:
	char _chr[100] = { 0 };
	char _col[55] = { 0 };
};
void Test() {
	C_C c;
	c.Get();
	c.Put();
	c.Printf();
}
int main() {
	Test();
	return 0;
}
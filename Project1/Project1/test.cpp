#include <iostream>
#include <string>
using namespace std;

void test() {
	string A, B;
	while (cin>>A>>B) {
		int a[100] = { 0 };
		int b[100] = { 0 };
		for (size_t i = 0; i < A.size(); ++i)++a[A[i]];
		for (size_t i = 0; i < B.size(); ++i)++b[B[i]];
		int count = 0;
		for (size_t i = 0; i < 100; ++i) {
			if (a[i] < b[i]) {
				++count;
			}
		}
		if (count == 0)cout << "Yes" << endl;
		else cout << "No" << endl;
		A.clear();
		B.clear();
		continue;
	}

}

int main() {
	test();
	return 0;
}
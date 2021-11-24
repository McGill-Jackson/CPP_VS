#include <iostream>
using namespace std;

class Widget {
public:
	Widget() {};
	Widget f(Widget u) {
		Widget v(u);
		Widget w = v;
		cout << "1" << endl;
		return w;
	}
};

int main() {
	Widget x;
	Widget y = x.f(x.f(x));
	return 0;
}
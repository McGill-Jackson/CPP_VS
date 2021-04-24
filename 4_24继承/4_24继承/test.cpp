#include <iostream>
using namespace std;
class Person {
public:
	void Printf() {
		cout << id << endl;
		cout << _i << endl;
		cout << _age << endl;
		cout << _n << endl;
	}
	static int _n;
protected:
	int _i = 1;
	int _age = 13;
private:
	int id = 10;
};
int Person::_n = 0;
class Student :public Person {

};
void Test() {
	Student stu;
	Person per;
	stu.Printf();
	cout << sizeof(stu) << endl;
	cout << sizeof(per) << endl;

}

int main() {
	Test();
	return 0;
}
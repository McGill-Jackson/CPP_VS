#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
//int& Add(int a, int b) {
//	int c = a + b;
//	return c;
//}
//
//int main() {
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1,2) is :" << ret << endl;
//	return 0;
//}

//class A {
//public:
//	/*A() {
//		_name = 18;
//		_age = 12;
//		_sex = 1;
//	}*/
//
//	/*A (int name = 18, int age = 12, int sex = 1) {
//		_name = name;
//		_age = age;
//		_sex = sex;
//	}*/
//	A (int name, int age, int sex) {
//		_name = name;
//		_age = age;
//		_sex = sex;
//	}
//private:
//	int _name;
//	int _age;
//	int _sex;
//};

//class String {
//public:
//	String(const char* str ="jack") {
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	~String() {
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};

class Data {
public:
	Data(int year = 1990, int mouth = 1,int day = 1) {
		_year = year;
		_mouth = mouth;
		_day = day;
	}

	bool operator==(const Data& d2) {
		return _year == d2._year
			&& _mouth == d2._mouth
			&& _day == d2._day;
	}
private:
	int _year;
	int _mouth;
	int _day;
};

int main() {
	Data d1(2017, 2, 24);
	Data d2(2017, 2, 25);
	cout << (d1 == d2) << endl;

	return 0;
}
#include <iostream>

using namespace std;

//class Date {
//public:
//	Date(int year = 1990,int mouth = 1,int day = 1) {
//		_year = year;
//		_mouth = mouth;
//		_day = day;
//	}
//	void Display() {
//		cout << "Display ( ) " << endl;
//		cout << "year:" << _year << endl;
//		cout << "mouth:" << _mouth << endl;
//		cout << "day:" << _day << endl;
//		Printf();
//	}
//	void Display() const {
//		cout << "Display ( ) " << endl;
//		cout << "year:" << _year << endl;
//		cout << "mouth:" << _mouth << endl;
//		cout << "day:" << _day << endl;
//	}
//	void Printf() const {
//		cout << "Heell" << endl;
//	}
//	void _printf(){
//		cout << "nihao" << endl;
//	}
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//
//void Test() {
//	Date d1;
//	d1.Display();
//	d1.Printf();
//
//	const Date d2;
//	d2.Display();
//}

//class Time {
//public:
//	Time(int hour = 0)
//		:_hour(hour) {
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date {
//public:
//	Date(int day)
//		:_day(day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//void Test() {
//	Date d1(1);
//}
//
//class Date {
//public:
//	Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//void Test() {
//	Date d1(2018);
//
//	d1 = 2019;
//}
//class B {
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//
//	int _b;
//};
//class A {
//public:
//	void Print() {
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//
//void Test() {
//	A a;
//	a.Print();
//}
//class Date {
//	friend	ostream& operator<<(ostream& _cout, const Date& d);
//	friend  istream& operator>>(istream& _cout, Date& d);
//public:
//	Date(int year, int mouth, int day)
//		:_year(year)
//		,_mouth(mouth)
//		,_day(day)
//	{}
//
//	
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d) {
//	_cout << d._year << "-" << d._mouth << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d) {
//	_cin >> d._year;
//	_cin >> d._mouth;
//	_cin >> d._day;
//	return _cin;
//}
//void Test() {
//	Date d(2017, 12, 24);
//	cin >> d;
//	cout << d << endl;
//}
//ÓÑÔªÀà



int main() {
	
	return 0;
}
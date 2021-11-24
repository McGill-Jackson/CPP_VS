#include <iostream>

using namespace std;

class Date {
public:
	//structure
	Date (int year = 1990,int mouth = 1,int day = 1)
		:_year(year)
		,_mouth(mouth)
		,_day(day)
	{}
	//destruction
	~Date()
	{}
	//copy
	Date(const Date& d) {
		_year = d._year;
		_mouth = d._mouth;
		_day = d._day;
	}
	//Gets the number of days in a certain month of a year
	int GetMouthDay(int year, int mouth) {
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[mouth];
		if (mouth == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
			day += 1;
		}
		return day;
	}
	Date& operator=(const Date& d);//
private:
	int _year;
	int _mouth;
	int _day;
};

int main() {

	return 0;
}
//The programming exercise of the second chapter
#include <iostream>

void test_one(void);
void test_two(void);
void test_three(void);
void test_three_one(void);
void test_three_two(void);
void test_four(void);
void test_five(void);
int test_five_one(int);
void test_six(void);
double test_six_one(double);
void test_seven(void);
void test_seven_one(int, int);
int main() {

	//test_one();
	//test_two();
	//test_three();
	//test_four();
	//test_five();
	//test_six();
	test_seven();
	return 0;
}
//Display your name and address
void test_one(void) {
	using std::cout;
	using std::endl;
	cout << "Name :Epic" << endl;
	cout << "Address :China" << endl;
}
//The length of the conversion
void test_two(void) {
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Please enter the distance you want to convert(long) :";
	int length = 0;
	cin >> length;
	length = length * 220;
	cout << "It is equivalent to " << length << " yards.";
}
//functtion definition module
void test_three(void) {
	test_three_one();
	test_three_one();
	test_three_two();
	test_three_two();
}
void test_three_one(void) {
	using std::cout;
	using std::endl;
	cout << "Three blind mice" << endl;
}
void test_three_two(void) {
	using std::cout;
	using std::endl;
	cout << "See how they run" << endl;
}
//display you age(month)
void test_four(void){
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Please enter your age(years) :";
	int age = 0;
	cin >> age;
	age = age * 12;
	cout << "You are " << age << "months old.";
}
//The temperature of the conversion
void test_five(void) {
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Please enter a Celsius value: ";
	int temp_C = 0;
	cin >> temp_C;
	int temp_F = test_five_one(temp_C);
	cout << temp_C << " degrees Celsius is " << temp_F << " degrees Fahrenheit.";
}
int test_five_one(int temp) {
	return 1.8 * temp + 32.0;
}
//Light years away
void test_six(void) {
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Enter the number of light years: ";
	double ly = 0;
	cin >> ly;
	double au = test_six_one(ly);
	cout << ly << " light years  = " << au << " astronomical untis.";
}
double test_six_one(double num) {
	return num * 63240;
}
//Time show
void test_seven(void) {
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Enter the number of hours: ";
	int hours = 0;
	cin >> hours;
	cout << "Enter the number of minutes: ";
	int minutes = 0;
	cin >> minutes;
	test_seven_one(hours, minutes);
}
void test_seven_one(int hours, int minutes) {
	using std::cout;
	using std::endl;
	cout << "Time: " << hours << ":" << minutes << endl;
}
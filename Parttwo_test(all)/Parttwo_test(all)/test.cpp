//The programming exercise of the second chapter
#include <iostream>

void test_one();
void test_two();
void test_three();
void test_three_one();
void test_three_two();
void test_four();
void test_five();
int test_five_one(int);
int main() {

	//test_one();
	//test_two();
	//test_three();
	//test_four();
	test_five();
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

//carrots.cpp -- food processing program
//using and displays a variable
//input and output
#include <iostream>

int main() {
	using namespace std;
	
	int carrots;			//declare an integer variable
	
	cout << "How many carrots do you have?" << endl;
	cin >> carrots; //C++ input
	cout << "Here are two more.";
	carrots = carrots + 2;
	//the next line cancatenates output
	cout << "Now you have " << carrots << "carrots." << endl;
	return 0;
}
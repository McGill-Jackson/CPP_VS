#include <cstdio>
#include <iostream>
using namespace std;
//1.final表示这个类不能再被继承
//2.final表示这个虚函数不能被重写
//class Person {
//public:
//	virtual void BuyTicket() {
//		cout << "买票--全价" << endl;
//	}
//	virtual ~Person() {
//		cout << "~Person()" << endl;
//	}
//};
////override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错
//class Student:public Person {
//public:
//	//重写:子类定义的接口与父类完全相同(返回类型为有继承关系的指针或引用也可)
//	virtual void BuyTicket() {
//		cout << "买票--半价" << endl;
//	}
//
//	//多态析构函数重写
//	virtual ~Student() {
//		cout << "~Student()" << endl;
//	}
//};
//
//void fuc(Person &people) {
//	people.BuyTicket();
//}
//
////void Test() {
////	Person p;
////	Student s;
////	fuc(p);
////	fuc(s);
////}
//void Test() {
//	Person* p = new Person;
//	Person* s = new Student;
//	delete p;
//	delete s;
//}

//class Base {
//public:
//	virtual void Func1() {
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2() {
//		cout << "Func2()" << endl;
//	}
//	void Func3() {
//		cout << "Func3()" << endl;
//	}
//private:
//	int _b1 = 1;
//};
//
//class Derive:public Base {
//public:
//	virtual void Func1() {
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func2() {
//		cout << "Derive::Func2()" << endl;
//	}
//	virtual void Func3() {
//		cout << "Derive::Func3()" << endl;
//	}
//	virtual void Func4() {
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 1;
//};

//void Test() {
//	Base b;
//	Derive d;
//}

class Base1 {
public:
	Base1(int b1 = 1)
		:_b1(b1)
	{}
	virtual void Func1() {
		cout << "Func1()" << endl;
	}
private:
	int _b1;
};
class Base2 {
public:
	Base2(int b2 = 1)
		:_b2(b2)
	{}
	virtual void Func2() {
		cout << "Func2()" << endl;
	}
private:
	int _b2;
};
class Derive :public Base1, public Base2 {
public:
	Derive(int d1 = 1)
		:_d1(d1)
	{}
	virtual void Func1() {
		cout << "Derive::Func1()" << endl;
	}
	virtual void Func3() {
		cout << "Func3()" << endl;
	}
private:
	int _d1;
};
typedef void(*vfptr)();
void printVTable(vfptr vfTable[]) {
	cout << "虚表地址" << vfTable << endl;
	vfptr* fptr = vfTable;
	while (*fptr != nullptr) {
		(*fptr)();
		++fptr;
	}
}
void PrintVTable(vfptr vTable[]) {
	cout << "虚表地址" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i) {
		printf("第%d个虚函数地址 :0x%p\n", i, vTable[i]);
		vfptr f = vTable[i];
		f();
	}
	cout << endl;
}
void Test() {
	Base1 b1;
	Base2 b2;
	Derive d;
	cout << "b1:" << endl;
	vfptr* ptr_b1 = (vfptr*)(*(int*)&b1);
	printVTable(ptr_b1);
	cout << "b2:" << endl;
	vfptr* ptr_b2 = (vfptr*)(*(int*)&b2);
	printVTable(ptr_b2);
	cout << "d:" << endl;
	vfptr* ptr_d = (vfptr*)(*(int*)&d);
	printVTable(ptr_d);
	vfptr* ptr_d2 = (vfptr*)(*(int*)((char*)&d+sizeof(Base1)));
	printVTable(ptr_d2);
}

int main() {
	Test();
	return 0;
}
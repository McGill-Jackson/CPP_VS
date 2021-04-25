#include <cstdio>
#include <iostream>
using namespace std;
//1.final��ʾ����಻���ٱ��̳�
//2.final��ʾ����麯�����ܱ���д
//class Person {
//public:
//	virtual void BuyTicket() {
//		cout << "��Ʊ--ȫ��" << endl;
//	}
//	virtual ~Person() {
//		cout << "~Person()" << endl;
//	}
//};
////override: ����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
//class Student:public Person {
//public:
//	//��д:���ඨ��Ľӿ��븸����ȫ��ͬ(��������Ϊ�м̳й�ϵ��ָ�������Ҳ��)
//	virtual void BuyTicket() {
//		cout << "��Ʊ--���" << endl;
//	}
//
//	//��̬����������д
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
	cout << "����ַ" << vfTable << endl;
	vfptr* fptr = vfTable;
	while (*fptr != nullptr) {
		(*fptr)();
		++fptr;
	}
}
void PrintVTable(vfptr vTable[]) {
	cout << "����ַ" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i) {
		printf("��%d���麯����ַ :0x%p\n", i, vTable[i]);
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
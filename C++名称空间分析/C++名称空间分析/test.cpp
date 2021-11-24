#include <iostream>
#include "namespace.h"
using namespace std;
//namespace Jill {
//	double bucket(double n) { return n; };
//	double fetch;
//	struct Hill { double Thrill; };
//}
//double fetch;
//int main() {
//	using namespace Jill;
//	Hill Thrill;
//		double water = bucket(2);
//	double fetch;
//	cin >> fetch;
//	cin >> ::fetch;
//	cin >> Jill::fetch;
//	return 0;
//}实验阶段

//struct Hill {	//结构体声明
//	int maple;
//	int poplar;
//};
namespace orchard {
	double apple;	//变量声明
	int pair;		//变量声明
	void mark();	//函数原型
	struct Wall {	//结构体声明
		int stone;
		double cement;
	};
}
namespace farm {
	double apple;	//变量声明
	int corn;		//变量声明
	double bucket(double n) { return n; };//函数声明
	struct Hill {	//结构体声明
		int stone;
		int tree;
	};
}
namespace farm {
	int sheep;		//变量声明
}
namespace orchard {
	void mark() {	//函数定义
		apple = apple / 4;
	}
}
//char apple;
//int main() {
//	using farm::apple;	//将apple添加到main定义的声明区域中
//	cin >> apple;		//在farm::apple中写值
//	cin >> ::apple;		//在全局名称空间的apple中写值
//	return 0;
//}using声明局部阶段
//void other(char& apple);			//函数原型
//using farm::apple;		//将apple添加到全局名称空间中
//int main() {
//	char apple;			//局部变量apple
//	cin >> apple;		//在局部变量apple中写值
//	cin >> ::apple;		//在farm::apple中写值
//	other(apple);
//	return 0;
//}
//void other(char& apple) {
//	cout << apple << endl;		//打印局部变量apple
//	cout << ::apple << endl;	//打印farm::apple
//}
//namespace element {		//外部名称空间
//	namespace fire {		//内部名称空间
//		int flame;
//	}
//	float water;
//}//名称空间嵌套
//namespace myth {			//我的名称空间
//	using farm::apple;
//	using namespace element;
//	using std::cout;
//	using std::cin;
//}//名称空间写入using
//namespace MF = myth::fire;	//建立别名
//using MF::flame;						//直接使用别名

char apple;			//全局名称空间
int main() {
	//using namespace farm;	//导入所有名称
	//double apple;			//局部apple,会隐藏farm::apple
	//cin >> apple;			//向局部apple中写值
	//cin >> ::apple;			//向全局apple中写值
	//cin >> farm::apple;		//向farm::apple中写值
	ice = 2;
	cout << ice;
	return 0;
}


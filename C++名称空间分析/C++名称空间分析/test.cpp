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
//}ʵ��׶�

//struct Hill {	//�ṹ������
//	int maple;
//	int poplar;
//};
namespace orchard {
	double apple;	//��������
	int pair;		//��������
	void mark();	//����ԭ��
	struct Wall {	//�ṹ������
		int stone;
		double cement;
	};
}
namespace farm {
	double apple;	//��������
	int corn;		//��������
	double bucket(double n) { return n; };//��������
	struct Hill {	//�ṹ������
		int stone;
		int tree;
	};
}
namespace farm {
	int sheep;		//��������
}
namespace orchard {
	void mark() {	//��������
		apple = apple / 4;
	}
}
//char apple;
//int main() {
//	using farm::apple;	//��apple��ӵ�main���������������
//	cin >> apple;		//��farm::apple��дֵ
//	cin >> ::apple;		//��ȫ�����ƿռ��apple��дֵ
//	return 0;
//}using�����ֲ��׶�
//void other(char& apple);			//����ԭ��
//using farm::apple;		//��apple��ӵ�ȫ�����ƿռ���
//int main() {
//	char apple;			//�ֲ�����apple
//	cin >> apple;		//�ھֲ�����apple��дֵ
//	cin >> ::apple;		//��farm::apple��дֵ
//	other(apple);
//	return 0;
//}
//void other(char& apple) {
//	cout << apple << endl;		//��ӡ�ֲ�����apple
//	cout << ::apple << endl;	//��ӡfarm::apple
//}
//namespace element {		//�ⲿ���ƿռ�
//	namespace fire {		//�ڲ����ƿռ�
//		int flame;
//	}
//	float water;
//}//���ƿռ�Ƕ��
//namespace myth {			//�ҵ����ƿռ�
//	using farm::apple;
//	using namespace element;
//	using std::cout;
//	using std::cin;
//}//���ƿռ�д��using
//namespace MF = myth::fire;	//��������
//using MF::flame;						//ֱ��ʹ�ñ���

char apple;			//ȫ�����ƿռ�
int main() {
	//using namespace farm;	//������������
	//double apple;			//�ֲ�apple,������farm::apple
	//cin >> apple;			//��ֲ�apple��дֵ
	//cin >> ::apple;			//��ȫ��apple��дֵ
	//cin >> farm::apple;		//��farm::apple��дֵ
	ice = 2;
	cout << ice;
	return 0;
}


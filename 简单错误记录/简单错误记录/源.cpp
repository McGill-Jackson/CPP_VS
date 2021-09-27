/*���ӣ�https://www.nowcoder.com/questionTerminal/67df1d7889cf4c529576383c2e647c48?f=discussion
��Դ��ţ����

����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����:
1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��
��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
	�ļ�·��Ϊwindows��ʽ
	�磺E:\V1R2\product\fpgadrive.c 1325
�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325
	���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������
	�������8����¼����ֻ���ǰ8����¼.
	����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�
*/
/*����˼·
�ۺ���ĿҪ������,������Ҫһ�����Ա�Ľṹ���洢ÿһ�������¼,���ڴ����¼֮����Ҫ˳��,�Ҵ�˳�򻹻�
��Ϊ����ļ�¼��ȡ�����������仯,����ѡ�����������д洢,�������ÿһ�����������ļ���,����,�������,
ǰ����ĵ�ַ�Լ���һ�γ��ֵ�˳��.
*/

#include <iostream>
#include <string>
using namespace std;
//���
struct RecordNode {
	string _name;
	size_t _row;
	size_t _count;
	RecordNode* _next;
	RecordNode* _front;
	size_t _serial;
	RecordNode(string name = "", size_t row = 0, size_t count = 0, RecordNode* next = nullptr, RecordNode* front = nullptr, size_t serial = 0)
		:_name(name)
		, _row(row)
		, _count(count)
		, _next(next)
		, _front(front)
		, _serial(serial)
	{}
};
//����(��ͷ���)
class FileRecord {
	typedef RecordNode rn;
	typedef rn* prn;
public:
	FileRecord()
		:_header(new rn)
	{}

	void Recive() {
		string name;
		size_t serial = 0;
		while (getline(cin, name)) {
			size_t row = 0;
			if (name.length() == 0)
				break;
			prn cur = _header;
			//Ѱ��·���ַ����е������ؼ�λ��
			size_t pos = name.rfind('\\');
			size_t pos2 = name.rfind(' ');
			int i = 0;
			//���ַ�����ʽ������ת��Ϊ���͸�ʽ������
			while (isdigit(name.substr(pos2 + 1, name.size() - pos2 + 1)[i]))
			{
				row = row * 10 + (name.substr(pos2 + 1, name.size() - pos2 + 1)[i] - '0');
				i++;
			}
			while (cur) {
				if ((cur->_name == name.substr(pos + 1, pos2 - (pos + 1))) && (cur->_row == row)) {
					++cur->_count;
					//�������½�����ַ������һ�������ȫ��ͬ,���ý����������,��Ϊ��һ�������
					//����ǵ�һ�����ļ������,�ټ�����һ������ı�������.
					if (cur->_front == _header)break;
					while ((cur->_count == cur->_front->_count && cur->_serial < cur->_front->_serial) || cur->_count > cur->_front->_count) {
						prn q = cur->_front;
						prn p = cur;
						if (q->_front == nullptr)break;
						q->_front->_next = p;
						p->_front = q->_front;
						if (p->_next != nullptr)
							p->_next->_front = q;
						q->_next = p->_next;
						p->_next = q;
						q->_front = p;
					}
					break;
				}
				//�������¼������ʱ,��û���ҵ�����ַ�����ͬ�ĵļ�¼,�򴴽�һ���µĽ��
				if (cur->_next == nullptr) {
					++serial;
					prn node = new rn(name.substr(pos + 1, pos2 - (pos + 1)), row, 1);
					node->_serial = serial;
					cur->_next = node;
					node->_front = cur;
					break;
				}
				cur = cur->_next;
			}
		}
		Print();
	}
	int Print() {
		prn cur = _header->_next;
		size_t count = 8;
		while (count && cur) {
			if (cur->_name.size() > 16)
				cout << cur->_name.substr(cur->_name.size() - 16) << " " << cur->_row << " " << cur->_count << endl;
			else cout << cur->_name << " " << cur->_row << " " << cur->_count << endl;
			cur = cur->_next;
			--count;
		}
		return 0;
	}
private:
	prn _header;
};

int main() {
	FileRecord a;
	a.Recive();
	return 0;
}
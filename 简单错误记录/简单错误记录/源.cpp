/*链接：https://www.nowcoder.com/questionTerminal/67df1d7889cf4c529576383c2e647c48?f=discussion
来源：牛客网

开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径
输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
	文件路径为windows格式
	如：E:\V1R2\product\fpgadrive.c 1325
输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325
	结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
	如果超过8条记录，则只输出前8条记录.
	如果文件名的长度超过16个字符，则只输出后16个字符
*/
/*解题思路
综合题目要求来看,我们需要一个线性表的结构来存储每一个错误记录,由于错误记录之间需要顺序,且此顺序还会
因为更多的记录读取进来而发生变化,所以选择链表来进行存储,而链表的每一个结点包含了文件名,行数,错误计数,
前后结点的地址以及第一次出现的顺序.
*/

#include <iostream>
#include <string>
using namespace std;
//结点
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
//链表(有头结点)
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
			//寻找路径字符串中的两个关键位置
			size_t pos = name.rfind('\\');
			size_t pos2 = name.rfind(' ');
			int i = 0;
			//将字符串格式的数字转化为整型格式的数字
			while (isdigit(name.substr(pos2 + 1, name.size() - pos2 + 1)[i]))
			{
				row = row * 10 + (name.substr(pos2 + 1, name.size() - pos2 + 1)[i] - '0');
				i++;
			}
			while (cur) {
				if ((cur->_name == name.substr(pos + 1, pos2 - (pos + 1))) && (cur->_row == row)) {
					++cur->_count;
					//如果这个新进入的字符串与第一个结点完全相同,则不用进行排序操作,因为上一次排序的
					//结果是第一个结点的计数最多,再计数加一并不会改变这个结果.
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
				//当错误记录遍历完时,还没有找到与此字符串相同的的记录,则创建一个新的结点
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
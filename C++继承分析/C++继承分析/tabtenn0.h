// tabtenn0.h -- a table-tennis base class
#ifndef TABTHNN0_H_			//�Ȳ���TABTHNN0_H_�Ƿ񱻺궨���
#define TABTHNN0_H_			//���û�б��궨���,����
#include <string>
using std::string;
//simple base class
class TableTennisPlayer {
private:
	string _firstname;
	string _lastname;
	bool _hasTable;
public:
	TableTennisPlayer(const string& fn = "none", const string& ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return _hasTable; };
	void ResetTable(bool v) { _hasTable = v; };
};
#endif						//����Ѿ������,����������

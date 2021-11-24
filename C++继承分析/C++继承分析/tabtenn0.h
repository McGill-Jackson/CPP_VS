// tabtenn0.h -- a table-tennis base class
#ifndef TABTHNN0_H_			//先测试TABTHNN0_H_是否被宏定义过
#define TABTHNN0_H_			//如果没有被宏定义过,则定义
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
#endif						//如果已经定义过,则向下运行

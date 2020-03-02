#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm> // for_each 批量删除账户
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
#include "Account.h"
#include "date.h"
// #include"Array.h"

struct deleter {// 该结构体在传递给for_each可以对一定区间的指针进行删除
	template <class T> void operator () (T* p) { delete p; }
};

class Controller {	//控制器，用来储存账户列表和处理命令
private:
	Date date;					//当前日期
	vector<Account *> accounts;	//账户列表
	bool end;					//用户是否输入了退出命令

public:
	Controller(const Date &date) : date(date), end(false) { }
	~Controller();
	const Date &getDate() const { return date; }
	bool isEnd() const { return end; }
	//执行一条命名，返回该命令是否改变了当前状态（即是否需要保存该命令）
	bool runCommand(const string &cmdLine);
};
Controller::~Controller() {
	for_each(accounts.begin(), accounts.end(), deleter());
}
bool Controller::runCommand(const string &cmdLine) {
	istringstream str(cmdLine);
	char cmd, type;
	int index, day;
	double amount, credit, rate, fee;
	string id, desc;
	Account* account;
	Date date1, date2;

	str >> cmd;
	switch (cmd) {
	case 'a':	//增加账户
		str >> type >> id;
		if (type == 's') {
			str >> rate;
			account = new SavingsAccount(date, id, rate);
		}
		else {
			str >> credit >> rate >> fee;
			account = new CreditAccount(date, id, credit, rate, fee);
		}
		accounts.push_back(account);
		return true;
	case 'd':	//存入现金
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->deposit(date, amount, desc);
		return true;
	case 'w':	//取出现金
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->withdraw(date, amount, desc);
		return true;
	case 's':	//查询各账户信息
		for (size_t i = 0; i < accounts.size(); i++)
			cout << "[" << i << "] " << *accounts[i] << endl;
		return false; // 查询账户信息的指令不需要保存
	case 'c':	//改变日期
		str >> day;
		if (day < date.getDay())
			cout << "You cannot specify a previous day";
		else if (day > date.getMaxDay())
			cout << "Invalid day";
		else
			date = Date(date.getYear(), date.getMonth(), day);
		return true;
	case 'n':	//进入下个月
		if (date.getMonth() == 12)
			date = Date(date.getYear() + 1, 1, 1);
		else
			date = Date(date.getYear(), date.getMonth() + 1, 1);
		for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
			(*iter)->settle(date);
		return true;
	case 'q':	//查询一段时间内的账目
		str >> date1 >> date2;
		Account::query(date1, date2);
		return false;
	case 'e':	//退出
		end = true;
		return false;
	}
	cout << "Inavlid command: " << cmdLine << endl;
	return false;
}


int main(){
    Date date(2008, 11, 1);
	/*
	SavingsAccount sa1(date, "S03755217", 0.015);
	SavingsAccount sa2(date, "S02342342", 0.015);
	CreditAccount ca(date, "C04237348", 10000, 0.0005, 50);
	Account *accounts[] = { &sa1, &sa2, &ca };
	const int n = sizeof(accounts)/sizeof(Account*);*/

	// Array<Account *> accounts(0);	//创建账户数组，元素个数为0，动态分配

	/*vector<Account *> accounts(0);
	cout << "(a)add new account (d)deposit (w)withdraw (s)show (c)change day (n)next mouth (q)query (e)exit" << endl;*/

	//char cmd;
	//do{
	//	date.show();
	//	cout << "\tTotal: " << Account::getTotal() << "\tCommand>";
	//	int index, day;
	//	double amount, rate, credit, fee;
	//	string desc, id;
	//	char type;
	//	Account* account;
	//	Date date1, date2;
	//	cin >> cmd;
	//	switch (cmd){
	//	case 'a':
	//		cin >> type >> id;
	//		if (type=='s'){
	//			cin >> rate;
	//			account = new SavingsAccount(date, id, rate);
	//		}else {
	//			cin >> credit >> rate >> fee;
	//			account = new CreditAccount(date, id, credit, rate, fee);
	//		}
	//		/*accounts.resize(accounts.getSize() + 1);
	//		accounts[accounts.getSize() - 1] = account;*/
	//		accounts.push_back(account); // vector动态添加
	//		break;
	//	case 'd':
	//		cin >> index >> amount;
	//		getline(cin, desc);
	//		accounts[index]->deposit(date, amount, desc);
	//		break;
	//	case 'w':
	//		cin >> index >> amount;
	//		getline(cin, desc);
	//		accounts[index]->withdraw(date, amount, desc);
	//		break;
	//	case 's':
	//		for (size_t i = 0; i < accounts.size(); i++){
	//			cout << "[" << i << "] ";
	//			accounts[i]->show();
	//			cout << endl;
	//		}
	//		break;
	//	case 'c':
	//		cin >> day;
	//		if (day < date.getDay())
	//			cout << "you can not specify a privious day";
	//		else if (day > date.getMaxDay())
	//			cout << "invalid day";
	//		else
	//			date = Date(date.getYear(), date.getMonth(), day);
	//		break;
	//	case 'n':
	//		if (date.getMonth() == 12)
	//			date = Date(date.getYear() + 1, 1, 1);
	//		else
	//			date = Date(date.getYear(), date.getMonth() + 1, 1);
	//		for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
	//			(*iter)->settle(date); // 迭代器记录
	//		break;
	//	case 'q':	//查询一段时间内的账目
	//		date1 = Date::read();
	//		date2 = Date::read();
	//		Account::query(date1, date2);
	//		break;
	//	}
	//} while (cmd != 'e');
	//
	//for_each(accounts.begin(), accounts.end(), deleter());

	/*for (int i = 0; i < accounts.getSize(); i++)
		delete accounts[i];*/


	// IOstream
	Controller controller(date);
	string cmdLine;
	const char *FILE_NAME = "commands.txt";
	ifstream fileIn(FILE_NAME);	//以读模式打开文件
	if (fileIn) {	//如果正常打开，就执行文件中的每一条命令
		while (getline(fileIn, cmdLine))
			controller.runCommand(cmdLine);
		fileIn.close();	//关闭文件
	}

	ofstream fileOut(FILE_NAME, ios_base::app);	//以追加模式
	cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;
	while (!controller.isEnd()) {	//从标准输入读入命令并执行，直到退出
		cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand> ";
		string cmdLine;
		getline(cin, cmdLine);
		if (controller.runCommand(cmdLine))
			fileOut << cmdLine << endl;	//将命令写入文件
	}

    
    return 0;
}

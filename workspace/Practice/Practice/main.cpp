#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm> // for_each 批量删除账户
#include<vector>
using namespace std;
#include "Account.h"
#include "date.h"
// #include"Array.h"

struct deleter {// 该结构体在传递给for_each可以对一定区间的指针进行删除
	template <class T> void operator () (T* p) { delete p; }
};


int main(){
    Date date(2008, 11, 1);
	/*
	SavingsAccount sa1(date, "S03755217", 0.015);
	SavingsAccount sa2(date, "S02342342", 0.015);
	CreditAccount ca(date, "C04237348", 10000, 0.0005, 50);
	Account *accounts[] = { &sa1, &sa2, &ca };
	const int n = sizeof(accounts)/sizeof(Account*);*/

	// Array<Account *> accounts(0);	//创建账户数组，元素个数为0，动态分配

	vector<Account *> accounts(0);
	cout << "(a)add new account (d)deposit (w)withdraw (s)show (c)change day (n)next mouth (q)query (e)exit" << endl;

	char cmd;
	do{
		date.show();
		cout << "\tTotal: " << Account::getTotal() << "\tCommand>";
		int index, day;
		double amount, rate, credit, fee;
		string desc, id;
		char type;
		Account* account;
		Date date1, date2;

		cin >> cmd;
		switch (cmd){
		case 'a':
			cin >> type >> id;
			if (type=='s'){
				cin >> rate;
				account = new SavingsAccount(date, id, rate);
			}else {
				cin >> credit >> rate >> fee;
				account = new CreditAccount(date, id, credit, rate, fee);
			}
			/*accounts.resize(accounts.getSize() + 1);
			accounts[accounts.getSize() - 1] = account;*/
			accounts.push_back(account); // vector动态添加
			break;
		case 'd':
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->deposit(date, amount, desc);
			break;
		case 'w':
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->withdraw(date, amount, desc);
			break;
		case 's':
			for (size_t i = 0; i < accounts.size(); i++){
				cout << "[" << i << "] ";
				accounts[i]->show();
				cout << endl;
			}
			break;
		case 'c':
			cin >> day;
			if (day < date.getDay())
				cout << "you can not specify a privious day";
			else if (day > date.getMaxDay())
				cout << "invalid day";
			else
				date = Date(date.getYear(), date.getMonth(), day);
			break;
		case 'n':
			if (date.getMonth() == 12)
				date = Date(date.getYear() + 1, 1, 1);
			else
				date = Date(date.getYear(), date.getMonth() + 1, 1);
			for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
				(*iter)->settle(date); // 迭代器记录
			break;
		case 'q':	//查询一段时间内的账目
			date1 = Date::read();
			date2 = Date::read();
			Account::query(date1, date2);
			break;
		}
	} while (cmd != 'e');
	
	for_each(accounts.begin(), accounts.end(), deleter());

	/*for (int i = 0; i < accounts.getSize(); i++)
		delete accounts[i];*/
    
    return 0;
}

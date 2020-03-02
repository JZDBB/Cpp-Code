#include<iostream>
#include <utility> //通过函数模板对任意数据类型重载了"<="，">", ">="等运算符，转换为通过"<"的调用
#include <cmath>
using namespace std;
using namespace std::rel_ops;//rel_ops重载两个关系操作符便可以得到6个，同时避免冲突
#include "date.h"
#include "Account.h"
#include"Accumulator.h"


AccountRecord::AccountRecord(const Date &date, const Account *account, double amount, double balance, const std::string& desc)
	: date(date), account(account), amount(amount), balance(balance), desc(desc) {
}

AccountRecord::~AccountRecord()
{
}

void AccountRecord::show() const {
	date.show();
	cout << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}


double Account::total = 0;
RecordMap Account::recordMap;

Account::Account(const Date &date, const string &id):id(id), balance(0)
{
	date.show();
	cout << "\t#" << id << "  created" << endl;
}

Account::~Account()
{
}

void Account::show() const
{
	cout << id << "\tBalance: " << balance;
}

void Account::deposit(const Date & date, double amount, const std::string & desc)
{
}

void Account::withdraw(const Date & date, double amount, const std::string & desc)
{
}

void Account::settle(const Date & date)
{
}

void Account::query(const Date & begin, const Date & end){
	if (begin <= end) { // 多重映射上限和下限得到历史账目
		RecordMap::iterator iter1 = recordMap.lower_bound(begin);
		RecordMap::iterator iter2 = recordMap.upper_bound(end);
		for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
			iter->second.show();
	}
}

void Account::record(const Date &date, double amount, const std::string & desc)
{
	amount = floor(amount * 100 + 0.5) / 100;	//保留小数点后两位
	balance += amount;
	total += amount;
	AccountRecord record(date, this, amount, balance, desc);
	recordMap.insert(make_pair(date, record));
	record.show();
}

void Account::error(const std::string & msg) const
{
	cout << "Error(#" << id << "):" << msg << endl;
}


// 储蓄账户

SavingsAccount::SavingsAccount(const Date& date, const string &id, double rate):Account(date, id), rate(rate), acc(date, 0) { }

SavingsAccount::~SavingsAccount()
{
}

void SavingsAccount::deposit(const Date& date, double amount, const std::string & desc)
{
	record(date, amount, desc);
	acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date& date, double amount, const string &desc)
{
	if (amount > getBalance()) {
		error("not enough money");
	}
	else {
		record(date, -amount, desc);
		acc.change(date, getBalance());
	}
}

void SavingsAccount::settle(const Date& date)
{
	double interest = acc.getSum(date) * rate	//计算年息
		/ (date - Date(date.getYear() - 1, 1, 1));
	if (interest != 0)
		record(date, interest, "interest");
	acc.reset(date, getBalance());
}

void SavingsAccount::show() const
{
	Account::show();
}


// 信用卡
CreditAccount::CreditAccount(const Date &date, const string& id, double credit, double rate,
	double fee):Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0){}

CreditAccount::~CreditAccount()
{
}


double CreditAccount::getAvailableCredit() const
{
	if (getBalance() < 0)
		return credit + getBalance();
	else
		return credit;
}

void CreditAccount::deposit(const Date &date, double amount, const std::string & desc)
{
	record(date, amount, desc);
	acc.change(date, getBalance());
}

void CreditAccount::withdraw(const Date &date, double amount, const std::string & desc)
{
	if (amount - getBalance() > credit) {
		error("not enough credit");
	}
	else {
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}

void CreditAccount::settle(const Date &date)
{
	double interest = acc.getSum(date) * rate;
	if (interest != 0)
		record(date, interest, "interest");
	if (date.getMonth() == 1)
		record(date, -fee, "annual fee");
	acc.reset(date, getDebt());
}

void CreditAccount::show() const
{
	Account::show();
	cout << "\tAvailable Credit:" << getAvailableCredit();
}




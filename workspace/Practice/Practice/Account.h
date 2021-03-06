#pragma once
#include<string>
#include"Accumulator.h"
#include"date.h"
#include<map>
#include <istream>
#include<string>
#include<stdexcept>

class Account;

class AccountRecord { // 账目记录
public:
	AccountRecord(const Date &date, const Account *account, double amount, double balance, const std::string& desc);
	~AccountRecord();
	void show() const;

private:
	Date date;
	const Account *account;
	double amount;
	double balance;
	std::string desc;
};

typedef std::multimap<Date, AccountRecord> RecordMap;

class Account{
public:
	~Account();
	const std::string &getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	virtual void show(std::ostream &out) const;
	// 虚函数声明用以子类调用
	virtual void deposit(const Date& date, double amount, const std::string &desc) = 0;
	virtual void withdraw(const Date& date, double amount, const std::string &desc) = 0; //取出现金
	virtual void settle(const Date &date) = 0;
	static void query(const Date& begin, const Date& end);

private:
	std::string id;
	double balance;
	static double total;
	static RecordMap recordMap;	//账目记录

protected: // 便于派生类访问调用
	Account(const Date &date, const std::string &id);
	void record(const Date &date, double amount, const std::string &desc);
	void error(const std::string &msg)const;
};

inline std::ostream & operator << (std::ostream &out, const Account &account) {
	account.show(out);
	return out;
}

// 储蓄卡类
class SavingsAccount: public Account{
public:
	SavingsAccount(const Date& date, const string &id, double rate);
	~SavingsAccount();
	virtual void deposit(const Date& date, double amount, const std::string &desc); //存入现金
	virtual void withdraw(const Date& date, double amount, const std::string &desc); //取出现金
	//结算利息，每年1月1日调用一次该函数
	virtual void settle(const Date &date);
	virtual void show(std::ostream &out) const;

private:
	Accumulator acc;
	double rate;
};


// 信用卡类
class CreditAccount: public Account{
public:
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);
	~CreditAccount();
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const;
	virtual void deposit(const Date &date, double amount, const std::string &desc); //存入现金
	virtual void withdraw(const Date &date, double amount, const std::string &desc); //取出现金
	//结算利息，每年1月1日调用一次该函数
	virtual void settle(const Date &date);
	virtual void show(std::ostream &out) const;

private:
	Accumulator acc;
	double credit; // 信用额度
	double rate; //日利率
	double fee; // 年费

	double getDebt() const {	//获得欠款额
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
};

class AccountException : public std::runtime_error {
private:
	const Account *account;
public:
	AccountException(const Account *account, const std::string &msg)
		: runtime_error(msg), account(account) { }
	const Account *getAccount() const { return account; }
};

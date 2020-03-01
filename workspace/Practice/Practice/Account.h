#pragma once
#include<string>
#include"Accumulator.h"
class Account{
public:
	~Account();
	const std::string &getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	void show() const;
	// 虚函数声明用以子类调用
	virtual void deposit(const Date& date, double amount, const std::string &desc);
	virtual void withdraw(const Date& date, double amount, const std::string &desc); //取出现金
	virtual void settle(const Date &date);

private:
	std::string id;
	double balance;
	static double total;

protected: // 便于派生类访问调用
	Account(const Date &date, const std::string &id);
	void record(const Date &date, double amount, const std::string &desc);
	void error(const std::string &msg)const;
};


// 储蓄卡类
class SavingsAccount: public Account{
public:
	SavingsAccount(const Date& date, const string &id, double rate);
	~SavingsAccount();
	void deposit(const Date& date, double amount, const std::string &desc); //存入现金
	void withdraw(const Date& date, double amount, const std::string &desc); //取出现金
	//结算利息，每年1月1日调用一次该函数
	void settle(const Date &date);
	void show() const;

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
	void deposit(const Date &date, double amount, const std::string &desc); //存入现金
	void withdraw(const Date &date, double amount, const std::string &desc); //取出现金
	//结算利息，每年1月1日调用一次该函数
	void settle(const Date &date);
	void show() const;

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

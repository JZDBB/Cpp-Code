#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
#include "Account.h"
#include "date.hpp"


int main(){
    Date date(2008, 11, 1);

	SavingsAccount sa1(date, "S03755217", 0.015);
	SavingsAccount sa2(date, "S02342342", 0.015);
	CreditAccount ca(date, "C04237348", 10000, 0.0005, 50);
	Account *accounts[] = { &sa1, &sa2, &ca };
	const int n = sizeof(accounts)/sizeof(Account*);

	cout << "(d)deposit (w)withdraw (s)show (c)change day (n)next mouth (e)exit" << endl;

	char cmd;
	do
	{
		date.show();
		cout << "\tTotal: " << Account::getTotal() << "\tCommand>";
		int index, day;
		double amount;
		string desc;

		cin >> cmd;
		switch (cmd){
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
				for (int i = 0; i < n; i++){
					cout << "[" << i << "]";
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
				break;
		}


	} while (cmd != 'e');
    
    return 0;
}

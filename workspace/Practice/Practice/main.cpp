#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#include "Account.h"
#include "date.hpp"


int main(){
    Date date(2008, 11, 1);

	SavingsAccount sa1(date, "S03755217", 0.015);
	SavingsAccount sa2(date, "S02342342", 0.015);
	CreditAccount ca(date, "C04237348", 10000, 0.0005, 50);
    
    sa1.deposit(Date(2008, 11, 5), 5000, "salary");
    ca.withdraw(Date(2008, 11, 15), 2000, "buy a cell");
	sa2.deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
	ca.settle(Date(2008, 12, 1));
	ca.deposit(Date(2008, 12, 1), 2016, "repay the credit");
	sa1.deposit(Date(2008, 12, 5), 5500, "salary");
	sa1.settle(Date(2009, 1, 1));
	sa2.settle(Date(2009, 1, 1));
	ca.settle(Date(2009, 1, 1));

	cout << endl;
	sa1.show(); cout << endl;
	sa2.show(); cout << endl;
	ca.show(); cout << endl;
	cout << "Total: " << Account::getTotal() << endl;
    
    return 0;
}

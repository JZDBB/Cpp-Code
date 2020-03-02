#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#include "date.h"

namespace
{
    const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365 };
}
Date::Date()
{
}
Date::Date(int year, int month, int day) :year(year), month(month), day(day) {
    if (day <= 0 || day > getMaxDay())
		throw runtime_error("Invalid date");
    int years = year - 1;
    totalDays = year * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
    if (isLeapYear() && month > 2) totalDays++;
}
Date Date::read(){
	int year, month, day;
	char c1, c2;
	cin >> year >> c1 >> month >> c2 >> day;
	return Date(year, month, day);
}

int Date::getMaxDay()const {
    if (isLeapYear() && month == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}
void Date::show() const {
    cout << getYear() <<"-"<< getMonth() <<"-"<< getDay();
}

// 重载<<和>>方便输入输出，同时返回为引用，方便连续使用
istream & operator >> (istream &in, Date &date) {
	int year, month, day;
	char c1, c2;
	in >> year >> c1 >> month >> c2 >> day;
	date = Date(year, month, day);
	return in;
}

ostream & operator << (ostream &out, const Date &date) {
	out << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return out;
}
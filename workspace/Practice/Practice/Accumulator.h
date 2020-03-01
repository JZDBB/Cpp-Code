#pragma once
#include"date.hpp"
class Accumulator
{
public:
	Accumulator(const Date &date, double value);
	~Accumulator();
	double getSum(const Date &date);
	void change(const Date &date, double value);
	void reset(const Date &date, double value);

private:
	Date lastDate;
	double value;
	double sum;
};


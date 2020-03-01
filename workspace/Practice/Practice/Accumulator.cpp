#include "Accumulator.h"



Accumulator::Accumulator(const Date &date, double value):lastDate(date), value(value), sum(0){}

Accumulator::~Accumulator(){}

double Accumulator::getSum(const Date &date){
	return sum + value * date.distance(lastDate);
}

void Accumulator::change(const Date &date, double value){
	sum = getSum(date);
	lastDate = date;
	this->value = value;

}

void Accumulator::reset(const Date &date, double value){
	sum = 0;
	lastDate = date;
	this->value = value;
}

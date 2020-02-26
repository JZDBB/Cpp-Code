#include "Clock.h"
#include<iostream>
using namespace std;

//Clock::Clock() : hour(0), minute(0), second(0){}
Clock::Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS)
{
}


Clock::~Clock()
{
}

void Clock::showTime() const{
	cout << hour << ":" << minute << ":" << second << endl;
}

void Clock::setTime(int newH, int newM, int newS) {
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60) {
		this->hour = newH;
		this->minute = newM;
		this->second = newS;
	}
	else
	{
		cout << "Time error!" << endl;
	}		
}


Clock & Clock::operator ++ () { // 返回当前对象的引用，是一个左值
	second++;
	if (second>=60)
	{
		second -= 60;
		minute++;
		if (minute>=60)
		{
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
Clock Clock::operator ++ (int) {
	Clock old = *this;
	++(*this); // 调用前置运算，前置和后置运算统一
	return old;
}

// 前置和后置的区别可以看出
// 前置使用的是自身的值参与return运算                            ——返回左值
// 后置是使用的自身加一之前的副本，事实上本身的数已经加一了。    ——返回右值

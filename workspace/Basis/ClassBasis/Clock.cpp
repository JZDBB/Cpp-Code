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

void Clock::showTime(){
	cout << hour << ":" << minute << ":" << second << endl;
}

void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}

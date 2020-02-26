#pragma once
#ifndef COMPLEX_H_
#define COMPLEX_H_

class Clock
{
public:
	void setTime(int newH, int newM, int newS);
	void showTime() const;
	// Clock() = default;
	Clock(int newH, int newM, int newS);
	Clock & operator ++ ();// 前置重载
	Clock operator ++ (int); // 后置重载 int只是用来区分前置和后置
	~Clock();
private:
	int hour, minute, second;
};


#endif // !COMPLEX_H_
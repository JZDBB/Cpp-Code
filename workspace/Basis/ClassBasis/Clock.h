#pragma once
class Clock
{
public:
	void setTime(int newH, int newM, int newS);
	void showTime();
	// Clock() = default;
	Clock(int newH, int newM, int newS);
	~Clock();
private:
	int hour, minute, second;
};


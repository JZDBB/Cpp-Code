#pragma once
class IntNum
{
public:
	IntNum();
	IntNum(int x);
	IntNum(const IntNum& n);
	IntNum(IntNum && n);
	~IntNum();
	int getInt();
private:
	int *xptr;
};


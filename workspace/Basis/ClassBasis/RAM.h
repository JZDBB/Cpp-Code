#pragma once
#include<iostream>
using namespace std;
enum RAM_Rank { DDR4, DDR3, DDR2, DDR1 };
class RAM {
private:
	int volume;
	RAM_Rank rrank;
	int rfrequency;
public:
	RAM(RAM_Rank r, int f, float v);
	RAM();
	~RAM();

	//数据接口 （为啥要有const）
	RAM_Rank GetrRank()const;
	int GetrFrequency()const;
	float GetVolume()const;

	void setrRank(RAM_Rank r);
	void setrFrequency(int f);
	void setVolume(float v);

	void run();
	void stop();
};


#include "RAM.h"
#include<iostream>
using namespace std;

RAM::RAM(RAM_Rank r, int f, float v) { rrank = r; rfrequency = f; volume = v; cout << "构造了一个RAM\n"; }
RAM::RAM() {};
RAM::~RAM() { cout << "析构了一个RAM\n"; };

//数据接口 （为啥要有const）
RAM_Rank RAM::GetrRank()const { return rrank; };
int RAM::GetrFrequency()const { return rfrequency; }
float RAM::GetVolume()const { return volume; }

void RAM::setrRank(RAM_Rank r) { rrank = r; }
void RAM::setrFrequency(int f) { rfrequency = f; }
void RAM::setVolume(float v) { volume = v; }

void RAM::run() { cout << "RAM begin!\n"; };
void RAM::stop() { cout << "RAM stop!\n"; };

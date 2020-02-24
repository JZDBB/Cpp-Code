#include "CPU.h"
#include<iostream>
using namespace std;


CPU::CPU(CPU_Rank r, int f, float v) { rank = r; frequency = f; voltage = v; cout << "构造了一个CPU\n"; }
CPU::CPU(CPU &cc) { rank = cc.rank; frequency = cc.frequency; voltage = cc.voltage; cout << " 拷贝构造了一次\n"; }
CPU::CPU(){}
CPU::~CPU() { cout << "析构了一个CPU\n"; };

CPU_Rank CPU::GetRank()const { return rank; };
int CPU::GetFrequency()const { return frequency; }
float CPU::GetVoltage()const { return voltage; }

void CPU::setRank(CPU_Rank r) { rank = r; }
void CPU::setFrequency(int f) { frequency = f; }
void CPU::setVoltage(float v) { voltage = v; }

void CPU::run() { cout << "CPU begin!\n"; };
void CPU::stop() { cout << "CPU stop!\n"; };
#pragma once

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
class CPU {
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	CPU(CPU_Rank r, int f, float v);
	CPU(CPU &cc);
	CPU();
	~CPU();

	//数据接口
	CPU_Rank GetRank()const;
	int GetFrequency()const;
	float GetVoltage()const;

	void setRank(CPU_Rank r);
	void setFrequency(int f);
	void setVoltage(float v);

	void run();
	void stop();

};


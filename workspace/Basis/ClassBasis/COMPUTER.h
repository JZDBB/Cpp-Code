#pragma once
#include<iostream>
using namespace std;

#include"CPU.h"
#include"RAM.h"
#include"CDROM.h"


class COMPUTER {
private:
	CPU my_cpu;
	RAM my_ram;
	CDROM my_cdrom;
	unsigned int storage_size;
	unsigned int bandwidth;

public:
	COMPUTER(CPU c, RAM r, CDROM cr, unsigned int s, unsigned int b);
	~COMPUTER();
	void Run();
	void Stop();
};



#include "COMPUTER.h"


COMPUTER::COMPUTER(CPU c, RAM r, CDROM cr, unsigned int s, unsigned int b) :my_cpu(c), my_ram(r), my_cdrom(cr) {
	storage_size = s;
	bandwidth = b;
	cout << "构造了一个computer ～\n";
}


COMPUTER::~COMPUTER()
{
}

void COMPUTER::Run() {
	my_cpu.run(); my_ram.run(); my_cdrom.run();
	cout << "COMPUTER  begin!\n";
}
void COMPUTER::Stop() {
	my_cpu.stop(); my_ram.stop(); my_cdrom.stop();
	cout << "COMPUTER  stop!\n";
}

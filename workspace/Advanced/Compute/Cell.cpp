#include "Cell.h"


const int SPLIT_TIME_MIN = 500;
const int SPLIT_TIME_MAX = 2000;

priority_queue<Cell> cellQueue;
int Cell::count = 0;

Cell::Cell(int birth):id(count++) {

	time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
}

int Cell::getId() const
{
	return id;
}

int Cell::getSplitTime() const
{
	return time;
}

bool Cell::operator<(const Cell & s) const
{
	return time > s.time;
}

void Cell::split() const
{
	Cell child1(time), child2(time);
	cout << time << "s: Cell #" << id << " splits to #"
		<< child1.getId() << " and #" << child2.getId() << endl;
	cellQueue.push(child1);
	cellQueue.push(child2);
}

Cell::~Cell()
{
}


#include "Cell.h"
#include<iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;



Cell::Cell(int birth):id(count++) {	//birth为细胞诞生时间
	//初始化，确定细胞分裂时间
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
	Cell child1(time), child2(time);	//建立两个子细胞
	cout << time << "s: Cell #" << id << " splits to #"
		<< child1.getId() << " and #" << child2.getId() << endl;
	cellQueue.push(child1);	//将第一个子细胞压入优先级队列
	cellQueue.push(child2);	//将第二个子细胞压入优先级队列
}

Cell::~Cell()
{
}


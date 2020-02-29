#pragma once
#ifndef CELL_H_
#define CELL_H_
#include <queue>
#include<iostream>
using namespace std;

class Cell;
extern priority_queue<Cell> cellQueue;

class Cell {
private:
	static int count;	//总数
	int id;		//编号
	int time;	//分裂时间
public:
	Cell(int birth);
	int getId() const;	
	int getSplitTime() const;	
	bool operator < (const Cell& s) const;	
	void split() const;
	~Cell();
};

#endif // !CELL_H_
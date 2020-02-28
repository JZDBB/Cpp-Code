#pragma once

const int SPLIT_TIME_MIN = 500;		//细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000;	//细胞分裂最长时间

class Cell;
priority_queue<Cell> cellQueue;

class Cell {	//细胞类
private:
	static int count;	//细胞总数
	int id;		//当前细胞编号
	int time;	//细胞分裂时间
public:
	Cell(int birth);
	int getId() const;	//得到细胞编号
	int getSplitTime() const;	//得到细胞分裂时间
	bool operator < (const Cell& s) const;	//定义“<”

	//细胞分裂
	void split() const;
	~Cell();
};
int Cell::count = 0;


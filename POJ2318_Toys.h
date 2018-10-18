#pragma once
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
class pointer{
public:
	int x;
	int y;
	pointer() : x(0), y(0) {}
	pointer(int a, int b) : x(a),  y(b)  {}
	pointer& operator =(const pointer& p) {
		x = p.x;
		y = p.y;
		return *this;
	}
};
class line {
public:
	pointer st;
	pointer en;
	int xmin;
	int xmax;
	line() {
		st = pointer();
		en = pointer();
		xmin = 0;
		xmax = 0;
	}
	line(pointer start, pointer end) : st(start), en(end), xmin(std::min(start.x, end.x)), xmax(std::max(start.x, end.x)) {}
};
class POJ2318_Toys
{
public:
	POJ2318_Toys();
	~POJ2318_Toys();
	int n, m;
	vector<pointer> LU, RD;
	//对于这种在类里面的头文件中定义的vector，若想声明vector的大小，不能在头文件中声明，可以现在头文件中声明，然后去构造函数中用resize()指明情况，
	vector<vector<line>>  porlines;
	vector<vector<pointer>> toypointers;
	bool in();
	bool left(line l,pointer p);
	int judge(pointer p, vector<line> porlines);
	void doing();
};


#pragma once
#ifndef COORDINATE_H
#define COORDINATE_H
#include<ostream>
using namespace std;


class Coordinate
{
	
public:
	friend ostream &operator<<(ostream &out, Coordinate &coor);		//重载输出运算符
	Coordinate(int x=0, int y=0);	//在构造时要进行初始化，不赋初值将会报错
	void printCoordinate();
	bool operator==(Coordinate &coor);
private:
	int m_iX;
	int m_iY;
};

#endif
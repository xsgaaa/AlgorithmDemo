#include"Coordinate.h"
#include<iostream>
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
	cout << endl;
}

ostream &operator<<(ostream &out, Coordinate &coor)
{
	out << "(" <<coor.m_iX << "," <<coor.m_iY << ")" << endl;
	return out;
}

bool Coordinate::operator==(Coordinate &coor)		//重载==号，以进行两个量的逻辑运算
{
	if (this->m_iX == coor.m_iX &&this->m_iY == coor.m_iY)
	{
		return true;
	}
	return false;
}
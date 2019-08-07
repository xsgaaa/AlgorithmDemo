#include"MyGraph.h"
#include<iostream>
using namespace std;

#define INFINITY 65535		// 用65535来代表无穷大

MyGraph::MyGraph(int n,int e,bool f)
{
	numVertexes = n;
	numEdges = e;
	flag = f;
	for (int i = 0; i < this->numVertexes; i++)
	{
		for (int j = 0; j < this->numVertexes; j++)
		{
			this->arc[i][j] = INFINITY;			// 邻接矩阵初始化
		}
	}
}

void MyGraph::CreateGraph()
{
	int i,j, w;
	cout << "请依次输入顶点：" << endl;
	for (int k = 0; k < this->numVertexes; i++)
	{
		cin >> vexs[k];
	}
	cout << "请输入边(Vi,Vj)上的下标i,下标j和对应的权w: " << endl;
	for (int k = 0; k < this->numEdges; k++)
	{
		cin >> i >> j >> w;
		if (!flag)
		{
			this->arc[i][j] = w;
			this->arc[j][i] = w;
		}
		else
		{
			this->arc[i][j] = w;
		}
	}
}
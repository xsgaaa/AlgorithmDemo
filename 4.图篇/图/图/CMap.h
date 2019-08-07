#pragma once
#ifndef CMAP_H
#define CMAP_H
#include"Node.h"
#include<vector>
using namespace std;

class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);		//向图中添加顶点（节点）
	void resetNode();				//重置顶点
	bool setValueToMatrixForDirectGraph(int row, int col, int val = 1);		//为有向图设置邻接矩阵     行，列，值
	bool setValueToMatrixForUndirectGraph(int row, int col, int val = 1);	//为无向图设置邻接矩阵

	void printMatrix();		//打印邻接矩阵

	void depthFirstTraverse(int nodeIndex);		//深度优先遍历
	void breathFirstTraverse(int nodeIndex);	//广度优先遍历

private:
	bool getValueFromMatrix(int row, int col, int &val);	//从矩阵中获取权值
	void breathFirstTraverseImpl(vector<int> preVec);		//广度优先遍历实现函数
private:
	int m_iCapacity;		//图中最多容纳的顶点数
	int m_iNodeCount;		//已添加的顶点的个数
	Node *m_pNodeArray;		//用来存放顶点数组
	int *m_pMatrix;			//用来存放邻接矩阵
};

#endif
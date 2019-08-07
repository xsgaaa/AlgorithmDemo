#pragma once
#ifndef CMAP_H
#define CMAP_H
#include"Node.h"
#include"Edge.h"
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

	void kruskalTree();							//克鲁斯卡尔算法生成树

private:
	bool getValueFromMatrix(int row, int col, int &val);	//从矩阵中获取权值

	int getMinEdge(vector<Edge> edgeVec);
	bool isInSet(vector<int>nodeSet, int target);
	void mergeNodeSet(vector<int> &nodeSetA, vector<int> &nodeSetB);
private:
	int m_iCapacity;		//图中最多容纳的顶点数
	int m_iNodeCount;		//已添加的顶点的个数
	Node *m_pNodeArray;		//用来存放顶点数组
	int *m_pMatrix;			//用来存放邻接矩阵

	Edge *m_pEdge;			//定义存放最小边的指针
};

#endif
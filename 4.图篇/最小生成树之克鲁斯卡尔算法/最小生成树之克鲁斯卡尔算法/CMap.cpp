#include"CMap.h"
#include<iostream>
#include<vector>
using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity*m_iCapacity];	//用一维矩阵来表示邻接矩阵（二维矩阵）
	//memset(m_pMatrix, 0, m_iCapacity*m_iCapacity*sizeof(int));	//memset将邻接矩阵初始化为0
	for (int i = 0; i < m_iCapacity*m_iCapacity; i++)
	{
		m_pMatrix[i] = 0;
	}

	m_pEdge = new Edge[m_iCapacity - 1];		//最小生成树的边的个数为点的个数减一
}

CMap::~CMap()
{
	delete[]m_pNodeArray;
	delete[]m_pMatrix;
	delete[]m_pEdge;
}

bool CMap::addNode(Node *pNode)
{
	if (pNode == NULL)
	{
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;	//传入数据
	m_iNodeCount++;		//结点个数加1
	return true;
}

void CMap::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectGraph(int row, int col, int val)	//函数实现这里不需要再写int val=1，否则会报错
{
	if (row < 0 && row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 && col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row*m_iCapacity + col] = val;		//有向图矩阵不沿对角线对称
	return true;
}

bool CMap::setValueToMatrixForUndirectGraph(int row, int col, int val)
{
	if (row < 0 && row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 && col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row*m_iCapacity + col] = val;
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}


bool CMap::getValueFromMatrix(int row, int col, int &val)	//获取弧的值
{
	if (row < 0 && row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 && col >= m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}

void CMap::printMatrix()		//打印邻接矩阵
{
	for (int i = 0; i < m_iCapacity; i++)		//行
	{
		for (int k = 0; k < m_iCapacity; k++)	//列
		{
			cout << m_pMatrix[i*m_iCapacity + k] << " ";
		}
		cout << endl;		//每行回车
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;			//定义最小权值
	int edgeIndex = 0;			//定义边的索引
	int i = 0;					//定义计数变量

	//找到第一条未被选择的边
	for (; i < (int)edgeVec.size(); i++)
	{
		if (!edgeVec[i].m_bSelected)
		{
			minWeight = edgeVec[i].m_iWeightValue;		//获取权值
			edgeIndex = i;								//获取边的索引
			break;										//找到之后立刻跳出for循环
		}
	}

	
	if (minWeight == 0)
	{
		return -1;
	}

	//找到最小边的索引
	for (; i < (int)edgeVec.size(); i++)
	{
		if (edgeVec[i].m_bSelected)
		{
			continue;
		}
		else
		{
			if (minWeight > edgeVec[i].m_iWeightValue)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}

	return edgeIndex;	//返回最小边的索引
}

//克鲁斯卡尔算法生成树
void CMap::kruskalTree()
{
	int value = 0;			//存放权值
	int edgeCount = 0;		//存放生成树中边的个数

	//定义存放节点集合的数组
	vector<vector<int>> nodeSets;		//相当于一个二维数组

	//第一步取出所有边
	vector<Edge> edgeVec;	

	for (int i = 0; i < m_iCapacity; i++)		//对称矩阵，取出所有右上方的边
	{
		for (int k = i + 1; k < m_iCapacity; k++)
		{
			getValueFromMatrix(i, k, value);
			if (value != 0)
			{
				Edge edge(i, k, value);
				edgeVec.push_back(edge);
			}
		}
	}

	//第二步：从所有边中取出组成最小生成树的边
	//1.找到算法结束条件
	while (edgeCount < m_iCapacity - 1)
	{

		//2.从边集合中找到最小边
		int minEdgeIndex=getMinEdge(edgeVec);		//获得最小边
		edgeVec[minEdgeIndex].m_bSelected = true;	//将最小边置为已选

		//3.找出最小边连接的点
		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;		//获取最小边的两个顶点
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;		//获取最小边的两个顶点

		bool nodeAIsInSet = false;				//点A是否在点集合中的标志
		bool nodeBIsInSet = false;				//点B是否在点集合中的标志

		int nodeAInSetLabel = -1;				//点A所在的集合的索引
		int nodeBInSetLabel = -1;				//点B所在的集合的索引

		//4.找出点所在的点集合
		for (int i = 0; i < (int)nodeSets.size(); i++)
		{
			nodeAIsInSet=isInSet(nodeSets[i], nodeAIndex);	//判断点A是否在点集合中
			if (nodeAIsInSet)	
			{
				nodeAInSetLabel = i;						//获取A所在的点集合的索引
			}
		}

		for (int i = 0; i < (int)nodeSets.size(); i++)
		{
			nodeBIsInSet = isInSet(nodeSets[i], nodeBIndex);//判断点B是否在点集合中
			if (nodeBIsInSet)
			{
				nodeBInSetLabel = i;						//获取B所在的点集合的索引
			}
		}

		//5.根据点所在集合的不同做出不同的处理
		if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)	//A与B都不在点集合中
		{
			vector<int> vec;
			vec.push_back(nodeAIndex);						//将A和B都存在到点集合中
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);						//点集合存到点数组中
		}
		else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1)	//只有A不在点集合中
		{
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);		//将A存到B所在的点集合中
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1)	//只有B不在点集合中
		{
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);		//将B存到A所在的点集合中
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)		//如果A和B都在点集合中，且不是同一个点集合
		{
			mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);			//将B所在的点集合合并到A所在的点集合中
			for (int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1; k++)			//删除B所在的点集合
			{
				nodeSets[k] = nodeSets[k + 1];
			}
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)   //如果A和B都在点集合中，在同一个点集合中
		{
			continue;			//构成回路，继续循环
		}

		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];			//将最小边添加到生成树中
		edgeCount++;										//生产树中的边数加1

		cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "--" << edgeVec[minEdgeIndex].m_iNodeIndexB << " ";		//输出边和权值
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int>nodeSet, int target)		//判断点是否在点集合中
{
	for (int i = 0; i <(int)nodeSet.size(); i++)
	{
		if (nodeSet[i] == target)
		{
			return true;
		}
	}
	return false;
}

void CMap::mergeNodeSet(vector<int> &nodeSetA, vector<int> &nodeSetB)	//合并点集合
{
	for (int i = 0; i <(int)nodeSetB.size(); i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}
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

//普里姆生成树
void CMap::primTree(int nodeIndex)
{
	int value = 0;				//用于取边
	int edgeCount=0;			//最小生成树中已选择的边数
	vector<int> nodeVec;		//点的集合
	vector<Edge> edgeVec;		//边的集合，边的数量没有限制

	cout << m_pNodeArray[nodeIndex].m_cData << endl;	//输出当前结点的数据

	nodeVec.push_back(nodeIndex);						//将当前结点存入点集合
	m_pNodeArray[nodeIndex].m_bIsVisited = true;		//将当前结点置为已访问

	//获取所有的待选边
	while (edgeCount < m_iCapacity - 1)					//边数等于点数减1，结束循环
	{
		int temp = nodeVec.back();						//取出尾部结点

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(temp, i, value);			//得到弧的权值
			if (value != 0)								//如果权值不为0
			{
				if (m_pNodeArray[i].m_bIsVisited)		//判断结点 i 是否已访问过
				{
					continue;							//继续循环，找下一个结点
				}
				else
				{
					Edge edge(temp, i, value);			//定义边
					edgeVec.push_back(edge);			//将边添加到待选边中
				}
			}
		}
		
		//从可选边集合中找出最小边
		int edgeIndex=getMinEdge(edgeVec);				//找出最短边的索引
		edgeVec[edgeIndex].m_bSelected = true;			//将边置为以选择

		cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB << " ";		//输出结点和边
		cout << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount] = edgeVec[edgeIndex];		//将边存入最小生成树的边集合中
		edgeCount++;									//最小生成树的边集合中边的数目加1

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;	//获取最小边中的另一个节点的索引

		nodeVec.push_back(nextNodeIndex);						//将点的索引加入到点集合中
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;		//将点置为已访问
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;			//定义最小权值
	int edgeIndex = 0;			//定义边的索引
	int i = 0;					//定义计数变量

	//找到第一条未被选择的边
	for (; i < edgeVec.size(); i++)
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
	for (; i < edgeVec.size(); i++)
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
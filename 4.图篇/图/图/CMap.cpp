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

//深度优先遍历
void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;										//存储弧的值
	cout << m_pNodeArray[nodeIndex].m_cData << " ";		//访问当前节点
	m_pNodeArray[nodeIndex].m_bIsVisited = true;		//将当前节点标识置为已访问

	for (int i = 0; i < m_iCapacity; i++)				//遍历与当前节点所连接的节点
	{
		getValueFromMatrix(nodeIndex, i, value);		//获取弧的值
		if (value == 1)									//节点与当前结点相连
		{
			if (m_pNodeArray[i].m_bIsVisited == true)	//节点是否访问过
			{
				continue;								//继续循环，找下个节点
			}
			else
			{
				depthFirstTraverse(i);					//对当前找到的节点进行深度优先遍历
			}
		}
		else
		{
			continue;									//与当前节点不相连，继续寻找下一个节点
		}
	}
}

//广度优先遍历
void CMap::breathFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";		//访问当前节点
	m_pNodeArray[nodeIndex].m_bIsVisited = true;		//将标识置为已访问

	vector<int>curVec;									//定义数组用于存储每一层得到的节点
	curVec.push_back(nodeIndex);						//将当前节点加入到数组中

	breathFirstTraverseImpl(curVec);					//调用深度优先搜索的实施函数
}

void CMap::breathFirstTraverseImpl(vector<int> preVec)
{
	int value=0;										//存储弧的值
	vector<int>curVec;									//定义数组用于存储每一层得到的节点
	for (int j = 0; j < (int)preVec.size(); j++)		//遍历前一层所有的节点
	{
		for (int i = 0; i < m_iCapacity;i++)			//找与当前节点相连的节点
		{
			getValueFromMatrix(preVec[j], i, value);	//获取弧的值
			if (value != 0)								//与当前节点相连
			{
				if (m_pNodeArray[i].m_bIsVisited == true)//判断是否访问过
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[i].m_cData << " ";//访问节点的数据
					m_pNodeArray[i].m_bIsVisited = true;	//将节点置为已访问
					curVec.push_back(i);					//将节点添加到储存层节点的数组中
				}
			}
		}
	}
	if (curVec.size() == 0)									//判断动态数组中是否还有元素
	{
		return;												//没有元素，返回
	}
	else
	{
		breathFirstTraverseImpl(curVec);					//有元素，继续递归调用
	}
}
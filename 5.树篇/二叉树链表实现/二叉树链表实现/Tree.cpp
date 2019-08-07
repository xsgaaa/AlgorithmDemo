#include"Tree.h"
#include<iostream>


Tree::Tree()
{
	m_pRoot = new Node();	//初始化根节点
}

Tree::~Tree()
{
	//DeleteNode(0, NULL);		//删除所有的节点
	m_pRoot->DeleteNode();		//会删除所有以根节点为父节点的所有节点
}
Node *Tree::SearchNode(int nodeIndex)
{
	 return m_pRoot->SearchNode(nodeIndex);		//调用节点的成员函数，进行搜索
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	//1.搜索父节点
	Node *temp = SearchNode(nodeIndex);		//先找到要添加根节点
	if (temp == NULL)						//没有找到节点
	{
		return false;			//返回错误
	}
	//2.定义新节点
	Node *node = new Node();	//定义一个新结点
	if (node == NULL)			//申请内存失败
	{
		return false;
	}
	//3.传递节点数据和索引
	node->index = pNode->index;	//传递索引
	node->data = pNode->data;	//传递数据
	node->pParent = temp;		//传递父指针
	//4.确定指针的指向
	if (direction == 0)			//direction为0，插入的是左孩子
	{
		temp->pLChild = node;	
	}
	if (direction == 1)			//direction为1，插入的是右孩子
	{
		temp->pRChild = node;
	}
	return true;				//添加节点成功
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	//1.搜索要删除的节点
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	//2.判断传入的顶点是否有效，决定是否将数据传递出去
	if (pNode != NULL)		//如果节点不为NULL，将数据传给节点
	{
		pNode->data = temp->data;
	}
	//3.删除节点
	temp->DeleteNode();
	return true;
}

void Tree::PreprderTraversal()
{
	m_pRoot->PreprderTraversal();
}

void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}
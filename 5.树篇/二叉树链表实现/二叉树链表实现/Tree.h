#pragma once
#ifndef TREE_H
#define TREE_H
#include"Node.h"


class Tree
{
public:
	Tree();							//构造函数
	~Tree();						//析构函数
	Node *SearchNode(int nodeIndex);	//搜索节点
	bool AddNode(int nodeIndex, int direction, Node *pNode);	//增加节点(索引、左/右、要增加的节点的指针)
	bool DeleteNode(int nodeIndex, Node *pNode);		//删除节点(索引、节点数据)
	void PreprderTraversal();	//前序遍历
	void InorderTraversal();	//中序遍历
	void PostorderTraversal();	//后序遍历
private:
	Node *m_pRoot;				//定义根节点
};





#endif
#pragma once

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	Node *SearchNode(int nodeIndex);		//搜索节点
	void DeleteNode();						//删除节点
	void PreprderTraversal();				//前序遍历
	void InorderTraversal();				//中序遍历
	void PostorderTraversal();				//后序遍历
public:
	int index;		//索引
	int data;		//存储的数据
	Node *pLChild;	//左孩子的指针
	Node *pRChild;	//右孩子的指针
	Node *pParent;	//父节点的指针
};


#endif
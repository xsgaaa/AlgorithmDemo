#include"Node.h"
#include<iostream>
using namespace std;
Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}
Node *Node::SearchNode(int nodeIndex)	//搜索节点，使用了递归算法
{
	//1.比较当前结点的索引
	if (this->index == nodeIndex)		//如果此节点的索引等于要查询的索引，则返回
	{
		return this;
	}
	//2.定义临时的节点
	Node *temp = NULL;		//定义一个变量，用于存储子节点找到的结果
	//3.比较当前结点左孩子的索引
	if (this->pLChild != NULL)			//如果左孩子存在
	{
		if (this->pLChild->index == nodeIndex)	//判断左节点的索引是否与要查询的索引一致
		{
			return this->pLChild;
		}
		else
		{
			temp= this->pLChild->SearchNode(nodeIndex);		//如果不一致，继续以左孩子为根，进行查找
			if (temp != NULL)
			{
				return temp;			//查找结果存在，则返回
			}
		}
	}
	//3.比较当前结点右孩子的索引
	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp=this->pRChild->SearchNode(nodeIndex);
			return temp;
		}
	}
	return NULL;
}

void Node::DeleteNode()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();	//删除当前结点的左孩子
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();	//删除当前结点的右孩子
	}
	
	if (this->pParent != NULL)			//当前结点存在父节点
	{
		if (this->pParent->pLChild == this)		//判断当前结点是父指针的左孩子
		{
			this->pParent->pLChild = NULL;		//将父指针的左孩子置为NULl
		}
		if (this->pParent->pRChild == this)		//判断当前结点是父指针的左孩子
		{
			this->pParent->pRChild = NULL;
		}
	}
	delete this;								//删除当前结点自身

}

void Node::PreprderTraversal()		//前序遍历
{
	cout << this->index<<"--------"<<this->data << endl;		//访问根节点
	if (this->pLChild != NULL)									//访问左节点
	{
		this->pLChild->PreprderTraversal();
	}
	if (this->pRChild != NULL)									//访问右节点
	{
		this->pRChild->PreprderTraversal();
	}
}

void Node::InorderTraversal()
{
	if (this->pLChild != NULL)									//访问左节点
	{
		this->pLChild->InorderTraversal();
	}
	cout << this ->index << "--------" << this->data << endl;	//访问根节点
	if (this->pRChild != NULL)									//访问右节点
	{
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();		
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	cout << this->index << "--------" << this->data << endl;
}
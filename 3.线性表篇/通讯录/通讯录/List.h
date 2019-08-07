#pragma once
#ifndef LIST_H
#define LIST_H
#include"Node.h"

class List
{
public:
	List();
	~List();				//类中含有this指针，无需再传其他参数
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node *pNode);
	int LocateElem(Node *pNode);
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);
	bool NextElem(Node *pCurrentNode, Node *pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node *pNode);
	bool ListDelete(int i, Node *pNode);
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);
private:
	Node *m_pList;
	int m_iLength;
};









#endif
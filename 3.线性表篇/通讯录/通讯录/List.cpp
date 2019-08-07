#include"List.h"
#include<iostream>
using namespace std;

List::List()
{
	m_pList = new Node;		//创建头结点
	//m_pList->data = 0;	//头结点数据域赋值为0，没有意义		
	m_pList->next = NULL;	//头结点指针域赋初值为NULL
	m_iLength = 0;			//头结点不算在链表长度之中
}

List::~List()				//删除所有结点
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList()		//保留头结点
{

	Node *currentNode = m_pList->next;
	while (currentNode != NULL)			//审讯当前的犯人
	{
		Node *temp = currentNode->next;	//找到下家
		delete currentNode;				//删除上家
		currentNode = temp;				//以前的下家变成上家
	}
	m_pList->next = NULL;
}

bool List::ListEmpty()		//C语言没有bool类型，大写的BOOL是人为的宏定义
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
		return false;
	//return m_iLength==0? true:false
}

int List::ListLength()
{
	return m_iLength;
}

bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;

	//堆中申请内存，如果在栈中申请内存，函数运行完之后，内存将会被回收
	Node *newNode = new Node;		
	if (newNode == NULL)		//申请内存失败，返回错误
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}
bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;

	//1.获取尾指针
	while (currentNode->next != NULL)		
	{
		currentNode = currentNode->next;
	}
	//2.建立新结点
	Node *newNode = new Node;
	if (newNode == NULL)		//堆中申请内存失败，返回错误
	{
		return false;
	}
	//3.传递数据
	newNode->data = pNode->data;
	//4.使新结点变成尾结点
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}


bool List::ListInsert(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}
	Node*currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	Node *newNode = new Node;
	if (newNode == NULL)		//堆中申请内存失败，返回错误
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListDelete(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)	//如果i等于m_iLength，那么删除尾结点的下一个结点，这是不可能的
	{
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::GetElem(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)	//如果i等于m_iLength，那么删除尾结点的下一个结点，这是不可能的
	{
		return false;
	}
	Node *currentNode = m_pList;
	for (int k = 0; k <= i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}
int List::LocateElem(Node *pNode)
{
	int count=0;
	Node *currentNode = m_pList;
	while (currentNode->next!=NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;				//保留当前结点的前一个结点
		currentNode = currentNode->next;	//使当前结点指向下一个结点
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)		//当前结点是头结点后面的一个结点，头结点不能返回数据域
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;

	while (currentNode->next != NULL)
	{			
		currentNode = currentNode->next;	//使当前结点指向下一个结点
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next==NULL)		//当前结点是最后结点，没有后继
			{
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}
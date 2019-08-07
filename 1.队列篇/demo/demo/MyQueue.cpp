#include"MyQueue.h"
#include<iostream> 
using namespace std;
MyQueue::MyQueue(int queueCapacity)
{
	m_iQqueueCapacity = queueCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	m_pQueue = new Customer[m_iQqueueCapacity];
}
MyQueue::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue = NULL;
}
void MyQueue::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty()const
{
	if (m_iQueueLen == 0)
	{
		return true;
	}
	else
		return false;
	// return m_iQueueLen==0？true：false
	//使用三目运算符
}

int MyQueue::QueueLength()const
{
	return m_iQueueLen;
}

bool MyQueue::QueueFull()const
{
	if (m_iQueueLen == m_iQqueueCapacity)
		return true;
	else
		return false;
}

bool MyQueue::EnQueue(Customer element)
{
	if (QueueFull())
		return false;
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail%m_iQqueueCapacity;
		m_iQueueLen++;
		return true;
	}
}

bool MyQueue::DeQueue(Customer &element)
{
	if (QueueEmpty())
		return false;
	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iHead = m_iHead%m_iQqueueCapacity;
	m_iQueueLen--;
	return true;

}

void MyQueue::QueueTraverse()
{
	cout << endl;
	for (int i = m_iHead; i < m_iQueueLen+ m_iHead; i++)
	{
		m_pQueue[i%m_iQqueueCapacity].printfInfo();
		cout << "前面还有" << (i - m_iHead) << "人" << endl;

	}
	cout << endl;
}
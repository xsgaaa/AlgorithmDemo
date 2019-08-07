#include"Node.h"

Node::Node(char data)
{
	m_cData = data;
	m_bIsVisited = false;		//默认false代表没有被访问过
}
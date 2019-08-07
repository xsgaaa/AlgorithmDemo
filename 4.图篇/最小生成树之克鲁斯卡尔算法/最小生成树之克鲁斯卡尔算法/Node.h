#pragma once
#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node(char data = 0);
public:
	char m_cData;		//数据值
	bool m_bIsVisited;	//标识是否被访问过
};

#endif
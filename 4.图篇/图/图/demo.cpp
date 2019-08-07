#include<iostream>
#include<stdio.h>

#include"CMap.h"
using namespace std;

/*
	图的存储 :邻接矩阵
	图的遍历：深度优先搜索、广度优先搜索

			A
		  /	  \
		 B     D
	   /  \  /  \
	  C    FG -  H
	   \  /
	    E

*/
int main()
{
	CMap *pMap = new CMap(8);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');
	
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);

	pMap->setValueToMatrixForUndirectGraph(0, 1);
	pMap->setValueToMatrixForUndirectGraph(0, 3);
	pMap->setValueToMatrixForUndirectGraph(1, 2);
	pMap->setValueToMatrixForUndirectGraph(1, 5);
	pMap->setValueToMatrixForUndirectGraph(3, 6);
	pMap->setValueToMatrixForUndirectGraph(3, 7);
	pMap->setValueToMatrixForUndirectGraph(6, 7);
	pMap->setValueToMatrixForUndirectGraph(2, 4);
	pMap->setValueToMatrixForUndirectGraph(4, 5);

	pMap->printMatrix();

	cout << endl;

	pMap->depthFirstTraverse(0);
	cout << endl;

	pMap->resetNode();
	pMap->breathFirstTraverse(0);


	system("pause");
	return 0;
}
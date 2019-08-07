#include<iostream>
#include"CMap.h"
#include"Edge.h"
/*

	最小生成树之克鲁斯卡尔：

	核心思想：
	1. 将图中的所有边都去掉；

	2. 将边按权值从小到大的顺序添加到图中，保证添加的过程中不会形成环 ；

	3. 重复上一步直到连接所有顶点，此时就生成了最小生成树。这是一种贪心策略。
		

	图：

			A
		 /  |  \
		B - F - E
		 \ /  \	/
		  C - D

	编号：

	A B C D E F 
	0 1 2 3 4 5

	弧及其权值：

	A-B  6		A-E  5		A-F  1
	B-C  3		B-F  2
	C-F  8		C-D  7
	D-F  4      D-E  2
	E-F  9

	类的关系说明：

	CMap	用到Node类
			用到Edge类
	Node类和Edge类没有继承关系，通过索引来进行联系

*/

int main()
{
	CMap *pMap = new CMap(6);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	pMap->setValueToMatrixForUndirectGraph(0, 1, 6);
	pMap->setValueToMatrixForUndirectGraph(0, 4, 5);
	pMap->setValueToMatrixForUndirectGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectGraph(1, 2, 3);
	pMap->setValueToMatrixForUndirectGraph(1, 5, 2);
	pMap->setValueToMatrixForUndirectGraph(2, 5, 8);
	pMap->setValueToMatrixForUndirectGraph(2, 3, 7);
	pMap->setValueToMatrixForUndirectGraph(3, 5, 4);
	pMap->setValueToMatrixForUndirectGraph(3, 4, 2);
	pMap->setValueToMatrixForUndirectGraph(4, 5, 9);

	pMap->kruskalTree();

	system("pause");
	return 0;
}
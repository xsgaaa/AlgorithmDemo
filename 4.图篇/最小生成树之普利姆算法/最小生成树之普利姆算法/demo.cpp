#include<iostream>
#include"CMap.h"
#include"Edge.h"
/*

	最小生成树之普利姆算法：

	核心思想：
		普里姆（Prim）算法思想是在n个顶点组成的连通无向网中，
		首先选定所有的顶点，把所有顶点分成两个集合，一个是属
		于集合里的顶点集合（开始时任选一个），其余的顶点属于
		集合外的顶点集合。其次，选择边，也就是每次选择一个端
		点在集合里，一个端点在集合外组成的边，并且这两个顶点
		组成边要是当前最小的权值，每往集合里加人一个顶点.相应
		的也就构成一棵最小生成树的边。当把集合外的所有顶点都
		加入到了集合里，也就构造了一棵最小生成树。

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

	pMap->primTree(0);

	system("pause");
	return 0;
}
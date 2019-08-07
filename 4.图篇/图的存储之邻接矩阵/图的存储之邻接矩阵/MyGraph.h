#pragma once
#define MAXVEX 100



class  MyGraph
{
	MyGraph(int v,int e,bool f);
	void CreateGraph();
private:
	char vexs[MAXVEX];			//顶点表
	int arc[MAXVEX][MAXVEX];	//邻接矩阵
	int numVertexes, numEdges;	//图中当前的顶点数和边数
	bool flag;					//标志，判断图是否是有向图,false代表是无向图
};
#pragma once
#include<list>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iterator>
#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include<queue>

using namespace std;

#define MAX_VERTEX_NUM 600
#define INFINITY 1000000			//定义无穷大

//=保存每个顶点信息的数据结构
struct GraphNode {
	bool known;			//当前结点距离起点的距离是否确定
	int dist;					//当前顶点到起点的最短距离
	int path;				//当前顶点到起点的最短路径的前一个顶点
};

//图节点信息
typedef struct Node
{
	int edge_num;		//边号
	int src;					//源点
	int vertex;				//自身
	int weight;			//边的权重
}Node;

//邻接表图
class Graph
{
private:
	int edge_num;		//图的边的个数
	int vertex_num;	//图的顶点的数目
	list<Node> *graph_list;		//邻接表
	vector<GraphNode> nodeArr;		//保存每个顶点信息的数组
public:
	Graph(){}
	Graph(char* graph[], int edgenum);
	~Graph();
	void print();
	void unweightShortestPath(int src);			//算法1求最短距离
	void unweightShortestPathAdv(int src);		//算法2求最短距离
	void printShortestPath();			//输出顶点src到各个顶点最短距离的信息
private:
	vector<int> get_graph_value(char* graph[], int columns);
	void addEdge(char* graph[], int columns);
};
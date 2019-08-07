#include<iostream>
using namespace std;
#include"Node.h"
#include"List.h"
#include"Person.h"
#include<string>
/*************************************************************/
//线性表 -- 通讯录
//
//联系人信息：姓名 电话


/*************************************************************/

int menu()
{
	//显示通讯录功能菜单
	cout << "功能菜单" << endl;
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;

	cout << "请输入：";

	int order = 0;
	cin >> order;
	return order;
}
void createPerson(List *pList)
{
	Node node;
	cout << "请输入姓名：" << endl;
	cin >> node.data.name;
	cout << "请输入电话：" << endl;
	cin >> node.data.phone;
	pList->ListInsertTail(&node);
}

void deletePerson(List *pList)
{
	Node node;		//在栈中定义临时节点
	int i;			//索引
	cout << "输入要删除的索引：" << endl;
	cin >> i;
	pList->ListDelete(i, &node);	//删除索引表示的节点，并获得数据
	cout << node.data.name << " 已经被删除！";		//显示被删除的人名
}
int main(void)
{
	int userOrder = 0;
	List *pList = new List();

	while (userOrder != 4)
	{
		userOrder = menu();
		switch (userOrder)
		{
		case 1:
			cout << "用户指令--->>新建联系人：" << endl;
			createPerson(pList);
			break;
		case 2:
			cout << "用户指令--->>删除联系人：" << endl;
			deletePerson(pList);
			break;
		case 3:
			cout << "用户指令--->浏览通讯录：" << endl;
			pList->ListTraverse();
			break;
		case 4:
			cout << "用户指令--->退出通讯录：" << endl;
			break;
		default:
			break;
		}
		

	}
	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}
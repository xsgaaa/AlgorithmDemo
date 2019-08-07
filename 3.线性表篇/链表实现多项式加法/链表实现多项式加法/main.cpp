#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct node
{
	float coef;		//多项式系数
	int expn;			//多项式指数
	node *next;		//指向下一个节点的指针
}Lnode,*Dxs;		//定义节点和指向结点的指针


//函数声明
Dxs create();
Dxs add_dxs(Dxs firsta, Dxs firstb);
void printDxs(Dxs h);
//void deleteNode(Dxs h, Dxs p);


int main()
{
	Dxs ha, hb, hc;			//定义第一个多项式ha，第二个多项式hb，结构多项式hc
	cout << "请依次输入第一个多项式的系数和指数\n" << endl;
	ha = create();
	cout << "请依次输入第二个多项式的系数和指数\n" << endl;
	hb = create();
	cout << "输入的第一个多项式是：" << endl;
	printDxs(ha->next);
	cout << "输入的第二个多项式是：" << endl;
	printDxs(hb->next);
	hc = add_dxs(ha, hb);
	cout << "两个多项式的和为：" << endl;
	printDxs(hc->next);

	system("pause");
	return 0;
}

//创建链表（读入数据以0 0结束）
Dxs create()
{
	float coef;				//定义系数部分
	int expn;					//定义指数部分
	Dxs first, qa, s;			//定义三个指针，first为头结点指针，qa为当前结点指针，s为新建节点指针
	first = (Dxs)malloc(sizeof(Lnode));			//为头结点分配内存
	first->coef = -1;										//头结点系数设为-1
	first->expn = -1;										//头结点指数设为-1
	first->next = NULL;									
	qa = first;													//将头结点指针传给qa
	while (1)
	{
		cin >> coef;											//输入系数
		cin >> expn;										//输入指数
		if (coef == 0 && expn == 0)				//系数和指数同时为0，表示输入结束
		{
			break;
		}
		s = (Dxs)malloc(sizeof(Lnode));			//为新结点分配内存
		s->coef = coef;									//为新结点的系数赋值
		s->expn = expn;									//为新结点的指数赋值
		s->next = NULL;							
		qa->next = s;										//使头结点的next指针指向新结点
		qa = s;													//将新结点传给qa
	}
	return first;												//返回头结点
}

//链表相加
Dxs add_dxs(Dxs firsta, Dxs firstb)
{
	//定义5个节点指针
	// first:	为结果多项式的头结点的指针
	// ha:	为第一个多项式当前结点的指针
	// hb:	为第二个多项式当前结点的指针
	// hc:	为第三个多项式当前结点的指针
	// s:		为新建结点的指针
	Dxs firstc, ha, hb, pc, s;							
	int a, b;														//存放系数和指数			
	float sum;													//存放相加的和
	firstc = (Dxs)malloc(sizeof(Lnode));			//为第一个节点分配内存
	firstc->coef = -1;										//第一个结点的初值设为-1
	firstc->expn = -1;
	firstc->next = NULL;
	pc = firstc;												//将头结点指针传给pc

	ha = firsta->next;									//获取第一个多项式的头结点之后的结点
	hb = firstb->next;									//获取第二个多项式的头结点之后的结点
	while (ha != NULL && hb != NULL)		//如果节点的指针都不为空
	{
		a = ha->expn;										//获取当前结点的指数
		b = hb->expn;
		if (a < b)												//如果指数小于
		{	
			//将a加入到c中，移动a和c的指针
			pc->next = ha;
			pc = pc->next;
			ha = ha->next;
		}
		else if (a > b)									//如果指数大于
		{
			//将b加入到C中，移动b和c的指针
			pc->next = hb;
			pc = pc->next;
			hb = hb->next;
		}
		else													//如果指数相等
		{
			sum = ha->coef + hb->coef;		//系数相加
			if (sum != 0.0)								//如果和不为0
			{
				//将和加入a中，再将a加入c中，移动C的指针
				ha->coef = sum;
				pc->next = ha;
				pc = pc->next;
			}
			else
			{
				//查找删除A中系数之和为0的那个节点
				s = firsta;
				while (s != ha)
				{
					s = s->next;
				}
				s->next = ha->next;
			}
			//ab已经处理完成，同时后移一位
			ha = ha->next;
			hb = hb->next;
		}
	}
	//将剩余部分加入到c后面
	if (ha != NULL)
	{
		pc->next = ha;
	}
	if (hb != NULL)
	{
		pc->next = hb;
	}
	return firstc;				//返回结果多项式的头结点
}

//遍历显示链表
void printDxs(Dxs h)
{
	while (h != NULL)
	{	
		if (h->next == NULL || h->next->coef<0)
		{
			cout << h->coef << "X^" << h->expn;
		}
		else
		{
			cout << h->coef << "X^" << h->expn << "+";
		}
		h = h->next;
	}
	cout << endl;
}


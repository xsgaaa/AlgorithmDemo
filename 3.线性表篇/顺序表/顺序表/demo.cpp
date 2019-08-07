#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include<iostream>
using namespace std;
/*********************************************************/
/*
	线性表---顺序表

	 3 5 7 2 9 1 8





*/
/*********************************************************/

int main(void)
{
	//3 5 7 2 9 1 8
	Coordinate e1(3,5);
	Coordinate e2(5,7);
	Coordinate e3(6,8);
	/*
	Coordinate e4 = 2;
	Coordinate e5 = 9;
	Coordinate e6 = 1;
	Coordinate e7 = 8;
	*/

	Coordinate temp(0,0);
	List *list1 = new List(10);

	//cout << "Length:"<<list1->ListLength() << endl;

	list1->ListInsert(0, &e1);

	//cout << "Length:" << list1->ListLength() << endl;

	list1->ListInsert(1, &e2);
	list1->ListInsert(2, &e3);
	/*list1->ListInsert(3, &e4);
	list1->ListInsert(4, &e5);
	list1->ListInsert(5, &e6);
	list1->ListInsert(6, &e7);*/



	list1->ListTraverse();
	
	//list1->priorelem(&e4, &temp);
	//cout << "temp:" << temp << endl;

	//list1->nextelem(&e4, &temp);
	//cout <<"temp:"<< temp << endl;

	delete list1;

	system("pause");
	return 0;
}

/*
		list1->ListDelete(0, &temp);

	if (!list1->ListEmpty())
	{
		cout << "not empty" << endl;
	}

	list1->ClearList();

	if (list1->ListEmpty())
	{
		cout << "empty" << endl;
	}





*/
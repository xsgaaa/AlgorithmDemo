/*
	伸展树(Splay Tree)是特殊的二叉查找树。
		它的特殊是指，它除了本身是棵二叉查找树之外，
		它还具备一个特点: 当某个节点被访问时，伸展
		树会通过旋转使该节点成为树根。这样做的好处
		是，下次要访问该节点时，能够迅速的访问到该
		节点。
*/


#include<iostream>
#include"SplayTree.h"
using namespace std;

static int arr[] = { 10,50,40,30,20,60 };
#define TBL_SIZE(a) ((sizeof(a))/(sizeof(a[0])))

int main()
{
	int i, ilen;
	SplayTree<int>* tree = new SplayTree<int>();

	cout << "==依次添加：";
	ilen = TBL_SIZE(arr);
	for (i = 0; i < ilen; i++)
	{
		cout << arr[i]<<" ";
		tree->insert(arr[i]);
	}

	cout << endl << "==前序遍历：";
	tree->preOrder();

	cout << endl << "==中序遍历：";
	tree->inOrder();

	cout << endl << "==后序遍历：";
	tree->postOrder();
	cout << endl;

	cout << "==最小值：" << tree->minimum() << endl;
	cout << "==最大值：" << tree->maximum() << endl;
	cout << "==树的详细信息：" << endl;
	tree->print();

	i = 30;
	cout << endl << "==旋转节点(" << i << ")为根节点";
	tree->splay(i);
	cout<< "==树的详细信息：" << endl;
	tree->print();

	tree->destroy();
	return 0;
}
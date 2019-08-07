#include<iostream>
#include"BSTree.h"
using namespace std;

static int arr[] = { 1,5,4,3,2,6 };
#define TBL_SIZE(a) ((sizeof(a))/(sizeof(a[0])))

int main()
{
	int i, ilen;
	BSTree<int>* tree = new BSTree<int>();

	cout << "==依次添加：";
	ilen = TBL_SIZE(arr);
	for (i = 0; i < ilen; i++)
	{
		cout << arr[i] << " ";
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

	cout << endl << "==删除节点: " << arr[3];
	tree->remove(arr[3]);

	cout << endl << "==中序遍历：";
	tree->inOrder();
	cout << endl;

	tree->destroy();

	return 0;

}

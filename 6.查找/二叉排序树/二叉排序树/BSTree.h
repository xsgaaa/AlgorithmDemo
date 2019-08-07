#pragma once
#include<iostream>
#include<iomanip>
using namespace std;



/*
		BSTNode是二叉查找树的节点，它包含二叉查找树的几个基本信息：
		(01) key -- 它是关键字，是用来对二叉查找树的节点进行排序的。
		(02) left -- 它指向当前节点的左孩子。
		(03) right -- 它指向当前节点的右孩子。
		(04) parent -- 它指向当前节点的父结点。
*/
template<class T>
class BSTNode
{
public:
	T key;				//关键字（键值）
	BSTNode *left;		//左孩子
	BSTNode *right;		//右孩子
	BSTNode *parent;	//父节点
	BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r) :key(value), parent(), left(l), right(r){}
};

template<class T>
class BSTree
{
private:
	BSTNode<T> *mRoot;		//根节点

public:
	BSTree();
	~BSTree();
	
	void preOrder();		//前序遍历
	void inOrder();			//中序遍历
	void postOrder();		//后序遍历

	BSTNode<T>* search(T key);		//（递归实现)查找"二叉树"中键值为key的节点
	BSTNode<T>* iterativeSearch(T key);	// (非递归实现)查找"二叉树"中键值为key的节点

	T minimum();	// 查找最小结点：返回最小结点的键值
	T maximum();	 // 查找最大结点：返回最大结点的键值。

	BSTNode<T>* successor(BSTNode<T> *x);	 // 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
	BSTNode<T>* predecessor(BSTNode<T> *x);	// // 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"

	void insert(T key);		//将结点(key为节点键值)插入到二叉树中
	void remove(T key);		// 删除结点(key为节点键值)
	void destroy();			// 销毁二叉树
	void print();			// 打印二叉树
private:
	void preOrder(BSTNode<T>* tree)const;	//前序遍历"二叉树"
	void  inOrder(BSTNode<T>* tree)const;	// 中序遍历"二叉树"
	void postOrder(BSTNode<T>* tree)const;	// 后序遍历"二叉树"
	BSTNode<T>* search(BSTNode<T>* x, T key) const;	//(递归实现)查找"二叉树x"中键值为key的节点
	BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;	// (非递归实现)查找"二叉树x"中键值为key的节点
	BSTNode<T>* minimum(BSTNode<T>* tree);		// 查找最小结点：返回tree为根结点的二叉树的最小结点
	BSTNode<T>* maximum(BSTNode<T>* tree);		// 查找最大结点：返回tree为根结点的二叉树的最大结点
	void insert(BSTNode<T>* &tree, BSTNode<T>* z);		// 将结点(z)插入到二叉树(tree)中
	BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T>* z);	// 删除二叉树(tree)中的结点(z)，并返回被删除的结点
	void destroy(BSTNode<T>* &tree);	// 销毁二叉树
	void print(BSTNode<T>* tree, T key, int direction);	// 打印二叉树
};

template<class T>
BSTree<T>::BSTree() :mRoot(NULL)	//构造函数
{

}

template<class T>
BSTree<T>::~BSTree()		//析构函数
{
	destroy();				//调用销毁函数
}

//前序遍历二叉树
template<class T>
void BSTree<T>::preOrder(BSTNode<T> *tree)const
{
	if (tree != NULL)					//如果结点不为空
	{
		cout << tree->key << " ";		//输出结点的值
		preOrder(tree->left);			//前序遍历结点左孩子
		preOrder(tree->right);			//前序遍历结点右孩子
	}
}

template<class T>
void BSTree<T>::preOrder()
{
	preOrder(mRoot);
}

//中序遍历二叉树，同样采用递归的方法
template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree)const
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " ";	//中间遍历结点
		inOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::inOrder()
{
	inOrder(mRoot);
}

//后序遍历二叉树
template<class T>
void BSTree<T>::postOrder(BSTNode<T>* tree)const
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";		//最后遍历结点
	}
}

template<class T>
void BSTree<T>::postOrder()
{
	postOrder(mRoot);
}

//递归实现，查找"二叉树x"中键值为key的结点
//返回的是最后一个查找的结点指针
template<class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key) const
{
	//x为NULL代表没找到 || 键值相等表明找到，返回该结点
	if (x == NULL || x->key == key)
		return x;
	//键值小于结点键值，则搜索左孩子，否则搜索右孩子
	if (key < x->key)		
		return search(x->left, key);
	else
		return search(x->right, key);
}

template<class T>
BSTNode<T>* BSTree<T>::search(T key)
{
	return search(mRoot, key);		//从根结点开始搜索键值
}

//(非递归实现)查找"二叉树x"中键值为key的节点
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T>* x, T key) const
{
	while ((x != NULL) && (x->key != key))
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(mRoot, key);
}

//查找最小结点：返回tree为根结点的二叉树的最小结点
//最左边的结点的值最小，一直往左边找
template<class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>*tree)
{
	if (tree == NULL)		//如果树为NULL，没有结点，则返回空
	{
		return NULL;
	}
	//左孩子不为空时，一直遍历，直至左孩子为空时退出
	while (tree->left != NULL)	
		tree = tree->left;
	return tree;
}

template<class T>
T BSTree<T>::minimum()
{
	BSTNode<T> *p = minimum(mRoot);		//p指向最小值的那个结点
	if (p != NULL)						//结点存在且分配内存正确
	{
		return p->key;
	}

	return (T)NULL;
}

//查找最大结点：返回tree为根结点的二叉树的最大结点
//最右边的结点的值最大，一直往右边找
template<class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template<class T>
T BSTree<T>::maximum()
{
	BSTNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

//找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
//比x稍微大一点，排在其后面的结点
template<class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x)
{
	// 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"
	if (x->right != NULL)
		return minimum(x->right);	
	// 如果x没有右孩子。则x有以下两种可能：
	// (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
	// (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
	BSTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

//找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
template<class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
	// 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
	if (x->left != NULL)
		return maximum(x->left);
	// 如果x没有左孩子。则x有以下两种可能：
	// (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
	// (02) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
	BSTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*
	将结点插入到二叉树中
	参数说明：
		tree	二叉树的根结点
		z   插入的结点
*/
template<class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
	BSTNode<T> *y = NULL;		//定义一个空节点指针，中间变量的作用
	BSTNode<T> *x = tree;		//定义一个指向根节点的结点指针
	while (x != NULL)			//当x==NULL的时候，x->parent=y
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)			//当树为空时，上面那个while循环不执行，所以y==NULL,直接将结点赋给根节点
		tree = z;
	else if (z->key < y->key)
		y->left = z;		//值比跟小，为左节点
	else
		y->right = z;		//值比跟小，为左节点
}

template<class T>
void BSTree<T>::insert(T key)
{
	//用键值初始化一个新结点，然后再插入
	BSTNode<T>* z = NULL;
	// 如果新建结点失败，则返回。
	if ((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL)
		return;
	insert(mRoot, z);
}


/*
	删除结点(z)，并返回被删除的结点
	参数说明：
		tree 二叉树的根结点
		z 删除的结点
	二叉树删除操作的三种情况:
		a)被删除节点z没有任何子女 
		b)被删节点z有一个子女 
		c)被删节点z有两个子女
*/
template<class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *z)
{
	BSTNode<T> *x = NULL;
	BSTNode<T> *y = NULL;
	if ((z->left == NULL) || (z->right == NULL))	//左右孩子存在NULL
		y = z;			//指针y指向要删除的节点
	else
		y = successor(z);		
	//左右孩子都不为空，把z的后继赋给y，y为z右子树中键值最小的结点

	if (y->left != NULL)
		x = y->left;	
	else
		x = y->right;

	if (x != NULL)
		x->parent = y->parent;

	if (y->parent == NULL)
		tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->key = y->key;

	return y;
}

template<class T>
void BSTree<T>::remove(T key)
{
	BSTNode<T> *z, *node;

	if ((z = search(mRoot, key)) != NULL)
		if ((node = remove(mRoot, z)) != NULL)
			delete node;
}

//销毁二叉树，递归实现
template<class T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;		//这一步要放到最后，先删除左子树，再删除右子树，最后删除本身
	tree = NULL;		//结点置为NULL
}

template<class T>
void BSTree<T>::destroy()
{
	destroy(mRoot);
}

/*
	打印二叉树	--	递归实现，先判断是不是根节点，然后打印左子树，再打印右子树
	key			--结点的键值
	direction	--		0,表示该节点是根节点;
				--		-1，表示该节点是它的父结点的左孩子;
						1，表示该节点是它的父结点的右孩子。

*/
template<class T>
void BSTree<T>::print(BSTNode<T> *tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			cout << setw(2) << tree->key << "is root" << endl;
		else
			cout << setw(2) << tree->key << " is" << setw(2) << key << "'s" << setw(12) << (direction == 1 ? "right child" : "lift child") << endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<class T>
void BSTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}


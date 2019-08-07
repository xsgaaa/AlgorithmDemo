#pragma once
#include<iomanip>
#include<iostream>
using namespace std;

template<class T>
class SplayTreeNode			//伸展树节点类
{
public:
	T key;					//关键字(键值）		
	SplayTreeNode *left;	//左孩子
	SplayTreeNode* right;	//右孩子

	SplayTreeNode():left(NULL),right(NULL){}

	SplayTreeNode(T value,SplayTreeNode *l,SplayTreeNode *r):
		key(value),left(l),right(r){}
};

template<class T>
class SplayTree
{
private:
	SplayTreeNode<T> *mRoot;
public:
	SplayTree();
	~SplayTree();

	void preOrder();
	void inOrder();
	void postOrder();

	SplayTreeNode<T>* search(T key);
	SplayTreeNode<T>* iterativeSearch(T key);

	T minimum();
	T maximum();

	//旋转key对应的节点为根节点，并返回值为根节点
	void splay(T key);

	void insert(T key);
	void remove(T key);
	void destroy();
	void print();
private:
	void preOrder(SplayTreeNode<T>* tree)const;
	void inOrder(SplayTreeNode<T>* tree)const;
	void postOrder(SplayTreeNode<T>* tree)const;

	SplayTreeNode<T>* search(SplayTreeNode<T>* x, T key)const;
	SplayTreeNode<T>* iterativeSearch(SplayTreeNode<T>* x, T key)const;
	SplayTreeNode<T>* minimum(SplayTreeNode<T>* tree);
	SplayTreeNode<T>* maximum(SplayTreeNode<T>* tree);

	// 旋转key对应的节点为根节点，并返回值为根节点。
	SplayTreeNode<T>* splay(SplayTreeNode<T>* tree,T key);

	SplayTreeNode<T>* insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z);
	SplayTreeNode<T>* remove(SplayTreeNode<T>* &tree, T key);
	void destroy(SplayTreeNode<T>* &tree);
	void print(SplayTreeNode<T> *tree, T key, int direction);
};

//构造函数
template<class T>
SplayTree<T>::SplayTree() :mRoot(NULL)
{

}

//析构函数
template<class T>
SplayTree<T>::~SplayTree()
{
	destroy(mRoot);
}

//前序遍历伸展树
template <class T>
void SplayTree<T>::preOrder(SplayTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void SplayTree<T>::preOrder()
{
	preOrder(mRoot);
}

//中序遍历伸展树
template <class T>
void SplayTree<T>::inOrder(SplayTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template <class T>
void SplayTree<T>::inOrder()
{
	inOrder(mRoot);
}

//后序遍历伸展树
template <class T>
void SplayTree<T>::postOrder(SplayTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}

template <class T>
void SplayTree<T>::postOrder()
{
	postOrder(mRoot);
}

//（递归实现）查找伸展树中键值为key的节点
template <class T>
SplayTreeNode<T>* SplayTree<T>::search(SplayTreeNode<T>* x, T key) const
{
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return search(x->left, key);
	else
		return search(x->right, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::search(T key)
{
	return search(mRoot, key);
}

/*
* (非递归实现)查找"伸展树x"中键值为key的节点
*/
template <class T>
SplayTreeNode<T>* SplayTree<T>::iterativeSearch(SplayTreeNode<T>* x, T key) const
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

template <class T>
SplayTreeNode<T>* SplayTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(mRoot, key);
}

//查找最小节点：返回tree为根节点的伸展树的最小结点
template <class T>
SplayTreeNode<T>* SplayTree<T>::minimum(SplayTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

template <class T>
T SplayTree<T>::minimum()
{
	SplayTreeNode<T> *p = minimum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

//查找最大结点：返回tree为根节点的伸展树的最大结点
template <class T>
SplayTreeNode<T>* SplayTree<T>::maximum(SplayTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template <class T>
T SplayTree<T>::maximum()
{
	SplayTreeNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
	旋转key对应的节点为根节点，并返回值为根节点
	注意：
	(a)：伸展树中存在"键值为key的节点"。
		将"键值为key的节点"旋转为根节点。
	(b)：伸展树中不存在"键值为key的节点"，并且key < tree->key。
		b-1 "键值为key的节点"的前驱节点存在的话，将"键值为key的节点"的前驱节点旋转为根节点。
		b-2 "键值为key的节点"的前驱节点存在的话，则意味着，key比树中任何键值都小，那么此时，将最小节点旋转为根节点。
	(c)：伸展树中不存在"键值为key的节点"，并且key > tree->key。
		c-1 "键值为key的节点"的后继节点存在的话，将"键值为key的节点"的后继节点旋转为根节点。
		c-2 "键值为key的节点"的后继节点不存在的话，则意味着，key比树中任何键值都大，那么此时，将最大节点旋转为根节点。
*/
template<class T>
SplayTreeNode<T>* SplayTree<T>::splay(SplayTreeNode<T>* tree, T key)
{
	//定义临时节点
	SplayTreeNode<T> N, *l, *r, *c;

	if (tree == NULL)
	{
		return tree;
	}
	N.left = N.right = NULL;
	l = r = &N;

	for (;;)
	{
		if (key < tree->key)
		{
			if (tree->left == NULL)
				break;
			if (key < tree->left->key)
			{
				c = tree->left;				//rotate right
				tree->left = c->right;
				c->right = tree;
				tree = c;
				if (tree->left == NULL)
					break;
			}
			r->left = tree;					//link right
			r = tree;
			tree = tree->left;
		}
		else if (key>tree->key)
		{
			if (tree->right->key)
			{
				c = tree->right;
				tree->right = c->left;		//rotate left
				c->left = tree;
				tree = c;
				if (tree->right == NULL)
					break;
			}
			l->right = tree;				//link left
			l = tree;
			tree = tree->right;
		}
		else
		{
			break;
		}
	}

	l->right = tree->left;		//assemble
	r->left = tree->right;
	tree->left = N.right;
	tree->right = N.left;

	return tree;
}

template<class T>
void SplayTree<T>::splay(T key)
{
	mRoot = splay(mRoot, key);
}

/*
	将节点插入到伸展树中，并返回根节点
*/
template<class T>
SplayTreeNode<T>* SplayTree<T>::insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z)
{
	SplayTreeNode<T> *y = NULL;
	SplayTreeNode<T> *x = tree;		//指针x指向根节点

	while (x != NULL)
	{
		y = x;					//保存当前根节点（要插入的节点的父节点）
		//查找z的插入位置
		if (z->key < x->key)	//小于当前根节点的值
			x = x->left;		//
		else if (z->key>x->key)
			x = x->right;
		else
		{
			cout << "不允许插入相同的节点（" << z->key << ")!" << endl;
			delete z;
			return tree;
		}
	}
	
	if (y == NULL)
		tree = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	return tree;
}

template<class T>
void SplayTree<T>::insert(T key)
{
	SplayTreeNode<T> *z = NULL;

	if ((z = new SplayTreeNode<T>(key, NULL, NULL)) == NULL)
		return;

	mRoot = insert(mRoot, z);

	mRoot = splay(mRoot, key);
}

template<class T>
SplayTreeNode<T>* SplayTree<T>::remove(SplayTreeNode<T>* &tree, T key)
{
	SplayTreeNode<T> *x;
	if (tree == NULL)
		return NULL;
	//查找键值为key的节点，找不到的话直接返回
	if (search(tree, key) == NULL)		
		return tree;
	//将key对应的节点旋转为根节点
	tree = splay(tree, key);
	if (tree->left != NULL)
	{
		//将tree的前驱节点旋转为根节点
		x = splay(tree->left, key);
		//移除tree节点
		x->right = tree->right;
	}
	else
		x = tree->right;

	delete tree;

	return x;
}

template<class T>
void SplayTree<T>::remove(T key)
{
	mRoot = remove(mRoot, key);
}

template<class T>
void SplayTree<T>::destroy(SplayTreeNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
	{
		destroy(tree->left);
	}
	if (tree->right != NULL)
		destroy(tree->right);

	delete tree;
}

template<class T>
void SplayTree<T>::destroy()
{
	destroy(mRoot);
}

template<class T>
void SplayTree<T>::print(SplayTreeNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
    {
		if (direction == 0)    // tree是根节点
			cout << setw(2) << tree->key << " is root" << endl;
		else                // tree是分支节点
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
     }
}

template <class T>
void SplayTree<T>::print()
{
     if (mRoot != NULL)
         print(mRoot, mRoot->key, 0);
}

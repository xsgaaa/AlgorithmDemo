#pragma once

/*
	C++ 语言实现红黑树
*/

#include<iostream>
#include<iomanip>
using namespace std;

enum RBTColor{RED,BLACK};	//定义枚举，包括两种颜色

template<class T>
class RBTNode				//红黑节点
{
public:
	RBTColor color;			//颜色
	T key;					//关键字(键值)
	RBTNode *left;			//左孩子
	RBTNode *right;			//右孩子
	RBTNode *parent;		//父节点

	//构造函数初始化
	RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):
		key(value),color(c),parent( ),left(l),right(r){}
};

template<class T>
class RBTree				//红黑树类
{
private:
	RBTNode<T> *mRoot;
public:
	RBTree();
	~RBTree();

	RBTNode<T>* search(T key);		//（递归实现）查找红黑树中键值为key的节点
	RBTNode<T>* iterativeSearch(T key);	//（非递归实现）查找红黑树中键值为key的节点

	T minimum();	//查找最小节点：返回最小节点的键值
	T maximum();	//查找最大节点：返回最小节点的键值

	RBTNode<T>* successor(RBTNode<T> *x);		//找节点(x)的后继节点。即，查找"红黑树中数据值大于该结点"的"最小结点"
	RBTNode<T>* predecessor(RBTNode<T> *x);		//找节点(x)的前驱节点。即，查找"红黑树中数据值小于该结点"的"最大结点"。

	void insert(T key);	//将结点(key为结点键值）插入到红黑树中
	void remove(T key);	//删除结点(key为结点键值）

	void destroy();		//销毁红黑树

	void print();		//打印红黑树

public:
	RBTNode<T>* search(RBTNode<T>* x, T key)const;
	RBTNode<T>* iterativeSearch(RBTNode<T> *x, T key)const;
	RBTNode<T>* minimum(RBTNode<T>* tree);
	RBTNode<T>* maximum(RBTNode<T>* tree);

	void leftRotate(RBTNode<T>* &root, RBTNode<T> *x);		//左旋
	void rightRotate(RBTNode<T>* &root, RBTNode<T> *y);		//右旋

	void insert(RBTNode<T>* &root, RBTNode<T>* node);	//插入函数
	void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);	//插入修正函数

	void remove(RBTNode<T>* &root, RBTNode<T>* node);	//删除函数
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);	//删除修正函数

	void destroy(RBTNode<T>* &tree);	//销毁红黑树
	void print(RBTNode<T>* tree, T key, int direction);		//打印红黑树

#define rb_parent(r)	((r)->parent)		//得到结点的父结点
#define rb_color(r)	((r)->color)			//得到结点的颜色
#define rb_is_red(r)	((r)->color==RED)	//判断结点是否为红色
#define rb_is_black(r)	((r)->color==BLACK)	//判断结点是否为黑色
#define rb_set_black(r)	do {(r)->color=BLACK;} while(0)	//结点颜色设置成黑色
#define rb_set_red(r)	do {(r)->color=RED;} while(0)	//结点颜色设置成黑色
#define rb_set_parent(r,p)	do {(r)->parent=(p);} while(0)	//设置父结点
#define rb_set_color(r,c)	do {(r)->color=(c);} while(0)	//设置结点颜色为当前颜色
};

template<class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
	mRoot = NULL;
}

template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

/*
	（递归实现）搜索键值为key的结点
	x:	搜索开始的结点
	T:	搜索的键值
	返回值：指向结点的指针
*/
template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key)const
{
	/*
		1.当节点为空，直接返回
		2.当键值等于当前结点的键值，直接返回
	*/
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
	{
		return search(x->left, key);	//当键值小于当前结点的键值，查找其左子树
	}
	else
		return search(x->right, key);	//当键值大于当前结点的键值，查找其右子树
}

template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);		//从根节点开始搜索键值为key的结点
}

/*
	(非递归实现)搜索键值为key的结点
	x:	搜索开始的结点
	T:	搜索的键值
	返回值：指向结点的指针
*/
template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key)const
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
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

/*
	查找最小节点（在红黑树的最左边，红黑树是二叉排序树，插入时其内部已经进行了排序）
	tree: 开始查找的结点
	返回值：指向结点的指针
*/
template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

/*
	查找红黑树中的最小值
	返回值：最小结点对应的键值
*/
template<class T>
T RBTree<T>::minimum()
{
	RBTNode<T> *p = minimum(mRoot);	//得到最小结点
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
	查找最大值对应的结点（在树的最右端）
	tree：开始搜索的结点
	返回值：指向结点的指针
*/
template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;

	return tree;
}

/*
	查找红黑树中的最大值
	返回值：树中的最大值
*/
template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T> *p = maximum(mRoot);	//得到最大的结点
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
	查找结点的后继
	x：要查找的结点
	返回值：结点指针
*/
template<class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
	//如果右子树不为空，返回右子树中的最小结点
	if (x->right != NULL)
		return minimum(x->right);
	//右子树为空的情况
	//1.x是一个左孩子，则x的后继结点为它的父结点
	//2.x是一个右孩子，则x是该分支最大结点，查找该局部分支的根节点，并且x在分支的左边
	/*
	               O --->要求的结点
				 /
				O
			  /   \
			 O     O --->假设它是x结点
	*/
	RBTNode<T> *y = x->parent;
	while ((y != NULL) && (x == y->right))	//为左结点，则跳出循环
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
	查找结点的前驱
	x：要查找的结点
	返回值：结点指针
*/
template<class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
	//左子树不为空，查找左子树的最大结点
	if (x->left != NULL)
		return maximum(x->left);
	//左子树不为空
	//1.x是一个右孩子，则x的前驱节点为它的父节点
	//2.x是一个左孩子，则x是该分支的最小值，查找该局部分支的根结点，x在节点的右子树上
	RBTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*
	对结点x进行左旋转
	root :	根结点
	x：		待旋转的结点
	左旋示意图(对节点x进行左旋)：
	      px                              px
	     /                               /
	    x                               y
	   /  \      --(左旋)-->           / \                #
	  lx   y                          x  ry
	     /   \                       /  \
	    ly   ry                     lx  ly	 
*/
template<class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T> *x)
{
	//设置x的右孩子为y
	RBTNode<T> *y = x->right;
	//将y的左孩子设为x的右孩子
	//如果y的左孩子非空，将x设为y的左孩子的父亲
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	//将x的父亲设为y的父亲
	y->parent = x->parent;

	if (x->parent == NULL)	//如果x的父亲是空节点，则将y设为根节点（只有根节点的父亲才为空）
	{
		root = y;
	}
	else
	{
		if (x->parent->left == x)	//x节点是左孩子，则y节点旋转后为左孩子
			x->parent->left = y;
		else
			x->parent->right = y;	//x节点是右孩子，则y节点旋转后为右孩子
	}
	//将x设为y的左孩子
	y->left = x;
	//将x的父节点设为y
	x->parent = y;
}


/*
	对红黑树的节点(y)进行右旋转
	右旋示意图(对节点y进行左旋)：
            py                               py
           /                                /
          y                                x
         /  \      --(右旋)-->            /  \                     #
        x   ry                           lx   y
       / \                                   / \                   #
      lx  rx                                rx  ry
 */
template<class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
	RBTNode<T> *x = y->left;

	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}

	x->right = y;
	y->parent = x;
}

/*
	红黑树插入修正函数
	
	在向红黑树中插入节点之后(失去平衡)，再调用该函数；
	目的是将它重新塑造成一颗红黑树。
	
	参数说明：
		root 红黑树的根
	    node 插入的结点        // 对应《算法导论》中的z
*/
template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent;	//定义父亲节点和祖父节点

	//若父亲节点存在，且父亲节点的颜色是红色
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		//得到祖父节点
		gparent = rb_parent(parent);
		//若父节点是祖父节点的左孩子
		if (parent == gparent->left)
		{
			RBTNode<T> *uncle = gparent->right;
			//Case 1: 叔叔节点是红色
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;	//重新循环while
			}
			//Case 2:叔叔是黑色，且当前结点是右孩子
			if (parent->right == node)
			{
				RBTNode<T> *tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			//case3 ：叔叔是黑色，且当前结点是左孩子
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else	//若父节点是祖父节点的右孩子
		{
			RBTNode<T> *uncle = gparent->left;
			//Case 1:叔叔节点是红色
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			//Case 2：叔叔是黑色，且当前结点是左孩子
			if (parent->left == node)
			{
				RBTNode<T> *tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			//Case 3： 叔叔是黑色，且当前结点是右孩子
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, gparent);
		}
	}
	//将根节点设置成黑色
	rb_set_black(root);
}

/*
	将节点插入到红黑树中
	参数说明：
		root	红黑树的根节点
		node	插入的结点
*/
template<class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *y = NULL;
	RBTNode<T> *x = root;
	//1.将红黑树当做一颗二叉查找树，将节点添加到二叉查找树中
	while (x != NULL)
	{
		y = x;		//存放要插入结点的父节点
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;
	//2.设置结点颜色为红色
	node->color = RED;
	//3.将它重新修正为一颗二叉查找树
	insertFixUp(root, node);
}

/*
	将结点(key为节点键值)插入到红黑树中
	
	参数说明：
	    tree 红黑树的根结点
		key 插入结点的键值
*/
template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z = NULL;
	//如果新建节点失败，则返回
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;

	insert(mRoot, z);
}

/*
	红黑树删除修正函数

	在从红黑树中删除插入节点后(红黑树失去平衡)，再调用该函数；
	目的是将它重新塑造成一颗二叉树

	参数说明：
		root	红黑树的根
		node	待修正的节点
*/
template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
	RBTNode<T> *other;
	//node不为根节点，且node为空或者node为黑色
	while ((!node || rb_is_black(node)) && node != root)
	{
		//node是左孩子
		if (parent->left == node)
		{
			//找到node的兄弟
			other = parent->right;
			if (rb_is_red(other))
			{
				//Case 1：x的兄弟w是红色的
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}

			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				//Case 2:x的兄弟w是黑色，且w的两个孩子也都是黑色的
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				//Case 3：x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色
				if ((!other->left || rb_is_black(other->right)))
				{
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				//Case 4：x的兄弟w是黑色的，并且w的右孩子是红色的，左孩子是任意颜色
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			other = parent->left;
			if (rb_is_red(other))
			{
				//Case 1：x的兄弟是红色的
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				//Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的 
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->left || rb_is_black(other->left))
				{
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
				rb_set_color(other,rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}

/*	
	删除节点(node),并返回被删除的节点

	参数说明：
		root 红黑树的根节点
		node 删除的节点
*/
template<class T>
void RBTree<T>::remove(RBTNode<T>* &root, RBTNode<T> *node)
{
	RBTNode<T> *child=NULL, *parent=NULL;
	RBTColor color=BLACK;
	//被删除节点的左右孩子都不为空
	if ((node->left != NULL) && (node->right != NULL))
	{
		//被删除节点的后继节点，称为取代节点
		//用它来取代被删除节点的位置，然后在将被删除节点去掉
		RBTNode<T> *replace = node;
		//获取后继节点
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;
		// "node节点"不是根节点(只有根节点不存在父节点)
		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else
			// "node节点"是根节点，更新根节点。
			root = replace;
		// child是"取代节点"的右孩子，也是需要"调整的节点"。
		// "取代节点"肯定不存在左孩子！因为它是一个后继节点。
		child = replace->left;
		parent = rb_parent(replace);
		// 保存"取代节点"的颜色
		color = rb_color(replace);
		// "被删除节点"是"它的后继节点的父节点"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child不为空
			if (child)
				rb_set_parent(child, parent);
			parent->left = child;

			replace->right = node->right;
			rb_set_parent(node->right, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK)
			removeFixUp(root, child, parent);

		delete node;
		return;
	}

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	parent = node->parent;
	// 保存"取代节点"的颜色
	color = node->color;

	if (child)
		child->parent = parent;
	// "node节点"不是根节点
	if (parent)
	{
		if (parent->left == node)
		{
			parent->left = child;
		}
		else
			parent->right = child;
	}
	else
		root = child;

	if (color == BLACK)
		removeFixUp(root, child, parent);

	delete node;
}

/*
	删除红黑树中键值为key的节点

	参数说明：
		tree 红黑树的根结点
*/
template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T> *node=NULL;
	// 查找key对应的节点(node)，找到的话就删除该节点
	if ((node == search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

template<class T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template<class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

/*
	打印"二叉查找树"
	
	key        -- 节点的键值
	direction  --  0，表示该节点是根节点;
	              -1，表示该节点是它的父结点的左孩子;
	               1，表示该节点是它的父结点的右孩子。
*/
template<class T>
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			cout << setw(2) << tree->key << "(B) is root" << endl;
		else
			cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2) << key << "'s" << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<class T>
void RBTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}


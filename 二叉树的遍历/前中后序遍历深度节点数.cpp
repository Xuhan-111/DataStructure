#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

struct bitnode
{
	char data;
	bitnode* ls;
	bitnode* rs;
};

typedef bitnode* btree;

void creat(btree &T)
{
	char x;
	cin >> x;
	if (x == '#')
	{
		T = NULL;
	}
	else
	{
		T = new bitnode();
		T->data = x;
		creat(T->ls);
		creat(T->rs);
	}
}

void DLR(btree &T)
{
	if (T)
	{
		cout << T->data << " ";
		DLR(T->ls);
		DLR(T->rs);
	}
}

void LDR(btree &T)
{
	if (T)
	{
		LDR(T->ls);
		cout << T->data << " ";
		LDR(T->rs);
	}
}
void LRD(btree &T)
{
	if (T)
	{
		LRD(T->ls);
		LRD(T->rs);
		cout << T->data << " ";
	}
}

void LDR_1(btree &T)
{
	stack <btree> st;
	btree q = new bitnode();
	btree p = T;

	while (p || !st.empty())
	{
		if (p)
		{
			st.push(p);
			p = p->ls;
		}
		else
		{
			q = st.top();
			st.pop();
			cout << q->data << " ";
			p = q->rs;
		}
	}

}

void DLR_1(btree &T)
{
	stack <btree> st;
	btree q = new bitnode();
	btree p = T;
	while (p || !st.empty())
	{
		if (p)
		{
			cout << p->data << " ";
			st.push(p);
			p = p->ls;
		}
		else
		{
			q = st.top();
			st.pop();
			p = q->rs;
		}
	}
}

void LRD_1(btree &T)
{
	stack <btree> st1;
	stack <btree> st2;
	btree q = new bitnode();
	btree p = T;
	st1.push(T);
	while (!st1.empty())
	{
		p = st1.top();
		st1.pop();
		st2.push(p);
		if(p->ls != NULL)
		{
			st1.push(p->ls);
		}
		if (p->rs != NULL)
		{
			st1.push(p->rs);
		}
	}
	while (!st2.empty())
	{
		q = st2.top();
		st2.pop();
		cout << q->data << " ";
	}
}
int depth(btree &T)
{
	if (T == NULL)
	{
		return 0;
	}
	int m = depth(T->ls);
	int n = depth(T->rs);
	if (m > n)
	{
		return m + 1;
	}
	return n + 1;
}

int count(btree &T)
{
	if (T == NULL)
	{
		return 0;
	}
	return count(T->ls) + count(T->rs) + 1;
}

int main()
{
	btree B;
	cout << "请输入二叉树的节点" << endl;
	creat(B);
	cout << "前序遍历结果 ";
	DLR(B);
	cout << endl;
	cout << "中序遍历结果 ";
	LDR(B);
	cout << endl;
	cout << "后序遍历结果 ";
	LRD(B);
	cout << endl;
	cout << "前序非递归遍历结果 ";
	DLR_1(B);
	cout << endl;
	cout << "中序非递归遍历结果 " ;
	LDR_1(B);
	cout << endl;
	cout << "后序非递归遍历结果 ";
	LRD_1(B);
	cout << endl;
	cout << "该树的深度是: " << depth(B) << endl;
	cout << "该树的节点个数是：" << count(B) << endl;
	int n;
	cin >> n;
	return 0;

}

/*
A B C # # D E # G # # F # # #

A B # C D # # E # # F # G H # # #
*/

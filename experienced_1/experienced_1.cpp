#include <iostream>
#include "BT.h"

using namespace std;

void main()
{
	Btree *root = NULL;
	int mass[] = { 30, 28, 10, 29, 14, 16, 27, 15, 9, 40, 60, 45, 44, 47, 80, 100, 90, 95, 94, 98};
	root = new Btree(mass[0]);
	for (int i = 1; i < 20; i++)
		root->Insert(root, mass[i]);

	if (Search(root, 8) == true) cout << "Found\n";
	else cout << "Not Found\n";

	cout << "max deep of Btree : " << CountDeep(root) << endl;
	print_Tree(root, CountDeep(root));

	system("pause");
}

Btree::Btree(int data)
{
	this->data = data;
	this->Right = NULL;
	this->Left = NULL;
}
void Btree::Insert(Btree * root, int data)
{
	if (root->data < data)
		if (root->Right != NULL)
		{
			Insert(root->Right, data);
		}
		else if (root->Right == NULL)
		{
			root->Right = new Btree(data);
		}
	if (root->data > data)
		if (root->Left != NULL)
		{
			Insert(root->Left, data);
		}
		else if (root->Left == NULL)
		{
			root->Left = new Btree(data);
		}
}
bool Search(Btree * root, int data) 
{
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->Left, data);
	}
	else {
		return Search(root->Right, data);
	}
}
int CountDeep(Btree * root)
{
	int maxLvL = 0;
	int i = root->data;
	static Btree * root_t = root;
	if (root->Left == NULL && root->Right == NULL)
		;
	else
	{
		maxLvL += (root->Left == NULL ? 0 : CountDeep(root->Left)) > (root->Right == NULL ? 0 : CountDeep(root->Right)) ? CountDeep(root->Left) : CountDeep(root->Right);
	}
	if (root_t == root)
		return maxLvL;
	return ++maxLvL;
}
void outPutTree(Btree * root)
{
	std::cout <<"-"<< root->data <<"-"<<std::endl;
	static Btree * root_t = root;
	if (root->Left == NULL && root->Right == NULL)
		;
	else
	{
		if (root->Left == NULL)
			;
		else
		{
			outPutTree(root->Left);
		}
		if (root->Right == NULL)
			;
		else
		{
			outPutTree(root->Right);
		}
	}
}
void print_Tree(Btree * root,int level)
{
	if (root)
	{
		print_Tree(root->Left, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << root->data << endl;
		print_Tree(root->Right, level + 1);
	}
}
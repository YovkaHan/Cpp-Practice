#pragma once

struct Btree
{
	int data;
	Btree * Left;
	Btree * Right;
	Btree(int data);
	void Insert(Btree * root, int data);
	~Btree()
	{
		delete Left;
		delete Right;
	}
};

bool Search(Btree * root, int data);
int CountDeep(Btree * root);
void outPutTree(Btree * root);
void print_Tree(Btree * root, int level);  
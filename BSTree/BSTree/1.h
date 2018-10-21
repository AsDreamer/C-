#pragma once
#include<assert.h>
typedef int BSTDataType;
typedef struct BSTreeNode
{
	struct BSTreeData* _left;
	struct BSTreeData* _right;
	int _data;
}BSTreeNode,*BSTNode;


int BSTreeInsert(BSTNode *ppTree, BSTDataType x);//插入
int BSTreeRemove(BSTreeNode** ppTree, BSTDataType x);//删除
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTDataType x);//查找

int BSTreeInsertR(BSTreeNode** ppTree, BSTDataType x);//插入，递归
int BSTreeRemoveR(BSTreeNode** ppTree, BSTDataType x);//删除，非递归
BSTreeNode* BSTreeFindR(BSTreeNode** ppTree, BSTDataType x);//查找，非递归
void BSTreeDestroy(BSTreeNode** ppTree);//销毁

void BSTreeInOrder(BSTreeNode** ppTree);//中序遍历
void TestBSTree();
void TestBSTreeR();

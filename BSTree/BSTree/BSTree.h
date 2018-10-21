#pragma once
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int BSTDataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTDataType _data;
}BSTreeNode;

int BSTreeInsert(BSTreeNode** ppTree, BSTDataType x);//插入
int BSTreeRemove(BSTreeNode** ppTree, BSTDataType x);//删除
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTDataType x);//查找

int BSTreeInsertR(BSTreeNode** ppTree, BSTDataType x);//插入，递归
int BSTreeRemoveR(BSTreeNode** ppTree, BSTDataType x);//删除，非递归
BSTreeNode* BSTreeFindR(BSTreeNode** ppTree, BSTDataType x);//查找，非递归
void BSTreeDestroy(BSTreeNode** ppTree);//销毁

void BSTreeInOrder(BSTreeNode** ppTree);//中序遍历
void TestBSTree();
void TestBSTreeR();


//运用场景
///////////////////////////////////////////////////////
// key
//#pragma once
//
//#include <stdio.h>
//#include <malloc.h>
//#include <assert.h>
//#include <string.h>
//
//typedef char* BSTKeyType;
////typedef int BSTValueType;
//
//typedef struct BSTreeNode
//{
//	struct BSTreeNode* _left;
//	struct BSTreeNode* _right;
//	BSTKeyType _key;
//}BSTreeNode;
//
//int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType x);
//int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType x);
//BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType x);
//
//void BSTreeInOrder(BSTreeNode** ppTree);
//void TestBSTree1();


//////////////////////////////////////////////////////
// key/value

//#pragma once
//
//#include <stdio.h>
//#include <malloc.h>
//#include <assert.h>
//#include <string.h>
//#include<stdlib.h>
//
//typedef char* BSTKeyType;
//typedef int BSTValueType;
//
//typedef struct BSTreeNode
//{
//	struct BSTreeNode* _left;
//	struct BSTreeNode* _right;
//	BSTKeyType _key;
//	BSTValueType _value;
//}BSTreeNode;
//
//int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value);
//int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType key);
//BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key);
//
//void BSTreeInOrder(BSTreeNode** ppTree);
//void TestBSTree1();

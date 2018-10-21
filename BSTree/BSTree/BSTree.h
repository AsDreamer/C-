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

int BSTreeInsert(BSTreeNode** ppTree, BSTDataType x);//����
int BSTreeRemove(BSTreeNode** ppTree, BSTDataType x);//ɾ��
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTDataType x);//����

int BSTreeInsertR(BSTreeNode** ppTree, BSTDataType x);//���룬�ݹ�
int BSTreeRemoveR(BSTreeNode** ppTree, BSTDataType x);//ɾ�����ǵݹ�
BSTreeNode* BSTreeFindR(BSTreeNode** ppTree, BSTDataType x);//���ң��ǵݹ�
void BSTreeDestroy(BSTreeNode** ppTree);//����

void BSTreeInOrder(BSTreeNode** ppTree);//�������
void TestBSTree();
void TestBSTreeR();


//���ó���
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

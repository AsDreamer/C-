#pragma once
#include<assert.h>
typedef int BSTDataType;
typedef struct BSTreeNode
{
	struct BSTreeData* _left;
	struct BSTreeData* _right;
	int _data;
}BSTreeNode,*BSTNode;


int BSTreeInsert(BSTNode *ppTree, BSTDataType x);//����
int BSTreeRemove(BSTreeNode** ppTree, BSTDataType x);//ɾ��
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTDataType x);//����

int BSTreeInsertR(BSTreeNode** ppTree, BSTDataType x);//���룬�ݹ�
int BSTreeRemoveR(BSTreeNode** ppTree, BSTDataType x);//ɾ�����ǵݹ�
BSTreeNode* BSTreeFindR(BSTreeNode** ppTree, BSTDataType x);//���ң��ǵݹ�
void BSTreeDestroy(BSTreeNode** ppTree);//����

void BSTreeInOrder(BSTreeNode** ppTree);//�������
void TestBSTree();
void TestBSTreeR();

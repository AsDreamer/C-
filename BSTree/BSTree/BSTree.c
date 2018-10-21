#include"BSTree.h"

BSTreeNode* BuyBSTreeNode(BSTDataType x)
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_data = x;

	return node;
}

int BSTreeInsert(BSTreeNode** ppTree, BSTDataType x)
{
	BSTreeNode* cur, *parent;
	parent = NULL;

	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 1;
	}

	cur = *ppTree;
	while (cur)
	{
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return 0;
	}

	if (parent->_data < x)
	{
		parent->_right = BuyBSTreeNode(x);
	}
	else
	{
		parent->_left = BuyBSTreeNode(x);
	}

	return 1;
}

int BSTreeRemove(BSTreeNode** ppTree, BSTDataType x)
{
	BSTreeNode* cur, *parent;

	parent = NULL;
	cur = *ppTree;
	while (cur)
	{
		if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			// 开始删除

			// 1.左为空/右为空
			// 2.左右都不为空
			if (cur->_left == NULL)
			{
				if (parent == NULL)
				{
					*ppTree = cur->_right;
				}
				else
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
			}
			else if(cur->_right == NULL)
			{
				if (parent == NULL)
				{
					*ppTree = cur->_left;
				}
				else
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
			}
			else
			{
				BSTreeNode* replace = cur->_right;
				while (replace->_left)
				{
					replace = replace->_left;
				}

				cur->_data = replace->_data;

				return BSTreeRemove(&cur->_right, replace->_data);
			}

			free(cur);

			return 1;
		}
	}
	
	return 0;
}

BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTDataType x)
{
	BSTreeNode* cur = *ppTree;
	while (cur)
	{
		if (cur->_data < x)
		{
			cur = cur->_right;
		}
		else if (cur->_data > x)
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}

	return NULL;
}

void BSTreeInOrder(BSTreeNode** ppTree)
{
	if (*ppTree == NULL)
	{
		return;
	}

	BSTreeInOrder(&(*ppTree)->_left);
	printf("%d ", (*ppTree)->_data);
	BSTreeInOrder(&(*ppTree)->_right);
}

void TestBSTree()
{
	int i = 0;
	BSTreeNode* pTree = NULL;
	int a[] = {5,3,4,1,7,8,2,6,0,9};
	for (; i < sizeof(a)/sizeof(int); ++i)
	{	
		BSTreeInsert(&pTree, a[i]);
	}

	BSTreeInOrder(&pTree);
	printf("\n");

	BSTreeRemove(&pTree, 2);
	BSTreeInOrder(&pTree);
	printf("\n");
	//BSTreeRemove(&ppTree, 1);
	//BSTreeRemove(&ppTree, 8);
	//BSTreeRemove(&ppTree, 5);

	//BSTreeInOrder(&ppTree);
	//printf("\n");

	//BSTreeRemove(&ppTree, 6);
	//BSTreeRemove(&ppTree, 5);


	/*BSTreeRemove(&ppTree, 0);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 1);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 2);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 3);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 4);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 5);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 6);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 7);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 8);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 9);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 10);
	BSTreeInOrder(&ppTree);
	printf("\n");*/

	//BSTreeInOrder(&ppTree);
	//printf("\n");
}

//int BSTreeInsertR(BSTreeNode** ppTree, BSTKeyType x)
//{
//	if (*ppTree == NULL)
//	{
//		*ppTree = BuyBSTreeNode(x);
//		return 1;
//	}
//
//	if ((*ppTree)->_key > x)
//		return BSTreeInsertR(&(*ppTree)->_left, x);
//	else if ((*ppTree)->_key < x)
//		return BSTreeInsertR(&(*ppTree)->_right, x);
//	else
//		return 0;
//}
//
//int BSTreeRemoveR(BSTreeNode** ppTree, BSTKeyType x)
//{
//	if (*ppTree == NULL)
//	{
//		return -1;
//	}
//
//	if ((*ppTree)->_key < x)
//	{
//		return BSTreeRemoveR(&((*ppTree)->_right), x);
//	}
//	else if ((*ppTree)->_key > x)
//	{
//		return BSTreeRemoveR(&((*ppTree)->_left), x);
//	}
//	else
//	{
//		BSTreeNode* del = *ppTree;
//
//		if ((*ppTree)->_left == NULL)
//		{
//			*ppTree = (*ppTree)->_right;
//
//			free(del);
//		}
//		else if ((*ppTree)->_right == NULL)
//		{
//			*ppTree = (*ppTree)->_left;
//
//			free(del);
//		}
//		else
//		{
//			BSTreeNode* replace = (*ppTree)->_right;
//			while (replace->_left)
//			{
//				replace = replace->_left;
//			}
//
//			(*ppTree)->_key = replace->_key;
//
//			return BSTreeRemoveR(&(*ppTree)->_right, replace->_key);
//		}
//	}
//
//	return 1;
//}
//
//BSTreeNode* BSTreeFindR(BSTreeNode** ppTree, BSTKeyType x)
//{
//	if (*ppTree == NULL)
//	{
//		return NULL;
//	}
//
//	if ((*ppTree)->_key > x)
//	{
//		return BSTreeFindR(&((*ppTree)->_left), x);
//	}
//	else if ((*ppTree)->_key < x)
//	{
//		return BSTreeFindR(&((*ppTree)->_right), x);
//	}
//	else
//	{
//		return *ppTree;
//	}
//}
//
//void TestBSTreeR()
//{
//	int i = 0;
//	BSTreeNode* pTree = NULL;
//	int a[] = {5,3,4,1,7,8,2,6,0,9};
//	for (; i < sizeof(a)/sizeof(int); ++i)
//	{	
//		BSTreeInsertR(&pTree, a[i]);
//	}
//
//	BSTreeRemoveR(&pTree, 0);
//	BSTreeRemoveR(&pTree, 1);
//	BSTreeRemoveR(&pTree, 2);
//	BSTreeRemoveR(&pTree, 3);
//	BSTreeRemoveR(&pTree, 4);
//	BSTreeRemoveR(&pTree, 5);
//	BSTreeRemoveR(&pTree, 6);
//	BSTreeRemoveR(&pTree, 7);
//	BSTreeRemoveR(&pTree, 8);
//	BSTreeRemoveR(&pTree, 9);
//	BSTreeRemoveR(&pTree, 10);
//
//	BSTreeInOrder(&pTree);
//	printf("\n");
//}

/////////////////////////////////////////////////////////////
// key 

//BSTreeNode* BuyBSTreeNode(BSTKeyType key, BSTValueType value)
//{
//	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
//	node->_left = NULL;
//	node->_right = NULL;
//	node->_key = (BSTKeyType)malloc(strlen(key) + 1);
//	strcpy(node->_key, key);
//	node->_value = value;
//
//	return node;
//}
//
//int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value)
//{
//	BSTreeNode* cur, *parent;
//	if (*ppTree == NULL)
//	{
//		*ppTree = BuyBSTreeNode(key, value);
//		return 1;
//	}
//
//	cur = *ppTree;
//	while (cur)
//	{
//		if (strcmp(cur->_key, key) > 0)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else if (strcmp(cur->_key, key) < 0)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	if (strcmp(parent->_key, key) < 0)
//	{
//		parent->_right = BuyBSTreeNode(key, value);
//	}
//	else
//	{
//		parent->_left = BuyBSTreeNode(key, value);
//	}
//
//	return 1;
//}
//
//BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key)
//{
//	BSTreeNode* cur = *ppTree;
//	while (cur)
//	{
//		if (strcmp(cur->_key, key) < 0)
//		{
//			cur = cur->_right;
//		}
//		else if (strcmp(cur->_key, key) > 0)
//		{
//			cur = cur->_left;
//		}
//		else
//		{
//			return cur;
//		}
//	}
//
//	return NULL;
//}
//
//void BSTreeInOrder(BSTreeNode** ppTree)
//{
//	BSTreeNode* root = *ppTree;
//	if (*ppTree == NULL)
//	{
//		return;
//	}
//
//	BSTreeInOrder(&root->_left);
//	printf("%s:%d\n", root->_key, root->_value);
//	BSTreeInOrder(&root->_right);
//}
//
////void TestBSTree1()
////{
////	char str[10];
////	BSTreeNode* pTree= NULL;
////	BSTreeInsert(&pTree, "insert");
////	BSTreeInsert(&pTree, "sort");
////	BSTreeInsert(&pTree, "find");
////	BSTreeInsert(&pTree, "tree");
////	BSTreeInsert(&pTree, "destory");
////
////	while (1)
////	{
////		scanf("%s", str);
////		if (BSTreeFind(&pTree, str))
////		{
////			printf("正确的单词\n");
////		}
////		else
////		{
////			printf("错误的单词\n");
////		}
////	}
////}
//
//void TestBSTree1()
//{
//	char str[10] = { '0' };
//	BSTreeNode* pTree = NULL;
//	while (1)
//	{
//		BSTreeNode* node;
//		scanf("%s", str);
//		if (strcmp(str, "exit") == 0)
//		{
//			break;
//		}
//
//		node = BSTreeFind(&pTree, str);
//		if (node)
//		{
//			node->_value++;
//		}
//		else
//		{
//			BSTreeInsert(&pTree, str, 1);
//		}
//	}
//
//	BSTreeInOrder(&pTree);
//}
int main()
{
 TestBSTree();
	return 0;
}
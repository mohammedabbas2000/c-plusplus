#pragma once
#ifndef _BINARY_TREE
#define _BINARY_TREE
typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};
node* NewNode(int);
node* Left(node*);
node* Right(node*);
node* randomInsertInto(node*, int);
node* randomTree();
void deleteTree(node*);
int height(node*);
void PrintGivenLevel(node*, int);
void PrintLevelOrder(node*);
void pre_order_traversal(node*);
void in_order_traversal(node*);
int isEmpty(node*);
int contains(node*, int);
int sumOfKeys(node*);
void printLeaves(node* root);
int countNodes(node* root);
void levelStatistics(node* root, int level);
int isPerfect(node*);
#endif

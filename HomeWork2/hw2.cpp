#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};
node* NewNode(int value)
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node* Left(node* root)
{
	return root->left;
}

node* Right(node* root)
{
	return root->right;
}

node* randomInsertInto(node* root, int value)
{
	if (root == NULL)
		root = NewNode(value);
	else if (rand() % 2 == 0)
		root->left = randomInsertInto(root->left, value);
	else
		root->right = randomInsertInto(root->right, value);
	return root;
}

node* randomTree()
{
	node* root = NULL;
	int size = 1 + rand() % 15;
	printf("\nsize=%d\n", size);
	int i;
	for (i = 1; i <= size; i++)
		root = randomInsertInto(root, 1 + rand() % 50);
	return root;
}

void deleteTree(node* root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int height(node* root)
{
	int Lh, Rh;
	if (root == NULL)
		return -1;
	Lh = height(root->left);
	Rh = height(root->right);
	if (Lh > Rh)
		return Lh + 1;
	else
		return Rh + 1;
}
void PrintGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d  ", root->data);
	else if (level > 1)
	{
		PrintGivenLevel(root->left, level - 1);
		PrintGivenLevel(root->right, level - 1);
	}
}
void PrintLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 0; i <= h + 1; i++)
	{
		PrintGivenLevel(root, i);
		printf("\n");
	}
}

void pre_order_traversal(node* root)
{
	if (root != NULL)
	{
		printf("%d  ", root->data);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void in_order_traversal(node* root)
{
	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d  ", root->data);
		in_order_traversal(root->right);
	}
}
//1.The int isEmpty function that receives a pointer to the root of a binary tree,
//And checks if the wood is empty.
//The function returns a value of 1 if the tree is empty, and 0 in another case.
int isEmpty(node* root) {
	
		if (root == NULL) return 1;
		else return 0;
	
}
//3.Function int contains(node * root, int key) that checks whether a key is in a binary tree.
//If a key appears in a tree, the function returns value 1
//If key does not appear in the tree - the function returns 0.
int contains(node* root, int key) {
	if (root == NULL)
		return 0;
	if (root->data == key)
		return 1;
	return contains(root->left, key) || contains(root->right, key);

}
//5.Function int sumOfKeys that calculates and returns the sum of the node values of a binary tree.
int sumOfKeys(node* root) {
	if (root == NULL)
		return 0;
	return (root->data + sumOfKeys(root->left) + sumOfKeys(root->right));
}
//2.Void printLeaves function that prints all leaves in a tree.
void printLeaves(node* root) {

	if (root != NULL)
	{
		if (root->right == NULL && root->left == NULL)
		{
			printf("%d  ", root->data);
		}
		printLeaves(root->left);
		printLeaves(root->right);;
	}
}
//4.Function int countNodes to calculate the total amount of nodes in a tree.
int countNodes(node* root) {
	if (!root)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}
//6.Void levelStatistics function that prints keys of all nodes that belong to the level level and also calculates and returns the number of nodes in the level.
void levelStatistics(node* root, int level) {
	static int count = 0;
	static int ll = level;

	if (root == NULL)
		return;
	if (level == 1) {
		printf("%d  ", root->data);
		count++;
	}
	else if (level > 1)
	{
		levelStatistics(root->left, level - 1);
		levelStatistics(root->right, level - 1);
	}
	if (level == ll)
		printf("count of roots of a level is %d ", count);
}
//7.The int isPerfect function that checks whether a tree is a perfect tree if the tree is paid, the function will return 1, otherwise it will return 0.
int isPerfect(node* root){
	int sum = 2;
	int h = height(root) - 1;
	for (int i = 0; i < h + 1; i++) {
		sum *= 2;
	}

	return sum - 1 == countNodes(root);
}
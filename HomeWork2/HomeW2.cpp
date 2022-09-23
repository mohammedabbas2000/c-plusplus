#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"hw2.h"

int main()
{
	srand(time(NULL));
	node* root;
	int H, num, NumToSearch, y;
	root = randomTree();
	H = height(root);
	printf("\n\nHeight of tree is %d\n", H);
	printf("\nLevels of Bynary Tree:\n");
	PrintLevelOrder(root);
	printf("\nPreorder Traversal tree\n");
	pre_order_traversal(root);
	printf("\n\nIn_order Traversal tree\n");
	in_order_traversal(root);
	printf("\n\nis the tree is empty : %d\n", isEmpty(root));//#1
	printf("\nThe Leaves of a nodes is: ");//#2
	printLeaves(root);//#2
	printf("\n enter number to check if number in tree:");//#3
	scanf("%d", &y);//#3
	printf("\n\is the number exists in the tree : %d\n", contains(root, y));//#3
	printf("\nThe count of a nodes is %d \n", countNodes(root));//#4
	printf("\n\nsum of the keys is: %d\n", sumOfKeys(root));//#5
	printf("\nIn level 3: ");//#6
	levelStatistics(root, 3);//#6
	printf("\n\is the tree is perfect : %d\n",isPerfect(root));//#7
	deleteTree(root);
	printf("\nTree deleted\n");
	return 0;
}
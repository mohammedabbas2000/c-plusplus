#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"hw3.h"

int main()
{
	BST *t = (BST*)malloc(sizeof(BST));
	t->root = NULL;
	insert(t, 208170009);
	insert(t, 323890001);
	insert(t, 222222222);
	insert(t, 333333333);
	updateExamGrade(t, 208170009, 70);
	updateMidtermGrade(t, 208170009, 100);
	updateExamGrade(t, 323890001, 60);
	updateMidtermGrade(t, 323890001, 100);
	updateExamGrade(t, 333333333, 100);
	updateMidtermGrade(t, 333333333, 85);
	updateExamGrade(t, 222222222, 70);
	updateMidtermGrade(t, 222222222, 95);
	reportstatistics(t);
	printf("%d\n", getNumOfFails(t));
	printf("Tree is:\n");
	printf("**************************************************\n");
	reportGrade(t);
	printf("**************************************************\n");

	freeTree(t); //free allocated memory!
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"hw1.h"

int main()
{
	list* head = NULL;
	int num, index;
	head = BuildList();
	PrintList(head);
	printf("\nEnter a number for new head node: ");
	scanf("%d", &num);
	head = addToHead(head, num);
	PrintList(head);

	printf("\nEnter a number for new tail node: ");
	scanf("%d", &num);
	head = addToTail(head, num);
	PrintList(head);

	printf("\nEnter a number and an index for new node: ");
	scanf("%d%d", &num, &index);
	head = addToIndex(head, num, index);
	PrintList(head);

	printf("\nSorted List: ");
	SelectionSort(head);
	PrintList(head);

	printf("\nEnter a value for delete: ");
	scanf("%d", &num);
	head = Delete(head, num);
	PrintList(head);
	printf("\nThe lenght of list is : ");
	printf("%d ", LinghtList(head));
	printf("\nThe sum of  the list is : ");
	printf("%d ", SumList(head));
	printf("\nEnter a number to find in which index it: ");
	scanf("%d", &num);
	FindIndex(head, num);

	printf("\nEnter a number for new node sort list: ");
	scanf("%d", &num);
	head = addNum(head, num);
	PrintList(head);

	head = Reverse_list(head);

	Product(head);
	head = FreeList(head);

	return 0;
}
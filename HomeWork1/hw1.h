#pragma once
#ifndef _LINKED_LIST
#define _LINKED_LIST
//#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
typedef struct List list;
struct List {
	int data;
	list* next;
};

list* BuildList();
void PrintList(list*);
list* BuildNode(int);
list* addToHead(list*, int);
list* addToTail(list*, int);
list* addToIndex(list*, int, int);
void SelectionSort(list*);
list* FreeList(list*);
list* Delete(list*, int);
int LinghtList(list*);
void FindIndex(list*,int);
int SumList(list*);
list* addNum(list * head, int value);
list* Reverse_list(list* head);
void Product(list* head);
#endif

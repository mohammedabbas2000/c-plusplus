#pragma once
#include <stdio.h>
#include<stdlib.h>
typedef struct Node {// the student struct
	int id;
	int mid_grade;
	int exam_grade;
	struct Node *left;
	struct Node *right;
	struct Node *parent;

} Node;
typedef struct BST {//binary searching tree struct
	struct Node *root;
} BST;
//1//This function introduces a new student with an ID.
void insert(BST *tree, int);
//2//Updates a score in the mid-quiz of a student with an ID number.
int  MidGrade(Node*, int, int);
void updateMidtermGrade(BST*, int, int);
//3//Updates the test score of a student with an ID number.
int ExamGrade(Node*, int, int);
void updateExamGrade(BST*, int, int);
//4//Returns the final score of a student with an ID number.
int getFinalGrade(BST*, int);
int FinalGrade(Node* , int);
//5//Returns the average in the final grades in the course.
double getAverageGrade(BST*);
double AverageGrade(Node*);
int count(Node*);//count of the student 
//6//Prints the student information on the screen, sorted by ID.
//Represent a student and contain the following information
void printNode(Node* node);
void reportGrade(BST* tree);
//7//Returns the number of course failures
int getNumOfFails(BST*);
int NumOfFails(Node*);
//8//Prints the number of students in the three grade grades represented on the screen
//Course Grades Statistics
void reportstatistics(BST*);
int NumOf56_75(Node*);
int NumOf76_94(Node*);
int NumOf95_100(Node*);
//free allocated memory!
void freeNodes(Node *node);
void freeTree(BST *tree);


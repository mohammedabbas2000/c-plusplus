#include<stdio.h>
#include<stdlib.h>
#include"hw3.h"
void insert(BST *tree, int id) {//This function introduces a new student with an ID.
	Node *newnode = (Node*)malloc(sizeof(Node));

	newnode->id = id;
	newnode->mid_grade = 0;
	newnode->exam_grade = 0;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;

	Node *y = NULL;
	Node *x = tree->root;

	while (x != NULL) {
		y = x;
		if (newnode->id < x->id)
			x = x->left;
		else
			x = x->right;
	}
	newnode->parent = y;
	if (y == NULL) // there was empty tree
		tree->root = newnode;
	else if (y->id > id)
	{
		y->left = newnode;
	}
	else
	{
		y->right = newnode;
	}
}
void freeNodes(Node *node) { //free allocated memory!!!
	if (node == NULL)
		return;
	freeNodes(node->left);
	freeNodes(node->right);
	free(node);
}

void freeTree(BST *tree) { //free allocated memory!!!
	freeNodes(tree->root);
}

int ExamGrade(Node* node, int id,int newGrade)//3//Updates the test score of a student with an ID number.
{
	if (node == NULL)
		return 0;
	if (node->id == id)
		node->exam_grade = newGrade;
	if (id <= node->id)
		return ExamGrade(node->left, id, newGrade);
	else
		return ExamGrade(node->right, id, newGrade);
}
void updateExamGrade(BST* tree, int id, int newGrade)//3//Updates the test score of a student with an ID number.
{
	 ExamGrade(tree->root, id, newGrade);
}

int MidGrade(Node* node, int id, int newGrade)//Updates a score in the mid-quiz of a student with an ID number.
{
	if (node == NULL)
		return 0;
	if (node->id == id)
		node->mid_grade = newGrade;
	if (id <= node->id)
		return  MidGrade(node->left, id, newGrade);
	else
		return  MidGrade(node->right, id, newGrade);
}
void updateMidtermGrade(BST* tree, int id, int newGrade)//Updates a score in the mid-quiz of a student with an ID number.
{
	MidGrade(tree->root, id, newGrade);
}
int getFinalGrade(BST * tree, int id)//Returns the final score of a student with an ID number.
{
	return FinalGrade(tree->root, id);
}
int FinalGrade(Node* node, int id)//Returns the final score of a student with an ID number.
{
	if (node == NULL)
		return 0;
	if (node->id == id) {
		float sum = float((float(node->exam_grade * 70) / 100) + (float(node->mid_grade * 30) / 100));
		int sum2 = int(sum);
		if ((sum - sum2) >= 0.5)
			return sum2 + 1;
		else
			return sum2;

	}
	if (id <= node->id)
		return  FinalGrade(node->left, id);
	else
		return  FinalGrade(node->right, id);
}
double getAverageGrade(BST* tree) {//Returns the average in the final grades in the course.
	return AverageGrade(tree->root)/ count(tree->root);

}
double AverageGrade(Node* root) {//Returns the average in the final grades in the course.
	
	if (root == NULL)
		return 0;

	return (FinalGrade(root, root->id) + AverageGrade(root->left) + AverageGrade(root->right));
}
int count(Node* root) {//count of the student 

	if (root == NULL)
		return 0;

	return 1 + count(root->left) + count(root->right);
}
void printNode(Node* node) {//Prints the student information on the screen, sorted by ID.
	if (node == NULL) {
		return;
	}

	printNode(node->left);
	printf("\n");
	printf("%d", node->id);
	printf(" %d", node->mid_grade);
	printf(" %d", node->exam_grade);
	printf(" %d", FinalGrade(node, node->id));
	printNode(node->right);

}
void reportGrade(BST* tree) {//Prints the student information on the screen, sorted by ID.
	printNode(tree->root);
	printf("\n");
}
int getNumOfFails(BST* tree) {//Returns the number of course failures
	return NumOfFails(tree->root);
}
int NumOfFails(Node* node) {//Returns the number of course failures
	if (node == NULL)
		return 0;
	if(FinalGrade(node, node->id)>56)
		return NumOfFails(node->left) + NumOfFails(node->right);
	else
		return 1+ NumOfFails(node->left) + NumOfFails(node->right);
}
void reportstatistics(BST* tree) {//Prints the number of students in the three grade grades represented on the screen
	printf("\n");
	printf("             Degree      final grade\n");
	printf("Good        (56-75)          %d\n",NumOf56_75(tree->root));
	printf("Vrey Good   (76-94)          %d\n",NumOf76_94(tree->root));
	printf("Excellent   (95-100)         %d\n",NumOf95_100(tree->root));

}
int NumOf56_75(Node* node) {//return the number of students that there grade between 56-75
	if (node == NULL)
		return 0;
	if(FinalGrade(node, node->id)>=56 && FinalGrade(node, node->id) <= 75)
		return 1 + NumOf56_75(node->left) + NumOf56_75(node->right);
	else
		return NumOf56_75(node->left) + NumOf56_75(node->right);
}
int NumOf76_94(Node* node) {//return the number of students that there grade between 76-94
	if (node == NULL)
		return 0;
	if (FinalGrade(node, node->id) >= 76 && FinalGrade(node, node->id) <= 94)
		return 1 + NumOf76_94(node->left) + NumOf76_94(node->right);
	else
		return NumOf76_94(node->left) + NumOf76_94(node->right);
}
int NumOf95_100(Node* node) {//return the number of students that there grade between 95-100
	if (node == NULL)
		return 0;
	if (FinalGrade(node, node->id) >= 95 && FinalGrade(node, node->id) <= 100)
		return 1 + NumOf95_100(node->left) + NumOf95_100(node->right);
	else
		return  NumOf95_100(node->left) + NumOf95_100(node->right);
}
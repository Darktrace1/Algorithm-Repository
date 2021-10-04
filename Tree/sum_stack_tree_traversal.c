#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;

int top = -1;
element Stack[SIZE];

// stack 구현
void push(element root);
element pop(void);

void preorder(element root);

TreeNode n1 = {1, NULL, NULL}; 
TreeNode n2 = {16, NULL, NULL}; 
TreeNode n3 = {25, NULL, NULL}; 
TreeNode n4 = {4, &n1, NULL}; 
TreeNode n5 = {20, &n2, &n3}; 
TreeNode n6 = {15, &n4, &n5};
element root = &n6;

int main(void) {
	printf("전위순회: "); preorder(root);
	printf("\n");
}

void push(element root) {
	Stack[top++] = root;
}

element pop(void) {
	element p = NULL;
	p = Stack[--top];
	return p;
}

void preorder(element root) {
	push(root);

	while(1) {
		
		root = pop();
		if(!root) break;
		
		printf("%d ", root->value);

		if(root->right != NULL)
			push(root->right);
		if(root->left != NULL)
			push(root->left);
	}
}

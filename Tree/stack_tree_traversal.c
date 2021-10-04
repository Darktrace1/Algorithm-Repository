#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;

int top = -1;
element Stack[SIZE];

TreeNode n1 = {1, NULL, NULL}; 
TreeNode n2 = {16, NULL, NULL}; 
TreeNode n3 = {25, NULL, NULL}; 
TreeNode n4 = {4, &n1, NULL}; 
TreeNode n5 = {20, &n2, &n3}; 
TreeNode n6 = {15, &n4, &n5};
element root = &n6;

// stack 구현
void push(element root);
element pop(void);

// traversal 구현
void preorder(element root);
void inorder(element root);
void postorder(element root);

int main(void) {
	printf("전위순회: "); preorder(root);
	printf("\n");
	printf("중위순회: "); inorder(root);
	printf("\n");
	printf("후위순회: "); postorder(root);
	printf("\n");
}

void push(element root) {
		Stack[++top] = root;
}

element pop(void) {
	element p = NULL;
	
	p = Stack[top--];
	return p;
}

void preorder(element root){
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

void inorder(element root){
	while(1) {
		for(; root; root = root->left)
			push(root);
		
		root = pop();
		if(!root) break;
		
		printf("%d ", root->value);
		root = root->right;	
	}
}

void postorder(element root){
	while(1) {
		do {
			if(root->value != -1 && root != NULL) {
				push(root);
				root = root->left;
			}
			else break;
		}while(root != NULL);

		root = pop();
		if(!root) break;
		
		if(root->right != NULL) {
			if(root->right->value == -1) {
				printf("%d ", root->value);
				root->value = -1;
			}
			else {
				push(root);
				root = root->right;
			}
		}
		else {
			printf("%d ", root->value);
			root->value = -1;
		}
	}

}


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;

//       15
//     4    20
//   1    16  25

TreeNode n1 = {1, NULL, NULL}; 
TreeNode n2 = {16, NULL, NULL}; 
TreeNode n3 = {25, NULL, NULL}; 
TreeNode n4 = {4, &n1, NULL}; 
TreeNode n5 = {20, &n2, &n3}; 
TreeNode n6 = {15, &n4, &n5};
element root = &n6;

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

	return 0;
}

void preorder(element root) {
	if(root) {
		printf("%d ", root->value);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(element root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->value);
		inorder(root->right);
	}
}

void postorder(element root) {
	if(root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->value);
	}
}

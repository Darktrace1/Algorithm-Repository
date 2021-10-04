#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;
int sum = 0;

void preorder(element root);

TreeNode n1 = {1, NULL, NULL}; 
TreeNode n2 = {16, NULL, NULL}; 
TreeNode n3 = {25, NULL, NULL}; 
TreeNode n4 = {4, &n1, NULL}; 
TreeNode n5 = {20, &n2, &n3}; 
TreeNode n6 = {15, &n4, &n5};
element root = &n6;

int main(void) {
	printf("전위순회: "); 
	preorder(root);
	printf("이 트리의 모든 노드의 합은 %d이다.\n", sum);
	return 0;
}

void preorder(element root) {
	if(root) {
		printf("%d ", root->value);
		sum += root->value;
		preorder(root->left);
		preorder(root->right);
	}
}

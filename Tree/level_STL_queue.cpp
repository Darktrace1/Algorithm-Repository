#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct TreeNode	{
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;
queue<element> q;

void level_order(element root);

TreeNode n1 = {1, NULL, NULL}; 
TreeNode n2 = {16, NULL, NULL}; 
TreeNode n3 = {25, NULL, NULL}; 
TreeNode n4 = {4, &n1, NULL}; 
TreeNode n5 = {20, &n2, &n3}; 
TreeNode n6 = {15, &n4, &n5};
element root = &n6;

int main(void) {
	
	printf("레벨순회: "); level_order(root);
	printf("\n");
}

void level_order(element root) {
	q.push(root);
	
	if(root == NULL) return;

	while(!q.empty()) {
		root = q.front();
		q.pop();
		printf("%d ", root->value);
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}

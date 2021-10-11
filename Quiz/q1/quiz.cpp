#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
	int value;
	struct Node *left, *right;
}Node;

queue<Node*> q;
stack<Node*> s;

Node* make_tree(void);
void level_order(Node* root);
void pre_order(Node* root);
void find_leafnodes(Node* root);
void find_max(Node* root);

int main(void) {
	Node* root = make_tree();
	level_order(root);
	pre_order(root);
  find_leafnodes(root);
  find_max(root);
	return 0;
}
//      1
//   2     3
// 4     5   6
//         7
//

Node* make_tree(void) {
	Node *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	n1 = (Node* ) malloc(sizeof(Node));
	n2 = (Node* ) malloc(sizeof(Node));
	n3 = (Node* ) malloc(sizeof(Node));
	n4 = (Node* ) malloc(sizeof(Node));
	n5 = (Node* ) malloc(sizeof(Node));
	n6 = (Node* ) malloc(sizeof(Node));
	n7 = (Node* ) malloc(sizeof(Node));

	n1->value = 4;
	n1->left = n1->right = NULL;
	
	n2->value = 7;
	n2->left = n2->right = NULL;
	
	n3->value = 6;
	n3->left = n3->right = NULL;

	n4->value = 5;
	n4->left = NULL;
	n4->right = n2;

	n5->value = 2;
	n5->left = n1;
	n5->right = NULL;
	
	n6->value = 3;
	n6->left = n4;
	n6->right = n3;

	n7->value = 1;
	n7->left = n5;
	n7->right = n6;


	Node* root = n7;
	return root;
}

void level_order(Node *root) {
	printf("[Level order] ");
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
	printf("\n[Pre order] ");
}

void pre_order(Node *root) {
	if(root) {
	printf("%d ", root->value);
	pre_order(root->left);
	pre_order(root->right);
	}
}

void find_leafnodes(Node* root) {
	int arr[3], i = 0;

	while(1) {
		for( ; root; root = root->left) {
			s.push(root);
			if((root->left == NULL) && (root->right == NULL))
				arr[i++] = (root->value);
		}

		if(!s.empty()){
			root = s.top();
			s.pop();
		}
		else
			root = NULL;

		if(root == NULL) break;
		root = root->right;
	}
	printf("\n[Leaf nodes] ");
	for(int j = 0; j < 3; j++)
		printf("%d ", arr[j]);
	printf("\n");
}

void find_max(Node* root) {
	int temp = root->value;

	while(1) {
		for( ; root; root = root->left) {
			s.push(root);
			if(temp < root->value)
				temp = root->value;
		}
		
		if(!s.empty()){
			root = s.top();
			s.pop();
		}
		else
			root = NULL;
		if(root == NULL) break;
		root = root->right;
	}
	printf("[Max] %d\n", temp);
}


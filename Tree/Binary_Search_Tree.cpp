#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>
using namespace std;

typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;
queue<element> q;

void menu(void);
element alloc_newnode(int, element, element);
element maketree(void);
element search(element, int);
element insert(element, int);
element delete_node(element, int);
element max_value(element);
void deleteTree(element);
void level_order(element);

int main(void) {
	int menu_num, search_data;
	bool loop = true;
	element root = maketree();

	while(loop) {
		menu();
		scanf("%d", &menu_num);
		switch(menu_num) {
			case 1 :
				printf("Input search data: ");
				scanf("%d", &search_data);

				if(search(root, search_data) != NULL) {
					printf("%d searched!\n", search_data);
				}
				else {
					printf("%d can't searched!\n", search_data);
				}
				level_order(root); 
				printf("\n");
				break;

			case 2 :
				printf("Input insert data: ");
				scanf("%d", &search_data);

				if(insert(root, search_data))
					printf("%d inserted!\n", search_data);

				level_order(root); printf("\n");
				break;

			case 3 :
				printf("Input delete data: ");
				scanf("%d", &search_data);

				if(delete_node(root, search_data) != NULL)
					printf("%d deleted!\n", search_data);

				level_order(root); printf("\n");
				break;

			case 4 :
				loop = false;
				break;
		}
	}
	deleteTree(root);
	
	return 0;
}

void menu(void) {
	printf("1. search\n");
	printf("2. insert\n");
	printf("3. delete\n");
	printf("4. quit\n");
	printf("-> ");
}

element alloc_newnode(int data, element l, element r) {
	element newnode = 
		(element ) malloc(sizeof(TreeNode));

	newnode->value = data;
	newnode->left = l;
	newnode->right = r;

	return newnode;
}

element maketree(void) {
	element n10 = alloc_newnode(30, NULL, NULL);
	element n9 = alloc_newnode(22, NULL, NULL);
	element n8 = alloc_newnode(12, NULL, NULL);
	element n7 = alloc_newnode(3, NULL, NULL);
	element n6 = alloc_newnode(99, NULL, NULL);
	element n5 = alloc_newnode(26, n9, n10);
	element n4 = alloc_newnode(7, n7, n8);
	element n3 = alloc_newnode(68, NULL, n6);
	element n2 = alloc_newnode(18, n4, n5);
	element n1 = alloc_newnode(35, n2, n3);
	element root = n1;

	return root;
}

element search(element ptr, int key) {
	if(ptr == NULL) return NULL;
	if(ptr->value == key) 
		return ptr;
	else if(ptr->value > key)
		return search(ptr->left, key);
	else
		return search(ptr->right, key);
}

element insert(element ptr, int key) {
	if(ptr == NULL) return alloc_newnode(key, NULL, NULL);

	if(ptr->value > key) 
		ptr->left = insert(ptr->left, key);
	else
		ptr->right = insert(ptr->right, key);

	return ptr;
}

element delete_node(element ptr, int key) {
	if(ptr == NULL) return ptr;

	if(ptr->value > key)
		ptr->left = delete_node(ptr->left, key);

	else if(ptr->value < key)
		ptr->right = delete_node(ptr->right, key);
	
	else {
		// 0 or 1
		if(ptr->left == NULL) {
			element tmp = ptr->right;
			free(ptr);
			return tmp;
		}
		else if(ptr->right == NULL) {
			element tmp = ptr->left;
			free(ptr);
			return tmp;
		}

		element tmp = max_value(ptr->left);

		ptr->value = tmp->value;

		ptr->left = delete_node(ptr->left, tmp->value);
	}
	return ptr;
}

element max_value(element ptr) {
	while(ptr && ptr->right) {
		ptr = ptr->right;
	}
	return ptr;
}
/*
void deleteTree(element *ptr) {
	if((*ptr) != NULL) {
		deleteTree(&(*ptr)->left);
		deleteTree(&(*ptr)->right);
		free(*ptr);
	}
}
*/
void deleteTree(element ptr) {
	if((ptr) != NULL) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		free(ptr);
	}
}

void level_order(element ptr) {
	q.push(ptr);
	
	if(ptr == NULL) return;

	while(!q.empty()) {
		ptr = q.front();
		q.pop();
		printf("%d ", ptr->value);

		if(ptr->left)
			q.push(ptr->left);
		if(ptr->right)
			q.push(ptr->right);
	}
}

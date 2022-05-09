#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode element;

int input(void);
element* alloc_newnode(int, element *, element *);
element* search(element *, int);
element* insert(element *, int);
void deleteTree(element *);

int main(void) {
	int N = input();
	int key, root_data;

	root_data = input();
	element *root = alloc_newnode(root_data, NULL, NULL);

	for(int i = 0; i < N-1; i++) {
		key = input();
		if(insert(root, key))
			continue;
	}

	int M = input();
	int *arr = (int *) malloc(sizeof(int) * M);

	for(int i = 0; i < M; i++) {
		key = input();
		if((search(root, key)) != NULL) {
			arr[i] = 1;
		} 
		else
			arr[i] = 0;
	}

	for(int i = 0; i < M; i++)
		printf("%d\n", arr[i]);

	free(arr);
}

int input(void) {
	int num;
	scanf("%d", &num);
	return num;
}

element* alloc_newnode(int data, element *l, element *r) {
	element *newnode = 
		(element *) malloc(sizeof(element));

	newnode->value = data;
	newnode->left = l;
	newnode->right = r;

	return newnode;
}

element* search(element *ptr, int key) {
	if(ptr == NULL) return NULL;

	if(key == ptr->value)
		return ptr;

	else if(key < ptr->value)
		return search(ptr->left, key);

	else
		return search(ptr->right, key);
}

element* insert(element *ptr, int key) {
	if(ptr == NULL) return alloc_newnode(key, NULL, NULL);

	if(key == ptr->value) return ptr;

	else if(key < ptr->value)
		ptr->left = insert(ptr->left, key);

	else
		ptr->right = insert(ptr->right, key);

	return ptr;
}

void deleteTree(element * ptr) {
	if(ptr) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		free(ptr);
	}
}


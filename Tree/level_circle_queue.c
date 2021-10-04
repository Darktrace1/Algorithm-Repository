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
typedef int boolean;

typedef struct CircleQueue {
	int front, rear;
	element data[SIZE];
}Queue;

// 원형 큐 구현
void init_Queue(Queue *q);
boolean is_empty(Queue *q);
boolean is_full(Queue *q);
void enqueue(Queue *q, element root);
element dequeue(Queue *q);

void level_order(element root);

TreeNode n1 = {1, NULL, NULL}; 
TreeNode n2 = {16, NULL, NULL}; 
TreeNode n3 = {25, NULL, NULL}; 
TreeNode n4 = {4, &n1, NULL}; 
TreeNode n5 = {20, &n2, &n3}; 
TreeNode n6 = {15, &n4, &n5};
element root = &n6;

int main(void) {
	Queue q;
	printf("레벨순회: "); level_order(root);
	printf("\n");
	return 0;
}

void init_Queue(Queue *q) {
	q->front = q->rear = 0;
}

boolean is_empty(Queue *q) {
	if(q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}

boolean is_full(Queue *q) {
	if((q->rear + 1) % SIZE == q->front)
		return TRUE;
	else
		return FALSE;
}

void enqueue(Queue *q, element root) {
	if(is_full(q)) {
		printf("Queue is full!\n");
		exit(1);
	}
	else {
		q->rear = (q->rear + 1) % SIZE;
		q->data[q->rear] = root;
	}
}

element dequeue(Queue *q) {
	if(is_empty(q)) {
		printf("Queue is empty!\n");
		exit(1);
	}
	else {
		q->front = (q->front + 1) % SIZE;
		return q->data[q->front];
	}
}

void level_order(element ptr) {
	Queue q;

	init_Queue(&q);
	if(ptr == NULL) return;
		
	enqueue(&q, ptr);
	while(!is_empty(&q)) {
		ptr = dequeue(&q);

		printf("%d ", ptr->value);

		if(ptr->left != NULL)
			enqueue(&q, ptr->left);
		if(ptr->right != NULL)
			enqueue(&q, ptr->right);
	}
}



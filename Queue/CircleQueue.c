#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef int boolean; 

typedef struct circleQueue {
	int rear;
	int front;
	element *data;
}Queue;

void print(void);
void init_queue(Queue *q, int size);
boolean is_empty(Queue* q); 
void enqueue(Queue *q, element data, int size);
element dequeue(Queue *q, int size);
boolean is_full(Queue *q, int size);
void queue_print(Queue q, int size);

void main(void) {
	Queue q;

	int size = 0, menu, value, pop_data;
	bool loop = true;

	printf("Queue's Size: ");
	scanf("%d", &size);

	init_queue(&q, size);

	while(loop) {
		print();
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Input value: ");
				scanf("%d", &value);
				if(is_full(&q, size))
					printf("Queue is full!\n");
				else {
					enqueue(&q, value, size);
					printf("%d Pushed!\n", value);
				}
				break;
			case 2:
				if(is_empty(&q))
					printf("Queue is Empty!\n");
				else {
					pop_data = dequeue(&q, size);
					printf("%d Popped!\n", pop_data);
				}
				break;
			case 3:
				queue_print(q, size);
				break;
			case 4:
				loop = false;
				break;
		}
	}
	free(q.data);
}

void print(void) {
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Show Queue\n");
	printf("4. Quit\n");
	printf("->");
}

// initialize Queue
void init_queue(Queue *q, int size) {
	q->front = 0;
	q->rear = 0;
	q->data = (element* ) malloc(sizeof(element) * size );
}

// When queue's front and rear are same, The Queue is empty!
boolean is_empty(Queue *q) {
	if(q->front == q->rear) 
		return TRUE;
	else 
		return FALSE;
}

void enqueue(Queue *q, element data, int size) {
	if(is_full(q, size)) {
		printf("큐가 포화상태입니다.\n");
		return;
	}
	
	else {
		q->rear = (q->rear + 1) % size; // Because of circleQueue's size 
		q->data[q->rear] = data;
	}
}

element dequeue(Queue *q, int size) {
	if(is_empty(q))
		printf("Queue is Empty!\n");

	q->front = (q->front + 1) % size;
	return q->data[q->front];
}

boolean is_full(Queue *q, int size) {
	if(((q->rear + 1) % size) == q->front)
		return TRUE;
	else
		return FALSE;
}

void queue_print(Queue q, int size) {
	int i = q.front;
	if(is_empty(&q)) { 
		printf("Queue is Empty!\n");
		return;
	}
	do {
		i = (i + 1) % size;
		printf("%d ", q.data[i]);
		if(i == q.rear)
			break;
	}while(i != q.front);
	printf("\n");
}

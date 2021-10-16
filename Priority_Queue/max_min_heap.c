#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[SIZE];
	int heap_size;
}Heap;

Heap* create(void);
void init(Heap*);
void insert_max_heap(Heap *, element);
void insert_min_value(Heap *, element);
element delete_max_heap(Heap *);
element delete_min_heap(Heap *);

int main(void) {
	element e4, e5, e6;
	
  element	e1 = { 20 }, e2 = { 30 }, e3 = { 10 };

	Heap *heap = create();
	init(heap);

	insert_min_value(heap, e1);
	insert_min_value(heap, e2);
	insert_min_value(heap, e3);

	for(int i = 1; i <= heap->heap_size; i++)
		printf("%d ", heap->heap[i].key);
	printf("\n");

	e4 = delete_min_heap(heap);
	printf("%d ", e4.key);
	e5 = delete_min_heap(heap);
	printf("%d ", e5.key);
	e6 = delete_min_heap(heap);
	printf("%d ", e6.key);

	free(heap);
	printf("\n");
	return 0;
}

Heap* create(void) {
	return (Heap *) malloc(sizeof(Heap));
}

void init(Heap* h) {
	h->heap_size = 0;
}

void insert_max_heap(Heap *h, element item) {
	int i;
	i = ++(h->heap_size);

	while(i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

void insert_min_value(Heap *h, element item) {
	int i;
	i = ++(h->heap_size);

	while(i != 1 && item.key < h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(Heap *h) {
	int parent = 1, child = 2;
	element item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];

	while(child <= h->heap_size) {
		if(child < h->heap_size && h->heap[child + 1].key > h->heap[child].key)
			break;

		if(tmp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];

		parent = child;

		child *= 2; 
	}
	h->heap[parent] = tmp;
	return item;
}

element delete_min_heap(Heap *h) {
	int parent = 1, child = 2;
	element item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	
	while(child <= h->heap_size) {
		if(child < h->heap_size && h->heap[child + 1].key < h->heap[child].key)
			child++;

		if(tmp.key <= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];

		parent = child;

		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int age;
	char name[100];
}element;

typedef struct {
	int size;
	element *heap;
}Heap;

Heap* create(void);
void init(Heap *, int);
void insert_max_heap(Heap *, element);
element delete_max_heap(Heap *);
void heap_sort(element *, int);

int main(int argc, char* argv[]) {
	int size;
	scanf("%d", &size);

	element *arr = 
		(element *) malloc(sizeof(element) * size);

	for(int i = 0; i < size; i++) {
		scanf("%d %s", &arr[i].age, arr[i].name);
	}



	heap_sort(arr, size);

	//for(int i = 0; i < size; i++) {
	//	printf("%d %s\n", arr[i].age, arr[i].name);
	//}
	//printf("\n");

	free(arr);
	return 0;
}

Heap* create() {
	return (Heap *) malloc(sizeof(Heap));
}

void init(Heap *h, int n) {
	h->size = 0;
	h->heap = 
		(element *) malloc(sizeof(element) * n);
}

void insert_max_heap(Heap *h, element item) {
	int i = ++(h->size);

	while(i != 1 && item.age > h->heap[i / 2].age) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(Heap *h) {
	int parent = 1, child = 2;
	element root = h->heap[1];
	element tmp = h->heap[(h->size)--];

	while(child <= h->size) {
		if(child < h->size && h->heap[child + 1].age > h->heap[child].age)
			child++;

		if(tmp.age >= h->heap[child].age) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return root;
}

void heap_sort(element *item, int size) {
	Heap *heap = create();
	init(heap, size);

	int i;
	for(i = 0; i < size; i++) 
		insert_max_heap(heap, item[i]);

	for(i = 0; i < size; i++) {
		item[i] = delete_max_heap(heap);
		printf("%d %s\n", item[i].age, item[i].name);
		for(int j = i; j < size; j++) {
			if(item[i].age == item[j].age) {
				printf("%d %s\n", item[j].age, item[j].name);
				break;
			}
		}	
	}
		item[i]	= delete_max_heap(heap);

	free(heap);
	heap = NULL;
}

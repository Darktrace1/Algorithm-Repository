#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define print(x) printf("\n");

typedef struct stack {
	int top;
	int *data;
	int max;
}Stack;

void menu(void);
void StackInitialize(Stack* stk, int size);
void StackPush(Stack* stk, int value);
int StackPop(Stack* stk);
void StackShow(Stack* stk);
int StackPeek(Stack* stk);
int StackIsEmpty(Stack* stk);
int StackSize(Stack* stk);


int main(int argc, char* argv[]) {
	bool loop = true;
	int menu_sel = 0, data = 0;
	int pop_data = 0;
	
	Stack s;
	StackInitialize(&s, 5);
	
	while(loop) {
	menu();
	scanf("%d", &menu_sel);

	switch(menu_sel) {
		case 1 :
			printf("INPUT: ");
			scanf("%d", &data);
			
			StackPush(&s, data);
			break;

		case 2 :
			pop_data = StackPop(&s);	
			break;

		case 3 :
			StackShow(&s);
			break;

		case 4 :
			loop = false;
			break;
			
		}
	}
	return 0;
}

void menu(void) {
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. SHOW STACK\n");
	printf("4. Exit\n");
	printf("->");
}

// Reset
void StackInitialize(Stack* stk, int size) {
	stk->top = -1;
	stk->data = (int*)malloc(size*sizeof(int));
	stk->max = size;
}

// Push
void StackPush(Stack* stk, int value) {
	if(stk->top < stk->max - 1) {
		stk->top++;
		stk->data[stk->top] = value;
		printf("%d PUSHED!", value);
		print(x);
	}
	else {
		stk->max = stk->max*2;
		stk->data = (int*)realloc(stk->data, stk->max * sizeof(int));
		printf("Stack size double... size: %d", stk->max);
		print(x);
		StackPush(stk, value);
	}
}

// Pop
int StackPop(Stack* stk) {
	if(stk->top >= 0) {
		int value = stk->data[stk->top];
		stk->top--;
		printf("-> value popped: %d", value);
		print(x);
		return value;
	}
	printf("Stack is Empty!");
	print(x);
}

// Show all data in stack
void StackShow(Stack* stk) {
	if(StackIsEmpty(stk)) {
		printf("Stack is Empty!\n");
	}
	else {
		printf("[Show Stack]\n");
		printf("Stack_Size: %d, Max_Stack_Size: %d\n", StackSize(stk), stk->max);
		StackIsEmpty(stk) ? printf("(Stack is Empty)\n") : printf("(Stack is not empty)\n");
		printf("Top of the Stack: %d\n", StackPeek(stk));
		
		printf("[");
		for(int i = StackSize(stk) - 1; i >= 0; i--)
			printf("%d, ", stk->data[i]);

		printf("]\n");
	}

}

// Show top data
int StackPeek(Stack* stk) {
	int temp;
	if(stk->top >= 0) {
		temp = stk->data[stk->top];
		return temp;
	}
	else {
		printf("Stack is Empty\n");
		return 0;
	}
}

// Empty stack
int StackIsEmpty(Stack* stk) {
	return(stk->top == -1);
}

// Stack Size
int StackSize(Stack* stk) {
	return(stk->top+1);
}

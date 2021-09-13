#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

char stack[SIZE];
int top = -1;

int isFull(void) {
	if(top >= SIZE - 1) {
		printf("Error: Stack is Full!\n");
		return 1;
	}
	else
		return 0;
}

int isEmpty(void) {
	if(top == -1) {
		printf("Error: Stack is Empty\n");
		return 1;
	}
	else
		return 0;
}

void push(int data) {
	if(!isFull()) {
		top++;
		stack[top] = data;
	}
}

char pop(void) {
	if(!isEmpty()) {
		char temp = stack[top];
		top--;
		return temp;
	}
}

int peek(void) {
	if(!isEmpty())
		return stack[top];
}

void printstack(void) {
	if(!isEmpty()) {
			for(int i = 0; i < top; i++)
				printf("%d ", stack[i]);
		
			printf("\n");
	}
}

void menu() {
	printf("1. push\n");
	printf("2. pop\n");
	printf("3. exit\n");
	printf("->");
}

int main(int argc, char* argv[]) {
	bool loop = true;
	int x;
	int data, temp;
	
	while(loop) {
	menu();
	scanf("%d", &x);

		switch(x) {
			case 1:
				printf("INPUT: ");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				temp = pop();
				printf("%d Popped!\n", temp);
				break;

			case 3:
				loop = false;
				break;
			}
	}
	return 0;
}

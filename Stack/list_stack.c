/*
학번: 5532545
학과: 컴퓨터공학과
이름: 김진범

리스트로 스택 구현하기
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack { // Stack 정의
	int data;
	struct Stack* next;
}Stack;

//필요한 함수 선언문
void menu(void); 	// menu 출력
int isEmpty(Stack **top);  // Stack이 비어있는지 확인
void PUSH(Stack **top, int value); // Stack에 data value 보관
void POP(Stack **top); // Stack에서 data value 꺼냄

int main(void) {
	Stack* top = NULL;	// 스택의 TOP(맨 앞 노드)을 선언
	
	int num, value;
	bool loop = true;

	while(loop) {
		menu();
		scanf("%d", &num);
	
		switch(num) {
			case 1:
				printf("INPUT: ");	// 삽입하고자 하는 data value 입력
				scanf("%d", &value);
				PUSH(&top, value);	// TOP의 주소값과 data value 전달
				break;

			case 2:
				if (!isEmpty(&top)) // Stack이 비어있지 않을때(Top이 NULL이 아닐때)
					POP(&top);	// Top의 주소값을 전달
				else
					printf("STACK IS EMPTY!\n"); // Stack이 비었을때는 해당 문구 출력
				break;

			case 3:
				loop = false; // loop에 false대입하여 반복문 종료
				break;
		}
	}
	return 0;
}

void menu(void) {
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.QUIT\n");
	printf("->");
}

int isEmpty(Stack **top) {
	return (*top == NULL); // Top이 NULL이면 비어있는 상태
}

void PUSH(Stack **top, int value) {
	Stack *p = (Stack *) malloc(sizeof(Stack)); // 새로운 노드 할당(생성)
	
	p->data = value;	// 새 노드에 data value 입력
	p->next = *top;		// 새 노드의 next를 top으로 설정
	*top = p;	// Stack의 Top을 새 노드 p로 설정

	printf("%d Pushed!\n", value);
}

void POP(Stack **top) {
	Stack *remove;	
	
	remove = *top; // remove를 top으로 설정
	*top = remove->next; // 제거하고자 하는 값의 next를 top으로 설정
	printf("%d Popped!\n", remove->data); // 꺼낸 값을 출력하여 알려줌
	free(remove); // 필요없는 값 제거
}

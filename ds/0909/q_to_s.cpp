
#include <queue>
using namespace std;

void menu(void);															// menu 출력하는 함수 선언
void push(int x);															// queue로 stack을 구현하는 함수 선언

queue<int> q1;																// 전역변수로 두개의 queue를 선언
queue<int> q2;

int main(int argc, char* argv[]) {
	
	int menu_num = 0;
	int x;																			// queue에 담기는 data value 담는 변수 선언
	
	bool boolean = true;												// while 종료를 위한 bool 변수 선언

	while(boolean) {
		menu();
		scanf("%d", &menu_num);										// 메뉴 선택 후 

		switch (menu_num) {
			case 1:																	// 1번 메뉴 선택시
				printf("INPUT: ");		
				scanf("%d", &x);											// data value 입력받은 후

				printf("%d PUSHED!\n", x);

				push(x);															// 입력 받은 data를 push 함수로 전달
				break;
			
			case 2:																	// 2번 메뉴 선택시
				if(q1.empty())												// queue로 구현된 stack가 비어있다면
					printf("STACK IS EMPTY\n");					// 비어있다고 출력
				else {																// 그렇지 않다면
					printf("%d POPPED!\n", q1.front()); // 최상위 data를 출력 후 data 삭제
					q1.pop();
				}
				break;

			case 3:																	// 3번 메뉴 선택시
				boolean = false;											// bool 변수를 false로 초기화 후 종료
				break;
			}
	}
	return 0;
}

void menu(void) {															// 메뉴 출력하는 함수
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Quit\n");
	printf("->");
}

void push(int x) {														// 두개의 queue로 stack 구현하는 함수
																							
																							// 1.
	if(q1.empty()) 															// 메인 큐(q1)가 비어있다면 
		q1.push(x);																// 큐에 x값 입력 후 함수 종료

																							// 2. 
	else { 																			// 메인 큐(q1)가 비어있지 않다면
		while(!q1.empty()) {											// 메인 큐(q1)가 비어질 때까지
			q2.push(q1.front());										// 서브 큐(q2)에 메인 큐(q1)의 front data를 추가 후
			q1.pop();																// 메인 큐(q1) front data 삭제
		}

		q1.push(x);																// 그 후에 전달받은 data를 다시 메인 큐(q1)에 추가하고	

		while(!q2.empty()) {											// 서브 큐(q2)가 비어질 때까지
			q1.push(q2.front());										// 메인 큐(q1)에 서브 큐(q2)의 front data를 추가 후
			q2.pop();																// 서브 큐(q2)의 front data 삭제
		}
	}
}

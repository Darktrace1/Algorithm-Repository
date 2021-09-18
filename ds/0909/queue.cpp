#include <stdio.h>
#include <queue>
using namespace std;
void menu();																	// 초기 메뉴를 출력하는 함수 선언
	
int main(int argc, char* argv[]) {
	queue<int> q;																// queue q 선언

	int menu_num = 0;														// 메뉴 선택에 사용되는 변수
	int x;																			// queue에 추가되는 data value를 담는 변수
	bool Loop = true;

	while (Loop) {															// bool 타입으로 while 관리						
		menu();																		// 메뉴 출력 및 선택
		scanf("%d", &menu_num);

		switch (menu_num) {
		case 1:
			printf("INPUT: "); 											// 1번 메뉴 선택
			scanf("%d", &x);												// 추가할 data value 입력
																						
			q.push(x);															// 입력된 data value를 q에 추가
			printf("%d PUSHED!\n\n", x);
			break;

		case 2:																		// 2번 메뉴 선택
			if (q.empty())													// queue가 비어있다면
				printf("QUEUE IS EMPTY!\n");					// 해당 문구 출력
	
			else {																	// queue가 비어있지 않다면
				printf("%d POPPED!\n\n", q.front());	// queue의 최상위 data value부터 삭제
				q.pop();
			}
			break;

		case 3:
			Loop = false;														// 프로그램 종료시에 bool 변수를 false로 초기화하여 반복문 종료
			break;
		}
	}
	return 0;
}

void menu(void) {
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. QUIT\n");
	printf("-> ");
}

#include <stdio.h>
#include <stack>

using namespace std;

void menu(); 																	// 초기 메뉴를 출력하는 함수 선언

int main(int argc, char* argv[]) {

	stack<int> s; 															// s라는 이름의 스택 선언
	
	int menu_num = 0; 													// 메뉴 선택에 사용되는 변수
	int x; 																			// 스택에 추가되는 data value 담는 변수
	bool Loop = true;

	while (Loop) { 															// bool 타입으로 while 관리
		menu();
		scanf("%d", &menu_num); 

		switch (menu_num) {
		case 1:																		// 1번 메뉴 선	택
			printf("INPUT: "); 											// 추가할 data value 입력
			scanf("%d", &x);												

			s.push(x);															// 입력된 data value를 s에 추가
			printf("%d PUSHED!\n\n", x);						
			break;				

		case 2:																		// 2번 메뉴 선택시
			if (s.empty())
				printf("STACK IS EMPTY!\n");					// stack s가 비어있다면 해당 문구 출력

			else {																	// 비어있지 않을시에
				printf("%d POPPED!\n\n", s.top());		// stack의 가장 상단의 data부터 삭제
				s.pop();
			}
			break;

		case 3:
			Loop = false;														// 프로그램 종료시에 bool 변수를 false로 초기화하여 while문 종료
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



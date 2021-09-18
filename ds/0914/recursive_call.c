#include <stdio.h>

int recursive(int n) {
	if(n > 4) {								// n이 5이상일때
		printf("\n"); 					// 줄바꿈 후 		
		return 0; 							// 종료
	}
	else {
		printf("*"); 						// n이 5보다 작을때 * 출력			
		return recursive(++n);	// 증가된 n으로 재귀 호출
	}
}

void main() {
	int n = 0;
	recursive(n);							// 전달인자로 int형 정수n을 전달
}

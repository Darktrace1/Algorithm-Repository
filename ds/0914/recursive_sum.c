#include <stdio.h>
#include <stdlib.h>

int recursive_call(int, int, int);												// recursive call을 위한 함수 선언문

int main(int argc, char* argv[]) {
	if(argc != 3) {
		printf("Please Write the two integer (Ex: %s 2 5)\n"	// 올바른 실행이 아닐시 경고문 출력
				, argv[0]);
		return 0;
	}
	
	int a, b;																								// 입력받을 정수와 결과값 출력에 필요한 변수
	int sum = 0;

	a = atoi(argv[1]);																			// argv로 받은 문자열을 정수화하는 과정
	b = atoi(argv[2]);
	
	sum = recursive_call(a, b, sum);												// result 변수에 함수의 반환값 저장

	printf("\nsum = %d\n", sum);														// 입력받은 두 정수 사이의 값을 다 더한 합 출력

	return 0;
}

int recursive_call(int a, int b, int sum) {								// recursive call을 위한 함수 출력
	if(a <= b) {																						// a가 b보다 작을때(Ex: 2, 5 일때)
		printf("%d ", a);																			// a를 출력하고
		sum += a;																							// sum을 a만큼 증가시키고
		recursive_call(++a, b, sum);													// 증가된 a와 b, sum을 전달인자로 가지는
	}																												// recursive_call함수를 재귀호출

	else 																										// 만약 a의 값이 b보다 커지게 된다면
		return sum;																						// sum 변수를 반환함과 동시에 함수종료
	
}


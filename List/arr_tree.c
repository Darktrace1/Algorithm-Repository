#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// 함수의 선언문
// 각 함수의 설명은 각 문단 앞에서 계속
int input_height(void);
void print(void);
void enter_data(int* tree, int count);
void print_tree(int* tree, int height, int count);
int print_branch(int height, int Lev, int branch_empty); 
int print_empty(int* tree, int arr_num, int Lev, int height);
void print_data(int* tree, int arr_num);
int search_tree(int* tree, int count);
void search_family_in_tree(int* tree, int count, int arr_num);

int main(void) {
	bool loop = true;
	int height;
	while(loop) {
		height = input_height(); // 트리의 최대 높이를 입력받음
		if(height > 0)
			break;
		else {
			printf("양의 정수를 입력해주세요!\n");
			continue;
		}
	}

	int count = (int)pow(2.0, (double)height); // 높이별 최대 노드 개수
	int* tree = NULL; 
	tree = (int*) malloc(sizeof(int) * count); // tree배열 동적할당

	enter_data(tree, count);
	
	print_tree(tree, height, count);

	int result;
	result = search_tree(tree, count);
	
	if (result == 1) {
		free(tree);
		return 0;
	}
}

// 배열의 최대 높이를 입력하는 함수
int input_height(void) {
	int n = 0;

	printf("tree height? ");
	scanf("%d", &n);
	return n;
}

// 입력 문구를 출력하는 함수;
void print(void) {
	printf("pos, data = ? (enter 0 0 to finish) ");
}

// 트리에 데이터를 입력하는 함수
void enter_data(int* tree, int count) {
	int index, data;
	int i;

	for(i = 1; i < count; i++) // 배열을 -1로 초기화한 후
		tree[i] = -1;

	for(i = 1; i < count; i++) { // 입력된 배열 인덱스에만 데이터 값을 대입
		print();
		scanf("%d %d", &index, &data);
		
		if(index != 0 && data != 0) { // 0 0이 입력되지 않은 경우에만
			if(index < count)	
				tree[index] = data;				// tree배열에 데이터 대입
			else {
				printf("1 ~ %d사이의 값을 입력해주세요!\n", count - 1);
				i--;
			}
		}
		else
			break;
	}

	printf("트리 데이터 입력이 완료되었습니다.");
}

// tree를 그리는 함수
void print_tree(int* tree, int height, int count) {
	int i, j;
	int Lev = 0;
	double x = 0.0;
	
	// 밑의 print_branch 함수에서 사용되는 변수 
	int branch_empty;
	branch_empty = 5;
	for(i = 0; i < height - 2; i++) {
		branch_empty *= 2;
		branch_empty++;
	}
	
	// 현재 출력되고 있는 노드의 Lev를 알려주는 for 반복문
	for(i = 1; i < count; ) {
		if(i == (int)pow(2.0, x)) {
			printf("\nLev%d: ", ++Lev);
			x++;
		}
		
		// 레벨별 공백
		// i값을 통해 현재 배열의 인덱스를 print_empty로 전달해주며
		// 그 함수 안에서 값이 자동으로 증가되어 반환된다.
		// branch_empty 또한 도출된 공식의 핵심 값으로 print_branch함수에 전달되며
		// 그 함수 안에서 값이 자동으로 증가되어 반환된다.

		else {
		// First Lev
			if(Lev == 1) {
				i = print_empty(tree, i, Lev, height); 
				printf("\n");
				branch_empty = print_branch(height, Lev, branch_empty);
				continue;
			}

			// Between First and Fianl
			else if(Lev != 1 && Lev != height) {
				i =	print_empty(tree, i, Lev, height);
				printf("\n");
				branch_empty = print_branch(height, Lev, branch_empty);
				continue;
			}
	
			// Final Lev
			else if(Lev == height) {
				i = print_empty(tree, i, Lev, height);
				printf("\n");
				continue;
			}
		}
	}
}

// 트리의 가지를 출력하는 함수
int print_branch(int height, int Lev, int branch_empty) {
	printf("      ");											// Levn: <-이 6개의 공백을 가지기 때문에
																				// 이를 대체하는 것을 위함이다.
	int i, j, check = 1;
	
	// 트리의 가지를 출력하는 함수에도 공백과 가지를 출력하기 위한 공식을 대입하였다.
	// 데이터 하나를 세 칸으로 두고 직접 세어보면 어떤 트리에서 어떤 height에도 상관없이 
	// 고정으로 1, 5라는 값이 나오는 것을 확인할 수 있었다.
	// 이를 가지고 트리의 height, Lev와 같은 정보를 활용하여
	// print_tree() 함수에 있는 branch_empty라는 공식을 이용한 변수를 만들 수 있었고 이를 전달받아
	// 다음과 같이 가지를 알맞은 공백수로 출력할 수 있었다.


	for(i = 0; i < branch_empty / 2 - 1; i++)							// 전달 받은 branch_empty만큼 공백 출력
		printf(" ");
	
	for(i = 0; i < (int)pow(2.0, (double)Lev) - 1; i++) {
		if(check % 2 != 0)									// branch_empty라는 변수는 height의 값에 따라 
			printf("/");											// 반복되는 수가 달라진다.
		else																// 그 수는 2^(Lev(현재 기록중인 트리의 Lev) - 1)라는
			printf("\\");											// 공식으로 도출되며
																				// 이 수만큼 branch_empty의 공백을 출력한 후	
		for(j = 0; j < branch_empty; j++)		// 가지를 출력하였다.
			printf(" ");
		check++;
 	}
 	printf("\\");
 	return branch_empty / 2;
}

// 공백을 출력하는 함수
int print_empty(int* tree, int arr_num, int Lev, int height) {
	int i, j;
	int count = (int)pow(2.0, (double)height); // 입력받을 수 있는 최대 노드값을 계산하여 저장
	int max_empty = (count - 2) / 2;					 // 최대로 들어갈 수 있는 공백을 계산하여 저장
	
	// 트리를 나무처럼 그리기 위해서 한 데이터를 3칸으로 두고 공식을 도출하였다.
	// 최대 높이가 n(height)일때 Lev1 ~ Lev(n-1)까지는
	// (2^(n - 각Lev) - 1) 개의 공백을 출력 후 데이터값을 출력한 다음
	// 다시 (2^(n - (각Lev - 1) - 1) 개의 공백을 출력 후 데이터 값을 출력하는 과정을
	// 2^((각Lev - 1) - 1개 만큼 반복하면 된다.
	//
	// 편의상 Lev(1)과 Lev(n)은 수동으로 출력하고 그 사이의 Lev을 반복문을 통하여
	// 출력하였다.


	// Lev 1
	if(Lev == 1) {
		for(i = 0; i < max_empty; i++)						// max_empty는 위에 계산된 변수를 활용하여
			printf("   ");													// 데이터 값과 공백을 알맞게 출력하였다.
		print_data(tree, arr_num);
		return ++arr_num;
	}

	// 중간 라인
	//
	// 중간의 공식들은 위에 설명한 공식을 기반으로 편의상 pow함수를 사용하여 
	// 출력하였다.
	else if(Lev != 1 && Lev != height) {
		for(i = 0; i < (int)pow(2.0, (double)(height - Lev)) - 1; i++) // 2^(n - Lev(현재 접근중인 노드의 Lev) - 1)개의	
			printf("   ");																							 // 공백을 출력 후
		print_data(tree, arr_num);																		 // 데이터 값을 출력
		arr_num++;	

		for(i = 0; i <  (int)pow(2.0, (double)(Lev - 1)) - 1; i++) {  // 이중 for문으로 2^(n - (Lev-1)) - 1개의 공백 출력 후 
			for(j = 0; j < (int)pow(2.0, (double)(height - (Lev - 1))) - 1; j++)
				printf("   ");																						// 데이터 값 출력하는 과정을
																																	// 2^(Lev-1) - 1번 반복하는 것을 구현하였다.
			print_data(tree, arr_num);
			arr_num++;
		}
		return arr_num;
	}
	
	// Lev n(여기서 n은 높이, height와 같은 의미이다.)
	else if (Lev == height) {
		for(i = 0; i < max_empty + 1; i++) {					// max_empty는 위에 계산된 변수를 활용하여
			print_data(tree, arr_num);									// 데이터 값과 공백을 알맞게 출력하였다.

			arr_num++;
			printf("   ");
		}
		return arr_num;
	}
}

// 데이터 값을 자리수에 맞게 나누어 조절하여 출력하는 함수
// 비어있을 경우'---'와 같이 출력
//  1의 자리일 경우 ' 1 '와 같이 출력
// 10의 자리일 경우 '1 0'와 같이 출력
//100의 자리일 경우 '100'와 같이 출력
// 그 이상부터는 그대로 출력
void print_data(int* tree, int arr_num) {
		if(tree[arr_num] >= 0) {																			// 배열에 데이터 값이 담겼을때
			if(tree[arr_num] % 10 == tree[arr_num])											// 담긴 데이터가 1의 자리일 경우
				printf(" %d ", tree[arr_num]);														// 칸에 맞게 출력
			else if(tree[arr_num] % 100 == tree[arr_num])								// 담긴 데이터가 10의 자리일 경우
				printf("%d %d", tree[arr_num] / 10, tree[arr_num] % 10);	// 칸에 맞게 잘라서 출력
			else if(tree[arr_num] % 1000 == tree[arr_num])							// 담긴 데이터가 100의 자리일 경우
				printf("%d", tree[arr_num]);															// 칸에 맞게 잘라서 출력
			else																												// 그 이외의 수의 경우
				printf("%d", tree[arr_num]);															// 데이터 값 그대로 출력
		}
		else 																													// 배열에 데이터 값이 담기지 않았을 경우
			printf("%c%c%c", '-', '-', '-');														// ---을 출력하여 비어있다는 것을 보여준다.
}

// 정보를 알고 싶은 데이터를 검색하는 함수
int search_tree(int* tree, int count) {
	int search_data;
	int check = 0;

	while(1) {
		printf("\n정보를 알고 싶은 데이터를 입력하세요 (종료시 999를 입력하시오): ");
		scanf("%d", &search_data);
		if(search_data == 999) // 999를 입력할 경우 1을 반환하며 함수가 종료된다.
			return 1;
		
		for(int i = 1; i < count; i++) {						// 배열을 1 ~ 최댓값까지 돌려서
			if(tree[i] == search_data) {							// 찾고자 하는 값을 찾았을 때
				printf("\n%d: ", search_data);					// 그 값을 출력하고
				check = 1;															// 찾았다는 것을 체크한 후
				search_family_in_tree(tree, count, i);	// 해당 배열의 인덱스 값을 찾는 함수에 전달
				}
		}
		if(check == 0) {														// 만약 찾지 못했다면 
			printf("\n%d: 존재하지 않는 데이터입니다.\n", search_data); 
			break;																		// 존재하지 않음을 할리고 다시 데이터를  입력받는다.
		}
		else
			continue;
	}
}

// 부모, 왼, 오른쪽 자식, 형제노드를 찾는 함수
void search_family_in_tree(int* tree, int count, int arr_num) {
	// 부모 노드 찾기
	printf("부모 = ");
	if((tree[arr_num / 2] != -1) && (arr_num != 1))		// 데이터 값이 없는 노드와 루트 노드의 경우 예외처리
		printf("%d ", tree[arr_num / 2]);
	else
		printf("없음 ");
	
	// 왼쪽, 오른쪽 자식노드 찾기
	printf("왼쪽 자식 = ");
	if(tree[2 * arr_num] != -1) {
		if(2 * arr_num < count)
			printf("%d, ", tree[2 * arr_num]);		// 자식노드의 경우도 데이터 값이 없는 노드 및
		else																		// 데이터 값이 넘어가는 경우 예외처리 
		printf("없음, ");
	}
	else
		printf("없음, ");

	printf("오른쪽 자식 = ");
	if(tree[(2 * arr_num) + 1] != -1) {
		if(2 * arr_num + 1 < count)							// 왼쪽 자식노드 찾기와 예외처리 조건 동일
			printf("%d, ", tree[2* arr_num + 1]);
		else
		printf("없음, ");
	}
	else
		printf("없음, ");

	// *추가점수 형제노드 찾기								형제노드의 경우 이진트리의 특성을 살려 
	printf("형제 노드 = ");									// 한 형제는 홀수와 짝수의 인덱스를 가진다는
	int num = 0, check = 0;									// 성질을 이용하여 구현하였다.
	// 	루트 노드 예외 처리
	if(arr_num == 1) 	
		printf("없음\n");

	else if(arr_num % 2 == 0) {							// 배열 인덱스의 수가 짝수일때
		if(tree[arr_num + 1] >= 0)						// 다음 인덱스가 데이터가 담겼을 경우
			printf("%d\n", tree[arr_num + 1]); 	// 그 값을 형제노드로 출력
		else
			printf("없음\n");										// 없으면 없음 출력
	}

	else if(arr_num % 2 != 0)								// 배열 인덱스의 수가 홀수일때
		if(tree[arr_num - 1] >= 0)						// 이전 인덱스에 데이터가 담겼을 경우
			printf("%d\n", tree[arr_num - 1]);	// 그 값을 형제노드로 출력
		else
			printf("없음\n");										// 없으면 없음 출력
	
}

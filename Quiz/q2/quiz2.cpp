/* 
 프로그램 제목: 10/12에 진행된 퀴즈(BST)의 코드 설명첨부
 작성자: 5532545 컴퓨터공학과 김진범
 작성일: 10/12
 과제방 3번 제출용
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>
using namespace std;

// 노드 구조체 생성
typedef struct TreeNode {
	int value;
	struct TreeNode *left, *right;
}TreeNode;

// TreeNode를 element로 재정의
typedef TreeNode element;
// 레벨 순회를 위한 STL_Queue 선언
queue<element *> q;
// 노드 메모리 해제시 갯수 카운팅하는 변수
int node_count = 0;

// 함수 사용을 위한 선언
void menu(void);
element* alloc_newnode(element *);
element* insert(element *, int);
element* search(element *, int);
void deleteTree(element *);
void level_order(element *);

int main(void) {
	element *root = NULL;
	int search_data, menu_num;
	bool loop = true;

	while(loop) { // loop가 false일때까지 반복
		menu();		  // menu 출력
		scanf("%d", &menu_num);
		// 메뉴 선택 후 각 메뉴 접근을 switch로 구현
		switch(menu_num) {
			// 입력 메뉴 선택 시
			case 1:
				while(1) {
					printf("입력 (종료는 -1): ");				
					scanf("%d", &search_data);					// 삽입할 값 입력 받음
					if(search_data != -1)								// 입력 값이 -1이 아니라면
						root = insert(root, search_data);	// 이진트리에 데이터 삽입
					else {
						printf("\n[Level Order] ");				
						level_order(root); printf("\n\n");// 종료조건이 활성화 되었다면 레벨 순회 출력 후
						break;														// 입력메뉴 종료
					}
				}
				break;

			// 탐색 메뉴 선택 시
			case 2:
				printf("탐색할 노드? : "); // 탐색할 노드 데이터 값 입력
				scanf("%d", &search_data);
																							// 탐색함수의 반환값이 NULL이 아니라면 해당 함수에서 문제조건 출력
				if(search(root, search_data) == NULL) // 탐색함수의 반환값이 NULL이라면
					printf("%d는 존재하지 않습니다\n\n", search_data); // 찾고자하는 data가 존재하지 않는 것으로 
				break;																// 해당 문구 print 후 탐색메뉴 종료
			
			// 레벨 순회 메뉴 선택 시
			case 3:
				printf("\n[Level Order] ");				// 레벨순회 출력
				level_order(root); printf("\n\n");
				break;														// 레벨순회 메뉴 종료

			// 프로그램 종료 시
			case 4:
				loop = false; // loop -> fasle
				break;				// 메뉴 선택 종료
		}
	}
	deleteTree(root); // root 변수를 전달하여 메모리 해제 후
	root = NULL;			// NULL로 초기화
	if(root == NULL) { // 초기화가 잘 되었다면 해당 문구 출력 후 프로그램 종료
		printf("%d개의 노드가 free됌.\n", node_count);
		printf("[종료]\n");
	}
	return 0;
}

// menu 출력 함수
void menu(void) {
	printf("1. 입력\n");
	printf("2. 탐색\n");
	printf("3. Level Order\n");
	printf("4. 종료\n");
	printf("번호를 넣으세요: ");
}

// 새 노드 등록하는 함수 
element* alloc_newnode(int key) {
	element *newnode = 
		(element *) malloc(sizeof(element)); 

	newnode->value = key;									 // value에 key
	newnode->left = newnode->right = NULL; // left, right에 NULL

	return newnode;												 // 생성된 노드 반환
}

// 노드를 트리에 삽입하는 함수
element* insert(element *ptr, int key) {
	if(ptr == NULL) return alloc_newnode(key); // 노드(ptr)가 NULL일때 노드 등록

	if(key == ptr->value) 										 // 노드의 value가 key랑 같을때
		return ptr;															 // 해당 노드 반환

	else if(key < ptr->value)									 // 노드의 값이 key보다 클때
		ptr->left = insert(ptr->left, key);			 // 현재노드의 왼쪽 값을 재귀호출

	else																			 // 반대의 경우
		ptr->right = insert(ptr->right, key);		 // 현재노드의 오른쪽 값을 재귀호출
		
	return ptr;																// 종료 전 노드 반환
}

// 트리에서 값을 탐색하는 함수
element* search(element *ptr, int key) {  
	int count = 0; // 탐색횟수 count하는 변수
	while(ptr != NULL) {	// 현재노드가 null일때까지 반복
		if(key == ptr->value) { // key가 노드value와 같을때
			printf("%d는 %d탐색으로 발견\n\n", key, ++count); // 몇회 탐색이 이루어졌는지 출력후	
			return ptr;	// 노드 반환
		}

		else if(key < ptr->value) { // key값이 현재노드의 값보다 작을때
			ptr = ptr->left;	// 노드의 왼쪽으로 진행 후
			count++; // 탐색횟수 증가
		}

		else {	// key값이 현재노드의 값보다 클때
			ptr = ptr->right; // 노드의 오른쪽으로 진행 후
			count++;	// 탐색횟수 증가
		}
	}
	return NULL; // 탐색하고자하는 노드가 tree에 없을때 NULL값 반환
}

// 레벨 순회를 STL_Queue로 구현한 함수
void level_order(element *ptr){	
	q.push(ptr);	// 현재 노드값을 queue에 삽입
 
 	if(ptr == NULL) return; // 현 노드값이 NULL일때 함수 종료

	while(!q.empty()) { // Queue가 비어있지 않을 때
		ptr = q.front();  // ptr을 Queue의 front값으로 초기화 후
		q.pop(); // Queue의 front값 삭제
		printf("%d ", ptr->value); // 삭제한 값 출력

		if(ptr->left) // 노드의 왼쪽 값이 null이 아닐때
			q.push(ptr->left); // 노드의 왼쪽 값 큐 삽입
		if(ptr->right) // 노드의 오른쪽 값이 null이 아닐때
			q.push(ptr->right); // 노드의 오른쪽 값 큐 삽입
	}
}

// 메모리 해제 함수(후위순회로 구현)
void deleteTree(element *root) {
	if(root) { // root가 null이 아닐때
		deleteTree(root->left); // 왼쪽값을 전달인자로 가지고 재귀호출
		deleteTree(root->right);// 오른쪽값을 전달인자로 가지고 재귀호출
		printf("%d 노드 free됌!\n", root->value); // 해제된 노드의 value 확인하는 문구 출력
		node_count++; free(root); // 해제된 노드를 count하는 변수 1 증가 후 메모리 해제
	}
}

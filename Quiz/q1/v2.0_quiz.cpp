/* 
 프로그램 제목: 10/05에 진행된 퀴즈(이진트리)의 코드 보완
 작성자: 5532545 컴퓨터공학과 김진범
 작성일: 10/07
과제방 3번 제출용
*/
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

// 노드 구조체 생성
typedef struct Node {
	int value;
	struct Node *left, *right;
}Node;

// Node*를 element로 재정의
typedef Node* element;
queue<Node*> q;
stack<Node*> s;

// 함수 사용을 위한 선언
element make_tree(void);
element alloc_newnode(int data, element l, element r);
void level_order(element ptr);
void pre_order(element ptr);
void find_leafnodes(element ptr);
void find_max(element ptr);
void deleteTree(element *root);

int main(void) {
	Node* root = make_tree();
	level_order(root);
	pre_order(root);
  find_leafnodes(root);
  find_max(root);
	return 0;
}
// 	 제공된 Tree 도면
//      1
//   2     3
// 4     5   6
//         7

element alloc_newnode(int data, element l, element r) { // 신규노드 생성 함수
	element node =
		(element ) malloc(sizeof(Node));
	// 전달받은 주솟값과 data값을 바탕으로 노드 초기화
	node->value = data;
	node->left = l;	
	node->right = r;

	return node;
}

element make_tree(void) { // 노드 생성 함수
	// 왼쪽부터 data, left, right로 해당 정보를 신규노드 생성 함수에 전달
	element n7 = alloc_newnode(7, NULL, NULL); 
  element n6 = alloc_newnode(4, NULL, NULL);
	element n5 = alloc_newnode(5, NULL, n7);
	element n4 = alloc_newnode(6, NULL, NULL);
  element n3 = alloc_newnode(2, n6, NULL);
	element n2 = alloc_newnode(3, n5, n4);
	element n1 = alloc_newnode(1, n3, n2);
	// 최상위 노드인 n1을 root node로 선언
	element root = n1;
	return root;
}

void level_order(element ptr) { // 레벨 순회를 queue로 구현한 함수
	// 큐의 FIFO 성질을 활용하여 구현
	printf("[Level order] ");
	q.push(ptr); // 들어온 순서대로 큐에 삽입
	
	if(ptr == NULL) return; // root가 NULL일때 함수 종료

	while(!q.empty()) {	// 큐가 비어있지 않을때
		ptr = q.front();	// 큐의 가장 앞을 ptr에 저장 후
		q.pop();					// 삭제
		
		printf("%d ", ptr->value); // 삭제한 값을 출력
		if(ptr->left)								// ptr의 왼쪽 자식이 NULL이 아니라면
			q.push(ptr->left);				// 왼쪽 자식을 큐에 삽입
		if(ptr->right)							// ptr의 오른쪽 자식이 NULL이 아니라면
			q.push(ptr->right);				// 오른쪽 자식을 큐에 삽입
	}															// 여기서 유의할 점은 왼쪽자식이 오른쪽 자식보다
	printf("\n[Pre order] ");			// 먼저 큐에 삽입된다는 점을 유의해야함
}

void pre_order(element ptr) { // 전위 순회를 recursive call로 구현한 함수
	if(ptr) {	// ptr이 NULL이 아닐때
		printf("%d ", ptr->value); // ptr 노드의 value를 출력 후
		pre_order(ptr->left);			 // 자기 자신에게 ptr->left를 전달
		pre_order(ptr->right);		 // 자기 자신에게 ptr->right를 전달
	}
}

void find_leafnodes(element ptr) { // 자식노드가 없는 노드를 출력하는 함수, 스택을 활용하여 구현
	int arr[100]; // leafnode를 저장할 배열 선언
	int i = 0;

	while(1) {
		for( ; ptr; ptr = ptr->left) { // ptr이 NULL이 아닐때까지 왼쪽으로 갈때
			s.push(ptr);	// 스택에 ptr값 삽입
			if((ptr->left == NULL) && (ptr->right == NULL)) // ptr의 왼쪽, 오른쪽 자식이 모두 NULL일때 leafnode라고 정의
				arr[i++] = (ptr->value);	// 배열에 leafnode의 value를 저장 후 배열 인덱스 증가
		}

		if(!s.empty()){ // 스택이 비어있지 않을때
			ptr = s.top();// ptr을 스택의 가장 윗 값으로 초기화한 후
			s.pop();			// 스택의 top value 삭제
		}
		else						// 스택이 비어있을때
			ptr = NULL;		// ptr은 NULL이라는 것을 직접 예외처리

		if(ptr == NULL) break; // ptr이 NULL일때 예외처리
		ptr = ptr->right;			// ptr을 ptr->right로 초기화
	}
	printf("\n[Leaf nodes] ");
	
	for(int j = 0; j < i; j++) // 증가된 배열의 인덱스 값 만큼 배열을 반복하여
		printf("%d ", arr[j]);	// 저장된 leafnode의 value 출력
	printf("\n");
}

void find_max(element ptr) { // node의 value 중 최댓값을 찾는 함수
	element *tmp_root = &ptr;	 // 동적 메모리 해제를 위한 임시 루트변수 선언
	int temp = ptr->value;		 // ptr의 value를 temp 변수에 저장

	while(1) {
		for( ; ptr; ptr = ptr->left) { // ptr이 NULL이 아닐때까지 왼쪽으로 갈때
			s.push(ptr);		// 스택에 ptr값 삽입
			if(temp < ptr->value) // 아까 선언한 temp보다 현재 ptr의 value가 클때
				temp = ptr->value; // temp를 새로 초기화
		}
		
		if(!s.empty()){ // 스택이 비어있지 않을때
			ptr = s.top();// ptr을 스택의 가장 윗 값으로 초기화한 후
			s.pop();			// 스택의 top value 삭제
		}
		else						// 스택이 비어있을때
			ptr = NULL;		// ptr은 NULL이라는 것을 직접 예외처리

		if(ptr == NULL) break; // ptr이 NULL일때 예외처리
			ptr = ptr->right;			// ptr을 ptr->right로 초기화
	}
	printf("[Max] %d\n", temp); // 최댓값 출력

	deleteTree(tmp_root); // 임시 루트변수를 동적메모리 해제 함수로 전달
	//free(*tmp_root);			// 임시 루트변수 해제
	//free(ptr);						// 전달받은 root 해제
}	

void deleteTree(element *tmp_root) { // 동적메모리 해제 함수 
	if((*tmp_root) != NULL) { 			 	 // tmp_root가 NULL이 아닐때
		deleteTree(&(*tmp_root)->left);  // 왼쪽 값으로 재귀호출
		deleteTree(&(*tmp_root)->right); // 오른쪽 값으로 재귀호출
		free(*tmp_root);								 // 노드 해제;
	}
}

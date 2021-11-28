#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stack>
using namespace std;

stack<int> s;
#define SIZE 26

typedef struct GraphType {
	int v_num; // 지도의 크기 v_num * v_num;
	int count;
	int vilage_count;
	int vilage[SIZE]; // 마을 수
	int map[SIZE][SIZE];
}GraphType;

int visited[SIZE][SIZE];
int fixed_x[4] = {0, 0, 1, -1};
int fixed_y[4] = {1, -1, 0, 0};

void init(GraphType *);
void insert_vilage(GraphType *);
void solveProblem(GraphType *);
void dfs_map(GraphType *, int, int);
int compare(const void *, const void *);

int main(void) {
	GraphType *g = (GraphType *) malloc(sizeof(GraphType));
	init(g); // 초기화
	insert_vilage(g); // 마을 삽입
	solveProblem(g);
	free(g);
	return 0;
}

void init(GraphType *g) {
	g->v_num = 0;
	g->count = 0;
	g->vilage_count = 0;
	for(int i = 0; i < SIZE; i++) {
		memset(g->map[i], 0, sizeof(int) * SIZE);
		memset(g->vilage, 0, sizeof(int));
		memset(visited[i], 0, sizeof(int) * SIZE);
	}
}

void insert_vilage(GraphType *g) {
	int i, j;
	scanf("%d", &(g->v_num));
	
	for(i = 0; i < g->v_num; i++) 
		for(j = 0; j < g->v_num; j++)
			scanf("%1d", &(g->map[i][j]));
}

void solveProblem(GraphType *g) {
	int i, j;
	int start = 0;
	for(i = 0; i < g->v_num; i++) {
		for(j = 0; j < g->v_num; j++) {
			if(g->map[i][j] && !visited[i][j]) {
				g->count = 0;
				dfs_map(g, i, j);
				g->vilage_count++;
				s.push(g->count);
			}
		}
	}

	int vilage[g->vilage_count];
	for(i = 0; i < g->vilage_count; i++) {
		vilage[i] = s.top();
		s.pop();
	}
	qsort(vilage, g->vilage_count, sizeof(int), compare);
	
	printf("%d\n", g->vilage_count);
	for(i = 0; i < g->vilage_count; i++)
		printf("%d\n", vilage[i]);
	
}

int compare(const void *a, const void *b) {
	int x = *(int *)a;
	int y = *(int *)b;
	return (x - y);
}

void dfs_map(GraphType *g, int x, int y) {
	visited[x][y] = 1;
	int i, new_x, new_y;

	g->count++;
	for(i = 0; i < 4; i++) {
		new_x = x + fixed_x[i];
		new_y = y + fixed_y[i];

		if(new_x >= 0 && new_y >= 0 && new_x < SIZE && new_y < SIZE) {
			if(g->map[new_x][new_y] && !visited[new_x][new_y]) {
				visited[new_x][new_y] = 1;
				dfs_map(g, new_x, new_y);
			}
		}
	}
}

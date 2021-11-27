#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
#define MAX 51
using namespace std;
queue<int> q;

typedef struct GraphType {
	int count;
	int map[MAX][MAX];
}GraphType;

int visited[MAX][MAX];
int fixed_x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int fixed_y[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int w, h;

void init(GraphType *);
void insert_island(GraphType *);
void solveProblem(GraphType *);
void dfs_map(GraphType *g, int, int);

int main(void) {
	GraphType *g;
	g = (GraphType *) malloc(sizeof(GraphType));
	
	//int h, w;
	while(1) {
		scanf("%d %d", &w, &h); // 크기 입력
		if(h == 0 && w == 0)
			break;

		init(g); // 초기화
		insert_island(g);	// 섬 삽입
		solveProblem(g); // 섬 탐색

		printf("%d\n", g->count);
	}
	free(g);
	return 0;
}

void init(GraphType *g) {
	g->count= 0;
	for(int i = 0; i < MAX; i++) {
		memset(g->map[i], 0, sizeof(int) * MAX);
		memset(visited[i], 0, sizeof(int) * MAX);
	}
}

void insert_island(GraphType *g) {
	int i, j;
	for(i = 0; i < h; i++)
		for(j = 0; j < w; j++)
			scanf("%d", &(g->map[i][j]));
}

void solveProblem(GraphType *g) {
	int i, j;
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			if(g->map[i][j] && !visited[i][j]) {	
				++g->count;
				dfs_map(g, i, j);
			}
		}
	}
}

// x = {0, 0, 1, -1, 1, 1, -1, -1};
// y = {1, -1, 0, 0, 1, -1, -1, 1};

void dfs_map(GraphType *g, int x, int y) {
	visited[x][y] = 1;
	int new_x, new_y;

	for(int i = 0; i < 8; i++) {
		new_x = x + fixed_x[i];
		new_y = y + fixed_y[i];
	
		if(new_x >= 0 && new_y >= 0 && new_x < MAX && new_y < MAX) {
			if(g->map[new_x][new_y] && !visited[new_x][new_y]) {
				visited[new_x][new_y] = 1;
				dfs_map(g, new_x, new_y);
			}
		}	
	}
}

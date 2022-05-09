#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 51

int visited[SIZE][SIZE];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int M, N, K;

typedef struct GraphType{
	int count;
	int map[SIZE][SIZE];
}GraphType;

void init(GraphType *);
void insert_baechu(GraphType *);
void solveProblem(GraphType *);
void dfs_map(GraphType *, int, int);

int main(void) {
	GraphType *g = (GraphType *) malloc(sizeof(GraphType));

	int n;
	scanf("%d", &n);

	int i, j;
	while(n--) {
		init(g);
		insert_baechu(g);
		solveProblem(g);
		printf("%d\n", g->count);
	}
}

void init(GraphType *g) {
	g->count = 0;
	for(int i = 0; i < SIZE; i++) {
		memset(g->map[i], 0, sizeof(int) * SIZE);
		memset(visited[i], 0, sizeof(int) * SIZE);
	}
}

void insert_baechu(GraphType *g) {
	scanf("%d %d %d", &M, &N, &K);

	int x, y;
	for(int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		g->map[y][x] = 1;
	}
}

void solveProblem(GraphType *g) {
	int i, j;
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if(g->map[i][j] && !visited[i][j]) {
				dfs_map(g, i, j);
				g->count++;
			}
		}
	}
}

void dfs_map(GraphType *g, int x, int y) {
	int nx, ny;
	visited[x][y] = 1;

	for(int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if(nx >= 0 && ny >= 0 && nx <= SIZE && ny <= SIZE) {
			if(g->map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				dfs_map(g, nx, ny);
			}
		}
	}
}

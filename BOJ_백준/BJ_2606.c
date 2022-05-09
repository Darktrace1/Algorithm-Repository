#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX 101

typedef struct GraphType{
	int num;
	int adj_mat[MAX][MAX];
}GraphType;

int visited[MAX] = {0};
int c = 0;

void init(GraphType *);
void insert_vertax(GraphType *);
void insert_edge(GraphType *, int, int);
void check(GraphType *, int);

int main(void) {
	GraphType *g;
	g = (GraphType *) malloc(sizeof(GraphType));
	init(g);

	int v, e;
	scanf("%d", &v);
	scanf("%d", &e);

	for(int i = 0; i < v; i++) 
		insert_vertax(g);

	int start, end;
	for(int i = 0; i < e; i++) {
		scanf("%d %d", &start, &end);
		insert_edge(g, start, end);
	}
	check(g, 1);
	printf("%d", c-1);
	free(g);
	return 0;
}

void init(GraphType *g) {
	g->num = 0;
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			g->adj_mat[i][j] = 0;
}

void insert_vertax(GraphType *g) {
	if((g->num) + 1 > MAX) {
		fprintf(stderr, "오류");
		return;
	}
	g->num++;
}

void insert_edge(GraphType *g, int start, int end) {
	if(start > g->num || end > g->num) {
		fprintf(stderr, "오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void check(GraphType *g, int v) {
	int w;
	visited[v] = 1;
	c++;
	for(w = 1; w <= g->num; w++)
		if(g->adj_mat[v][w] && !visited[w])
			check(g, w);
}

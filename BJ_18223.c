#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#define SIZE 5000
#define INF 1000000

typedef struct GraphType {
	int ver_n; // 정점의 개수
	int edge_n; // 간선의 개수
	int weight[SIZE][SIZE];
}GraphType;

int distance[SIZE];
int visited[SIZE];

void graph_init(GraphType *);
void insert_edge(GraphType *, int, int, int);
int choose(int *, int, int *);
void print_status(GraphType *g);
void djikstra(GraphType *, int);

int main(void) {
	GraphType *g;
	g = (GraphType *) malloc(sizeof(GraphType));
	graph_init(g);

	int friend_num;
	// 정점의 개수, 간선의 개수, 건우가 있는 정점
	scanf("%d %d %d", &(g->ver_n), &(g->edge_n), &friend_num);

	int start, end, weight;
	for(int i = 0; i < g->edge_n; i++) {
		scanf("%d %d %d", &start, &end, &weight);
		insert_edge(g, start-1, end-1, weight);
	}

	djikstra(g, 0);
	int	final = g->ver_n - 1;
	int result1 = distance[final];
	int result2 = distance[friend_num - 1];
	djikstra(g, friend_num - 1);
	result2 += distance[g->ver_n - 1];

	if(result1 >= result2)
		printf("SAVE HIM");
	else
		printf("GOOD BYE");

	free(g);
	return 0;
}

void graph_init(GraphType *g) {
	g->edge_n = 0;
	g->ver_n = 0;
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			g->weight[i][j] = INF;
}

void insert_edge(GraphType *g, int start, int end, int weight) {
	g->weight[start][end] = weight;
	g->weight[end][start] = weight;
}

int choose(int distance[], int n, int visited[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i = 0; i < n; i++) {
		if(distance[i] < min && !visited[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void djikstra(GraphType *g, int start) {
	int i, u, w;
	for(i = 0; i < SIZE; i++) {
		distance[i] = 0;
		visited[i] = 0;
	}

	for(i = 0; i < g->ver_n; i++) {
		distance[i] = g->weight[start][i];
		visited[i] = 0;
	}
	visited[start] = 1;
	distance[start] = 0;

	for(i = 0; i < g->ver_n - 1; i++) {
		//print_status(g);
		u = choose(distance, g->ver_n, visited);
		visited[u] = 1;

		for(w = 0; w < g->ver_n; w++)
			if(!visited[w])
				if(distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}

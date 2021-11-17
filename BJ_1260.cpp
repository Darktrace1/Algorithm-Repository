#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stack>
#include <queue>
#define MAX 1001
using namespace std;

typedef struct GraphType {
	int num;
	int adj_mat[MAX][MAX];
}GraphType;

stack<int> s;
queue<int> q;
typedef GraphType* G;
int visited[MAX];

void init(G g);
void insert_vertax(G g);
void insert_edge(G g, int, int);
void dfs(G g, int);
void dfs_stack(G g, int);
void bfs(G g, int);

int main(void) {
	G g;
	g = (G) malloc(sizeof(GraphType));
	init(g);
	
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for(int i = 0; i < N; i++)
		insert_vertax(g);

	int start, end;
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		insert_edge(g, start, end);
	}
	dfs_stack(g, V);
	printf("\n");
	bfs(g, V);
	free(g);
	return 0;
}

void init(G g) {
	g->num = 0;

	for(int i = 0; i < MAX; i++)
		memset(g->adj_mat[i], 0, sizeof(int) * MAX);
}

void insert_vertax(G g) {
	if((g->num) + 1 > MAX) {
		fprintf(stderr, "오류");
		return;
	}
	g->num++;
}

void insert_edge(G g, int start, int end) {
	if(start > g->num || end > g->num) {
		fprintf(stderr, "오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs(G g, int v) {
	visited[MAX] = {0};
	visited[v] = 1;
	printf("%d ", v);

	for(int w = 1; w <= g->num; w++)
		if(g->adj_mat[v][w] && !visited[w])
			dfs(g, w);
}

void dfs_stack(G g, int v) {
	visited[MAX] = {0};
	s.push(v);
	
	while(!s.empty()) {
		v = s.top();
		s.pop();

		if(visited[v])
			continue;
		visited[v] = 1;
		printf("%d ", v);

		for(int w = g->num; w >= 1; w--)
			if(g->adj_mat[v][w] && !visited[w])
				s.push(w);
	}
}

void bfs(G g, int v) {
	int w;
	visited[v] = 0;
	printf("%d", v);
	q.push(v);

	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(w = 1; w <= g->num; w++)
			if(g->adj_mat[v][w] && visited[w]) {
				visited[w] = 0;
				printf(" %d", w);
				q.push(w);
			}
	}
}

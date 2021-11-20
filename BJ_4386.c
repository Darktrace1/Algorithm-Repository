#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10000
#define INF 1000L

typedef struct coor {
	float x, y;
	int n;
}coordinate;

// 간선의 정보
typedef struct Edge {
	coordinate start, end;
	float cost;
}edge;

// 그래프 정보
typedef struct GraphType {
	int edge_n; // 간선의 개수
	int ver_n; // 정점의 개수
	edge edges[2 * SIZE];
}GraphType;

int parent[SIZE];

void set_init(int n);
int find_set(int curr);
void set_union(int a, int b);
void init_graph(GraphType *g);
void insert_edge(GraphType *g, coordinate start, coordinate end, double w);
int compare(const void *a, const void *b);
void kruskal(GraphType *g);
int dist_a_to_b(GraphType *g, coordinate *coor);
// 두 점 사이의 거리를 계산하는 함수
double calc_dist(coordinate start, coordinate end);

int main(void) {
	GraphType *g;
	g = (GraphType *) malloc(sizeof(GraphType));
	init_graph(g);

	scanf("%d", &(g->ver_n));

	coordinate coor[g->ver_n];
	//coor = (coordinate *) malloc(sizeof(coordinate) * g->ver_n);

	double x, y;
	for(int i = 0; i < g->ver_n; i++) {
		scanf("%lf %lf", &x, &y);
		coor[i].x = x; coor[i].y = y; coor[i].n = i; // x, y 좌표 대입
		//printf("%d: %.2lf, %.2lf ", coor[i].n, coor[i].x, coor[i].y);
	}

	dist_a_to_b(g, coor); // 두 점 사이의 거리 측정하여 간선에 비용삽입
	kruskal(g);
	free(g);
	//free(coor);
	return 0;
}

void set_init(int n) {
	for(int i = 0; i < n; i++)
		parent[i] = -1;
}

int find_set(int curr) {
	if(parent[curr] == -1)
		return curr;

	while(parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b) {
	int root1 = find_set(a);
	int root2 = find_set(b);
	
	if(root1 != root2)
		parent[root1] = root2;
}

void init_graph(GraphType *g) {
	g->edge_n = 0;
	g->ver_n = 0;
	for(int i = 0; i < 2 * SIZE; i++) {
		g->edges[i].start.x = 0; g->edges[i].start.y = 0;
		g->edges[i].end.x = 0; g->edges[i].end.y = 0;
		g->edges[i].cost = INF;
	}
}

void insert_edge(GraphType *g, coordinate start, coordinate end, double w) {
	g->edges[g->edge_n].start = start;
	g->edges[g->edge_n].end = end;
	g->edges[g->edge_n].cost = w;
	g->edge_n++;
}

int compare(const void *a, const void *b) {
	edge *x = (edge*)a;
	edge *y = (edge*)b;
	return (x->cost - y->cost);
}

void kruskal(GraphType *g) {
	int edge_accepted = 0;
	int uset, vset;
	double ans = 0.0;
	edge e;

	set_init(g->ver_n);
	qsort(g->edges, g->edge_n, sizeof(edge), compare);

	int i = 0;
	while(edge_accepted < (g->ver_n - 1)) {
		e = g->edges[i];
		uset = find_set(e.start.n);
		vset = find_set(e.end.n);
		if(uset != vset) {
			ans += g->edges[i].cost;
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
	printf("%.2lf\n", ans);
}

// 
void dist_a_to_b(GraphType *g, coordinate *coor) {
	int k = 0;
	double dist;
	for(int i = 0; i < g->ver_n; i++) {
		for(int j = i + 1; j < g->ver_n; j++) {
			dist = calc_dist(coor[i], coor[j]);
			insert_edge(g, coor[i], coor[j], dist);
		}
	}
}

// 두 점 사이의 거리를 계산하는 함수
double calc_dist(coordinate start, coordinate end) {
	double x = pow(fabs(end.x - start.x), 2);
	double y = pow(fabs(end.y - start.y), 2);
	return sqrt(x + y);
}


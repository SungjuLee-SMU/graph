#include "graph.h"
#define SN 10;

typedef struct {
	int V;
	int E;
	int** M;
} graphType;
typedef graphType* graphPtr;

graphPtr Create(int V) {
	graphPtr g = new graphType;
	g->E = 0;
	g->V = 0;
	g->M = InsertVertex(V, V, 0);
	return g;
}

int** InsertVertex(int NRow, int NCol, int Value) {
	int** m;
	m = new int* [NRow];

	for (int i = 0; i < NRow; i++) {
		m[i] = new int[NCol];
		for (int i = 0; i < NRow; i++) {
			for (int j = 0; j < NCol; j++)
				m[i][j] = Value;
		}
		return m;
	}
}

void InsertEdge(graphPtr g, int V1, int V2, int weight)
{
	if (g->M[V1][V2] == 0) {
		g->E++;
		g->M[V1][V2] = weight;
		g->M[V2][V1] = weight;
	}
}

void DeleteVertex(graphPtr g, int V1) {
	for (int i = 0; i < g->V; i++) {
		g->M[V1][i] = 0;
		g->M[i][V1] = 0;
	}
}

void DeleteEdge(graphPtr g, int V1, int V2) {
	if (g->M[V1][V2] != 0) {
		g->E--;
		g->M[V1][V2] = 0;
		g->M[V2][V1] = 0;
	}
}

void RetrieveVertex(graphPtr g, int Value) {
	for (int i = 0; i < g->V; i++) {
		for (int j = 0; j < g->V; j++) {
			if (g->M[i][j] == Value) {
				cout << "찾음" << Value << endl;
			}
			else
				cout << "찾지 못함" << endl;
		}
	}
}

void IsAdjacent(graphPtr g, int V1, int V2) {
	for (int i = 0; i < g->V; i++) {
		if (g->M[V1][i] != V2) {
			cout << "IsAdjacent" << endl;
		}
		else
			cout << "NotAdjacent" << endl;
	}
}

void IsEmpty(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		for (int j = 0; j < g->V; j++) {
			if (g->M[i][j] != 0) {
				cout << "IsEmpty" << endl;
			}
			else
				cout << "NotEmpty" << endl;
		}
	}
}

void Destroy(int NRow, int **m)
{
	for(int i = 0; i < NRow; i++)
		delete(m[i]);
	delete(m);
}

graphPtr InitGraph(int V)
{
	graphPtr G = new graphType;
	G->V = V;
	G->E = 0;
	G->M = InsertVertex(V, V, 0);
	return G;
}

int main()
{
	graphPtr GP=NULL;
	GP = Create(6);
	InsertEdge(GP, 0, 1, 12);
	InsertEdge(GP, 0, 4, 5);
	InsertEdge(GP, 1, 2, 3);
	InsertEdge(GP, 2, 3, 4);
	InsertEdge(GP, 2, 4, 8);
	InsertEdge(GP, 3, 2, 4);
	InsertEdge(GP, 4, 0, 5);
	InsertEdge(GP, 4, 2, 8);
	IsAdjacent(GP, 5, 2);
	DeleteVertex(GP, 5);

	return 0;
}
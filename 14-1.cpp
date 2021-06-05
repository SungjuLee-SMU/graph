#include <iostream>
using namespace std;
#define MAXNODE 100 
#define SN 10;

typedef struct {
	int V;
	int E;
	int** M;
} graphType;

typedef graphType* graphPtr;


int** InitMatrix(int NRow, int NCol, int Value) {
	int** m;
	m = new int* [NRow];

	for (int i = 0; i < NRow; i++) {
		m[i] = new int[NCol];
		for (int j = 0; j < NCol; j++)
			m[i][j] = Value;
	}
	return m;
}


void FreeMatrix(int** m, int NRow) {
	for (int i = 0; i < NRow; i++)
		delete(m[i]);
	delete(m);
}


graphPtr Creat(int V) {
	graphPtr G = new graphType;
	G->V = V;
	G->E = 0;
	G->M = InitMatrix(V, V, 0);
	return G;
}

void InsertVertex(graphPtr g, int V1) {
	if (g->V < V1) {
		int** m = InitMatrix(V1, V1, 0);
		for (int i = 0; i < g->V; i++) {
			for (int j = 0; j < g->V; j++) {
				m[j][i] = g->M[i][j];
			}
		}
		g->V = V1;
		g->M = m;
	}
}

void InsertEdge(graphPtr g, int V1, int V2, int weight) {
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


void RetieveVertex(graphPtr g, int value) {
	for (int i = 0; i < g->V; i++) {
		for (int j = 0; j < g->V; j++) {
			if (g->M[i][j] == value) {
				cout << i << " ";
			}
		}
	}
}


bool IsAdjacent(graphPtr g, int V1, int V2) {
	for (int i = 0; i < g->V; i++) {
		if (g->M[V1][i] != V2)
			printf("IsAdjacent");
	}
	printf("NotAdjacent");
}


bool IsEmpty(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		for (int j = 0; j < g->V; j++) {
			if (g->M[i][j] != 0)
				printf("IsEmpty\n");
		}
	}
	printf("NotEmpty\n");
}

void Destroy(graphPtr g) {
	FreeMatrix(g->M, g->V);
	g->V = 0;
	g->E = 0;
	printf("Destroy");
}

void Print_Graph(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		for (int j = 0; j < g->V; j++) {
			printf("  %d", g->M[i][j]);
		}
		cout << endl;
	}
}


int main() {
	graphPtr GP = NULL;
	GP = Creat(6);
	InsertEdge(GP, 0, 1, 12);
	InsertEdge(GP, 0, 4, 5);
	InsertEdge(GP, 1, 2, 3);
	InsertEdge(GP, 2, 3, 4);
	InsertEdge(GP, 2, 4, 8);
	InsertEdge(GP, 3, 2, 4);
	InsertEdge(GP, 4, 0, 5);
	InsertEdge(GP, 4, 2, 8);

	Print_Graph(GP);
	cout << endl;
	
	DeleteVertex(GP, 3);
	Print_Graph(GP);
	cout << endl;

	DeleteEdge(GP, 0, 1);
	Print_Graph(GP);
	cout << endl;

	RetieveVertex(GP, 5);
	cout << endl;

	Destroy(GP);
	
	return 0;
}

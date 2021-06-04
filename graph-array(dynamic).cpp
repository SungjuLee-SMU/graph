#include <iostream>
using namespace std;

typedef struct {
	int V; //정점
	int E; //간선(연결되는 거)
	int** M;
}graphType;
typedef graphType* Gptr;

int** InsertVertex(int n1, int n2, int data) {
	int** m;
	m = new int* [n1];

	for (int i = 0; i < n1; i++) {
		m[i] = new int[n2];
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				m[i][j] = data;
			}
		}
		return m;
	}
}

Gptr Create(int v) {
	Gptr G = new graphType;
	G->E = 0;
	G->V = v;
	G->M = InsertVertex(v, v, 0);
	return G;
}

void IsEmpty(Gptr G) {
	for (int i = 0; i < G->V; i++) {
		for (int j = 0; j < G->V; j++) {
			if (G->M[i][j]==0)
				cout << "Empty" << endl;
			else
				cout << "Not Empty" << endl;
		}
	}
}

void InsertEdge(Gptr G, int v1, int v2, int data) {
	if (G->M[v1][v2] == 0) {
		G->M[v1][v2] = data;
		G->M[v2][v1] = data;
		G->E++;
	}
}

void Destroy1(int** m, int v1) {
	for (int i = 0; i < v1; i++) {
		delete(m[i]);
	}
	delete(m);
}

void Destroy2(Gptr G) {
	Destroy1(G->M, G->V);
	G->E = 0;
	G->V = 0;
}

void RetrieveVertex(Gptr G, int key) {
	for (int i = 0; i < G->V; i++) {
		for (int j = 0; j < G->V; j++) {
			if (G->M[i][j] == key) {
				cout << "Find: " << key << endl;
			}
			else {
				cout << "No key" << endl;
			}
		}
	}
}

void IsAdjacent(Gptr G, int v1, int v2) {
	for (int i = 0; i < G->V; i++) {
		if (G->M[v1][i] != v2) {
			cout << "IsAdjacent" << endl;
		}
		else
			cout << "NotAdjacent" << endl;
	}
}

void DeleteVertex(Gptr G, int v1) {
	for (int i = 0; i < G->V; i++) {
		G->M[v1][i] = 0;
		G->M[i][v1] = 0;
	}
}

void DeleteEdge(Gptr G, int v1, int v2) {
	if (G->M[v1][v2] != 0) {
		G->M[v1][v2] = 0;
		G->M[v2][v1] = 0;
		G->E--;
	}
}

int main() {
	Gptr GP = NULL;
	GP = Create(6);
	InsertEdge(GP, 0, 1, 12);
	InsertEdge(GP, 0, 4, 5);
	InsertEdge(GP, 1, 2, 3);
	InsertEdge(GP, 2, 3, 4);
	InsertEdge(GP, 2, 4, 8);
	InsertEdge(GP, 3, 2, 4);
	InsertEdge(GP, 4, 0, 5);
	InsertEdge(GP, 4, 2, 8);

	RetrieveVertex(GP, 5);

	Destroy2(GP);

	return 0;
}
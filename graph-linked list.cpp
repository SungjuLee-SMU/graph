#include "graph.h"
#define SN 10;

typedef struct node{
	int Data;
	node* Next;
} node;
typedef node* Nptr;

typedef struct {
	int V;
	int E;
	node** L;
} graphType;

typedef graphType* graphPtr;

int** InitMatrix(int NRow, int NCol, int Value) {
	int** m;
	m = new int* [NRow];
	for (int i = 0; i < NRow; i++) {
		m[i] = new int[NCol];
	}
	for (int i = 0; i < NRow; i++) {
		for (int j = 0; j < NCol; j++) {
			m[i][j] = Value;
		}
	}
	return m;
}

graphPtr Create(int V) {
	graphPtr g = new graphType;
	g->V = V;
	g->E = 0;
	g->L = new node*;
	for (int i = 0; i < V; i++) {
		g->L[i] = NULL;
	}
	return g;
}

void InsertVertex(graphPtr g, int V1, int key) {
	g->L[V1]->Data = key;
}

void InsertEdge(graphPtr g, int V1, int V2) {
	Nptr temp = new node;
	temp->Data = V2;
	temp->Next = g->L[V1];
	g->L[V1] = temp;
}

void DeleteVertex(graphPtr g, int V1) {
	g->L[V1]->Data = 0;
}

void DeleteEdge(graphPtr g, int V1) {
	g->L[V1] = 0;
	free(g->L[V1]);
	g->E--;
}

void RetrieveVertex(graphPtr g, int key) {
	for (int i = 0; i < g->V; i++) {
		if (g->L[i]->Data == key) {
			cout << "찾음: " << key << endl;
		}
		else {
			cout << "찾지 못함" << endl;
		}
	}
}

bool IsAdjacent(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		for (; g->L[i] != NULL; g->L[i]->Next) {
			if(g->L[i] != 0)
				cout << "IsAdjacent" << endl;
		}
	}
}

bool IsEmpty(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		if (g->L[i] == NULL) {
			cout << "IsEmpty" << endl;
		}
		else {
			cout << "NotEmpty" << endl;
		}
	}
}

graphPtr InitGraph(int V){
	graphPtr g = new graphType;
	g->V = V;
	g->E = 0;
	g->L = new node*;
	for (int i = 0; i < V; i++)
		g->L[i] = NULL;
	return g;
}

void FreeMatrix(int** m, int NRow) {
	for (int i = 0; i < NRow; i++) {
		delete(m[i]);
	}
	delete(m);
}

void Destroy(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		free(g->L[i]);
	}
	free(g->L);
	g->V = 0;
	g->E = 0;
}

int main(){
	graphPtr GP = NULL;
	GP = Create(5);
	InsertEdge(GP, 0, 1);
	InsertEdge(GP, 0, 4);
	InsertEdge(GP, 1, 2);
	InsertEdge(GP, 2, 3);
	InsertEdge(GP, 2, 4);
	InsertEdge(GP, 3, 2);
	InsertEdge(GP, 4, 0);
	InsertEdge(GP, 4, 2);
	IsAdjacent(GP);
	DeleteVertex(GP, 5);
	Destroy(GP);

	return 0;
}
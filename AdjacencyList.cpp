#include <iostream>
using namespace std;

typedef struct node{
	int Data;
	node* Next;
}node;
typedef node* Nptr;

typedef struct{
	int V;
	int E;
	node** L;
}graphType;
typedef graphType* Gptr;

Gptr Create(int V) {
	Gptr G = new graphType;
	G->V = V;
	G->E = 0;
	G->L = new node*;
	for (int i = 0; i < V; i++) {
		G->L[i] = NULL;
	}
	return G;
}

void InsertEdge(Gptr G, int v1, int v2) {
	Nptr temp = new node;
	temp->Data = v2;
	temp->Next = G->L[v1];
	G->L[v1] = temp;
}

void IsAdjacent(Gptr G) {
	for (int i = 0; i < G->V; i++) {
		for (; G->L[i] != NULL; G->L[i] = G->L[i]->Next) {
			cout << i << "번째는 " << G->L[i]->Data << "와 연결" << endl;
		}
	}
}

void InsertVertex(Gptr G, int v1, int key) {
	G->L[v1]->Data = key;
}

void DeleteVertex(Gptr G, int v1) {
	G->L[v1]->Data = 0;
}

void DeleteEdge(Gptr G, int v1) {
	G->L[v1] = 0;
	free(G->L[v1]);
	G->E--;
}

void RetrieveVertex(Gptr G, int key) {
	for (int i = 0; i < G->V; i++) {
		if (G->L[i]->Data == key)
			cout << "Find: " << key << endl;
		else
			cout << "Not Found" << endl;
	}
}

void Destroy(Gptr G) {
	for (int i = 0; i < G->V; i++) {
		free(G->L[i]);
	}
	free(G->L);
	G->V = 0;
	G->E = 0;
}

void IsEmpty(Gptr G) {
	for (int i = 0; i < G->V; i++) {
		if (G->L[i] == NULL)
			cout << "IsEmpty" << endl;
		else
			cout << "NotEmpty" << endl;
	}
}

int main() {
	Gptr GP = NULL;
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

	RetrieveVertex(GP, 4);

	//Destroy(GP);

	return 0;
}
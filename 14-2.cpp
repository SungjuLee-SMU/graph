#include <iostream>
using namespace std;
#define MAXNODE 100 
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

graphPtr InitGraph(int V);
void InsertEdge(graphPtr g, int V1, int V2);

graphPtr InitGraph(int V){
	graphPtr G = new graphType;
	G->V = V;
	G->E = 0;
	G->L = new node*;
	for (int i = 0; i < V; i++)
		G->L[i] = NULL;
	return G;
}
void ShowFromNode(graphPtr g, int i) {
	for (; g->L[i] != NULL ; g->L[i] = g->L[i]->Next) {
		cout << i << "¹øÂ°: " << g->L[i]->Data << endl;
	}
}

void ShowAdjacencyGraph(graphPtr g) {
	for (int i = 0; i < g->V; i++) {
		ShowFromNode(g, i);
		cout << endl;
	}
}

void InsertEdge(graphPtr g, int V1, int V2){ 
  Nptr temp = new node;
  temp->Data = V2;
  temp->Next = g->L[V1];
  g->L[V1] = temp;
}

void InsertVertex(graphPtr G, int V1, int key) {
	G->L[V1]->Data = key;
}

void DeleteEdge(graphPtr G, int V1) {
	G->L[V1] = 0;
	free(G->L[V1]);
	G->E--;
}

void DeleteVertex(graphPtr G, int V1) {
	G->L[V1]->Data = 0;
}

void RetieveVertex(graphPtr G, int key) {
	for (int i = 0; i < G->V; i++) {
		if (G->L[i]->Data == key)
			cout << key << endl;
	}
}

void IsEmpty(graphPtr G) {
	for (int i = 0; i < G->V; i++) {
		if (G->L[i] == NULL)
			cout << "IsEmpty" << endl;
		else
			cout << "NotEmpty" << endl;
	}
}

void Destroy(graphPtr G) {
	for (int i = 0; i < G->V; i++) {
		free(G->L[i]);
	}
	free(G->L);
	G->V = 0;
	G->E = 0;
}

int main() {

	graphPtr GP = NULL;
	GP = InitGraph(5);
	InsertEdge(GP, 0, 1);
	InsertEdge(GP, 0, 4);
	InsertEdge(GP, 1, 2);
	InsertEdge(GP, 2, 3);
	InsertEdge(GP, 2, 4);
	InsertEdge(GP, 3, 2);
	InsertEdge(GP, 4, 0);
	InsertEdge(GP, 4, 2);

	DeleteVertex(GP, 3);
	cout << endl;
	
	DeleteEdge(GP, 1);
	cout << endl;
	
	ShowAdjacencyGraph(GP);

	return 0;
}

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
		cout << i << "¹øÂ° : " << g->L[i]->Data << endl;
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

int main(){

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

	ShowAdjacencyGraph(GP);


	return 0;
}
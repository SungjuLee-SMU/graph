#include "graph.h"
#define SN 10;

typedef struct {
	int V;
	int E;
	int** M;
} graphType;
typedef graphType* graphPtr;


int** InitMatrix(int NRow, int NCol, int Value)
{
	int** m;
	m = new int*[NRow];

	for (int i = 0; i < NRow; i++)
		m[i] = new int[NCol];
		for (int i = 0; i < NRow; i++)
			for (int j = 0; j < NCol; j++)
				m[i][j] = Value;
		return m;
}

void FreeMatrix(int NRow, int **m)
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
	G->M = InitMatrix(V, V, 0);
	return G;
}

void InsertEdge(graphPtr g, int V1, int V2, int weight)
{
  if (g->M[V1][V2] == 0){
	  g->E++;
	  g->M[V1][V2] = weight;
	  g->M[V2][V1] = weight;
  }
}


int main()
{
	graphPtr GP=NULL;
	GP = InitGraph(6);
	InsertEdge(GP, 0, 1, 12);
	InsertEdge(GP, 0, 4, 5);
	InsertEdge(GP, 1, 2, 3);
	InsertEdge(GP, 2, 3, 4);
	InsertEdge(GP, 2, 4, 8);
	InsertEdge(GP, 3, 2, 4);
	InsertEdge(GP, 4, 0, 5);
	InsertEdge(GP, 4, 2, 8);

	return 0;
}
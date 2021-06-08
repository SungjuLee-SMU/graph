// dataStructure_prac14_Graph.cpp
#include <iostream>
using namespace std;

struct Graph {
	int vertexNum;
	int **adjMatrix;
};

Graph Create(int num) {
	Graph g;

	g.vertexNum = 0;
	g.adjMatrix = new int*[num];
	for ( int i = 0; i < num; i++ ){
		g.adjMatrix[i] = new int[num];
	}

	return g;
}

void InsertVertex( int num, Graph myGraph ) {
	for ( int i = 0; i < myGraph.vertexNum; i++ ) {
		delete[] (myGraph.adjMatrix[i]);
	}
	delete[](myGraph.adjMatrix);

	myGraph.adjMatrix = new int*[num];
	for ( int i = 0; i < num; i++ ) {
		myGraph.adjMatrix[i] = new int[num];
	}

	myGraph.vertexNum = num;	
}

void Destroy ( Graph myGraph ) {
	for ( int i = 0; i < myGraph.vertexNum; i++ ) {
		delete[] (myGraph.adjMatrix[i]);
	}
	delete[](myGraph.adjMatrix);
}

void InsertEdge(int v, int u, Graph myGraph ) {
	myGraph.adjMatrix[v][u] = 1;
	myGraph.adjMatrix[u][v] = 1;
}

void DeleteEdge( int v, int u, Graph myGraph ) { 
	myGraph.adjMatrix[v][u] = 0;
	myGraph.adjMatrix[u][v] = 0;
}

void RetrieveVertex ( int v, Graph myGraph ) {
	for ( int i = 0; i < myGraph.vertexNum; i++ ){
		if ( myGraph.adjMatrix[v][i] == 1 ){
			cout << i << " ";
		}
	}
	cout << endl;
}

bool IsAdjacent ( int v, int u, Graph myGraph ) {
	if ( myGraph.adjMatrix[v][u] == 1 || myGraph.adjMatrix[u][v] == 1 )
		return true;
	else 
		return false;
}

bool IsEmpty ( Graph myGraph ){
	if ( myGraph.vertexNum == 0 ) 
		return true;
	else
		return false;
}

int main(void){
	Graph myGraph;

	myGraph = Create(3);
	InsertEdge( 0, 1, myGraph );
	InsertVertex ( 5, myGraph );
	InsertEdge( 1, 1, myGraph );
	DeleteEdge( 1, 1, myGraph );
	RetrieveVertex( 1, myGraph );
	InsertEdge ( 2, 2, myGraph );
	RetrieveVertex( 2, myGraph );
	cout << IsAdjacent( 2, 2, myGraph );
	cout << IsEmpty(myGraph) << endl;
	Destroy(myGraph);
	cout << IsEmpty(myGraph) << endl;

	return 0;

}
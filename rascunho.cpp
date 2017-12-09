/*
* Problema da coleta de neve
* 1 - Eulerização de Grafo - Edmonds e Johnson
* 2 - Percorrer caminho - algoritmo de fleury
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <vector>

#define MAX 20

using namespace std;

struct station{
	int mat[][];
	int dist;
};

class graph {
	private:
		station matrix[MAX][MAX];
	public:
		graph() {
			for (int i = 0; i < MAX; ++i)
			{
				for (int j = 0; j < MAX; ++j)
				{
					matrix[i][j].x = -1;
					matrix[i][j].y = -1;
					if (i == j)
					{
						matrix[i][j].dist = 0;
					}
					else matrix[i][j].dist = -1;
				}
			}
		}
		int euclideanD(int x, int x1,int y, int y1);
		bool checkEuler(station matrix[][], int nVertix);
		void process(station matrix[][], int v);
		//~graph();
};


int graph :: euclideanD(int x, int x1, int y, int y1){
	return sqrt( pow(x1-x,2) + pow(y1-y,2) );
}

// Cheking if the Graph is on Euler properties
bool graph :: checkEuler(station matrix, int nVertix) {
	int cont = 0;
	for (int i = 0; i < nVertix; ++i)
	{
		for (int j = 0; j < nVertix; ++j)
		{
			if (matrix[i][j] > 0)
			{
				cont++;
			}
		}
		if(cont == 0 || cont % 2 != 0) {
			return false;
		}
	}
}
// para encontrar o caminho minimo
void FloydWarshall(int mat[][], int v) {
	for(int k = 0; k < v; k++) {
		for(int i = 0; i < v; i++) `{
			for(int j = 0; j < v; j++) {
				if( mat[i][k] + mat[k][j] < mat[i][j] ){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
// Here we apply the algorithm to Eulerize a Graph G generic
void graph :: EdmondsJohnson(int mat[][], int v) {
	// here is where things get confused
	// Eulerize the graph:
	// 1 - Seja I o conjunto de todos os nao de grau impar
	
	int cout = 0;
	vector<int> vector Q;
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			if ( mat[i][j] > 0 )
			{
				cont++;
			}
			if ( (j == v-1) and (cont % 2) != 0 )
			{
				Q.push_back(i);
				cont = 0;
			} else cont = 0;
		}
	}
	// Agora eu tenho uma fila 
	// com todos os vertices de grau impar
	// preciso ver a distancia do caminho minimo para cada vertices
	// i e j que pertecem a fila
	// vou fazer uma matriz com matchings
	
	int menor = 0, aux = 0;
	int matchings[Q.size()-1][Q.size()]
	stack<int> stack S;
	for(int i = 0; i < Q.size()-1; i++) {
		for(int j = 0; j < 2; j++) {
			
		}
	}
	// Agora eu tenho os matchings, preciso ver o matching mais
	// "barato" - caminho minimo
	// mais facil pego a matriz resultante do algoritmo de warshall
	// e 

}


// Here we apply the algorithm to Eulerize a Graph G generic
void graph :: process(station mat[][], int v) {
	if (checkEuler){
		Fleury(mat, v);
	} else {
		// here is where we get confused
		// Eulerize the graph
		EdmondsJohnson(mat, v);
		Fleury(mat, v);
	}
}

int main () {

	return 0;
}

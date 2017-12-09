/*
* Problema da coleta de neve
* 1 - Eulerização de Grafo - Edmonds e Johnson
* 2 - Percorrer caminho - Algoritmo de Fleury
* 3 - Caminho minimo - Warshall 
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>


using namespace std;

void DFS(int G[][] ,stack &S, int x, int t, int E) {   
    int k = 0, m, a;
    S.push(x);
    for( int i = t; i < v ; i++ ) { 
        if( G[i][x] > 0 )   
        {   
            k = 1;
            G[i][x] = 0;
            G[x][i] = 0;
            DFS(G, S, i, 0);   
            break; 
        }
    }
    if( k == 0 )   
    {   
        S.pop();
        m = S.top();
        G[x][m] = 1;   
        G[m][x] = 1;   
        a = x + 1;
       // e = numero de arestas 
        if(S.size() != E)   
        {   
            S.pop();
            DFS(G, S, m, a);   
        }   
        else   
            S.push(x);
    }
}

// Algoritmo de Fleury 
// x vertice inicial 
// E numero de arestas
// uma variavel qualquer 
void Fleury(int G[][], int x, int E) {
    int k = 0, m;
    stack<int> S;
    // uma busca em profundidade para encontrar o caminho euleriano  
    // eu empilho os vertices na busca e desempilho para mostrar o caminho  
    DFS(G, S, x, 0, E);
    while( S.size() != 0 ) {
        m = S.top();
        // fazer uma alteração aqui:
        // quando eu vou desempilhando eu pego esse caminho, vejo se ele já foi
        // percorrido e calculo o tempo...
        cout << m + 1;
        S.pop();
    }
    cout << endl;
}

int euclideanD(int x1, int x2, int y1, int y2) {
	return sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
}

// Cheking if the Graph is on Euler properties
// check if every vertice have pair degree
bool checkEuler(int mat[][], int nVertix) {
	int cont = 0;
	for (int i = 0; i < nVertix; ++i)
	{
		for (int j = 0; j < nVertix; ++j)
		{
			if (mat[i][j] > 0)
			{
				cont++;
			}
		}
		if(cont == 0 || cont % 2 != 0)
		{
			return false;
		}
	}
}

// para encontrar o caminho minimo
void FloydWarshall(int mat[][], int v) {
	for(int k = 0; k < v; k++) {
		for(int i = 0; i < v; i++) {
			for(int j = 0; j < v; j++) {
				if( mat[i][k] + mat[k][j] < mat[i][j] ){
					mat[i][j] = mat[i][k] + mat[k][j];
				}
			}
		}
	}
}

// Here we apply the algorithm to Eulerize a Graph G generic
void EdmondsJohnson(int mat[][], int v) {

	// here is where things get confused
	// Eulerize the graph:
	// 1 - Seja I o conjunto de todos os de grau impar
	// no caso Q

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
			} 
			else cont = 0;
		}
	}

	// Agora eu tenho uma fila 
	// com todos os vertices de grau impar
	// vou fazer os matchings

	int menor = 0, aux = 0;

	// preciso ver a distancia do caminho minimo para cada vertices
	// i e j que pertecem a fila
	int matchings[Q.size()-1][Q.size()];
	stack<int> stack S;
	for(int i = 0; i < Q.size()-1; i++) {
		for(int j = 0; j < 2; j++) {
			
		}
	}
	// Agora eu tenho os matchings, preciso ver o matching mais
	// "barato" - caminho minimo
	// mais facil pego a matriz resultante do algoritmo de warshall
	// e vejo as combinações de cada matching 

}


// Here we apply the algorithm to Eulerize a Graph G generic
void process(int mat[][], int v) {
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

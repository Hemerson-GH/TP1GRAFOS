#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Aresta {
	int vertex;
	int weight;
	
	Aresta(int v, int w);
};

Aresta::Aresta(int v, int w){
	vertex = v;
	weight = w;
}

vector < vector <Aresta> > GRAPH(100); // constroi um vector de 100 linhas};

void imprimiCaminho(vector <int> caminho) {
    
    int menorPeso = 0;
    
    cout << "[ ";
    
    for(int i = 0; i < (int)caminho.size(); i++) {
        cout << caminho[i] << " "; // imprimi o caminho(vector), todos os elementos do vector que foi passado		
    }
	cout << "]" << endl;	
	
    for (int i = 0; i < (int)caminho.size(); i++)
	{
		menorPeso = GRAPH[caminho[i]][0].weight;
		
		for (int j = 0; j < (int)GRAPH[caminho[i]].size(); j++)
		{
			if (GRAPH[caminho[i]][j].vertex == caminho[i+1])
			{
				if (menorPeso < GRAPH[caminho[i]][j].weight)
				{
					menorPeso = GRAPH[caminho[i]][j].weight;
				}
				//~ cout << GRAPH[caminho[i]][j].vertex << " " << GRAPH[caminho[i]][j].weight << " ";
			}
		}
	}
	cout << "Menor peso é " << menorPeso << endl;
}

bool nohVizinhoNaoEstaPresenteNoCaminho(int node, vector <int> caminho) {
	for(int i = 0; i < (int)caminho.size(); i++) {// percorre o caminho(vector) procurando se o no que foi passado pertence ao caminho
		if(caminho[i] == node) {
			return false; // se obteve exito na busca retornara false
		}
	}
	
	return true; // caso nao encontrou ira retornar true
}

void encontraCaminho(int partida, int destino)
{
    vector <int> caminho; // crio um novo vector para armazenar o caminho
    //~ vector <int> caminho; // crio um novo vector para armazenar o caminho
    caminho.push_back(partida); // adiciono o vertice de partida ao inicio do caminho
    queue < vector <int>> q; // cria uma fila de vector
    q.push(caminho); // coloco o caminho(vector) na fila

    while(!q.empty()) // execute ate a pilha for vazia
    {
        caminho = q.front(); // caminho recebe primeiro elemento da fila, que antes era o caminho
        q.pop(); // desenfilera a fila de caminhos
		
		
        int ultimoNohDoCaminho = caminho[caminho.size()-1]; // ultimonoh recebendo o ultimo elemento do caminho(vector)
	
        if(ultimoNohDoCaminho == destino) {// compara se ja chegou no destino
            cout << "O Caminho Necessário é :: ";
            imprimiCaminho(caminho); // imprimi todo percuso
        }
        else {
			// imprimiCaminho(caminho);
        } 
        
       for(int i = 0; i < (int)GRAPH[ultimoNohDoCaminho].size(); i++) {
            if(nohVizinhoNaoEstaPresenteNoCaminho(GRAPH[ultimoNohDoCaminho][i].vertex, caminho)) {
                vector <int> new_caminho(caminho.begin(), caminho.end());
                new_caminho.push_back(GRAPH[ultimoNohDoCaminho][i].vertex);
                q.push(new_caminho);
            }
        }
    }
}
int main()
{
    int T  	= 1;
    
    while(T--)
    {
		GRAPH[1].push_back( Aresta(2, 10) );
		GRAPH[1].push_back( Aresta(3, 15) );
		
		GRAPH[2].push_back( Aresta(1, 10) );
		GRAPH[2].push_back( Aresta(3, 8) );
		GRAPH[2].push_back( Aresta(4, 1) );
		
		GRAPH[3].push_back( Aresta(2, 8) );
		GRAPH[3].push_back( Aresta(1, 15) );
		GRAPH[3].push_back( Aresta(5, 5) );
		
		GRAPH[4].push_back( Aresta(2, 1) );
		
		GRAPH[5].push_back( Aresta(3, 5) );
		
		//~ for (int i = 1; i <= 5; i++)
		//~ {
			//~ cout << i << "=> ";
			//~ for (int j = 0; j < (int)GRAPH[i].size(); j++)
			//~ {
				//~ cout << GRAPH[i][j].vertex << " " << GRAPH[i][j].weight << " ";
			//~ }
			//~ cout << endl;
		//~ }
		
        encontraCaminho(1, 5);
    }

    return 0;
}

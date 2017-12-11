#include <iostream>
#include <limits.h>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct CaminhoEPeso{
	vector <int> caminho;
	int menorPeso;
	int numCaso;
	CaminhoEPeso(vector <int> caminhoConstrutor, int menorPesoConstrutor, int numCasoConstrutor);
};

CaminhoEPeso::CaminhoEPeso(vector <int> caminhoConstrutor, int menorPesoConstrutor, int numCasoConstrutor){
	caminho = caminhoConstrutor;
	menorPeso = menorPesoConstrutor;
	numCaso = numCasoConstrutor;
}

struct Aresta {
	int verticeAdj;
	int pesoAresta;
	
	Aresta(int v, int w);
};

Aresta::Aresta(int v, int w){
	verticeAdj = v;
	pesoAresta = w;
}

vector < CaminhoEPeso > caminhosPossiveis;
int numCaso = 1;

void relacionaPesoComCaminho(vector < vector <Aresta> > grafo, vector <int> caminho) 
{    
    int menorPeso = INT_MAX;	
	
    for (int i = 0; i < (int)caminho.size()-1; i++)
	{
		for (int j = 0; j < (int)grafo[caminho[i]].size(); j++)
		{
			if (grafo[caminho[i]][j].verticeAdj == caminho[i+1])
			{
				if (menorPeso > grafo[caminho[i]][j].pesoAresta)
				{
					menorPeso = grafo[caminho[i]][j].pesoAresta;
				}
			}
		}
	}
	
	caminhosPossiveis.push_back(CaminhoEPeso(caminho, menorPeso, numCaso++));
}

bool verticeNaoPertenceNoCaminho(int vertice, vector <int> caminho) 
{
	for(int i = 0; i < (int)caminho.size(); i++) 
	{
		if(caminho[i] == vertice) 
		{
			return false; 
		}
	}
	
	return true; 
}

void encontraCaminhos(vector < vector <Aresta> > grafo, int partida, int destino)
{
    vector <int> caminho;
    caminho.push_back(partida);
    queue < vector <int> > filaDeCaminhos;
    filaDeCaminhos.push(caminho);

    while(!filaDeCaminhos.empty()) 
    {
        caminho = filaDeCaminhos.front();
        filaDeCaminhos.pop();
		
        int ultimoCaminho = caminho[caminho.size()-1];
	
		if(ultimoCaminho == destino) 
		{
			relacionaPesoComCaminho(grafo, caminho); 
		}
        
		for(int i = 0; i < (int)grafo[ultimoCaminho].size(); i++) 
		{
			if( verticeNaoPertenceNoCaminho(grafo[ultimoCaminho][i].verticeAdj, caminho) ) 
			{
				vector <int> novo_caminho(caminho.begin(), caminho.end());
				novo_caminho.push_back(grafo[ultimoCaminho][i].verticeAdj);
				filaDeCaminhos.push(novo_caminho);
			}
		}
    }
}

CaminhoEPeso confereMelhorCaminho(vector <CaminhoEPeso> caminhosEncontrados)
{
	CaminhoEPeso melhorCaminho = caminhosEncontrados[0];
	
	for (int i = 0; i < (int)caminhosEncontrados.size(); i++)
	{
		if (melhorCaminho.menorPeso < caminhosEncontrados[i].menorPeso)
		{
			melhorCaminho = caminhosEncontrados[i];
		} 
		else if (melhorCaminho.menorPeso == caminhosEncontrados[i].menorPeso)
		{
			if (melhorCaminho.caminho.size() > caminhosEncontrados[i].caminho.size())
			{
				melhorCaminho = caminhosEncontrados[i];
			}
		}
	}	
	
	return melhorCaminho;	
}

//~ int main(int argc, char* argv[])
int main()
{
	//~ if (argc != 2)
	//~ {
		//~ cerr << "Preciso: ";
		//~ cerr << argv[0] << " E Um Arquivo De Texto" << endl;
		//~ exit(EXIT_FAILURE);
	//~ }
	
	//~ ifstream arq(argv[1]);
	
	ifstream arq("entradas.txt");
	
	int numVertices, numArestas, vertice, verticeAdj, pesoAresta;
    int partida, destino, numeroDePassageiros;
    
    if (arq.good()) 
    {
		arq >> numVertices;
		arq >> numArestas;
		
		while(numVertices != 0 && numArestas != 0)
		{
			vector < vector <Aresta> > grafo(numVertices+1);

			for (int i = 1; i <= numArestas; i++)
			{
				arq >> vertice;
				arq >> verticeAdj;
				arq >> pesoAresta;
				grafo[vertice].push_back( Aresta(verticeAdj, pesoAresta) );
				grafo[verticeAdj].push_back( Aresta(vertice, pesoAresta) );				
			}		
			
			arq >> partida;
			arq >> destino;
			arq >> numeroDePassageiros;

			encontraCaminhos(grafo, partida, destino);
			
			confereMelhorCaminho(caminhosPossiveis);
			CaminhoEPeso melhornumCaso = confereMelhorCaminho(caminhosPossiveis);
			
			cout << "Caso #" << melhornumCaso.numCaso << endl;
			cout << "Mínimo de viagens = " << ceil((double)numeroDePassageiros/(melhornumCaso.menorPeso-1)) << endl;
			cout << "Rota: ";
			
			for (int j = 0; j < (int)melhornumCaso.caminho.size(); j++)
			{
				cout << melhornumCaso.caminho[j];
				
				if(j < (int)melhornumCaso.caminho.size()-1) 
				{ 
					cout <<  " - "; 
				}
			}
			
			cout << endl << endl;
			
			arq >> numVertices;
			arq >> numArestas;	
			
			numCaso = 1;
			caminhosPossiveis.clear();
			grafo.clear();
		}
		
	} 
	
	else {
		cout << "Arquivo corrompido" << endl;
	}
    
    // Função que retorna o tempo de execução do programa
	clock_t Ticks[2] = { clock(), clock() };
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    cout << endl << "Tempo Gasto: Milissegundos: " <<  Tempo;	
	// Função que retorna o tempo de execução do programa

    return 0;
}

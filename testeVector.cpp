#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct CaminhoEPeso{
	vector <int> caminho;
	int pesoMenor;
	
	CaminhoEPeso(vector <int> caminhoConstrutor, int pesoMenorConstrutor);
};

CaminhoEPeso::CaminhoEPeso(vector <int> caminhoConstrutor, int pesoMenorConstrutor){
	caminho = caminhoConstrutor;
	pesoMenor = pesoMenorConstrutor;
}

struct Aresta {
	int vertex;
	int weight;
	
	Aresta(int v, int w);
};

Aresta::Aresta(int v, int w){
	vertex = v;
	weight = w;
}

vector < vector <Aresta> > GRAPH(100); 
vector < CaminhoEPeso > caminhosPossiveis;
vector < CaminhoEPeso > caminhosPossiveisOrdenados;

void BubbleSort(int n, vector < CaminhoEPeso > caminhos)
{
	CaminhoEPeso aux = caminhos[0];
	
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (caminhos[j].pesoMenor > caminhos[j+1].pesoMenor)
			{
				aux = caminhos[j+1];
				caminhos[j+1] = caminhos[j];
				caminhos[j] = aux;
			}
		}
	}
}

void imprimiCaminho(vector <int> caminho) 
{    
    int menorPeso = 1000000;
    
    //~ cout << "[ ";
    
    //~ for(int i = 0; i < (int)caminho.size(); i++) {
        //~ cout << caminho[i] << " ";
    //~ }
	//~ cout << "]" << endl;	
	
    for (int i = 0; i < (int)caminho.size()-1; i++)
	{
		for (int j = 0; j < (int)GRAPH[caminho[i]].size(); j++)
		{
			if (GRAPH[caminho[i]][j].vertex == caminho[i+1])
			{
				if (menorPeso > GRAPH[caminho[i]][j].weight)
				{
					menorPeso = GRAPH[caminho[i]][j].weight;
				}
			}
		}
	}
	
	caminhosPossiveis.push_back(CaminhoEPeso(caminho, menorPeso));
}

bool nohVizinhoNaoEstaPresenteNoCaminho(int node, vector <int> caminho) 
{
	for(int i = 0; i < (int)caminho.size(); i++) 
	{
		if(caminho[i] == node) 
		{
			return false; 
		}
	}
	
	return true; 
}

void encontraCaminhos(int partida, int destino)
{
    vector <int> caminho;
    caminho.push_back(partida);
    queue < vector <int>> q;
    q.push(caminho);

    while(!q.empty()) 
    {
        caminho = q.front();
        q.pop();
		
        int ultimoNohDoCaminho = caminho[caminho.size()-1];
	
        if(ultimoNohDoCaminho == destino) 
        {
            //~ cout << "O Caminho Necessário é :: ";
            imprimiCaminho(caminho); 
        }
        else {
			// imprimiCaminho(caminho);
        } 
        
       for(int i = 0; i < (int)GRAPH[ultimoNohDoCaminho].size(); i++) 
       {
            if(nohVizinhoNaoEstaPresenteNoCaminho(GRAPH[ultimoNohDoCaminho][i].vertex, caminho)) 
            {
                vector <int> new_caminho(caminho.begin(), caminho.end());
                new_caminho.push_back(GRAPH[ultimoNohDoCaminho][i].vertex);
                q.push(new_caminho);
            }
        }
        
    }
    
}

//~ CaminhoEPeso confereViagens(vector <CaminhoEPeso> caminhos)
void confereViagens(vector <CaminhoEPeso> caminhos)
{
	//~ QuickSort(caminhos, 0, (int)caminhos.size());
	BubbleSort((int)caminhos.size(), caminhos);
	
	for (int i = 0; i < (int)caminhosPossiveisOrdenados.size(); i++)
	{
		cout << "Percurso (";
		for (int j = 0; j < (int)caminhosPossiveisOrdenados[i].caminho.size(); j++)
		{
			cout << caminhosPossiveisOrdenados[i].caminho[j];
			if(j < (int)caminhosPossiveisOrdenados[i].caminho.size()-1 ) { cout <<  ", "; }
		}
		cout << ") Menor Peso " << caminhosPossiveisOrdenados[i].pesoMenor << endl;
	}	
}

int main()
{
    int T  	= 1;
    
    while(T--)
    {
		GRAPH[1].push_back( Aresta(2, 30) );
		GRAPH[1].push_back( Aresta(3, 15) );
		GRAPH[1].push_back( Aresta(4, 10) );
		
		GRAPH[2].push_back( Aresta(4, 25) );
		GRAPH[2].push_back( Aresta(5, 60) );
		
		GRAPH[3].push_back( Aresta(4, 40) );
		GRAPH[3].push_back( Aresta(6, 20) );
		
		GRAPH[4].push_back( Aresta(7, 35) );
		
		GRAPH[5].push_back( Aresta(7, 20) );
		
		GRAPH[6].push_back( Aresta(7, 30) );
		
		//~ for (int i = 1; i <= 5; i++)
		//~ {
			//~ cout << i << "=> ";
			//~ for (int j = 0; j < (int)GRAPH[i].size(); j++)
			//~ {
				//~ cout << GRAPH[i][j].vertex << " " << GRAPH[i][j].weight << " ";
			//~ }
			//~ cout << endl;
		//~ }
		
        encontraCaminhos(1, 7);
        confereViagens(caminhosPossiveis);
    }

    return 0;
}

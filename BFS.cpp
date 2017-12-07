#include <stdio.h>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector <vector <int> > GRAPH(100);

inline void imprimiCaminho(vector <int> caminho)
{
    cout << "[ ";
    for(int i = 0; i < (int)caminho.size(); i++)
    {
        cout << caminho[i] << " ";
    }
    cout << "]" << endl;
}

bool nohVizinhoNaoEstaPresenteNoCaminho(int node, vector <int> caminho)
{
    for(int i = 0; i < (int)caminho.size(); i++)
    {
        if(caminho[i] == node)
          return false;
    }
    return true;
}

int encontraCaminho(int partida, int destino, int totalnode, int totaledge)
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
            cout << "O Caminho Necessário é :: ";
            imprimiCaminho(caminho);
        }
        else
        {
           // imprimiCaminho(caminho);
        }

        for(int i = 0; i < (int)GRAPH[ultimoNohDoCaminho].size(); i++)
        {
            if(nohVizinhoNaoEstaPresenteNoCaminho(GRAPH[ultimoNohDoCaminho][i], caminho))
            {
                vector <int> new_caminho(caminho.begin(), caminho.end());
                new_caminho.push_back(GRAPH[ultimoNohDoCaminho][i]);
                q.push(new_caminho);
            }
        }
    }
    return 1;
}
int main()
{
    //freopen("out.txt","w",stdout);

    int T, N, M, u, v, partida, destino;
    
    cout << "Insira a quantidade de grafos para o teste" << endl;
    
    cin >> T;

    while(T--)
    {
        cout << ("Insira O Total De Vertices & Total De Arestas\n");
        
        cin >> N >> M;
        
        for(int i = 1; i <= M; i++)
        {
            cin >> u >> v;
            GRAPH[u].push_back(v);
        }

        cout << "Insira O Vertice De Partida E Destino" << endl;

        cin >> partida >> destino;
        
        encontraCaminho(partida, destino, N, M);
    }

    return 0;
}

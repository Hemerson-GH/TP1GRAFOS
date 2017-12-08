#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//////////////////// FUNCOeS AUXILIAReS ////////////////////
struct graph{
  int peso;
  int vertix;
  int ancestral;
};

struct Aresta{
	int x1, y1, x2, y2;
	Aresta(int x1, int x2, int y1, int y2);
};

Aresta::Aresta(int xP1, int xP2, int yP1, int yP2){
	x1 = xP1;
	y1 = yP1;
	x2 = xP2; 
	y2 = yP2;
}
//procurar todas as possibilidades de caminhos
// funcao paths(matriz, vetices)

int numVertices(vector <Aresta> v)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		i--;
	}	
	return 1;
}

int addVertice(vector <Aresta> vertices, int x1, int x2)
{
	bool repeat = false;
	
	for (int i = 0; i < (int)vertices.size() && repeat == false; i++, i++)
	{
		if ( (x1 == vertices[i].x1 && x2 == vertices[i].x2))
		{
			repeat = true;
			cout << x1 << " " << x2 << endl;
			cout << vertices[i].x1 << " " << vertices[i+1].x2 << endl;
			cout << vertices[i].y1 << " " << vertices[i+1].y2 << endl << endl;
		}		
	}	
	
	if (!repeat)
	{
		//~ vertices.push_back();
		return 1;
	}
	
	cout << "NIL" << endl;	
	return 0;
}

int euclideanDistance(int x1, int x2, int y1, int y2){
	return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}

//~ int main(int argc, char* argv[])
int main()
{
	//~ if (argc != 2)
	//~ {
		//~ cerr << "Uso: " << endl;
		//~ cerr << argv[0] << " arquivoEntrada" << endl;
		//~ exit(EXIT_FAILURE);
	//~ }
	
	//~ ifstream arq(argv[1]);
	ifstream arq("exe2.txt");
	
	string cases;
	
	string ele;
	
	string linha = "";
	
	vector <Aresta> ligacoes;
	
	int x2, y2, x1, y1;
	
	string vertexInit[2];
	//~ int mat[3][4];
	
	vector <int> vertex;

	int n = 0;
	
	if (arq.good()) {

		//~ arq >> cases;
		getline(arq, cases);
		
		//~ arq >> vertexInit[0];
		getline(arq, vertexInit[0]);
		//~ getline(arq, vertexInit[1]);
		//~ arq >> vertexInit[1];
		
		//~ int espacoEmBranco;
		//~ arq >> espacoEmBranco;
		getline(arq, linha);
		int cont = 0;
		
		while(getline(arq, linha) && cont == 0)
		{
			//~ if (linha == "" ) {cout << "Parei"; break;}
			if (linha == "" ) {cont = 1;}
			
			stringstream line(linha);
			//~ ligacoes.push_back(linha);
			
			line >> x1 >> y1 >> x2 >> y2;
			//~ cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
			
			//~ cout << "distancia " << euclideanDistance(x1, x2, y1, y2) << endl;
			
			if(cont == 0) { 
				ligacoes.push_back( Aresta(x1, x2, y1, y2) );
				n += addVertice(ligacoes, x1, x2);
				n += addVertice(ligacoes, y1, y2);
				
			}
		}
		
		

	} else {
		cout << "Arquivo corrompido" << endl;
	}
	
	cout << n << endl;
	
	for (int i = 0; i < (int)ligacoes.size(); i++)
	{
		cout << ligacoes[i].x1 << ' ' << ligacoes[i].y1 << ' ' << ligacoes[i].x2 << ' ' << ligacoes[i].y2 << endl;
	}
	
	
	//~ cout << cases << endl;
	//~ cout << vertexInit[0] << " === " << vertexInit[1] << endl;
	
	//~ for (int i = 0; i < 2; i++)
	//~ {
		//~ cout << vertexInit[i] << endl;	
	//~ }	
	//~ for (int i = 0; i < (int) texto.size(); i++)
	//~ {
		//~ cout << texto[i] << ' ';	
	//~ }	

  return 0;
}

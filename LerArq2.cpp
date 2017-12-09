#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <time.h>
#include <cmath>

using namespace std;

struct graph{
  int peso;
  int vertix;
  int ancestral;
};

struct Cordenadas{
	int vertex;
	float x, y, x2, y2;
	Cordenadas(int vertex, float x, float y);
	Cordenadas(float x, float y, float x2, float y2);
};

//~ struct Cordenada{
	//~ float x, y;
	//~ Cordenada(float x, float y);
//~ };

Cordenadas::Cordenadas(int v, float xP1, float yP1){
	vertex = v;
	x = xP1;
	y = yP1;
}
Cordenadas::Cordenadas(float xP1, float yP1, float xP2, float yP2){
	x = xP1;
	y = yP1;
	x = xP2;
	y = yP2;
}

vector <Cordenadas> vertices;
vector <Cordenadas> grafoInteiro;

bool addvertices(int i, float x, float y) {
	bool repeat = false;
	
	if ((int)vertices.size() != 0) {
		for (int i = 0; i < (int)vertices.size() && repeat == false; i++) {
			if ( (x == vertices[i].x) && (y == vertices[i].y)) {
				repeat = true;			
			}		
		}	
	}
	
	if (repeat == false) {
		vertices.push_back(Cordenadas(i, x, y));
		return true;
	}
	
	return false;
}

int euclideanDistance(int x1, int x2, int y1, int y2){
	return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}

void preencheMat(int** mat){
	int valor = 0, iterador =  0;
	for (int i = 0; i < (int)grafoInteiro.size(); i++)
	{
		for (int j = 0; j < (int)vertices.size(); j++)
		{
			if ( (grafoInteiro[i].x == vertices[j].x && grafoInteiro[i].y == vertices[j].y) ||
			     (grafoInteiro[i].x == vertices[j].x && grafoInteiro[i].y == vertices[j].y) )
			{
				
				valor = euclideanDistance(grafoInteiro[i].x, grafoInteiro[i].x2, grafoInteiro[i].y, grafoInteiro[i].y2);
				iterador = (int)vertices[j].vertex;
				cout << valor << endl;
				mat[iterador][iterador] = valor;
			}
		}	
	}	
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
	
	string cases, linha = "";
	
	float x2, y2, x1, y1;
	int i = 1;
	
	if (arq.good()) {

		getline(arq, cases);
		getline(arq, linha);
		getline(arq, linha);
		
		stringstream line(linha);
		line >> x1 >> y1;
		vertices.push_back( Cordenadas(i, x1, y1) );		
		//~ grafoInteiro.push_back( Cordenadas(x1, y1) );		
		i++;
		int cont = 0;
		
		while(getline(arq, linha) && cont == 0)
		{
			
			if (linha == "" ) {cont = 1;}
			
			stringstream line(linha);
			
			line >> x1 >> y1 >> x2 >> y2;
			
			if(linha != "" && cont == 0) { 
				if ( addvertices(i, x1, y1) ) { i++; } 
				if ( addvertices(i, x2, y2) ) { i++; }
				grafoInteiro.push_back(Cordenadas(x1, y1, x2, y2));
			}
		}
		
		int n = (int)vertices.size();
		
		int **mat = new int*[n];
	
	
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[n];
		}
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				mat[i][j] = 0;
			}			
		}
		
		preencheMat(mat);
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << mat[i][j] << " " << endl;
			}			
		}

	} else {
		cout << "Arquivo corrompido" << endl;
	}
	
	for (int i = 0; i < (int)vertices.size(); i++)
	{
		cout << vertices[i].vertex << "\t" << vertices[i].x << "\t" << vertices[i].y << "\t";
		if (i == 1 || i == 3)
		{
			cout << "\n";
		}
		
	}
	
	clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Tempo gasto: ms." <<  Tempo;
    getchar();
	
  return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <time.h>
#include <cmath>

using namespace std;

// nao esta sendo utilizado ainda ou nao vai ser
struct graph{
  int peso;
  int vertix;
  int ancestral;
};

// 
struct Cordenadas{
	int vertex, vertex1, vertex2;
	float x, y, x2, y2;
	double distance;
	Cordenadas(int vertex, float x, float y);
	Cordenadas(float x, float y, float x2, float y2, double distance, int v1, int v2);
};

// construtor para a lista de vertices nao repetidos
Cordenadas::Cordenadas(int v, float xP1, float yP1){
	vertex = v;
	x = xP1;
	y = yP1;
}

// construtor para a lista com todos os vertices
Cordenadas::Cordenadas(float xP1, float yP1, float xP2, float yP2, double dist, int v1, int v2){
	x = xP1;
	y = yP1;
	x2 = xP2;
	y2 = yP2;
	distance = dist;
	vertex1 = v1;
	vertex2 = v2;
}

vector <Cordenadas> vertices; // lista que vai guardar apenas os vertices nao repetidos
vector <Cordenadas> grafoInteiro; // lista com todos os vertices do arquivo para fazer comparações

// adiciona os nao repetidos vertices na lista 
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

// calcula a distancia euclidiana
int euclideanDistance(float x1, float x2, float y1, float y2){
	return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}

// preenche a matriz com os pesos de cada aresta relacionado aos vertices
void preencheMat(int** mat){
	int valor = 0, v1, v2;
	
	for (int i = 0; i < (int)vertices.size(); i++) {
		for (int j = 0; j < (int)grafoInteiro.size(); j++) {
			if ( (vertices[i].x == grafoInteiro[j].x && vertices[i].y == grafoInteiro[j].y) 
																	|| (vertices[i].x == grafoInteiro[j].x2 && vertices[i].y == grafoInteiro[j].y2))
			{
				valor = grafoInteiro[j].distance;
				v1 = grafoInteiro[j].vertex1;
				v2 = grafoInteiro[j].vertex2;
				mat[v1][v2] = valor;
				mat[v2][v1] = valor;
			}		
		}	
	}	
}

// realiza uma busca para saber qual vertice é dono da coordenada passada 
int buscaVert(float x, float y) {	
	for (int i = 0; i < (int)vertices.size(); i++) {
		if (vertices[i].x == x && vertices[i].y == y) 
		{
			return vertices[i].vertex;
		}	
	}	
	return 999999999;
	// POG, arrumar depois 
}


/* Ele pediu que para testar o programa ele passaria apenas o ./exe e o arquivo de teste
 * eu ja arrumei, porém esta commitado porque esta em fase de teste ainda e nao quero ficar
 * executando toda hora pelo terminal, sendo assim é so executar que roda normalmente...
 */
 
 
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
	int i = 1, v1, v2, cont = 0; 
	double dist = 0.0;
	
	if (arq.good()) { // lê arquivo se ele estiver ok

		getline(arq, cases); // utilizar depois os numeros de casos
		getline(arq, linha); // lê linha em branco 
		getline(arq, linha); // lê o primeiro vertive ou coordenada
		
		stringstream line(linha);
		line >> x1 >> y1;
		vertices.push_back( Cordenadas(i++, x1, y1) );
		
		while(getline(arq, linha) && cont == 0)
		{
			
			if (linha == "" ) { cont = 1; } // POG, para fazer a leitura para somente um grafo 
			
			stringstream line(linha); // pega linha inteira lida do arquivo destrincha ela para adicionar na lista
			
			line >> x1 >> y1 >> x2 >> y2; // passa da variavel destrinchada para cada variavel
			
			if(linha != "" && cont == 0) { // POG, confere se nao chegou em uma linha em branco
				
				if ( addvertices(i, x1, y1) ) { i++; } // adiciona na lista os não repetidos e incrementa o iterador i
				if ( addvertices(i, x2, y2) ) { i++; } // adiciona na lista os não repetidos e incrementa o iterador i
				dist = euclideanDistance(x1, x2, y1, y2); // atribui a distancia euclidiana de para as coordenadas passadas
				v1 = buscaVert(x1, y1); // confere de quem é o vertice com essas coordenadas
				v2 = buscaVert(x2, y2); // confere de quem é o vertice com essas coordenadas
				grafoInteiro.push_back(Cordenadas(x1, y1, x2, y2, dist, v1, v2)); // adiociona tudo na lista
			
			}
		}
		
		int n = (int)vertices.size(); // atribui a n a quantidade de vertices que a matriz tem que ter		
		int **mat = new int*[n]; 
	
		for (int i = 1; i <= n; i++){
			mat[i] = new int[n];
		}
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				mat[i][j] = 0;
			}			
		}
		
		// aloca uma matriz de ponteiros e atribui '0' a todos os valores dela
		
		preencheMat(mat); // preenche a matriz com os determinados valores corretos
		
		// imprimi matriz para conferir se esta certo;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cout << mat[i][j] << " ";
			}			
			cout << endl;
		}
		
		// qualquer operação que for realizar com a matriz podera ser feito aqui

	} else {
		cout << "Arquivo corrompido" << endl; // caso o arquivo esteja corrompido
	}
	
	
	// Função que retorna o tempo de execução
	
	clock_t Ticks[2];
    Ticks[0] = clock(), Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Tempo gasto: ms." <<  Tempo;
    //~ getchar();
	
	// Função que retorna o tempo de execução
	
  return 0;
}

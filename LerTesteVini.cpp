#include <iostream>
#include <fstream>
#include <vector>
#include<stdio.h>

using namespace std;

//////////////////// FUNCOeS AUXILIAReS ////////////////////
struct graph{
  int coordenadas[2];
};
//procurar todas as possibilidades de caminhos
// funcao paths(matriz, vetices)

void addVertice(vector <int> vertices, int v)
{
	bool repeat = false;
	
	for (int i = 0; i < (int) vertices.size(); i++)
	{
		if (v == vertices[i])
		{
			repeat = true; 
		}		
	}	
	
	if (!repeat)
	{
		vertices.push_back(v);
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
	int cases;
	// vou usar ele para ler caracter a caracter
	int ele, i = 1, j = 0;
	bool conexo = false;
	
	vector <graph> vertex;
	arq >> cases;
	
	if(arq.good()){
		
		while(ele != '/' and !EOF){
			
		arq >> ele;
		
		arq >> vertex[0].coordenadas[0];
		
		arq >> vertex[0].coordenadas[1];
		cout << vertex[0].coordenadas[0];
		
		arq >> ele;
		vertex[i].coordenadas[j] = ele;
		
		arq >> ele;
		vertex[i].coordenadas[j+1] = ele;
		
		if ( vertex[i].coordenadas[j] == vertex[0].coordenadas[0] and 
				vertex[i].coordenadas[j] == vertex[0].coordenadas[1] ){
			conexo = true;			
		}
		j = 0;
		i++;
		}
	}
	else {
		cout << "Arquivo corrompido" << endl;
	}
	
	for (int i = 0; i < (int)vertex.size(); i++)
	{
		for(int j = 0; j < 2; j++) {
			cout << vertex[i].coordenadas[j] << ' ';
			
		}	
	}	
	

  return 0;
}
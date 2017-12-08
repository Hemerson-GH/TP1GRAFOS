#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//////////////////// FUNCOeS AUXILIAReS ////////////////////
struct graph{
  int peso;
  int vertix;
  int ancestral;
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
	
	string cases;
	
	string ele;
	
	string texto = "";
	
	string vertexInit[2];
	
	vector <int> vertex;

	if (arq.good()) {

		//~ arq >> cases;
		getline(arq, cases);
		
		//~ arq >> vertexInit[0];
		getline(arq, vertexInit[0]);
		getline(arq, vertexInit[1]);
		//~ arq >> vertexInit[1];
		
		
		while (arq.good())
		{
			//~ arq >> texto;
			getline(arq, texto);
			
			if (texto != " ")
			{
				cout << texto << endl;
			}
			
			//~ texto += ele;
			//~ if (true)
			//~ {
				//~ cout << ele << ' ';
				//~ //vertex.push_back(ele);
			//~ }
			
		}

	} else {
		cout << "Arquivo corrompido" << endl;
	}
	
	cout << cases << endl;
	cout << vertexInit[0] << " === " << vertexInit[1] << endl;
	
	//~ for (int i = 0; i < (int)vertex.size(); i++)
	//~ {
		//~ cout << vertex[i] << ' ';	
	//~ }	
	//~ for (int i = 0; i < (int) texto.size(); i++)
	//~ {
		//~ cout << texto[i] << ' ';	
	//~ }	

  return 0;
}

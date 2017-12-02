#include <iostream>
#include <fstream>

using namespace std;
//////////////////// FUNCOeS AUXILIAReS ////////////////////
struct graph{
  int peso;
  int vertix;
  int ancestral;
};
//procurar todas as possibilidades de caminhos
// funcao paths(matriz, vetices)


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "Uso: " << endl;
		cerr << argv[0] << " arquivoEntrada" << endl;
		exit(EXIT_FAILURE);
	}

  ifstream arq(argv[1]);

  if (arq.good()) {

    int v, e;
    arq >> v >> e;
    int matAdj[v][v];

    for (int i = 1; i <= v; i++){
      for (int j = 1; j <= v; j++) {
          matAdj[i][j] = -1;
      }
    }

    int peso, i, j;

    for (int k = 1; k <= e; k++) {
      arq >> i >> j >> peso;
      matAdj[i][j] = peso;
      matAdj[i][j] = peso;
    }

    for (int i = 1; i <= v; i++){
      for (int j = 1; j <= v; j++) {
          cout << matAdj[i][j] << ' ';
      }
      cout << endl;
    }

  } else {
    cout << "Arquivo corrompido" << endl;
  }

  return 0;
}

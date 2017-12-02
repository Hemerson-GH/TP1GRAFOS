// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <iostream>
#include <limits.h>

using namespace std;

#define V 7

int minDistance(int dist[], bool sptSet[])
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++) {
    if (sptSet[v] == false && dist[v] <= min) {
      // cout << "vertice: " << v+1 << endl;
      min = dist[v], min_index = v;
      //cout << "dist[v]: " << dist[v] << endl << endl;

    }
  }

  return min_index;
}

void printSolution(int dist[], int n)
{
   cout << "Vertex" << "\t" << "Distance from Source\n";
   for (int i = 0; i < V; i++)
      cout << i+1 << "\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
     int dist[V];   

     bool sptSet[V];
     for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
        // dist[i] = INT_MAX, sptSet[i] = false;
      }
     dist[src] = 0;
     for (int i = 0; i < V; i++)
     {
       int u = minDistance(dist, sptSet);
      //  cout << "u:" << u+1 << "////" << endl;
       sptSet[u] = true;
       for (int v = 0; v < V; v++)

         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
            cout << graph[u][v] << "<-" << dist[v] << endl;
            cout << "dist[u]--> " << dist[u] << " u->" << u << "\t" << "dist[v]--> " << dist[v] << " v-> " << v << endl;
          }
     }
     printSolution(dist, V);
}

int main()
{
   int graph[V][V] = {{0 , 30, 15, 10, 0,  0,  0},
                      {30, 0,  0,  25, 60, 0,  0},
                      {15, 0,  0,  40, 0, 20,  0},
                      {10, 25, 40,  0, 0,  0,  35},
                      {0 , 60, 0,   0, 0,  0,  20},
                      {0, 0,   20,  0, 0,  0,  20},
                      {0, 0,   0,  35, 20, 20, 0},
                     };

    dijkstra(graph, 0);

    return 0;
}

/*program on all pair shortest path or Floyd Warshall algorithm in c
problem on Finding Minimum Distance of Vertices from a Given Source in a Graph using Floyd Warshall algorithm.*/

#include <stdio.h>
#include<stdlib.h>

#define vertices 4
#define infinity 9999

void printMatrix(int A[][vertices]);

void floydWarshall(int graph[][vertices])
{
  int A[vertices][vertices], i, j, k;

  for (i = 0; i < vertices; i++)
    for (j = 0; j < vertices; j++)
      A[i][j] = graph[i][j];

  for (k = 0; k < vertices; k++)
  {
    for (i = 0; i < vertices; i++)
    {
      for (j = 0; j < vertices; j++)
      {
        if (A[i][k] + A[k][j] < A[i][j])
          A[i][j] = A[i][k] + A[k][j];
      }
    }
  }
  printMatrix(A);
}

void printMatrix(int A[][vertices])
{
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      if (A[i][j] == infinity)
        printf("%4s", "infinity");
      else
        printf("%4d", A[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int graph[vertices][vertices] = {{0, 3, infinity, 5},
             {2, 0, infinity, 4},
             {infinity, 1, 0, infinity},
             {infinity, infinity, 2, 0}};
  floydWarshall(graph);
  return 0;
}

#include<stdio.h>
#include<string.h>
#define INF 999
int D[10][10];
int P[10][10];
int V,E;
int G[10][10];
//Reading Graph
void readGraph()
{
  int i=0,j=0;
  printf("\nEnter graph in matrix form\n");
  for(i=0;i<V;i++)
  {
    for(j=0;j<V;j++)
    {
      scanf("%d",&G[i][j]);
    }
  }
}
//Displaying graph
void displayGraph(int G[][10])
{
  for(int i = 0;i<V;i++)
  {
    for (int j=0;j<V;j++)
      printf("%d\t",G[i][j]);
    printf("\n");
  }
 printf("\n");
}

//Initializing
void initialize()
{
  for (int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++)
    {
      if (i==j)
      {
        D[i][j] = 0;
        P[i][j] = -1;
      }
      else if(G[i][j] == 0)
      {
        D[i][j] = INF;
        P[i][j] = -1;
      }
      else
      {
        D[i][j] = G[i][j];
        P[i][j] = i;
      }
    }
  }
}


//floyd warshall
void floydwarshall()
{
  int i,j,k;
  for(k = 0; k < V; k++)
  {
    for(i = 0; i < V; i++)
    {
      for(j = 0; j < V; j++ )
      {
        if (D[i][j]<=D[i][k]+D[k][j])
          continue;
        else
        {
          D[i][j] = D[i][k]+D[k][j];
          P[i][j] = P[k][j];
        }
      }
    }
  }
}

//Printing Path
void printpath(int s,int v)
{
  if (v==s)
    printf(" %d  ",s);
  else if(P[s][v] == -1)
    printf("No path exist");
  else
  {
    printpath(s,P[s][v]);
    printf("-->");
    printf(" %d ",v);
  }
}


int main()
{
  printf("\n Enter number of vertices : ");
  scanf("%d",&V);

  readGraph();
  displayGraph(G);
  initialize();
  printf("\nAfter initialization...D and P matrix\n");
  printf("\n D Matrix...\n");
  displayGraph(D);
  printf("\n P Matrix...\n");
  displayGraph(P);
  floydwarshall();
  printf("\nAfter Floyd Warshall...D and P matrix\n");
  printf("\n D Matrix...\n");
  displayGraph(D);
  printf("\n P Matrix...\n");
  displayGraph(P);

  printf("\nPrinting Path\n");
  for (int i = 0; i<V ; i++)
  {
    for(int j =0; j<V ; j++)
    {
      if (i == j)
        continue;
      printf("path from %d to %d is ",i,j);
      printpath(i,j);
      printf("\n");
    }
  }

  return 0;
}


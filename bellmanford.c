#include "stdio.h"
#define INF 999
int G[10][10];
int d[10],p[10];
int edge[10][3];
void readgraph(int V)
{
  int i=0,j=0;
  printf("Enter graph in matrix form");
  for(i=0;i<V;i++)
  {
    for(j=0;j<V;j++)
    {
      scanf("%d",&G[i][j]);
    }
  }

}

void displayGraph(int  V)
{
  for(int i = 0;i<V;i++)
  {
    for (int j=0;j<V;j++)
      printf("%d\t",G[i][j]);
    printf("\n");
  }

}
void createtable(int V, int E)
{int k = 0;
  for(int i = 0;i<V;i++)
  {
    for(int j = 0;j < V; j++)
    {
      if(G[i][j]!=0)
      {
        edge[k][0] = i;
        edge[k][1] = j;
        edge[k][2] = G[i][j];
        k++;
      }
    }
  }
  printf("\nEdge table \n");
  for(int i = 0;i<E;i++)
      printf("%d --> %d : %d \n",edge[i][0],edge[i][1],edge[i][2]);
}
void initialize(int V,int s)
{
  for (int i = 0;i<V;i++)
  {

      d[i] = INF;
      p[i] = -1;

  }
  d[s] = 0;

}

void relax(int u,int v,int w)
{
  if(d[v]>d[u]+w)
  {
    d[v] = d[u] +w;
    p[v] = u;
  }

}

int negcycle(int E)
{
  for(int i = 0;i<E;i++)
  {
    if(d[edge[i][1]]>d[edge[i][0]]+edge[i][2])
      return 0;
  }
  return 1;
}

void printpath(int s,int v)
{
  if (v==s)
    printf(" %d   ",s);
  else if(p[v] == -1)
    printf("No path exist");
  else
  {
    printpath(s,p[v]);
    printf("-->");
    printf(" %d ",v);
  }

}

int main(void) {
 int V,E,s;  //V = no.of Vertices, E = no.of Edges, S is source vertex

    printf("Enter number of vertices in graph\n");
    scanf("%d",&V);

    printf("Enter number of edges in graph\n");
    scanf("%d",&E);

    readgraph(V);
    printf("\nGraph is \n");
    displayGraph(V);

    createtable(V,E);


    printf("Enter source vertex in graph\n");
    scanf("%d",&s);

    initialize(V,s);
    printf("\n shortest path estimate after initialization \n");
    for(int i =0;i<V;i++)
      printf("%d \t",d[i]);

    printf("\n");
    printf("\n predecessor after initialization\n");
    for(int i =0;i<V;i++)
      printf("%d \t",p[i]);


    for (int i = 0; i < V-1; i++)
    {
      for (int j = 0; j < E; j++)
      {
        relax(edge[j][0],edge[j][1],edge[j][2]);
      }
    }


  printf("\n shortest path estimate\n");
    for(int i =0;i<V;i++)
      printf("%d \t",d[i]);

    printf("\n");
    printf("\n predecessor\n");
    for(int i =0;i<V;i++)
      printf("%d \t",p[i]);

  int flag = negcycle(E);
  if (flag==1)
    printf("\nSSSP Exist");
  else
    printf("Negative weight Cycle");

  printf("\nPrinting Path\n");
  for (int i = 0;i<=V-1;i++)
  {

    if (i ==s)
      continue;
    printf("path from %d to %d is ",s,i);
    printpath(s,i);
    printf("\n");
  }

  return 0;
}

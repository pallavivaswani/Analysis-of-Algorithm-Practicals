#include <stdio.h>

int parent[10],rank[10];
int G[10][10],edge[10][3];
int V,E=0;
int totalcost=0;
void readGraph()
{
  printf("\nEnter adjacency matrix \n");
  for(int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++)
    {
      scanf("%d",&G[i][j]);
      if(G[i][j] !=0 && i<j)
        E++;
    }
  }
}

void displaygraph()
{
  printf("\nGraph is... \n");
  for(int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++)
    {
      printf("%d\t",G[i][j]);
    }
    printf("\n");
  }
}

void print1Darray(char *str,int a[])
{
  printf("\n%s [] : ",str);

  for(int i = 0;i < V; i++)
  {
    printf("\t%d",a[i]);
  }
}

void makeset(int x)
{
    parent[x] = x;
    rank[x] = 0;
}

void createtable()
{int k = 0;
  for(int i = 0;i<V;i++)
  {
    for(int j = 0;j < V; j++)
    {
      if(G[i][j]!=0 && i<j)
      {
        edge[k][0] = i;
        edge[k][1] = j;
        edge[k][2] = G[i][j];
        k++;
      }

    }
  }
}
void printEdgeTable()
{
  printf("\nEdge table \n");
  for(int i = 0;i<E;i++)
      printf("%d --> %d : %d \n",edge[i][0],edge[i][1],edge[i][2]);
}
void bubbleSort()
{
   int i, j;
   for (i = 0; i < E-1; i++)
       for (j = 0; j < E-i-1; j++)
           if (edge[j][2] > edge[j+1][2])
           {
               int temp = edge[j][0];
               edge[j][0] = edge[j+1][0];
               edge[j+1][0] =temp;
               temp = edge[j][1];
               edge[j][1] = edge[j+1][1];
               edge[j+1][1] =temp;
               temp = edge[j][2];
               edge[j][2] = edge[j+1][2];
               edge[j+1][2] =temp;
           }

}


int findset(int x)
{
    if (x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void link(int x,int y)
{
    if (rank[x] > rank[y])
        parent[y] = x;
    else
    {
        parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]+=1;

    }
}
void unionop(int x, int y)
{
    link(findset(x),findset(y));
}

void main()
{
  printf("\nEnter number of vertices\n");
  scanf("%d",&V);
  readGraph();
  displaygraph();
  printf("No.of vertex : %d\nNo.of Edges : %d\n",V,E);

  for(int i=0;i<V;i++)
  {
    makeset(i);
  }
  createtable();
  printf("\n\nEdge table before Sorting\n");
  printEdgeTable();
  bubbleSort();
  printf("\n\nEdge table after Sorting\n");
  printEdgeTable();

  for (int i=0;i<E;i++)
  {
      if(findset(edge[i][0])!=findset(edge[i][1]))
      {
         unionop(edge[i][0],edge[i][1]);
         totalcost+=edge[i][2];
         //print1Darray("parent array",parent);
         //print1Darray("rank array",rank);
         printf("\n\nEdges (%d,%d) : %d", edge[i][0],edge[i][1],edge[i][2]);
      }
  }
  //print1Darray("\nparent array",parent);
  //print1Darray("rank array",rank);
  printf("\n\nTotal Cost : %d", totalcost);
}

#include "stdio.h"

int G[10][10];
int n,m;
int x[10];
int soln = 1;
void readGraph()
{
   for(int i = 1; i <= n; i++)
    for(int j=1; j <= n; j++)
    {
      if(i==j)
        G[i][j] = 0;
      else if(i>j)
        G[i][j] = G[j][i];
      else
      {
        printf("\nG[%d][%d] : ",i,j);
        scanf("%d",&G[i][j]);
      }
    }
}

void printGraph()
{
  printf("\n Graph is ...\n");
   for(int i = 1; i <= n; i++)
    {
      for(int j=1; j <= n; j++)
        printf("\t%d",G[i][j]);
      printf("\n");
    }
}

void display()
{
  printf("\nSolution %d : ",soln++);
  for(int i=1; i<=n; i++)
    printf("\t%d",x[i]);
  printf("\n");
}

int getNodeColor(int k)
{
  int j;
  do
  {

    x[k] = (x[k]+1)%(m+1);

    if(x[k] == 0)
      return x[k];

    for( j= 1; j <= k-1; j++)
    {
      if(G[k][j] != 0 && (x[k] == x[j]))
        break;
    }

    if(j==k)
      return x[k];
  }while(1);
}

void mcoloring(int k)
{
  do
  {

    x[k] = getNodeColor(k);

    if (x[k] == 0) return;

    if(k == n)
      display();

    else  mcoloring(k+1);


  }while(1);

}

int main(void)
{
  printf("\n Enter No. of vertices in graph\n");
  scanf("%d",&n);
  readGraph();
  printGraph();
  printf("\n Enter No. of colors\n");
  scanf("%d",&m);
  mcoloring(1);

  return 0;
}

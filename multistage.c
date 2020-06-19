#include<stdio.h>

#include<string.h>
#define INF 999

int V,K;
int G[10][10];
int d[10]= {INF} ;
int cost[10] = {INF};
int p[10] = {0};
//Reading Graph
void readGraph()
{
  for (int i = 0; i <= V; i++)
    {
      G[i][i] = 0;
      for(int j = i+1; j < V; j++)
      {
        printf("\n Enter egde cost %d --> %d ",i,j);
        scanf("%d",&G[i][j]);
        G[j][i]=0;
      }
    }
}
//Displaying graph
void displayGraph()
{
  for(int i = 0;i<V;i++)
  {
    for (int j=0;j<V;j++)
      if(G[i][j]!=0)
        printf("%d --> %d = %d\t",i,j,G[i][j]);
      //printf("%d\t",G[i][j]);
    printf("\n");
  }

}

//forwardapproach
void forwardmultistage()
{
  cost[V-1] = 0;
  for (int j = V-2; j>=0; j--)
  {
    for  (int r = V-1; r > j; r--)
    {
      if(G[j][r]!=0)
        if(cost[j]>cost[r]+G[j][r])
        {
          cost[j]=cost[r]+G[j][r];
          d[j] = r;
        }
    }

  }
}
//Printing forward min cost path
void forwardcostpath()
{
  p[0] = 0;
  p[K-1] = V-1;

  for (int j=1; j<=K-2; j++)
    p[j] = d[p[j-1]];

  for(int j=0; j < K; j++)
    if(j == K-1)
      printf(" %d\n",p[j]);
    else
       printf("%d--> ",p[j]);
}

//backwardapproach
void backwardmultistage()
{
  cost[0] = 0;
  for (int j = 1; j<=V-1; j++)
  {
    for  (int r = j-1; r >=0; r--)
    {
      if(G[r][j]!=0)
        if(cost[j]>cost[r]+G[r][j])
        {
          cost[j]=cost[r]+G[r][j];
          d[j] = r;
        }
    }

  }
}

void backwardcostpath()
{
  p[0] = 0;
  p[K-1] = V-1;

  for (int j=K-2; j>0; j--)
    p[j] = d[p[j+1]];

  for(int j=0; j < K; j++)
    if(j == K-1)
      printf(" %d\n",p[j]);
    else
       printf("%d--> ",p[j]);
}

void printarray(int c[10])
{
  for(int i=0;i<V;i++)
    printf(" %d ",c[i]);
  printf("\n");
}

void initialize()
{
  for(int i=0;i<V;i++)
  {
    cost[i]=INF;
    d[i]  = -1;
  }
}


int main()
{
  int choice;
  printf("\n Enter number of vertices : ");
  scanf("%d",&V);
  printf("\n Enter number of stages : ");
  scanf("%d",&K);
  initialize();
  readGraph();
  printf("\n Egdes in graph are : \n");
  displayGraph();


  forwardmultistage();
  printf("\n Using Forward approach\n");
  printf("\n Cost array is : ");
  printarray(cost);
  printf(" d array is : ");
  printarray(d);
  printf("\n Minimum Cost from %d to %d is %d",0,V-1,cost[0]);
  printf("\n Minimum Cost Path is : ");
  forwardcostpath();

  initialize();
  backwardmultistage();
  printf("\n\n Using Backward approach");
  printf("\n Cost array is : ");
  printarray(cost);
  printf(" d array is : ");
  printarray(d);
  printf("\n Minimum Cost from %d to %d is %d",0,V-1,cost[V-1]);
  printf("\n Minimum Cost Path is  ");
  backwardcostpath();

}


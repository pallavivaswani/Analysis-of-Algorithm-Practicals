#include<stdio.h>
#include<string.h>
int V[20][20];
int keep[20][20];
int v[20],w[20],n,W;

void readWeight()
{
  for(int i =1; i <= n; i++ )
  {
    printf("\nEnter Weight of obj %d",(i));
    scanf("%d",&w[i]);
  }
}

void readValue()
{
  for(int i =1; i <= n; i++ )
  {
    printf("\nEnter Value of obj %d",(i));
    scanf("%d",&v[i]);
  }
}

void print1Darray(int arr[10])
{
  for(int i =1; i <= n; i++ )
    printf("%d  ",arr[i]);
  printf("\n");
}

void calculate()
{
  for(int i = 0; i <= n; i++) //first column
    V[i][0] = 0;
  for(int i = 0; i <= W; i++) //first row
    V[0][i] = 0;

  for(int i = 1; i<=n; i++)
  {
    for(int j = 1; j <= W; j++)
    {
      if(w[i]<=j)
      {
        if(V[i-1][j]<(V[i-1][j-w[i]]+v[i]))
        {
          V[i][j] = V[i-1][j-w[i]]+v[i];
          keep[i][j] = 1;
        }
        else
        {
          V[i][j] = V[i-1][j];
          keep[i][j] = 2;
        }
      }
      else
      {
        V[i][j] = V[i-1][j];
        keep[i][j] = 2;
      }
    }
  }
}

void printknapsack()
{
  for (int i = n; i > 0; i--)
  {
    if(W>0 && keep[i][W] == 1)
    {
      printf("%d ",i);
      W = W - w[i];
    }

  }
}

int main()
{
  printf("\n Enter knapsack capacity \n");
  scanf("%d",&W);
  printf("\n Enter Number of Objects ... \n");
  scanf("%d",&n);
  readWeight();

  readValue();
  printf("\n Weight is : ");
  print1Darray(w);
  printf("\n Profit is : ");
  print1Darray(v);
  calculate();
  printf("\nMaximum Profit is %d\n",V[n][W]);
  printf("\nElements in knapsack  are :  ");
  printknapsack();
  return 0;
}

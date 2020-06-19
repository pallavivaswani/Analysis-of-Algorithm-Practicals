#include "stdio.h"
#include "stdlib.h"
int cnt = 0;
int x[10];
int totalcalls = 0;
int place(int k,int i)
{
  for(int j = 1 ;j<=k-1; j++)
  {
    if((x[j] == i)||(abs(x[j]-i) == abs(j-k)))
      return 0;
  }
  return 1;
}
void display2d(int n)
{int k;
  cnt+=1;
  printf("\n\nSolution %d : \n",cnt);
  for (int i=1;i<=n;i++)
  {
    k = x[i];
    for(int j=1;j<=n;j++)
    {
      if(j==k)
        printf("\tQ");
      else
        printf("\t--");
    }
    printf("\n");
  }
}
void display(int n)
{
  //cnt+=1;
  printf("\nx[] = \t");
  for (int i = 1; i<=n; i++)
    printf("%d\t",x[i]);
  printf("\n-------------------------------------------------------------------");
}
void NQueens(int k, int n)
{
  totalcalls+=1;
  for (int i=1;i <=n; i++)
  {
    if(place(k,i)==1)
    {
      x[k] = i;
      if(k==n)
        {display2d(n);//2dprinting
        display(n);}//for printing solution vector
      else
        NQueens(k+1,n);
    }
  }

}

int main(void) {
  int n;
  printf("\n Enter number of queens: ");
  scanf("%d",&n);
  NQueens(1,n);
  printf("\nTotal No.of nodes in the tree = %d", totalcalls);
  return 0;
}

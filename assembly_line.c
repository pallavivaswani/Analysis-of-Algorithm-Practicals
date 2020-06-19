#include "stdio.h"

void readProcessingTime(int a[][10],int n)
{
  int i = 0, j = 0;
  for (i = 0; i <= 1; i++)
  {
    for ( j = 0; j <n ; j++)
    {
      printf("\n Enter processing time of station S[%d][%d]  : ",(i+1),(j+1));
      scanf("%d",&a[i][j]);
    }
  }
}

void readTransferTime(int t[][10],int n)
{
  int i = 0, j = 0;
  for (i = 0; i <= 1; i++)
  {
    for ( j = 1; j <n ; j++)
    {
      printf("\n Enter transfer time from station S[%d][%d] : ",(i+1),(j));
      scanf("%d",&t[i][j]);
    }
  }
}

void print2dArray(int a[][10], int n, char *str)
{
  int i=0,j;

  for (; i <= 1; i++)
  {
    //printf("Assembly line %d:\t",(i+1));
    printf("%s %d:\t",str,(i+1));
    if (str == "Assembly line")
      j=0;
    else
      j=1;
    for ( ; j <n ; j++)
    {
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
   printf("\n");
}

void read1darray(int e[], char *str,int n)
{
  for(int i =0 ; i<2; i++)
  {
    printf("Enter %s %d",str,(i+1));
    scanf("%d",&e[i]);
  }

}

void display1darray(int e[], char *str,int n)
{
  printf("%s :\t",str);
  for(int i =0 ; i<n; i++)
  {
    printf("%d\t",e[i]);
  }
   printf("\n\n");
}

void printschedule(int L,int l[][10],int n)
{
  int i = L;
  printf("\nS%d%d",i,n);

  for(int j = n-1; j >= 1; j--)
  {
    if(i==1)
      i = l[0][j];
    else
      i = l[1][j];
    printf(" <--- S%d%d",i,j);
  }

}

void calculate(int e[], int x[],int a[][10], int t[][10], int n)
{
  int l[2][10],F=0,L=0;
  int f[2][10];
  //total processing time till station 1 on both assembly line
  for(int i = 0; i < 2; i++)
    f[i][0]  = e[i] + a[i][0];

  // going from station 2 till last station n

    int i =0;
    for(int j = 1; j < n; j++)
    {
      if((f[i][j-1] + a[i][j]) <= (f[i+1][j-1] + a[i][j] + t[i+1][j]))
      {
        f[i][j] = f[i][j-1] + a[i][j];
        l[i][j] = 1;
      }

      else
      {
        f[i][j] = f[i+1][j-1] + a[i][j] + t[i+1][j];
        l[i][j] = 2;
      }

      if((f[i+1][j-1] + a[i+1][j]) <= (f[i][j-1] + a[i+1][j] + t[i][j]))
      {
        f[i+1][j] = f[i+1][j-1] + a[i+1][j];
        l[i+1][j] = 2;
      }

      else
      {
        f[i+1][j] = f[i][j-1] + a[i+1][j] + t[i][j];
        l[i+1][j] = 1;
      }
    }
  i=0;
  if(f[i][n-1]+x[i] <= f[i+1][n-1]+x[i+1])
  {
    F = f[i][n-1]+x[i];
    L = 1;
  }
  else
  {
    F = f[i+1][n-1]+x[i+1];
    L = 2;
  }

 /* for(int i=0;i<2;++i)
  {
    for (int j = 0;j < n; j++)
      printf("%d",f[i][j]);
      printf("\n");
  }*/
  printf("Optimal Value(Fastest Time) is %d",F);
  printschedule(L,l,n);

}


int main(void) {
  int a[2][10],t[2][10],e[2],x[2],f[2][10];
  int n;

  printf("\nEnter number of station on each assembly line : ");
  scanf("%d",&n);

  readProcessingTime(a,n);
  printf("\n\nProcessing Times are : \n");
  print2dArray(a,n,"Assembly line");

  readTransferTime(t,n);
  printf("\n\nTransfer Times are : \n");
  print2dArray(t,n,"transfer time");

  read1darray(e,"Entry time",2);
  display1darray(e,"Entry Time",2);

  read1darray(x,"Exit time",2);
  display1darray(x,"Exit Time",2);

  calculate(e,x,a,t,n);

}

#include "stdio.h"
int x[10] = {0};
int m;
int w[10];
int n,cnt=0,noofsoln=0;


void displaysubset(int x[],int  k,int num)
{
  printf("Subset %d : {",num);
  for(int i=0;i<=k;i++)
  {
    if(x[i] == 1)
      printf(" %d ",w[i]);
  }
  printf("}\n------------------------------------------");
}

void display(int x[],int k)
{
  noofsoln+=1;
  printf("\n\nSolution %d : {",noofsoln);
  for (int i=0;i<=k;i++)
    printf(" %d  ", x[i]);
  if(k<n)
  {
    for(int i=k+1;i<n;i++)
      printf(" 0  ");
  }
  printf("}\n");
  displaysubset(x,k,noofsoln);
}
void sumofsubset(int s, int r, int k)
{
  cnt+=1;
  x[k] = 1;
  if(s+w[k] == m)
    display(x,k);
  else if (s + w[k] + w[k+1] <= m)
    sumofsubset(s + w[k],r-w[k],k+1);

  if((s+r-w[k]>=m) && (s+w[k+1]<=m))
  {
    x[k] = 0;
    sumofsubset(s ,r-w[k],k+1);
  }

}

int main(void) {

  printf("Enter total sum required : ");
  scanf("%d",&m);
  printf("Enter no of elements in subset : ");
  scanf("%d",&n);
  int r=0;
  for(int i=0;i<n;i++)
  {
    printf("Enter element %d : ",(i+1));
    scanf("%d",&w[i]);
    r+=w[i];
  }
  sumofsubset(0, r ,0);

  printf("\n No of Nodes (call to sumofsubset procedure)  : %d\n",cnt);


}

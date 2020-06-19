#include "stdio.h"

void read1Darray(int arr[],int n,char *str)
{
  for (int i = 0; i < n; i++)
  {
    printf ("\nEnter %s of object %d : ",str,(i+1));
    scanf("%d",&arr[i]);
  }
}

void dis_wt_val(int w[],int v[],int n)
{
  printf("\nObject  Weight  Profit\n");
  for (int i = 0;  i < n; i++)
  {
    printf("  %d\t  %d\t  %d\n",(i+1),w[i],v[i]);
  }
}

void dis_wt_val_ratio(int p[],int w[],int v[],int n,float ratio[])
{
  printf("\nObject  Weight  Profit  Ratio\n");
  for (int i = 0;  i < n; i++)
  {
    printf("  %d\t  %d\t  %d  \t%f\n",p[i],w[i],v[i],ratio[i]);
  }
}

void calculate_ratio(float ratio[],int w[],int v[],int n)
{
  printf("\n calculating ratio \n");
  for(int i=0;i<n;i++)
    ratio[i] = (float)v[i]/w[i];

}

void sort(float ratio[],int w[],int v[], int p[],int n)
{
  printf("\n Sorting \n");
  for(int i = 0; i< n-1;i++)
  {
    for(int  j = 0; j< n-i-1; j++)
    {
      if(ratio[j] < ratio[j+1])
      {
        float t1 = ratio[j+1];
        ratio[j+1] = ratio[j];
        ratio[j] = t1;

        int t2 = w[j+1];
        w[j+1] = w[j];
        w[j] = t2;

        t2 = v[j+1];
        v[j+1] = v[j];
        v[j] = t2;

        t2 = p[j+1];
        p[j+1] = p[j];
        p[j] = t2;
      }
    }
  }
}

void fractionalKP(int p[],int w[],int v[],int n,int W)
{
  float finalvalue = 0;
  int currwt = 0;
  printf("Items in knapsack are : \n");
  for(int i = 0; i < n; ++i)
  {
    if(currwt + w[i] <= W)
    {
      currwt+=w[i];
      finalvalue += v[i];
      printf(" Item %d is added completely \n",p[i]);
    }
    else
    {
      int remain = W - currwt;
      if(remain>0)
      {
      finalvalue += v[i] * ((double) remain / w[i]);
      printf("Item %d is added partly by fraction (%d/%d)",p[i],remain,w[i]);
      }
      break;
    }
  }
  printf("\nTotal Profit: %2.3f",finalvalue);
}

int main(void) {
  int W,n;
  printf("Enter knapsack capacity : ");
  scanf("%d",&W);
  printf("\nEnter number of objects : ");
  scanf("%d",&n);

  int v[n],w[n];

  printf("\nEnter Weights \n");
  read1Darray(w,n,"weight");

  printf("\nEnter Profit \n");
  read1Darray(v,n,"profit");

  dis_wt_val(w,v,n);

  float ratio[n];
  calculate_ratio(ratio,w,v,n);
  int p[n];
  for (int i = 0; i < n; i++)
    p[i] = i+1;

  dis_wt_val_ratio(p,w,v,n,ratio);
  //to store indices


  sort(ratio,w,v,p,n);

  dis_wt_val_ratio(p,w,v,n,ratio);
  fractionalKP(p,w,v,n,W);
  return 0;
}

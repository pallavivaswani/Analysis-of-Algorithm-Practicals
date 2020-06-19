#include <stdio.h>
int arr[10];
int n=0;
int min=0,max=0;
void read_array()
{
    for(int i=0;i<n;i++)
    {
        printf("\n Enter element %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
}
void print1Darray(char *str,int a[])
{
  printf("\n%s [] : ",str);

  for(int i = 0;i < n; i++)
  {
    printf("\t%d",a[i]);
  }
}

void  minmax(int i,int j)
{   int min1=0,max1=0,mid=0;
    if (i==j)
    {
        min = max = arr[i];
    }
    else if(i==j-1)
    {
        if(arr[i]<arr[j])
        {
            min = arr[i];
            max = arr[j];
        }
        else
        {
            min = arr[j];
            max = arr[i];
        }
    }
    else
    {
        mid = (int)(i+j)/2;
        minmax(i,mid);
        max1 = max;min1=min;
        minmax(mid+1,j);
        if (max<max1)
            max = max1;
        if (min>min1)
            min = min1;
    }
}

void main()
{
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    read_array();
    print1Darray("Array",arr);
    minmax(0,n-1);
    printf("\nMinimum is %d \n",min);
    printf("\nMaximum is %d \n",max);
}

#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
	int i,j,k,index,temp[10];
	i=low;j=mid+1;index=low;
	while((i<=mid) && (j<=high))
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
		}
		else
		{
			temp[index]=a[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=high)
		{
		temp[index++]=a[j++];
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index++]=a[i++];
		}
	}
		for(k=low;k<index;k++)
		{
			a[k]=temp[k];
		}
}
void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	int a[100],n,i;
      printf("Enter number of elements\n");
      scanf("%d", &n);
     
      printf("Enter the elements\n");
      for (i= 0; i< n; i++)
        scanf("%d", &a[i]);
     
           printf("Before sorting\n");
      for (i=0; i<n; i++)
        printf("%d\n", a[i]);
	merge_sort(a,0,n-1);
         printf("After sorting\n");
      for (i=0; i<n; i++)
        printf("%d\n", a[i]);
	return 0;
}

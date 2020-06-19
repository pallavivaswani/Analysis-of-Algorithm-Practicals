#include <stdio.h>
int n = 0;//no of programs


void readarray(int a[10])
{
    for(int i=0; i<n ;i++)
    {
       printf("\n Enter length of tape %d ",(i+1));
       scanf("%d",&a[i]);
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

void bubbleSort(int a[])
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>  a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void calculate1(int a[])
{
    float MRT = 0;
    for (int j  = 0; j<n; j++)
    {
        int sum = 0;
        for (int k=0;k<=j;k++)
            sum+=a[k];
        MRT+=sum;
    }

    printf("\n\nMean Retrieval Time with one tape is : %f\n",(float)MRT/n);
}
void calculate2(int a[],int num)
{

    int tapes[num][10];
    float MRT[num][1];
    float Final_MRT = 0;
    int j=0;
    for(int i = 0,k=0; i< n; i++)
    {
        tapes[j][k] = a[i];
        j = (j+1)%(num);
        if(i%num == num-1)
            k++;
    }

    for(int i = 0; i<num;i++)
    {
        int end ;
        if(n%num>=(i+1))
            end = ((int)n/num) + 1;
        else
            end = (int)n/num;
        printf("\n\n Tape %d has programs of length : ",(i));
         int sum = 0;
        for(int j = 0; j<end;j++)
        {
            printf("%d\t",tapes[i][j]);
            for (int k=0;k<=j;k++)
                sum+=tapes[i][k];

        }
        MRT[i][0] = (float)sum/end;
        Final_MRT+=MRT[i][0];
        printf("\nMRT of tape %d is %f\n",i,MRT[i][0]);
        printf("\n");
    }
    printf("\n\nOverall Mean Retrieval Time for %d tapes is %f \n",num,(Final_MRT/n));

}
void main()
{
    int L[10];//length of each program
    printf("\nEnter number of programs : ");
    scanf("%d",&n);
    readarray(L);
    printf("\n\nBefore Sorting: \n");
    print1Darray("Length",L);
    printf("\n\nAfter Sorting: \n");
    bubbleSort(L);
    print1Darray("Length",L);
    int ch;

    printf("\n\nEnter Choice  1. Single Tape 2. Multiple Tape ");
    scanf("%d",&ch);

    if (ch==1)
    {
        calculate1(L);
    }
    else if(ch == 2)
    {
        printf("\n\n Enter number of tapes");
        int num;
        scanf("%d",&num);
        calculate2(L,num);
    }

}


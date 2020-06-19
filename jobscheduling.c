#include<stdio.h>
#include<conio.h>
int n,i,j,k,t;
int check(int slot[],int p)
{
    int ptr=0;
    for(i=0;i,n;i++)
        if(slot[i]==p)
            ptr++;
        if(ptr==0)
            return 1;
        else
            return 0;
}
int main()
{
    printf("Enter number of jobs: ");
    scanf("%d",&n);
    int slot[n],deadline[n],profit[n];
    for(i=0;i<n;i++)
    {
        printf("Enter profit of job %d :",i+1);
        scanf("%d",&profit[i]);
        printf("Enter deadline of job %d :",i+1);
        scanf("%d",&deadline[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(profit[i]<profit[j])
            {
                t=profit[i];
                profit[i]=profit[j];
                profit[j]=t;
                t=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=t;
            }
        }
    }
    printf("After sorting profit values in increasing order: \nPROFIT\tDEADLINES\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\n",profit[i],deadline[i]);
    }
     for(i=0;i<n;i++)
    {
        slot[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=deadline[i];j>0;j--)
        {
            if(check(slot,j)==1)
            slot[i]=j;
            break;
        }
    }
    printf("PROFIT\tDEADLINE\tSLOT\tALLOCATED\n");
    for(i=0;i<n;i++)
    {
        if(slot[i]>0)
        {
            printf("%d\t%d\t%d\t[%d-%d]",profit[i],deadline[i],slot[i]-1,slot[i]);
        }
        else
        {
            printf("%d\t%d\t%d REJECTED",profit[i],deadline[i]);
        }
    }
}

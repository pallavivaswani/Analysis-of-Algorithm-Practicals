#include<stdio.h>
int main()
{
    int i,m,n;
    float v[n],w[n],x[n],set[n];
    float sw=0.0,sp=0.0,frac=0.0;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter capacity of knapsack: ");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        printf("Enter item %d: ",(i+1));
        scanf("%f",&x[i]);
        printf("Enter value corresponding to item %d: ",(i+1));
        scanf("%f",&v[i]);
        printf("Enter weight corresponding to item %d: ",(i+1));
        scanf("%f",&w[i]);
        printf("\n");
    }
    printf("ITEMS\tVALUE\tWEIGHT\n");
     for(i=0;i<n;i++)
    {
        printf("  %f\t  %f\t  %f\n",x[i],v[i],w[i]);
    }
     /*for(i=0;i<n;i++)
    {
    if(sw+w[i]<=m)
    {
        set[i]=set[i]+x[i];
        sw=sw+w[i];
        sp=sp+v[i];
    }
    else
    {
        frac=(m-sw)/w[i];
        set[i]=set[i]+x[i]*frac;
        sw=sw+w[i]*frac;
        sp=sp+v[i]*frac;
    }
    }
    printf("ITEMS\tVALUE\tWEIGHT\tSET\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t%f\t%f\t%f\n",x[i],v[i],w[i],set[i]);
    }
    printf("Total Knapsack weight: %f",sw);
    printf("Total knapsack profit value: %f",sp);*/
return 0;
}

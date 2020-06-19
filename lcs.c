#include<stdio.h>
#include<string.h>
int b[100][100];

void print_lcs(int b[100][100],char x[],int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==3)
	{
		print_lcs(b,x,i-1,j-1);
		printf("%c ",x[i-1]);
	}
	else if(b[i][j]==1)
	{
		print_lcs(b,x,i-1,j);
	}
	else
	{
		print_lcs(b,x,i,j-1);
	}
}

void lcs(char x[],char y[])
{
	int m,n,i,j;
	m=strlen(x);
	n=strlen(y);
	//int b[m+1][n+1],
	int c[m+1][n+1];
	for(i=0;i<m+1;i++)
		c[i][0]=0;
	for(i=1;i<n+1;i++)
		c[0][i]=0;
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=3;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=2;
			}
		}
	}
	printf("\nTotal length of characters: %d\n",c[m][n]);
	printf("%s\n",x);
	print_lcs(b,x,m,n);
	printf("\n");
}

void main()
{
	char x[100],y[100];
	printf("Enter first string: ");
	gets(x);
	printf("Enter second string: ");
	gets(y);
	lcs(x,y);
}

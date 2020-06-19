#include "stdio.h"
int start[4][4],inter[4][4];
int goal[4][4];
int n=4;
int m = 16;
int x,y;//to keep track of empty space
int cx=0,gx=0;
int mincost ;

void readState(int a[][4])
{
  for(int i = 0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
     }
  }
}

void display1D(int a[])
{
  for(int i=0;i<m;i++)
    printf("\t%d ",a[i]);
  printf("\n");
}
void display(int a[][4])
{
  for(int i = 0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
}

int test(int temp[][4])
{
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      if(temp[i][j]!=goal[i][j])
        return 0;
    }

  return 1;
}


void calposition(int a[])
{
  int j,k,i=0;

  for(k=0;k<m;k++)
  {
    int c =0;
    if(k!=m-1)//for all tiles except empty tile
    {
      for(int i = 0; i < n; i++)
      {
        for(j = 0; j < n; j++)
        {
          if(start[i][j] != k+1)
            c++;
          else
            break;
        }
        if(j!=n)
          break;
      }
    }
    else //for last empty tile
    {

      for(int i = 0; i < n; i++)
      {
        for(j = 0; j < n; j++)
        {
          if(start[i][j] != 0)
            c++;
          else
            break;
        }
        if(j!=n)
          break;
      }
    }

    a[k] = c;
  }


}
int less(int a[],int i)
{
  int c=0;
  int temp = a[i];
  for(int j=i-1; j>=0; j--)
      {
        if(a[j]>temp)
          c++;
      }

  return c;
}

int checkfeasible()
{
  int pos[m];
  calposition(pos);
  int l [m];

  printf("\nPosition : ");
  display1D(pos);

  for(int i =0 ; i< m; i++)
    l[i]  = less(pos,i);

  printf("\n Less [] : ");
  display1D(l);
  int suml=0,x;
  for(int i=0;i<m;i++)
    suml+=l[i];

  //check pos of empty tile in Initial State
  if(pos[m-1] == 1|| pos[m-1] == 3 ||pos[m-1] == 4||pos[m-1] == 6||pos[m-1] == 9||pos[m-1] == 11||pos[m-1] == 12||pos[m-1] == 14)
      x=1;
  else
      x=0;
  //printf("%d ...\n",(suml+x));
  if((suml+x)%2==0)
    return 1;
  else
    return 0;

}

void findSpace(int temp[][n])
{int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
        if(temp[i][j]==0)
        {
          x=i;y=j;
          break;
        }
      }
    if(j<n)
      break;
  }
}

int cost(int temp[][n])
{
	int c=0;
	for(int i=0;i < n;i++)
		for(int j=0;j < n;j++)
		{
			if(temp[i][j]!=goal[i][j])
			  c++;
		}
	return c;
}

int move(char c)
{
  int temp1[n][n];
  int p,hx=0;
  for(int i=0;i<n;i++)
    for(int j=0;j < n; j++)
        temp1[i][j] = start[i][j];

  if(c=='U'&& x!=0)
  {
    p=temp1[x][y];
		temp1[x][y]=temp1[x-1][y];
		temp1[x-1][y]=p;
  }

  else if(c=='D'&& x!=n-1)
  {
    p=temp1[x][y];
		temp1[x][y]=temp1[x+1][y];
		temp1[x+1][y]=p;
  }

  else if(c=='R'&& y!=n-1)
  {
    p=temp1[x][y];
		temp1[x][y]=temp1[x][y+1];
		temp1[x][y+1]=p;
  }

  else if(c=='L'&& y!=0)
  {
    p=temp1[x][y];
		temp1[x][y]=temp1[x][y-1];
		temp1[x][y-1]=p;
  }

  hx=cost(temp1);
	cx = gx + hx;
	if(cx < mincost)
	{
		mincost=cx;
		for(int i=0;i < n;i++)
			for(int j=0;j < n;j++)
				inter[i][j]=temp1[i][j];
	}
}



void main()
{

  int temp2[n][n];
   //Reading initial state
  printf("\n Enter initial state of 15 puzzle : \n");
  readState(start);
  //Reading Goal state
  printf("\n Enter Goal state of 15 puzzle : \n");
  readState(goal);
  printf("\n Start state of 15 puzzle : \n\n");
  display(start);
  printf("\nGoal state of 15 puzzle : \n\n");
  display(goal);
  if(test(start))
  {
    printf("Initial State is same as goal state.....No move required\n");
  }
  else if(checkfeasible())
  {
    printf("Solution is possible ");

    while(test(start)==0)
    {

      gx++;
      mincost = 999;
      findSpace(start);

      move('U');
      move('R');
      move('D');
      move('L');

      printf("\nIntemediate state %d\n",gx);
      display(inter);

      printf("min distance from goal state is %d\n",mincost-gx);

      for(int i=0;i < n;i++)
			  for(int j=0;j < n;j++)
			  {
			    start[i][j]=inter[i][j];

			  }

    }
    printf("\nGoal State  reached \nTotal no.of moves : %d\n",gx);
  }
  else
    printf("\n Solution not possible..\n");

}

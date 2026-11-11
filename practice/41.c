#include <stdio.h>
int main()
{
	const int size=3;
	int board[size][size];
	int numo;
	int numx;
	int result=-1;
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			scanf("%d",board[i][j]);
		}
	}
	for(i=0;i<size&&result==-1;i++)
	{
		numo=0;
		numx=0;
		for(j=0;j<size;j++)
		{
			if(board[i][j]==1)
			{
				numx++;
			}
			else if(board[i][j]==0)
			{
				numo++;
			 } 
	    }
		    if(numx==size)
		    {
			    result=1;
		    }
			else if(numo==size)
			{
				result=0;
			}
	}
	for(j=0;j<size&&result==-1;j++)
	{
		numo=0;
		numx=0;
		for(i=0;i<size;i++)
		{
			if(board[i][j]==1)
			{
				numx++;
			}
			else if(board[i][j]==0)
			{
				numo++;
			}
	    }
			if(numx==size)
			{
				result=1;
			}
			else if(numo==size)
			{
				result=0;
			}
	}
	for(i=0;i<size&&result==-1;i++)
	{
		numx=0;
		numo=0;
		if(board[i][i]==1)
		{
			numx++;
		}
		else if(board[i][i]==0)
		{
			numo++;
		}
		if(numx==size)
		{
			result=1;
		}
		else if(numo==size)
		{
			result=0;
		}
	}
	for(i=0;i<size;i++)
	{
		if(board[i][size-i-1]==1)
		{
			numx++;
		}
		else if(board[i][size-i-1]==0)
		{
			numo++;
		}
		if(numx==size)
		{
			result=1;
		}
		else if(numo==size)
		{
			result=0;
		}
	}
	if(result==-1)
	{
		printf("Æ½¾Ö");
	}
	if(result==0)
	{
		printf("oÓ®"); 
	}
	if(result==1)
	{
		printf("xÓ®");
	}
	return 0;
}

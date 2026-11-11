#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int num=1;
	int i;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			num=0;
			break;
		}
	}
	if(num==1)
	{
		printf("%d是素数。\n",x);
	}
	else if(num==0)
	{
		printf("%d不是素数。\n",x);
	}
	return 0;
 } 

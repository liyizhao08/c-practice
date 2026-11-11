#include <stdio.h>
int main()
{
	int x;
	for(x=2;x<100;x++)
   {
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
		printf("%d\n",x);
	}
   }
	return 0;
 } 

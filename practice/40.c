#include <stdio.h>
int main()
{
	const int max_num=100;
	int x;
	int i;
	int isprime[max_num];
	for(i=0;i<max_num;i++)
	{
		isprime[i]=1;
	}
	for(x=2;x<max_num;x++)
	{
		if(isprime[x])
		{
			for(i=2;i*x<max_num;i++)
			{
				isprime[i*x]=0;
			}
		}
	}
	for(i=2;i<max_num;i++)
	{
		if(isprime[i])
		{
			printf("%d ",i);
		}
	}
	return 0;
}


#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i=1;
	int first=1;
	while(i<N)
	{
		first*=10;
		i++;
	}
	i=first;
	while(i<first*10)
	{
		int t=i;
		int sum=0;
		do
		{
			int d=t%10;
			int a;
			int p=1;
			for(a=1;a<=N;a++)
			{
				p*=d;
			}
			t/=10;
			sum+=p;
		}while(t>0);
		if(sum==i)
	{
		printf("%d ",i);
	}
		i++;
	}
	return 0;
} 

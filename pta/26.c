#include <stdio.h>
int main()
{
	int M,N;
	scanf("%d %d",&M,&N);
	int i;
	int t=M;
	int sum=0;
	int count=0;
	while(t<=N)
	{
		int isprime=1;
		if(t==1)
		{
			t=2;
		}
		for(i=2;i<t;i++)
		{
			if(t%i==0)
			{
				isprime=0;
				break;
			}
			
		}
		if(isprime==1)
		{
			sum+=t;
			count++;
		}
		t++;
	}
	printf("%d %d",count,sum);
	return 0;
} 

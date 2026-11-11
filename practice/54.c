#include <stdio.h>
int isprime(int a,int prime1[],int primenumber);
int main()
{
	const int number=10;
	int prime[number];
	prime[0]=2;
	int cnt=1;
	int i=3;
	while(cnt<number)
	{
		if(isprime(i,prime,cnt))
		{
			prime[cnt++]=i;
		}
		i++;
	}
	int j;
	for(j=0;j<number;j++)
	{
		printf("%d",prime[j]);
		if((j+1)%5!=0)
		{
			printf("\t");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}
int isprime(int a,int prime1[],int primenumber)
{
	int ret=1;
	int k;
	for(k=0;k<primenumber;k++)
	{
		if(a%prime1[k]==0)
		{
			ret=0;
			break;
		}
	}
	return ret;
}

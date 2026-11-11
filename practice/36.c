#include <stdio.h>
int main0(int i)
{
	int isprime=1;
	int k;
	for(k=2;k<i;k++)
	{
		if(i%k==0)
		{
			isprime=0;
			break;
		}
	}
	return isprime;
}
int main()
{
	int m,n;
	int sum=0;
	int count=0;
	scanf("%d %d",&m,&n);
	int i;
	if(m=1)
	{
		m=2;
	}
	for(i=m;i<=n;i++)
	{
		if(main0(i))
		{
			sum+=i;
			count++;
		}
	}
	printf("%d %d",sum,count);
	return 0;
}

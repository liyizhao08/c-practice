#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int min;
	if(a<b)
	{
		min=a;
	}
	else
	{
		min=b;
	}
	int i;
	int sum;
	for(i=1;i<min;i++)
	{
		if(a%i==0&&b%i==0)
		{
			sum=i;
		}
	}
	printf("%d",sum);
	return 0;
} 

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	double num=1.0;
	for(i=1;i<=n;i++)
	{
		num*=i;
	}
	printf("1/%d!=%lf",n,1/num);
	return 0;
}

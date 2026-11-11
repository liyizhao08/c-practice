#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	double num=0.0;
	double a=1.0;
	int i;
	for(i=1;i<=n;i++)
	{
		num+=a/i;
		a=-a;
	}
	printf("f(%d)=%lf",n,num);
	return 0;
} 

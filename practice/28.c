#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	double a=1;
	double b=2;
	double t;
	double sum=0.0;
	for(i=1;i<=n;i++)
	{
		sum+=b/a;
		t=b;
		b=a+b;
		a=t;
	}
	printf("%.2f",sum);
	return 0;
}

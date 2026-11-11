#include <stdio.h>
int main()
{
	int a,n;
	scanf("%d %d",&a,&n);
	int sum=0;
	int p=0;
	int i;
	for(i=1;i<=n;i++)
	{
		p=p*10+a;
		sum+=p;
	}
	printf("%d",sum);
	return 0;
}

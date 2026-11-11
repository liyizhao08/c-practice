#include <stdio.h>
int main()
{
	int n;
	int num=1;
	int i=n;
	scanf("%d",&n);
	for(i>=1;i--)
	{
		num*=i;
	}
	printf("%d!=%d\n",n,num);
	return 0;
}

#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d/%d",&a,&b);
	int c=a;
	int d=b;
	int t;
	while(d>0)
	{
		t=c%d;
		c=d;
		d=t;
	}
	printf("%d/%d\n",a/c,b/c);
	return 0;
}

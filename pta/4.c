#include <stdio.h>
int main()
{
	printf("请输入三个数。\n");
	int a,b,c;
	int max=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
		{
			max=a;
		}
		else
		{
			max=c;
		}
	}
	else if(a<b)
	{
		if(b>c)
		{
			max=b;
		}
		else
		{
			max=c;
		}
	}
	printf("最大的数是%d。\n",max);
	return 0;
}

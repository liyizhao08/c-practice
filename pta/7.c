#include <stdio.h>
int main()
{
	int num;
	int n=0;
	scanf("%d",&num);
	if(num==0)
	{
		printf("1\n");
		return 0;
	}
	while(num>0)
	{
		num/=10;
		n++;
	}
	printf("%d\n",n);
	return 0;
}

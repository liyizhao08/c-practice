#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int a;
	int b;
	int i=0; 
	int num[1000];
	do
	{
		a=x%10;
		num[i]=a;
		x/=10;
		i++;
	}while(x>0);
	int j;
	for(j=0;j<i;j++)
	{
		printf("%d ",num[j]);
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
void num(int a,int b)
{
	int i;
	int sum=0;
	for(i=a;i<=b;i++)
	{
		sum+=i;
	}
	printf("%d到%d的和是%d\n",a,b,sum);
}
int main()
{
	num(10,20);
	num(30,40);
	return 0;
 }

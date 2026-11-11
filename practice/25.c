#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i=1;
	while(i<=N)
	{
		int j=1;
		while(j<=i)
		{
			printf("%d*%d=%d",j,i,i*j);
			if(i*j<10)
			{
				printf("   ");
			}
			else
			{
				printf("  ");
			}
			j++;
		}
		i++;
		printf("\n");
	}
	return 0;
}

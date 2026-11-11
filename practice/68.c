#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d = ",n);
	int i;
	int ans=0;
	for(i=2;i<=n/i;i++)
	{
		int cnt=0;
		while(n%i==0)
		{
			n/=i;
			cnt++;
		}
		if(cnt>0)
		{
			if(ans==1)
			{
				printf(" * ");
			}
			if(cnt==1)
			{
				printf("%d",i);
			}
			else
			{
				printf("%d^%d",i,cnt);
			}
			ans=1;
		}
	}
	if(n>1)
	{
		if(ans==1)
		{
			printf(" * ");
		}
		printf("%d",n);
	}
	return 0;
 } 

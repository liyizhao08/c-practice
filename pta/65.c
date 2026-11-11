#include <stdio.h>
int main()
{
	int s,n;
	scanf("%d %d",&s,&n);
	int i;
	int x[n],y[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	int k,l,temp;
	for(k=0;k<n-1;k++)
	{
		for(l=0;l<n-1-k;l++)
		{
			if(x[l]>x[l+1])
			{
				temp=x[l];
				x[l]=x[l+1];
				x[l+1]=temp;
				temp=y[l];
				y[l]=y[l+1]; 
				y[l+1]=temp;
			}
		}
	}
	int j;
	int ans=1;
	for(j=0;j<n;j++)
	{
		if(s<=x[j])
		{
			printf("NO");
			return 0;
		}
		else
		{
			s+=y[j];
		}
	}
	if(ans==1)
	{
		printf("YES");
	}
	return 0;
 } 

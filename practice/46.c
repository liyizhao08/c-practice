#include <stdio.h>
int main()
{
	void minmax(int a[],int len,int *min,int *max);
	int a[]={1,2,3,4,5,6,7,8,9,10,23,45,67,77,88};
	int min,max;
	minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
	printf("min=%d,max=%d",min,max);
	return 0;
}

void minmax(int a[],int len,int *min,int *max)
{
	int i;
	*min=*max=a[0];
	for(i=1;i<len;i++)
	{
		if(a[i]>*max)
		{
			*max=a[i];
		}
		if(a[i]<*min)
		{
			*min=a[i];
		}
	}
}

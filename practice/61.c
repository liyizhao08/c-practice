#include <stdio.h>
struct numbo
{
	int num;
	struct numbo *p;
};
int main()
{
	struct numbo num1={1,NULL};
	struct numbo num2={2,NULL};
	struct numbo num3={3,NULL};
	num1.p=&num2;
	num2.p=&num3;
	struct numbo *cur=&num1;
	while(cur!=0)
	{
		printf("%d",cur->num );
		if(cur->p ) printf("->");
		cur=cur->p ;
	}
	return 0;
}

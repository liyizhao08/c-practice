#include <stdio.h>
typedef struct 
{
	int x;
	int y;
}a;
int main()
{
	a num={5,6};
	a sum={7,8};
	printf("a.x=%d  a.y=%d",num.x,num.y);
	printf("a.x=%d  a.y=%d",sum.x,sum.y);
	return 0;
 } 

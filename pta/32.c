#include <stdio.h>
int main()
{
	long double a=1.0;
	printf("sizeof(a)=%d\n",sizeof(a));
	printf("sizeof(a+1.0)=%d\n",sizeof(a+1.0));
	return 0;
} 

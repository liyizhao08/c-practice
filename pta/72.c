#include <stdio.h>
int main()
{
	int num=0;
	printf("%*d\n",4,123);
	printf("%dty%n\n",12345,&num);
	printf("%d\n",num);
	return 0;
 } 

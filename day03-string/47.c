#include <stdio.h>
int main()
{
	char ac[]={0,1,2,3,4,5,6,7,8,9};
	char *p=&ac[0];
	char *p1=&ac[5];
	printf("p=%p\n",p);
	printf("p1=%p\n",p1);
	printf("p1-p=%d\n",p1-p);
	int ai[]={0,1,2,3,4,5,6,7,8,9};
	int *q=&ai[0];
	int *q1=&ai[6];
	printf("q=%p\n",q);
	printf("q1=%p\n",q1);
	printf("q1-q=%d\n",q1-q);
	printf("q1-1=%x\n",q1-1);
	printf("q1-1=%p\n",q1-1);
	return 0; 
 } 

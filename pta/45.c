#include <stdio.h>
int main()
{
	void f(int *p);
	void g(int i);
	
	int i=6;
	printf("%p\n",&i);
	f(&i);
	g(i);
	return 0;
 } 
 
 void f(int *p)
 {
 	printf("p=%p\n",p);
 	*p=34;
 }
 void g(int i)
 {
 	int j=i;
 	printf("j=%d",j);
 }

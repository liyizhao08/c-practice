#include <stdio.h>
int *f(void);
void g(void);
int main()
{
	int *p=f();
	printf("*p=%d\n",*p);
	g(); 
	printf("*p=%d\n",*p);
	return 0;
 } 
 int *f(void)
 {
 	int i=12;
 	printf("i=%p\n",&i);
 	return &i;/*返回本地变量的地址是危险的，因为在主函数中会被其他本地变量使用*/ 
 }
 void g(void)
 {
 	int k=24;
 	printf("k=%p\n",&k);
 	printf("k=%d\n",k);
 }

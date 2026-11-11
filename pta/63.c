#include <stdio.h>
int gall=10;/*全局变量如果没有初始化，会默认给0，指针给NULL,这和本地变量不同*/ 
void f(int a);
void num(int a);
int main() 
{
	printf("in main gall=%d\n",gall);
	f(gall);
	num(gall);
	printf("agen in main gall=%d\n",gall);
}
void f(int a)
{
	printf("in f gall=%d\n",gall);
	gall+=10;
	printf("agen in f gall=%d\n",gall);
}
void num(int a)
{
	int gall=1;/*就近原则，因为num函数里的局部变量gall和全局变量重名了所以num
	函数用的是局部变量*/ 
	printf("in num gall=%d\n",gall);
	gall+=2;
	printf("agen in num gall=%d\n",gall);
}

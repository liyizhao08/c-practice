#include <stdio.h>
void f(int a);
void act();
int gall=12; 
int main()
{
	int num=1;
	f(num);
	f(num);
	f(num);
	act();
	printf("num=%d\n",num);
 } 
 void f(int a)
 {
 	static int sum=1;/*static会使变量sum变成静态本地变量，相当于初始化一次，然后
	 后续不管进入函数几次sum'都不会被初始化为1*/
	 /*此时sum有全局变量的生存周期，又有局部变量的有限范围*/ 
 	printf("in f sum=%d\n",sum);
 	sum=sum+a;
 	printf("in f sum=%d\n",sum);
 }
 void act()
 {
 	int k=1;
 	static int sum1=10;/*相当于全局变量*/ 
 	printf("sum1=%p\n",&sum1);/*0040400C*/
 	printf("gall=%p\n",&gall);/*00404004*/
 	/*这两个地址相差8个字节，就是两个int类型，(因为f函数里面还有一个static)*/ 
 	printf("k   =%p\n",&k);
 }

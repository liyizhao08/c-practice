#include <stdio.h>
#define pi 3.14/*除注释符号外，其他符号也会因为宏而被替换进代码，很容易引起编译错误*/ 
#define num 1+2/*宏*/ 
#define prt printf("abc")\
printf("bcd")/*当宏中有多行代码是要加'\'并且后面不能有任何字符*/
#define DEBUG/*没有值的宏，通常用来做条件编译的*/ 
int main()
{
	double sum;
	int sum1;
	sum=pi*2;
	sum1=num*2;
	printf("%lf\n",sum);
	printf("%d\n",sum1);
	return 0;
 } 

#include <stdio.h>
void swap(int *p1,int *p2);
void divmod(int c,int d,int *p3,int *p4);/*函数前提提示*/ 
void bad(int *p);
void good(int**p); 
int main()
{
	int a=100;
	int b=200;
	int A,B;/*A为商，B为余数*/ 
	swap(&a,&b);
	divmod(17,5,&A,&B);/*函数中定义的是指针所以要传地址*/ 
	printf("a=%d,b=%d\n",a,b);/* *p就像是虚无中的锚点，可以在其他函数中改变主函数传进去的地址里的变量*/ 
	printf("A=%d,B=%d\n",A,B);/*从主函数中传入变量，可以在函数中完成运算并通过*p传入地址*/ 
	int x=100;
	int *pp = &x;/*这里定义了指针pp(pp就是x的地址，因为bad那里是int*p所以pp也可以用&x代替，这就是为什么bad那里不用&）,*pp是x的值*/ 
	printf("x=%p\n",&x); 
	printf("初始      pp = %p,x=%p,x=%d\n", (void *)pp,&x,x);
	bad(pp);/* pp储存了x的地址，bad就类似于函数，pp和p只是地址一样但他们在两个位面 
	然后p=NULL就改变了 pp交给p的地址，但没改变x，然后pp的地址也没变*/ 
	printf("bad 之后  pp = %p,x=%p,x=%d\n", (void *)pp,&x,x);
	good(&pp);/*给了pp的地址然后变为0*/ 
	printf("good 之后 pp = %p,x=%p,x=%d\n", (void *)pp,&x,x);
	/*bad改变了pp交给p的地址但没有影响pp，good改变了pp储存的x的地址*/ 
	return 0;
 } 
 void swap(int *p1,int *p2)
 {
 	int t;
 	t=*p1;
 	*p1=*p2;
 	*p2=t;
 }
 void divmod(int c,int d,int *p3,int *p4)
 {
 	if(d==0)
 	{
 		*p3=0;
 		*p4=0;
 		return;/*只结束函数，不返回值*/ 
	 }
 	*p3=c/d;
 	*p4=c%d;
 }
 void bad(int *p)
 {
 	printf("  bad 内部 p = %p\n", (void *)p);
 	p=NULL;
 	printf("  bad 内部改完 p = %p\n", (void *)p);
 }
 void good(int **p)
 {
 	p=NULL;
 }

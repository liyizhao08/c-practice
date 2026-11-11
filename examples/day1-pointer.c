#include <stdio.h>
int main()
{
	int a=1;
	char b='a';
	double c=2.0;
	int *p1;
	char *p2;
	double *p3;
	p1=&a;
	p2=&b;
	p3=&c;
	printf("a=%d,a=%p,*p1=%d,p1=%p\n",a,(void*)&a,*p1,p1);
	printf("b=%c,b=%p,*p2=%c,p2=%p\n",b,(void*)&b,*p2,p2);
	printf("c=%lf,c=%p,*p3=%lf,p3=%p\n",c,(void*)&c,*p3,p3);/*(void*)是通用指针可用于普通变量*/ 
	*p1=3;/* *p指的是指针所指地址里面的变量，*p发生变化，变量也随之改变*/
	/* *p+1是地址里变量加1；p+1是地址加1，所增加的是sizeof(对应的数据类型）即字节长度*/ 
	printf("a=%d,p1=%p\n",a,p1);/*p1指向的地址a里面的变量因*p1的改变而发生变化，但p1仍指向a，地址名a不变，所以p1地址不变*/ 
	int num[]={1,2,3,4,5,6,7,8,9};/*在数组中元素的地址是不同且连续的，相邻元素之间的间隔为定义数组的数据类型的字节长，
	如int就是4，char是1，double是8*/ 
	int *p4;
	p4=num;
	printf("*p4=%d,p4=%p,num[0]=%p,num[1]=%p\n",*p4,p4,&num[0],&num[1]);
	printf("*p4++=%d,num[2]=%p,num[3]=%p\n",*p4++,&num[2],&num[3]);/*'++'的优先级比'*'高*/
	printf("p4=%p\n",p4);/* *p++是取出当前变量然后指针指向下一个地址，(*p)++是输出当前变量然后变量加1，地址不变
	++*p是当前地址变量加1然后输出，*++p是 指向下一个地址然后输出变量*/ 
	int *p5,*p6,*p7;
	p5=&num[3];/*4*/
	p6=&num[5];/*6*/
	p7=&num[7];/*8*/
	int a1,a2,a3;
	a1=(*p5)++;
	a2=*++p6;/*此时p6指向num[6]*/ 
	a3=++*p7;
	int i;
	for(i=0;i<9;i++)
	{
		printf("num[%d]=%p  ",i,&num[i]);
	}
	printf("\n");
	printf("a1=%d,a2=%d,a3=%d\n",a1,a2,a3);
	printf("a1=%p,a2=%p,a3=%p\n",&a1,&a2,&a3);
	printf("sizeof(int)=%lu,sizeof(char)=%lu,sizeof(double)=%lu\n",(unsigned long)sizeof(int),(unsigned long)sizeof(char),(unsigned long)sizeof(double));
	int p8=p7-p6;/*如果是数组指针那么两指针相减是数组下标相减,就是两指针对应地址的对应元素中有多少个元素*/ 
	/* p8=1是因为p6因为在第35行代码中指向了num[6]*/ 
	printf("p8=%d\n",p8);
	for (i = 0; i < 9; i++)
	{
    printf("num[%d]=%d  *(num+%d)=%d  &num[%d]=%p  num+%d=%p  值%s 址%s\n",
           i, num[i], i, *(num+i),
           i, (void *)&num[i], i, (void *)(num+i),/*num[i]=*(num+i)*/
           num[i] == *(num+i) ? "等" : "不等",
           &num[i] == (num+i) ? "等" : "不等");
	}
	int *p9; 
	p9  = &num[6];
    printf("元素个数 : %ld\n", (long)((p9 + 1) - p9));                    // 1
    printf("字节数   : %ld\n", (long)((char *)(p9+1) - (char *)p9));      // 4对应整数类型的字节长 
	return 0;
 } 

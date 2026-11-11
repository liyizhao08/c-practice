#include <stdio.h>
typedef struct point
{
	int x;
	int y;
}point;
void move(point p,int dx,int dy)
{
	p.x+=dx;
	p.y+=dy;/*因为没有地址所以传进来的是副本，不会影响主函数*/ 
}
void move_change(point *p,int dx,int dy)
{
	p->x+=dx;/*传进来的是指针，有地址，所以会影响到主函数*/ 
    p->y+=dy;
}
typedef struct node
{
	int num;
	struct node *next;/* 没加struct编译报错，因为程序要到右括号才能生效，在结构体中node还不存在 
	。而且编译器不知道指针next是什么类型的*/ 
}node;
int main()
{
	point p={3,4};
	point q=p;
	q.x=23;
	point *pp=&p;
	printf("p.x=%d  p.y=%d\n",p.x,p.y);
	printf("pp->x=%d   pp->y=%d\n",pp->x,pp->y);
	printf("(*pp).x=%d   (*pp).y=%d\n",(*pp).x,(*pp).y);/* *pp.x不行，因为'.'的优先级更高，计算机会先看pp.x而
	pp是指针，要用->所以要加括号*/ 
	printf("q.x=%d  q.y=%d\n",q.x,q.y);
	p.x=10;
	printf("改之后：p.x=%d   p.y=%d\n",p.x,p.y);
	move(p,100,100);
	printf("move之后  p.x=%d  p.y=%d\n",p.x,p.y);/*将变量值传进去，没有地址改变的是副本，主函数没有影响*/ 
	move_change(pp,100,100);/*将指针传进去，提供了地址，通过地址改变变量主函数也受到了影响*/ 
	printf("move_change之后   pp->x=%d   pp->y=%d\n",pp->x,pp->y);
	
	
	node n1={1,NULL};
	node n2={2,NULL};
	node n3={3,NULL};
	n1.next=&n2;
	n2.next=&n3;
	printf("n1.num=%d   n1.next->num=%d\n",n1.num,n1.next->num);/* 因为n1.next=&n2,所以编译器通过n2的地址进入n2
	并提取出n2.num*/ 
	node *cur=&n1;
	while(cur!=NULL)/*循环条件*/ 
	{
		printf("%d",cur->num);/*输出变量*/ 
		if(cur->next) printf("->");/*通过指针中的地址进入下一组数据，如果n2改为0，就会少一个'->'*/ 
		cur=cur->next;/*相当于cur=&n2进入下一组数据*/ 
	}
	printf("\n");
	return 0;
 } 

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int val;
	struct _node *next;
}node;

void add(node ** pHead,int number);
void search(node **pHead,int target);

int main()
{
	node *head=NULL;
	int number;
	do
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			add(&head,number); 
		}
	}while(number!=-1);
	node *cur=head;
	node *temp;
	while(cur)
	{
		printf("%d\n",cur->val );
		cur=cur->next ;
	}
	int target;
	printf("输入数字\n");
	scanf("%d",&target);
	search(&head,target);
	printf("删除后的链表\n");
	cur=head;
	while(cur)
	{
		printf("%d\n",cur->val );
		cur=cur->next ;
	}
	cur=head;
	while(cur)
	{
		temp=cur->next ;
		free(cur);
		cur=temp;
	}
	head=NULL;
	return 0; 
}

void add(node ** pHead,int number)
{
	node *p=(node *)malloc(sizeof(node));
	p->val =number;
	p->next =NULL;
	node *last=*pHead;/*每次循环重置，时期从第一个结点开始*/ 
	if(last==NULL)
		{
			*pHead=p;
		}
	else
		{
			while(last->next )
		{
		    last=last->next; 
		}
		    last->next =p;
		}
}

void search(node **pHead,int target)
{
	node *cur=*pHead;
	node *prev=NULL;
	int position=1;
	while(cur!=NULL)
	{
		if(cur->val ==target)
		{
			printf("找到了,在第%d个节点\n",position);
			if(prev==NULL)
			{
				*pHead=cur->next ;
			}
			else
			{
				prev->next =cur->next ;
			}
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->next ;
		position++;
	}
	printf("没有找到 %d\n",target);
}

#include <stdio.h>
#include <stdlib.h>
const int block_size=20;
typedef struct 
{
	int *add;
	int size;
}arry;

arry arry_create(int size_long)
{
	arry b;
	b.size =size_long;
	b.add =malloc(sizeof(int)*size_long);
	return b;
}

void free_arry(arry *num)
{
	free(num->add );
	num->add =NULL;
	num->size =0;
}

int arry_size(const arry *a)
{
	return a->size ;
 } 
 
 void arry_inflate(arry *a,int more_size);
 int *arry_at(arry *a,int index)
 {
 	if(index>=a->size )
 	{
 		arry_inflate(a,(index/block_size+1)*block_size-a->size );
	 }
 	return &(a->add[index]);
 }
 
 void arry_inflate(arry *a,int more_size)
 {
 	/*int *p=(int*)malloc(sizeof(int)*(a->size +more_size));
 	int k;
 	for(k=0;k<a->size ;k++)
 	{
 		p[k]=a->add [k];
	 }
	 free(a->add );
	 a->add =p;
	 a->size +=more_size;*/
	 /*realloc版本 */
	 int new_size;
	 new_size=a->size+more_size;
	 int *p=(int*)realloc(a->add,sizeof(int)*new_size);/*原地扩容*/ 
	 if(p!=NULL)
	 {
	 a->add=p;/*指针p的地址交给结构体*/ 
	 a->size=new_size;
     }
     
  } 
  
int main()
{
	int n;
	scanf("%d",&n);
	arry a=arry_create(n);
	int i;
	for(i=0;i<a.size ;i++)
	{
		a.add[i] =i;
	}
	int j;
	for(j=0;j<a.size ;j++)
	{
		printf("%d\n",a.add[j] );
	}
	printf("\n");
	printf("%d\n",arry_size(&a));
	printf("%d\n",*arry_at(&a,1));
	printf("\n");
	int number=0;
	int cnt=a.size ;
	while(number!=-1)
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			*arry_at(&a,cnt++)=number;
		}
	}
	int l;
	printf("追加后的数组\n");
	for(l=0;l<cnt;l++)
	{
		printf("%d\n",*arry_at(&a,l));
	}
	printf("当前容量为%d\n",arry_size(&a));
	free_arry(&a);
	return 0;
}

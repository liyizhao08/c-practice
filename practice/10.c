#include <stdio.h>
	int count=0;
	int a=0;
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int num=rand()%100+1;
	printf("我已经想好了一个1到100之间的数。\n");
	do
	{
		printf("猜猜这个数。\n");
		scanf("%d",&a);
		count++;
		if(a>num)
		{
			printf("你猜的数大了。\n");
		}
		else if(a<num)
		{
			printf("你猜的数小了。\n");
		}
	}
	while(a!=num);
	printf("恭喜你，猜对了！\n");
	return 0;
}

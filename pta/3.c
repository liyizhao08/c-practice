#include <stdio.h>
int main()
{
	int num0;
	int num1=0;
	int num2=0;
	int num3=0;
	int num4=0;
	int num5=0;
	int score=0;
	printf("准备好了吗，准备好按1，没准备好按0。\n");
	scanf("%d",&num0);
	if(num0==1)
	{
		printf("那么游戏开始。\n");
	}
	else
	{
		printf("那准备好了告诉我。\n");
		return 0;
	}
	printf("第一题：\n");
	printf("5+2=");
	scanf("%d",&num1);
	if(num1==7)
	{
		printf("太棒了，让我们开始下一题吧。\n");
		score+=20;
	}
	else
	{
		printf("不对哦，正确答案是7，再接再厉！\n");
	}
	printf("第二题：\n");
	printf("10+2=");
	scanf("%d",&num2);
	if(num2==12)
	{
		printf("太棒了，让我们开始下一题吧。\n");
		score+=20;
	}
	else
	{
		printf("不对哦，正确答案是12，再接再厉！\n");
	}
	printf("第三题：\n");
	printf("50*3=");
	scanf("%d",&num3);
	if(num3==150)
	{
		printf("太棒了，让我们开始下一题吧。\n");
		score+=20;
	}
	else
	{
		printf("不对哦，正确答案是150，再接再厉！\n");
	}
	printf("第四题：\n");
	printf("25-12=");
	scanf("%d",&num4);
	if(num4==13)
	{
		printf("太棒了，让我们开始下一题吧。\n");
		score+=20;
	}
	else
	{
		printf("不对哦，正确答案是13，再接再厉！\n");
	}
	printf("第五题：\n");
	printf("80/4= ");
	scanf("%d",&num5);
	if(num5==20)
	{
		score+=20;
	}
	else
	{
		printf("不对哦，正确答案是20，再接再厉！\n");
	}
	  printf("游戏结束，你的得分是%d分\n",score);
	 if(score>=60)
	 {
	 	printf("太棒了！\n");
	 }
	 else
	 {
	 	printf("还需努力。\n");
	 }
	 return 0;
 } 

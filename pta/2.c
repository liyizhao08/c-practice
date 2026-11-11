#include <stdio.h>
int main()
{
	int price=0;
	int a=50;
	int b=30;
	int c=20;
	int d=10;
	int f=5;
	printf("月初。\n");
	printf("你的生活费是：\n");
	scanf("%d",&price);
	printf("餐厅。\n");
	printf("服务员：先生需要些什么？\n");
	printf("你：先看菜单。\n");
	printf("服务员；好的先生，我们有这些菜品：a：牛排 50元，b：火腿 30元，c：鸡蛋 20元，d：配菜 10元，f：馒头 5元。\n");
	printf("你：我要一些牛排和牛排，一大块上好的牛排，加上所有的牛排，再浇上浓浓的牛排。\n");
	printf("服务员：生吃一头牛啊，先生。\n");
	printf("你：我知道，另外再来一份冰镇牛排。\n");
	int num=price-a*6;
	if(num>=0)
	{
		printf("还剩%d元。\n",num);
	}
	else
	{
		printf("余额不足。\n");
		printf("游戏失败。\n");
		return 0;
	}
	 printf("月中。\n");
	 printf("餐厅。\n");
	 printf("服务员：先生需要些什么？\n");
	 printf("你：我要一些火腿和鸡蛋一大块上好的炸牛排加上所以的配菜浇上浓浓的汁。\n");
	 printf("服务员：这得花不少钱。\n");
	 printf("你：我知道，另外再来一杯冰镇浓汁。\n");
	 int num1=num-(b+c+d);
	 if(num1>=0)
	{
		printf("还剩%d元。\n",num1);
	}
	else
	{
		printf("余额不足。\n");
		printf("游戏失败。\n");
		return 0;
	}
	  printf("月末。\n");
	  printf("餐厅。\n");
	  printf("服务员：先生需要些什么？\n"); 
	  printf("你：我要一份馒头和馒头，一大块上好的馒头，馒头上多放点馒头，在浇上一百度的开水。\n");
	  printf("服务员：这得花不少钱。\n");
	  printf("你：牛魔的黑店，我带着回家吃不行吗，再来一份冰馒头。\n");
	  int num2=num1-f*6;
	 if(num2>=0)
	{
		printf("还剩%d元。\n",num2);
	}
	else
	{
		printf("余额不足。\n");
		printf("游戏失败。\n");
		return 0;
	}
	printf("月底。\n");
	printf("餐厅。\n");
	printf("服务员：先生需要些什么？\n");
	printf("你：我要一些浓浓的汁，上好的浓浓的汁，加上所有的浓浓的汁，再浇上浓浓的汁。\n");
	printf("服务员：这得花不少浓浓的汁，先生。\n");
	if(num2>=0)
	{
		printf("恭喜你，存活了下来。\n");
	}
	else
	{
		printf("游戏失败。\n");
		return 0;
	}
	return 0;
}

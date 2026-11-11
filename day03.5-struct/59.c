#include <stdio.h>
#include <stdbool.h>
struct date
{
	int year;
	int month;
	int day;
}day1;/*全局变量*/ 
bool isleap(struct date a);
int numofdate(struct date a); 
int main()
{
	day1.year =2026;
	day1.month =10;
	day1.day=31;
	printf("%d-%d-%d\n",day1.year ,day1.month ,day1.day );
	struct date today;
	printf("输入日期：\n");
	scanf("%d %d %d",&today.year ,&today.month ,&today.day );
	if(today.day !=numofdate(today))
	{
		today.day +=1;
	}
	else if(today.month ==12)
	{
		today.day =1;
		today.month =1;
		today.year +=1;
	}
	else
	{
		today.day =1;
		today.month +=1;
	}
	printf("tomorrow's is %d-%d-%d",today.year ,today.month ,today.day );
	return 0;
}
int numofdate(struct date a)
{
	int days;
	const int monthnum[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(a.month ==2&&isleap(a))
	{
		days=29;
	}
	else
	{
		days=monthnum[a.month -1];
	}
	return days;
}
bool isleap(struct date a)
{
	bool leap=false;
	if((a.year%4==0&&a.year %100!=0)||(a.year %400==0))
	{
		leap=true;
	}
	return leap;
}

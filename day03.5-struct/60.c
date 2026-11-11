#include <stdio.h>
typedef struct date 
{
	int year;
	int month;
	int day;
}day3;
int main()
{
	day3 day4={2026,10,30};
	printf("%d-%d-%d\n",day4.year ,day4.month ,day4.day );
	struct date day1={2026,10,29};
	struct date *day2;
	day2=&day1;
	printf("%d-%d-%d\n",day1.year ,day1.month ,day1.day );
	printf("%d-%d-%d\n",day2->year ,day2->month ,day2->day );
	day2->day=30;
	printf("%d-%d-%d\n",day1.year ,day1.month ,day1.day);
	return 0;
 } 

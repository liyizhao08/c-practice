#include <stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
int main()
{
     struct date today={2026,10,28};
     struct date today1={2026,10};
     struct date *today2;
     struct date days={2026,10,28};
     today2=&days;
     printf("today is %d-%d-%d\n",today.year ,today.month ,today.day);
     printf("today is %d-%d-%d\n",today1.year ,today1.month ,today1.day );
     printf("today is %d-%d-%d\n",today2->year ,today2->month ,today2->day);
     return 0;
 } 

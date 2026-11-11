#include <stdio.h>
enum color {red,yellow,green};
void f(enum color c);
int main()
{
	enum color t;
	printf("ÇëÊäÈëÑÕÉ«´úÂë\n");
	scanf("%d",&t);
	f(t);
	return 0;
}
void f(enum color c)
{
	switch(c)
	{
		case red:
			printf("red\n");
			break;
		case yellow:
			printf("yellow\n");
			break;
		case green:
			printf("green\n");
			break;
		default:
			printf("worring\n");
			break;
	}
}
